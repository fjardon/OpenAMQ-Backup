/* Copyright 2000-2005 The Apache Software Foundation or its licensors, as
 * applicable.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "apr_arch_poll_private.h"

#if defined(POLL_USES_POLL) || defined(POLLSET_USES_POLL)

static apr_int16_t get_event(apr_int16_t event)
{
    apr_int16_t rv = 0;

    if (event & APR_POLLIN)
        rv |= POLLIN;
    if (event & APR_POLLPRI)
        rv |= POLLPRI;
    if (event & APR_POLLOUT)
        rv |= POLLOUT;
    if (event & APR_POLLERR)
        rv |= POLLERR;
    if (event & APR_POLLHUP)
        rv |= POLLHUP;
    if (event & APR_POLLNVAL)
        rv |= POLLNVAL;

    return rv;
}

static apr_int16_t get_revent(apr_int16_t event)
{
    apr_int16_t rv = 0;

    if (event & POLLIN)
        rv |= APR_POLLIN;
    if (event & POLLPRI)
        rv |= APR_POLLPRI;
    if (event & POLLOUT)
        rv |= APR_POLLOUT;
    if (event & POLLERR)
        rv |= APR_POLLERR;
    if (event & POLLHUP)
        rv |= APR_POLLHUP;
    if (event & POLLNVAL)
        rv |= APR_POLLNVAL;

    return rv;
}

#endif /* POLL_USES_POLL || POLLSET_USES_POLL */


#ifdef POLL_USES_POLL

#define SMALL_POLLSET_LIMIT  8

APR_DECLARE(apr_status_t) apr_poll(apr_pollfd_t *aprset, apr_int32_t num,
                                   apr_int32_t *nsds, 
                                   apr_interval_time_t timeout)
{
    int i, num_to_poll;
#ifdef HAVE_VLA
    /* XXX: I trust that this is a segv when insufficient stack exists? */
    struct pollfd pollset[num];
#elif defined(HAVE_ALLOCA)
    struct pollfd *pollset = alloca(sizeof(struct pollfd) * num);
    if (!pollset)
        return APR_ENOMEM;
#else
    struct pollfd tmp_pollset[SMALL_POLLSET_LIMIT];
    struct pollfd *pollset;

    if (num <= SMALL_POLLSET_LIMIT) {
        pollset = tmp_pollset;
    }
    else {
        /* This does require O(n) to copy the descriptors to the internal
         * mapping.
         */
        pollset = malloc(sizeof(struct pollfd) * num);
        /* The other option is adding an apr_pool_abort() fn to invoke
         * the pool's out of memory handler
         */
        if (!pollset)
            return APR_ENOMEM;
    }
#endif
    for (i = 0; i < num; i++) {
        if (aprset[i].desc_type == APR_POLL_SOCKET) {
            pollset[i].fd = aprset[i].desc.s->socketdes;
        }
        else if (aprset[i].desc_type == APR_POLL_FILE) {
            pollset[i].fd = aprset[i].desc.f->filedes;
        }
        else {
            break;
        }
        pollset[i].events = get_event(aprset[i].reqevents);
    }
    num_to_poll = i;

    if (timeout > 0) {
        timeout /= 1000; /* convert microseconds to milliseconds */
    }

    i = poll(pollset, num_to_poll, timeout);
    (*nsds) = i;

    for (i = 0; i < num; i++) {
        aprset[i].rtnevents = get_revent(pollset[i].revents);
    }
    
#if !defined(HAVE_VLA) && !defined(HAVE_ALLOCA)
    if (num > SMALL_POLLSET_LIMIT) {
        free(pollset);
    }
#endif

    if ((*nsds) < 0) {
        return apr_get_netos_error();
    }
    if ((*nsds) == 0) {
        return APR_TIMEUP;
    }
    return APR_SUCCESS;
}


#endif /* POLL_USES_POLL */


#ifdef POLLSET_USES_POLL

struct apr_pollset_t
{
    apr_pool_t *pool;
    apr_uint32_t nelts;
    apr_uint32_t nalloc;
    struct pollfd *pollset;
    apr_pollfd_t *query_set;
    apr_pollfd_t *result_set;
#ifdef APR_SOCKET_BUFFER
    apr_uint32_t cnelts;
    struct pollfd *cpollset;
    apr_uint32_t *cpollmap;
#endif
};

APR_DECLARE(apr_status_t) apr_pollset_create(apr_pollset_t **pollset,
                                             apr_uint32_t size,
                                             apr_pool_t *p,
                                             apr_uint32_t flags)
{
    if (flags & APR_POLLSET_THREADSAFE) {                
        *pollset = NULL;
        return APR_ENOTIMPL;
    }

    *pollset = apr_palloc(p, sizeof(**pollset));
    (*pollset)->nelts = 0;
    (*pollset)->nalloc = size;
    (*pollset)->pool = p;
    (*pollset)->pollset = apr_palloc(p, size * sizeof(struct pollfd));
    (*pollset)->query_set = apr_palloc(p, size * sizeof(apr_pollfd_t));
    (*pollset)->result_set = apr_palloc(p, size * sizeof(apr_pollfd_t));
#ifdef APR_SOCKET_BUFFER
    (*pollset)->cnelts = 0;
    (*pollset)->cpollset = apr_palloc(p, size * sizeof(struct pollfd));
    (*pollset)->cpollmap = apr_palloc(p, size * sizeof(apr_uint32_t));
#endif /* APR_SOCKET_BUFFER */
    return APR_SUCCESS;
}

APR_DECLARE(apr_status_t) apr_pollset_destroy(apr_pollset_t *pollset)
{
    return APR_SUCCESS;
}

APR_DECLARE(apr_status_t) apr_pollset_add(apr_pollset_t *pollset,
                                          const apr_pollfd_t *descriptor)
{
    if (pollset->nelts == pollset->nalloc) {
        return APR_ENOMEM;
    }

    pollset->query_set[pollset->nelts] = *descriptor;

    if (descriptor->desc_type == APR_POLL_SOCKET) {
        pollset->pollset[pollset->nelts].fd = descriptor->desc.s->socketdes;
    }
    else {
        pollset->pollset[pollset->nelts].fd = descriptor->desc.f->filedes;
    }

    pollset->pollset[pollset->nelts].events =
        get_event(descriptor->reqevents);
    pollset->nelts++;

    return APR_SUCCESS;
}

APR_DECLARE(apr_status_t) apr_pollset_remove(apr_pollset_t *pollset,
                                             const apr_pollfd_t *descriptor)
{
    apr_uint32_t i;

    for (i = 0; i < pollset->nelts; i++) {
        if (descriptor->desc.s == pollset->query_set[i].desc.s) {
            /* Found an instance of the fd: remove this and any other copies */
            apr_uint32_t dst = i;
            apr_uint32_t old_nelts = pollset->nelts;
            pollset->nelts--;
            for (i++; i < old_nelts; i++) {
                if (descriptor->desc.s == pollset->query_set[i].desc.s) {
                    pollset->nelts--;
                }
                else {
                    pollset->pollset[dst] = pollset->pollset[i];
                    pollset->query_set[dst] = pollset->query_set[i];
                    dst++;
                }
            }
            return APR_SUCCESS;
        }
    }

    return APR_NOTFOUND;
}

APR_DECLARE(apr_status_t) apr_pollset_poll(apr_pollset_t *pollset,
                                           apr_interval_time_t timeout,
                                           apr_int32_t *num,
                                           const apr_pollfd_t **descriptors)
{
    int rv = 0;
    apr_uint32_t i, j;
#ifdef APR_SOCKET_BUFFER
    int cevents;

    for (i = 0; i < pollset->nelts; i++) {
        if ((pollset->pollset[i].events & POLLIN) && 
            (pollset->query_set[i].desc.s->rbuf_used > 0)) {
            rv++;
            pollset->pollset[i].revents = POLLIN;
            if (pollset->pollset[i].events != POLLIN) {
                cevents = pollset->pollset[i].events & ~POLLIN;
            } else {
                cevents = 0;
            }
        } else {
            pollset->pollset[i].revents = 0;
            cevents = pollset->pollset[i].events;
        }
        if (cevents) {
            pollset->cpollset[pollset->cnelts].fd = pollset->pollset[i].fd;
            pollset->cpollset[pollset->cnelts].events = cevents;
            pollset->cpollset[pollset->cnelts].revents = 0; 
            pollset->cpollmap[pollset->cnelts] = i;
            pollset->cnelts++;
        }
    }

    if (rv) {
        if (pollset->cnelts) {
            apr_uint32_t more_ready = 
                poll (pollset->cpollset, pollset->cnelts, 0);
            if (more_ready) {
                for(i = 0; more_ready-- && i < pollset->cnelts; i++) {
                    if (pollset->cpollset[i].revents) {
                        if (!pollset->pollset[pollset->cpollmap[i]].revents)
                            rv++;
                        pollset->pollset[pollset->cpollmap[i]].revents |= 
                            pollset->cpollset[i].revents;
                    }
                }
            }
        }
        (*num) = rv;
    }

    if (pollset->cnelts) {
        pollset->cnelts = 0;
    }
#endif /* APR_SOCKET_BUFFER */

    if (rv == 0) {
        if (timeout > 0) {
            timeout /= 1000;
        }
        rv = poll(pollset->pollset, pollset->nelts, timeout);
        (*num) = rv;
        if (rv < 0) {
            return apr_get_netos_error();
        }
        if (rv == 0) {
            return APR_TIMEUP;
        }
    }

    j = 0;
    for (i = 0; i < pollset->nelts; i++) {
        if (pollset->pollset[i].revents != 0) {
            pollset->result_set[j] = pollset->query_set[i];
            pollset->result_set[j].rtnevents =
                get_revent(pollset->pollset[i].revents);
            j++;
        }
    }
    if (descriptors)
        *descriptors = pollset->result_set;
    return APR_SUCCESS;
}

#endif /* POLLSET_USES_POLL */
