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

#include "apr_arch_networkio.h"
#include "apr_support.h"

#if APR_HAS_SENDFILE
/* This file is needed to allow us access to the apr_file_t internals. */
#include "apr_arch_file_io.h"
#endif /* APR_HAS_SENDFILE */

/* osreldate.h is only needed on FreeBSD for sendfile detection */
#if defined(__FreeBSD__)
#include <osreldate.h>
#endif

apr_status_t apr_socket_send(apr_socket_t *sock, const char *buf, 
                             apr_size_t *len)
{
    apr_ssize_t rv;
    
    if (sock->options & APR_INCOMPLETE_WRITE) {
        sock->options &= ~APR_INCOMPLETE_WRITE;
        goto do_select;
    }

    do {
        rv = write(sock->socketdes, buf, (*len));
    } while (rv == -1 && errno == EINTR);

    while (rv == -1 && (errno == EAGAIN || errno == EWOULDBLOCK) 
                    && (sock->timeout > 0)) {
        apr_status_t arv;
do_select:
        arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
                rv = write(sock->socketdes, buf, (*len));
            } while (rv == -1 && errno == EINTR);
        }
    }
    if (rv == -1) {
        *len = 0;
        return errno;
    }
    if ((sock->timeout > 0) && (rv < *len)) {
        sock->options |= APR_INCOMPLETE_WRITE;
    }
    (*len) = rv;
    return APR_SUCCESS;
}

#ifdef APR_SOCKET_BUFFER
static apr_ssize_t do_read(apr_socket_t *sock, char *buf, apr_size_t len)
{
    apr_ssize_t rv;
    apr_ssize_t bytes_read;

    if (len == 0)
        return 0;

    if (sock->rbuf_size)
    {
        if (sock->rbuf_used == 0)
        {
            bytes_read = read (sock->socketdes, sock->rbuf, sock->rbuf_size);
            if (bytes_read <= 0)
                return bytes_read;

            sock->rbuf_used = bytes_read;
            sock->rbuf_pos  = sock->rbuf;
        }
        if (len <= sock->rbuf_used) {
            bytes_read = len;
        } else {
            bytes_read = sock->rbuf_used;
        }
        memcpy (buf, sock->rbuf_pos, bytes_read);
        sock->rbuf_pos += bytes_read;
        sock->rbuf_used -= bytes_read;
        rv = bytes_read;
    } else {
        rv = read (sock->socketdes, buf, len);
    }
    return rv;
}
#endif /* APR_SOCKET_BUFFER */

apr_status_t apr_socket_recv(apr_socket_t *sock, char *buf, apr_size_t *len)
{
    apr_ssize_t rv;
    apr_status_t arv;

    if (sock->options & APR_INCOMPLETE_READ) {
        sock->options &= ~APR_INCOMPLETE_READ;
        goto do_select;
    }

    do {
#ifdef APR_SOCKET_BUFFER
        rv = do_read(sock, buf, (*len));
#else
        rv = read(sock->socketdes, buf, (*len));
#endif /* APR_SOCKET_BUFFER */
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK)
                      && (sock->timeout > 0)) {
do_select:
        arv = apr_wait_for_io_or_timeout(NULL, sock, 1);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
#ifdef APR_SOCKET_BUFFER
                rv = do_read(sock, buf, (*len));
#else
                rv = read(sock->socketdes, buf, (*len));
#endif /* APR_SOCKET_BUFFER */
            } while (rv == -1 && errno == EINTR);
        }
    }
    if (rv == -1) {
        (*len) = 0;
        return errno;
    }
    if ((sock->timeout > 0) && (rv < *len)) {
        sock->options |= APR_INCOMPLETE_READ;
    }
    (*len) = rv;
    if (rv == 0) {
        return APR_EOF;
    }
    return APR_SUCCESS;
}

apr_status_t apr_socket_sendto(apr_socket_t *sock, apr_sockaddr_t *where,
                               apr_int32_t flags, const char *buf,
                               apr_size_t *len)
{
    apr_ssize_t rv;

    do {
        rv = sendto(sock->socketdes, buf, (*len), flags, 
                    (const struct sockaddr*)&where->sa, 
                    where->salen);
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK)
                      && (sock->timeout > 0)) {
        apr_status_t arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        } else {
            do {
                rv = sendto(sock->socketdes, buf, (*len), flags,
                            (const struct sockaddr*)&where->sa,
                            where->salen);
            } while (rv == -1 && errno == EINTR);
        }
    }
    if (rv == -1) {
        *len = 0;
        return errno;
    }
    *len = rv;
    return APR_SUCCESS;
}

apr_status_t apr_socket_recvfrom(apr_sockaddr_t *from, apr_socket_t *sock,
                                 apr_int32_t flags, char *buf, 
                                 apr_size_t *len)
{
    apr_ssize_t rv;

    do {
        rv = recvfrom(sock->socketdes, buf, (*len), flags, 
                      (struct sockaddr*)&from->sa, &from->salen);
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK)
                      && (sock->timeout > 0)) {
        apr_status_t arv = apr_wait_for_io_or_timeout(NULL, sock, 1);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        } else {
            do {
                rv = recvfrom(sock->socketdes, buf, (*len), flags,
                              (struct sockaddr*)&from->sa, &from->salen);
            } while (rv == -1 && errno == EINTR);
        }
    }
    if (rv == -1) {
        (*len) = 0;
        return errno;
    }

    (*len) = rv;
    if (rv == 0 && sock->type == SOCK_STREAM) {
        return APR_EOF;
    }

    return APR_SUCCESS;
}

#ifdef HAVE_WRITEV
apr_status_t apr_socket_sendv(apr_socket_t * sock, const struct iovec *vec,
                              apr_int32_t nvec, apr_size_t *len)
{
    apr_ssize_t rv;
    apr_size_t requested_len = 0;
    apr_int32_t i;

    for (i = 0; i < nvec; i++) {
        requested_len += vec[i].iov_len;
    }

    if (sock->options & APR_INCOMPLETE_WRITE) {
        sock->options &= ~APR_INCOMPLETE_WRITE;
        goto do_select;
    }

    do {
        rv = writev(sock->socketdes, vec, nvec);
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK) 
                      && (sock->timeout > 0)) {
        apr_status_t arv;
do_select:
        arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
                rv = writev(sock->socketdes, vec, nvec);
            } while (rv == -1 && errno == EINTR);
        }
    }
    if (rv == -1) {
        *len = 0;
        return errno;
    }
    if ((sock->timeout > 0) && (rv < requested_len)) {
        sock->options |= APR_INCOMPLETE_WRITE;
    }
    (*len) = rv;
    return APR_SUCCESS;
}
#endif

#if APR_HAS_SENDFILE

/* TODO: Verify that all platforms handle the fd the same way,
 * i.e. that they don't move the file pointer.
 */
/* TODO: what should flags be?  int_32? */

/* Define a structure to pass in when we have a NULL header value */
static apr_hdtr_t no_hdtr;

#if defined(__linux__) && defined(HAVE_WRITEV)

apr_status_t apr_socket_sendfile(apr_socket_t *sock, apr_file_t *file,
                                 apr_hdtr_t *hdtr, apr_off_t *offset,
                                 apr_size_t *len, apr_int32_t flags)
{
    int rv, nbytes = 0, total_hdrbytes, i;
    apr_status_t arv;

#if APR_HAS_LARGE_FILES && defined(HAVE_SENDFILE64)
    apr_off_t off = *offset;
#define sendfile sendfile64

#elif APR_HAS_LARGE_FILES && SIZEOF_OFF_T == 4
    /* 64-bit apr_off_t but no sendfile64(): fail if trying to send
     * past the 2Gb limit. */
    off_t off;
    
    if ((apr_int64_t)*offset + *len > INT_MAX) {
        return EINVAL;
    }
    
    off = *offset;

#else
    off_t off = *offset;
#endif

    if (!hdtr) {
        hdtr = &no_hdtr;
    }

    /* Ignore flags for now. */
    flags = 0;

    if (hdtr->numheaders > 0) {
        apr_size_t hdrbytes;

        /* cork before writing headers */
        rv = apr_socket_opt_set(sock, APR_TCP_NOPUSH, 1);
        if (rv != APR_SUCCESS) {
            return rv;
        }

        /* Now write the headers */
        arv = apr_socket_sendv(sock, hdtr->headers, hdtr->numheaders,
                               &hdrbytes);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return errno;
        }
        nbytes += hdrbytes;

        /* If this was a partial write and we aren't doing timeouts, 
         * return now with the partial byte count; this is a non-blocking 
         * socket.
         */
        total_hdrbytes = 0;
        for (i = 0; i < hdtr->numheaders; i++) {
            total_hdrbytes += hdtr->headers[i].iov_len;
        }
        if (hdrbytes < total_hdrbytes) {
            *len = hdrbytes;
            return apr_socket_opt_set(sock, APR_TCP_NOPUSH, 0);
        }
    }

    if (sock->options & APR_INCOMPLETE_WRITE) {
        sock->options &= ~APR_INCOMPLETE_WRITE;
        goto do_select;
    }

    do {
        rv = sendfile(sock->socketdes,    /* socket */
                      file->filedes, /* open file descriptor of the file to be sent */
                      &off,    /* where in the file to start */
                      *len);   /* number of bytes to send */
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK) 
                      && (sock->timeout > 0)) {
do_select:
        arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
                rv = sendfile(sock->socketdes,    /* socket */
                              file->filedes, /* open file descriptor of the file to be sent */
                              &off,    /* where in the file to start */
                              *len);    /* number of bytes to send */
            } while (rv == -1 && errno == EINTR);
        }
    }

    if (rv == -1) {
        *len = nbytes;
        rv = errno;
        apr_socket_opt_set(sock, APR_TCP_NOPUSH, 0);
        return rv;
    }

    nbytes += rv;

    if (rv < *len) {
        *len = nbytes;
        arv = apr_socket_opt_set(sock, APR_TCP_NOPUSH, 0);
        if (rv > 0) {
                
            /* If this was a partial write, return now with the 
             * partial byte count;  this is a non-blocking socket.
             */

            if (sock->timeout > 0) {
                sock->options |= APR_INCOMPLETE_WRITE;
            }
            return arv;
        }
        else {
            /* If the file got smaller mid-request, eventually the offset
             * becomes equal to the new file size and the kernel returns 0.  
             * Make this an error so the caller knows to log something and
             * exit.
             */
            return APR_EOF;
        }
    }

    /* Now write the footers */
    if (hdtr->numtrailers > 0) {
        apr_size_t trbytes;
        arv = apr_socket_sendv(sock, hdtr->trailers, hdtr->numtrailers, 
                               &trbytes);
        nbytes += trbytes;
        if (arv != APR_SUCCESS) {
            *len = nbytes;
            rv = errno;
            apr_socket_opt_set(sock, APR_TCP_NOPUSH, 0);
            return rv;
        }
    }

    apr_socket_opt_set(sock, APR_TCP_NOPUSH, 0);
    
    (*len) = nbytes;
    return rv < 0 ? errno : APR_SUCCESS;
}

#elif defined(__FreeBSD__) || defined(__DragonFly__)

/* Release 3.1 or greater */
apr_status_t apr_socket_sendfile(apr_socket_t * sock, apr_file_t * file,
                                 apr_hdtr_t * hdtr, apr_off_t * offset,
                                 apr_size_t * len, apr_int32_t flags)
{
    off_t nbytes = 0;
    int rv, i;
    struct sf_hdtr headerstruct;
    apr_size_t bytes_to_send = *len;

    /* Ignore flags for now. */
    flags = 0;

    if (!hdtr) {
        hdtr = &no_hdtr;
    }

#if defined(__FreeBSD_version) && __FreeBSD_version < 460001
    else if (hdtr->numheaders) {

        /* On early versions of FreeBSD sendfile, the number of bytes to send 
         * must include the length of the headers.  Don't look at the man page 
         * for this :(  Instead, look at the the logic in 
         * src/sys/kern/uipc_syscalls::sendfile().
         *
         * This was fixed in the middle of 4.6-STABLE
         */
        for (i = 0; i < hdtr->numheaders; i++) {
            bytes_to_send += hdtr->headers[i].iov_len;
        }
    }
#endif

    headerstruct.headers = hdtr->headers;
    headerstruct.hdr_cnt = hdtr->numheaders;
    headerstruct.trailers = hdtr->trailers;
    headerstruct.trl_cnt = hdtr->numtrailers;

    /* FreeBSD can send the headers/footers as part of the system call */
    do {
        if (sock->options & APR_INCOMPLETE_WRITE) {
            apr_status_t arv;
            sock->options &= ~APR_INCOMPLETE_WRITE;
            arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
            if (arv != APR_SUCCESS) {
                *len = 0;
                return arv;
            }
        }
        if (bytes_to_send) {
            /* We won't dare call sendfile() if we don't have
             * header or file bytes to send because bytes_to_send == 0
             * means send the whole file.
             */
            rv = sendfile(file->filedes, /* file to be sent */
                          sock->socketdes, /* socket */
                          *offset,       /* where in the file to start */
                          bytes_to_send, /* number of bytes to send */
                          &headerstruct, /* Headers/footers */
                          &nbytes,       /* number of bytes written */
                          flags);        /* undefined, set to 0 */

            if (rv == -1) {
                if (errno == EAGAIN) {
                    if (sock->timeout > 0) {
                        sock->options |= APR_INCOMPLETE_WRITE;
                    }
                    /* FreeBSD's sendfile can return -1/EAGAIN even if it
                     * sent bytes.  Sanitize the result so we get normal EAGAIN
                     * semantics w.r.t. bytes sent.
                     */
                    if (nbytes) {
                        /* normal exit for a big file & non-blocking io */
                        (*len) = nbytes;
                        return APR_SUCCESS;
                    }
                }
            }
            else {       /* rv == 0 (or the kernel is broken) */
                if (nbytes == 0) {
                    /* Most likely the file got smaller after the stat.
                     * Return an error so the caller can do the Right Thing.
                     */
                    (*len) = nbytes;
                    return APR_EOF;
                }
            }
        }    
        else {
            /* just trailer bytes... use writev()
             */
            rv = writev(sock->socketdes,
                        hdtr->trailers,
                        hdtr->numtrailers);
            if (rv > 0) {
                nbytes = rv;
                rv = 0;
            }
            else {
                nbytes = 0;
            }
        }
        if ((rv == -1) && (errno == EAGAIN) 
                       && (sock->timeout > 0)) {
            apr_status_t arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
            if (arv != APR_SUCCESS) {
                *len = 0;
                return arv;
            }
        }
    } while (rv == -1 && (errno == EINTR || errno == EAGAIN));

    (*len) = nbytes;
    if (rv == -1) {
        return errno;
    }
    return APR_SUCCESS;
}

#elif defined(__hpux) || defined(__hpux__)

/* HP cc in ANSI mode defines __hpux; gcc defines __hpux__ */

/* HP-UX Version 10.30 or greater
 * (no worries, because we only get here if autoconfiguration found sendfile)
 */

/* ssize_t sendfile(int s, int fd, off_t offset, size_t nbytes,
 *                  const struct iovec *hdtrl, int flags);
 *
 * nbytes is the number of bytes to send just from the file; as with FreeBSD, 
 * if nbytes == 0, the rest of the file (from offset) is sent
 */

apr_status_t apr_socket_sendfile(apr_socket_t *sock, apr_file_t *file,
                                 apr_hdtr_t *hdtr, apr_off_t *offset,
                                 apr_size_t *len, apr_int32_t flags)
{
    int i;
    apr_ssize_t rc;
    apr_size_t nbytes = *len, headerlen, trailerlen;
    struct iovec hdtrarray[2];
    char *headerbuf, *trailerbuf;

#if APR_HAS_LARGE_FILES && defined(HAVE_SENDFILE64)
    /* later HP-UXes have a sendfile64() */
#define sendfile sendfile64
    apr_off_t off = *offset;

#elif APR_HAS_LARGE_FILES && SIZEOF_OFF_T == 4
    /* HP-UX 11.00 doesn't have a sendfile64(): fail if trying to send
     * past the 2Gb limit */
    off_t off;

    if ((apr_int64_t)*offset + *len > INT_MAX) {
        return EINVAL;
    }
    off = *offset;
#else
    apr_off_t off = *offset;
#endif

    if (!hdtr) {
        hdtr = &no_hdtr;
    }

    /* Ignore flags for now. */
    flags = 0;

    /* HP-UX can only send one header iovec and one footer iovec; try to
     * only allocate storage to combine input iovecs when we really have to
     */

    switch(hdtr->numheaders) {
    case 0:
        hdtrarray[0].iov_base = NULL;
        hdtrarray[0].iov_len = 0;
        break;
    case 1:
        hdtrarray[0] = hdtr->headers[0];
        break;
    default:
        headerlen = 0;
        for (i = 0; i < hdtr->numheaders; i++) {
            headerlen += hdtr->headers[i].iov_len;
        }  

        /* XXX:  BUHHH? wow, what a memory leak! */
        headerbuf = hdtrarray[0].iov_base = apr_palloc(sock->pool, headerlen);
        hdtrarray[0].iov_len = headerlen;

        for (i = 0; i < hdtr->numheaders; i++) {
            memcpy(headerbuf, hdtr->headers[i].iov_base,
                   hdtr->headers[i].iov_len);
            headerbuf += hdtr->headers[i].iov_len;
        }
    }

    switch(hdtr->numtrailers) {
    case 0:
        hdtrarray[1].iov_base = NULL;
        hdtrarray[1].iov_len = 0;
        break;
    case 1:
        hdtrarray[1] = hdtr->trailers[0];
        break;
    default:
        trailerlen = 0;
        for (i = 0; i < hdtr->numtrailers; i++) {
            trailerlen += hdtr->trailers[i].iov_len;
        }

        /* XXX:  BUHHH? wow, what a memory leak! */
        trailerbuf = hdtrarray[1].iov_base = apr_palloc(sock->pool, trailerlen);
        hdtrarray[1].iov_len = trailerlen;

        for (i = 0; i < hdtr->numtrailers; i++) {
            memcpy(trailerbuf, hdtr->trailers[i].iov_base,
                   hdtr->trailers[i].iov_len);
            trailerbuf += hdtr->trailers[i].iov_len;
        }
    }

    do {
        if (nbytes) {       /* any bytes to send from the file? */
            rc = sendfile(sock->socketdes,      /* socket  */
                          file->filedes,        /* file descriptor to send */
                          off,                  /* where in the file to start */
                          nbytes,               /* number of bytes to send from file */
                          hdtrarray,            /* Headers/footers */
                          flags);               /* undefined, set to 0 */
        }
        else {              /* we can't call sendfile() with no bytes to send from the file */
            rc = writev(sock->socketdes, hdtrarray, 2);
        }
    } while (rc == -1 && errno == EINTR);

    while ((rc == -1) && (errno == EAGAIN || errno == EWOULDBLOCK) 
                      && (sock->timeout > 0)) {
        apr_status_t arv = apr_wait_for_io_or_timeout(NULL, sock, 0);

        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
                if (nbytes) {
                    rc = sendfile(sock->socketdes,    /* socket  */
                                  file->filedes,      /* file descriptor to send */
                                  off,                /* where in the file to start */
                                  nbytes,             /* number of bytes to send from file */
                                  hdtrarray,          /* Headers/footers */
                                  flags);             /* undefined, set to 0 */
                }
                else {      /* we can't call sendfile() with no bytes to send from the file */
                    rc = writev(sock->socketdes, hdtrarray, 2);
                }
            } while (rc == -1 && errno == EINTR);
        }
    }

    if (rc == -1) {
        *len = 0;
        return errno;
    }

    /* Set len to the number of bytes written */
    *len = rc;
    return APR_SUCCESS;
}
#elif defined(_AIX) || defined(__MVS__)
/* AIX and OS/390 have the same send_file() interface.
 *
 * subtle differences:
 *   AIX doesn't update the file ptr but OS/390 does
 *
 * availability (correctly determined by autoconf):
 *
 * AIX -  version 4.3.2 with APAR IX85388, or version 4.3.3 and above
 * OS/390 - V2R7 and above
 */
apr_status_t apr_socket_sendfile(apr_socket_t * sock, apr_file_t * file,
                                 apr_hdtr_t * hdtr, apr_off_t * offset,
                                 apr_size_t * len, apr_int32_t flags)
{
    int i, ptr, rv = 0;
    void * hbuf=NULL, * tbuf=NULL;
    apr_status_t arv;
    struct sf_parms parms;

    if (!hdtr) {
        hdtr = &no_hdtr;
    }

    /* Ignore flags for now. */
    flags = 0;

    /* word to the wise: by default, AIX stores files sent by send_file()
     * in the network buffer cache...  there are supposedly scenarios
     * where the most recent copy of the file won't be sent, but I can't
     * recreate the potential problem, perhaps because of the way we
     * use send_file()...  if you suspect such a problem, try turning
     * on the SF_SYNC_CACHE flag
     */

    /* AIX can also send the headers/footers as part of the system call */
    parms.header_length = 0;
    if (hdtr && hdtr->numheaders) {
        if (hdtr->numheaders == 1) {
            parms.header_data = hdtr->headers[0].iov_base;
            parms.header_length = hdtr->headers[0].iov_len;
        }
        else {
            for (i = 0; i < hdtr->numheaders; i++) {
                parms.header_length += hdtr->headers[i].iov_len;
            }
#if 0
            /* Keepalives make apr_palloc a bad idea */
            hbuf = malloc(parms.header_length);
#else
            /* but headers are small, so maybe we can hold on to the
             * memory for the life of the socket...
             */
            hbuf = apr_palloc(sock->pool, parms.header_length);
#endif
            ptr = 0;
            for (i = 0; i < hdtr->numheaders; i++) {
                memcpy((char *)hbuf + ptr, hdtr->headers[i].iov_base,
                       hdtr->headers[i].iov_len);
                ptr += hdtr->headers[i].iov_len;
            }
            parms.header_data = hbuf;
        }
    }
    else parms.header_data = NULL;
    parms.trailer_length = 0;
    if (hdtr && hdtr->numtrailers) {
        if (hdtr->numtrailers == 1) {
            parms.trailer_data = hdtr->trailers[0].iov_base;
            parms.trailer_length = hdtr->trailers[0].iov_len;
        }
        else {
            for (i = 0; i < hdtr->numtrailers; i++) {
                parms.trailer_length += hdtr->trailers[i].iov_len;
            }
#if 0
            /* Keepalives make apr_palloc a bad idea */
            tbuf = malloc(parms.trailer_length);
#else
            tbuf = apr_palloc(sock->pool, parms.trailer_length);
#endif
            ptr = 0;
            for (i = 0; i < hdtr->numtrailers; i++) {
                memcpy((char *)tbuf + ptr, hdtr->trailers[i].iov_base,
                       hdtr->trailers[i].iov_len);
                ptr += hdtr->trailers[i].iov_len;
            }
            parms.trailer_data = tbuf;
        }
    }
    else {
        parms.trailer_data = NULL;
    }

    /* Whew! Headers and trailers set up. Now for the file data */

    parms.file_descriptor = file->filedes;
    parms.file_offset = *offset;
    parms.file_bytes = *len;

    /* O.K. All set up now. Let's go to town */

    if (sock->options & APR_INCOMPLETE_WRITE) {
        sock->options &= ~APR_INCOMPLETE_WRITE;
        goto do_select;
    }

    do {
        rv = send_file(&(sock->socketdes), /* socket */
                       &(parms),           /* all data */
                       flags);             /* flags */
    } while (rv == -1 && errno == EINTR);

    while ((rv == -1) && (errno == EAGAIN || errno == EWOULDBLOCK) 
                      && (sock->timeout > 0)) {
do_select:
        arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
        else {
            do {
                rv = send_file(&(sock->socketdes), /* socket */
                               &(parms),           /* all data */
                               flags);             /* flags */
            } while (rv == -1 && errno == EINTR);
        }
    }

    (*len) = parms.bytes_sent;

#if 0
    /* Clean up after ourselves */
    if(hbuf) free(hbuf);
    if(tbuf) free(tbuf);
#endif

    if (rv == -1) {
        return errno;
    }

    if ((sock->timeout > 0)
          && (parms.bytes_sent 
                < (parms.file_bytes + parms.header_length + parms.trailer_length))) {
        sock->options |= APR_INCOMPLETE_WRITE;
    }

    return APR_SUCCESS;
}
#elif defined(__osf__) && defined (__alpha)
/* Tru64's sendfile implementation doesn't work, and we need to make sure that
 * we don't use it until it is fixed.  If it is used as it is now, it will
 * hang the machine and the only way to fix it is a reboot.
 */
#elif defined(HAVE_SENDFILEV)
/* Solaris 8's sendfilev() interface 
 *
 * SFV_FD_SELF refers to our memory space.
 *
 * Required Sparc patches (or newer):
 * 111297-01, 108528-09, 109472-06, 109234-03, 108995-02, 111295-01, 109025-03,
 * 108991-13
 * Required x86 patches (or newer):
 * 111298-01, 108529-09, 109473-06, 109235-04, 108996-02, 111296-01, 109026-04,
 * 108992-13
 */

#if APR_HAS_LARGE_FILES && defined(HAVE_SENDFILEV64)
#define sendfilevec_t sendfilevec64_t
#define sendfilev sendfilev64
#endif

apr_status_t apr_socket_sendfile(apr_socket_t *sock, apr_file_t *file,
                                 apr_hdtr_t *hdtr, apr_off_t *offset,
                                 apr_size_t *len, apr_int32_t flags)
{
    apr_status_t rv, arv;
    apr_size_t nbytes;
    sendfilevec_t *sfv;
    int vecs, curvec, i, repeat;
    apr_size_t requested_len = 0;

    if (!hdtr) {
        hdtr = &no_hdtr;
    }

    /* Ignore flags for now. */
    flags = 0;

    /* Calculate how much space we need. */
    vecs = hdtr->numheaders + hdtr->numtrailers + 1;
    sfv = apr_palloc(sock->pool, sizeof(sendfilevec_t) * vecs);

    curvec = 0;

    /* Add the headers */
    for (i = 0; i < hdtr->numheaders; i++, curvec++) {
        sfv[curvec].sfv_fd = SFV_FD_SELF;
        sfv[curvec].sfv_flag = 0;
        sfv[curvec].sfv_off = (apr_off_t)hdtr->headers[i].iov_base;
        sfv[curvec].sfv_len = hdtr->headers[i].iov_len;
        requested_len += sfv[curvec].sfv_len;
    }

    /* If the len is 0, we skip the file. */
    if (*len)
    {
        sfv[curvec].sfv_fd = file->filedes;
        sfv[curvec].sfv_flag = 0;
        sfv[curvec].sfv_off = *offset;
        sfv[curvec].sfv_len = *len; 
        requested_len += sfv[curvec].sfv_len;

        curvec++;
    }
    else {
        vecs--;
    }

    /* Add the footers */
    for (i = 0; i < hdtr->numtrailers; i++, curvec++) {
        sfv[curvec].sfv_fd = SFV_FD_SELF;
        sfv[curvec].sfv_flag = 0;
        sfv[curvec].sfv_off = (apr_off_t)hdtr->trailers[i].iov_base;
        sfv[curvec].sfv_len = hdtr->trailers[i].iov_len;
        requested_len += sfv[curvec].sfv_len;
    }

    /* If the last write couldn't send all the requested data,
     * wait for the socket to become writable before proceeding
     */
    if (sock->options & APR_INCOMPLETE_WRITE) {
        sock->options &= ~APR_INCOMPLETE_WRITE;
        arv = apr_wait_for_io_or_timeout(NULL, sock, 0);
        if (arv != APR_SUCCESS) {
            *len = 0;
            return arv;
        }
    }
 
    /* Actually do the sendfilev
     *
     * Solaris may return -1/EAGAIN even if it sent bytes on a non-block sock.
     *
     * If no bytes were originally sent (nbytes == 0) and we are on a TIMEOUT 
     * socket (which as far as the OS is concerned is a non-blocking socket), 
     * we want to retry after waiting for the other side to read the data (as 
     * determined by poll).  Once it is clear to send, we want to retry
     * sending the sendfilevec_t once more.
     */
    arv = 0;
    do {
        /* Clear out the repeat */
        repeat = 0;

        /* socket, vecs, number of vecs, bytes written */
        rv = sendfilev(sock->socketdes, sfv, vecs, &nbytes);

        if (rv == -1 && errno == EAGAIN) {
            if (nbytes) {
                rv = 0;
            }
            else if (!arv && (sock->timeout > 0)) {
                apr_status_t t = apr_wait_for_io_or_timeout(NULL, sock, 0);

                if (t != APR_SUCCESS) {
                    *len = 0;
                    return t;
                }

                arv = 1; 
                repeat = 1;
            }
        }
    } while ((rv == -1 && errno == EINTR) || repeat);

    if (rv == -1) {
        *len = 0;
        return errno;
    }

    /* Update how much we sent */
    *len = nbytes;
    if ((sock->timeout > 0) && (*len < requested_len)) {
        sock->options |= APR_INCOMPLETE_WRITE;
    }
    return APR_SUCCESS;
}
#else
#error APR has detected sendfile on your system, but nobody has written a
#error version of it for APR yet.  To get past this, either write 
#error apr_socket_sendfile or change APR_HAS_SENDFILE in apr.h to 0.
#endif /* __linux__, __FreeBSD__, __DragonFly__, __HPUX__, _AIX, __MVS__,
	  Tru64/OSF1 */

#endif /* APR_HAS_SENDFILE */
