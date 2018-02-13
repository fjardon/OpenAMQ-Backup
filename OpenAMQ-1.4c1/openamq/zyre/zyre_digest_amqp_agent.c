/*---------------------------------------------------------------------------
    zyre_digest_amqp_agent.c - functions for zyre_digest_amqp_agent.

    Generated from zyre_digest_amqp_agent.smt by smt_gen.gsl using GSL/4.

    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "ipr.h"                        //  For iPR classes
#include "smt.h"                        //  For SMT classes
#include "zyre_digest_amqp_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((zyre_digest_amqp_agent_destroy_t *) thread->method->data)

#define announce_m ((zyre_digest_amqp_agent_announce_t *) thread->method->data)

#define before_m ((zyre_digest_amqp_agent_before_t *) thread->method->data)

#define send_request_m ((zyre_digest_amqp_agent_send_request_t *) thread->method->data)

#define online_m ((zyre_digest_amqp_agent_online_t *) thread->method->data)

#define offline_m ((zyre_digest_amqp_agent_offline_t *) thread->method->data)

#define arrived_m ((zyre_digest_amqp_agent_arrived_t *) thread->method->data)

#define returned_m ((zyre_digest_amqp_agent_returned_t *) thread->method->data)

#define _zyre_backend_unbind_m ((zyre_digest_amqp_agent__zyre_backend_unbind_t *) thread->method->data)

#define _http_access_module_unbind_m ((zyre_digest_amqp_agent__http_access_module_unbind_t *) thread->method->data)

#define open_m ((zyre_digest_amqp_agent_open_t *) thread->method->data)

#define after_m ((zyre_digest_amqp_agent_after_t *) thread->method->data)

#define close_m ((zyre_digest_amqp_agent_close_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    announce_m_event                               = 3,
    before_m_event                                 = 4,
    send_request_m_event                           = 5,
    online_m_event                                 = 6,
    offline_m_event                                = 7,
    arrived_m_event                                = 8,
    returned_m_event                               = 9,
    _zyre_backend_unbind_m_event                   = 10,
    _http_access_module_unbind_m_event             = 11,
    open_m_event                                   = 12,
    after_m_event                                  = 13,
    close_m_event                                  = 14,
};

#define laststate                                  2
#define lastevent                                  14
#define lastplace                                  31

#define zyre_digest_amqp_agent_agent_name          "Zyre-Digest-Amqp-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define announce_m_event_name                      "Announce-M"
#define before_m_event_name                        "Before-M"
#define send_request_m_event_name                  "Send-Request-M"
#define online_m_event_name                        "Online-M"
#define offline_m_event_name                       "Offline-M"
#define arrived_m_event_name                       "Arrived-M"
#define returned_m_event_name                      "Returned-M"
#define _zyre_backend_unbind_m_event_name          "-Zyre-Backend-Unbind-M"
#define _http_access_module_unbind_m_event_name    "-Http-Access-Module-Unbind-M"
#define open_m_event_name                          "Open-M"
#define after_m_event_name                         "After-M"
#define close_m_event_name                         "Close-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define unnamed_4_action_name                      "Unnamed-4"
#define announce_action_name                       "Announce"
#define unnamed_6_action_name                      "Unnamed-6"
#define before_action_name                         "Before"
#define unnamed_8_action_name                      "Unnamed-8"
#define send_request_action_name                   "Send-Request"
#define unnamed_10_action_name                     "Unnamed-10"
#define online_action_name                         "Online"
#define unnamed_12_action_name                     "Unnamed-12"
#define offline_action_name                        "Offline"
#define unnamed_14_action_name                     "Unnamed-14"
#define arrived_action_name                        "Arrived"
#define unnamed_16_action_name                     "Unnamed-16"
#define returned_action_name                       "Returned"
#define unnamed_18_action_name                     "Unnamed-18"
#define _zyre_backend_unbind_action_name           "-Zyre-Backend-Unbind"
#define unnamed_20_action_name                     "Unnamed-20"
#define _http_access_module_unbind_action_name     "-Http-Access-Module-Unbind"
#define unnamed_22_action_name                     "Unnamed-22"
#define open_action_name                           "Open"
#define unnamed_24_action_name                     "Unnamed-24"
#define after_action_name                          "After"
#define unnamed_26_action_name                     "Unnamed-26"
#define close_action_name                          "Close"
#define unnamed_28_action_name                     "Unnamed-28"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
zyre_digest_amqp_agent_destroy_t;

typedef struct
  {
    http_access_module_t *  portal;
    smt_log_t *    log;
  }
zyre_digest_amqp_agent_announce_t;

typedef struct
  {
    http_access_module_t *  portal;
    http_access_context_t *  context;
  }
zyre_digest_amqp_agent_before_t;

typedef struct
  {
    char *         user;
    char *         realm;
  }
zyre_digest_amqp_agent_send_request_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         reply_queue;
  }
zyre_digest_amqp_agent_online_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_digest_amqp_agent_offline_t;

typedef struct
  {
    zyre_backend_t *  portal;
    zyre_peer_method_t *  method;
  }
zyre_digest_amqp_agent_arrived_t;

typedef struct
  {
    zyre_backend_t *  portal;
    zyre_peer_method_t *  method;
  }
zyre_digest_amqp_agent_returned_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_digest_amqp_agent__zyre_backend_unbind_t;

typedef struct
  {
    http_access_module_t *  portal;
  }
zyre_digest_amqp_agent__http_access_module_unbind_t;

typedef struct
  {
    http_access_module_t *  portal;
    http_access_context_t *  context;
  }
zyre_digest_amqp_agent_open_t;

typedef struct
  {
    http_access_module_t *  portal;
    http_access_context_t *  context;
  }
zyre_digest_amqp_agent_after_t;

typedef struct
  {
    http_access_module_t *  portal;
    http_access_context_t *  context;
  }
zyre_digest_amqp_agent_close_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        zyre_digest_amqp_t
            *zyre_digest_amqp;
    
} zyre_digest_amqp_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_announce_cache = NULL;
static icl_cache_t
    *s_before_cache = NULL;
static icl_cache_t
    *s_send_request_cache = NULL;
static icl_cache_t
    *s_online_cache = NULL;
static icl_cache_t
    *s_offline_cache = NULL;
static icl_cache_t
    *s_arrived_cache = NULL;
static icl_cache_t
    *s_returned_cache = NULL;
static icl_cache_t
    *s__zyre_backend_unbind_cache = NULL;
static icl_cache_t
    *s__http_access_module_unbind_cache = NULL;
static icl_cache_t
    *s_open_cache = NULL;
static icl_cache_t
    *s_after_cache = NULL;
static icl_cache_t
    *s_close_cache = NULL;

static const char *thread_name [] = {
    "<NULL>",
    class_thread_name
};

static const char *state_name [] = {
    "<NULL>",
    main_state_name,
    shutting_down_state_name
};

static const char *event_name [] = {
    "<NULL>",
    shutdown_event_name,
    destroy_m_event_name,
    announce_m_event_name,
    before_m_event_name,
    send_request_m_event_name,
    online_m_event_name,
    offline_m_event_name,
    arrived_m_event_name,
    returned_m_event_name,
    _zyre_backend_unbind_m_event_name,
    _http_access_module_unbind_m_event_name,
    open_m_event_name,
    after_m_event_name,
    close_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT)   ||  defined (BASE_TRACE)  || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT)   ||  defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    unnamed_4_action_name,
    announce_action_name,
    unnamed_6_action_name,
    before_action_name,
    unnamed_8_action_name,
    send_request_action_name,
    unnamed_10_action_name,
    online_action_name,
    unnamed_12_action_name,
    offline_action_name,
    unnamed_14_action_name,
    arrived_action_name,
    unnamed_16_action_name,
    returned_action_name,
    unnamed_18_action_name,
    _zyre_backend_unbind_action_name,
    unnamed_20_action_name,
    _http_access_module_unbind_action_name,
    unnamed_22_action_name,
    open_action_name,
    unnamed_24_action_name,
    after_action_name,
    unnamed_26_action_name,
    close_action_name,
    unnamed_28_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_DESTROY))
static icl_stats_t *s_zyre_digest_amqp_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_FREE))
static icl_stats_t *s_zyre_digest_amqp_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_3))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_4))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ANNOUNCE))
static icl_stats_t *s_zyre_digest_amqp_agent_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_6))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_BEFORE))
static icl_stats_t *s_zyre_digest_amqp_agent_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_8))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_SEND_REQUEST))
static icl_stats_t *s_zyre_digest_amqp_agent_send_request_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_10))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ONLINE))
static icl_stats_t *s_zyre_digest_amqp_agent_online_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_12))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_OFFLINE))
static icl_stats_t *s_zyre_digest_amqp_agent_offline_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_14))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_14_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ARRIVED))
static icl_stats_t *s_zyre_digest_amqp_agent_arrived_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_16))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_16_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_RETURNED))
static icl_stats_t *s_zyre_digest_amqp_agent_returned_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_18))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_18_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT__ZYRE_BACKEND_UNBIND))
static icl_stats_t *s_zyre_digest_amqp_agent__zyre_backend_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_20))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_20_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT__HTTP_ACCESS_MODULE_UNBIND))
static icl_stats_t *s_zyre_digest_amqp_agent__http_access_module_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_22))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_22_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_OPEN))
static icl_stats_t *s_zyre_digest_amqp_agent_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_24))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_24_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_AFTER))
static icl_stats_t *s_zyre_digest_amqp_agent_after_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_26))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_26_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_CLOSE))
static icl_stats_t *s_zyre_digest_amqp_agent_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_28))
static icl_stats_t *s_zyre_digest_amqp_agent_unnamed_28_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    zyre_digest_amqp_agent_manager  (smt_thread_t **thread);
static int    zyre_digest_amqp_agent_catcher  (smt_thread_t *thread);
static int    zyre_digest_amqp_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT)     ||  defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_3                (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_announce                 (smt_thread_t *thread);
static int    action_unnamed_6                (smt_thread_t *thread);
static int    action_before                   (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_send_request             (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_online                   (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_offline                  (smt_thread_t *thread);
static int    action_unnamed_14               (smt_thread_t *thread);
static int    action_arrived                  (smt_thread_t *thread);
static int    action_unnamed_16               (smt_thread_t *thread);
static int    action_returned                 (smt_thread_t *thread);
static int    action_unnamed_18               (smt_thread_t *thread);
static int    action__zyre_backend_unbind     (smt_thread_t *thread);
static int    action_unnamed_20               (smt_thread_t *thread);
static int    action__http_access_module_unbind  (smt_thread_t *thread);
static int    action_unnamed_22               (smt_thread_t *thread);
static int    action_open                     (smt_thread_t *thread);
static int    action_unnamed_24               (smt_thread_t *thread);
static int    action_after                    (smt_thread_t *thread);
static int    action_unnamed_26               (smt_thread_t *thread);
static int    action_close                    (smt_thread_t *thread);
static int    action_unnamed_28               (smt_thread_t *thread);
static int
zyre_digest_amqp_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
zyre_digest_amqp_agent_destroy_destructor (void *data);
static int
zyre_digest_amqp_agent_announce_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    smt_log_t *    log);
int
zyre_digest_amqp_agent_announce_destructor (void *data);
static int
zyre_digest_amqp_agent_before_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context);
int
zyre_digest_amqp_agent_before_destructor (void *data);
static int
zyre_digest_amqp_agent_send_request_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         user,
    char *         realm);
int
zyre_digest_amqp_agent_send_request_destructor (void *data);
static int
zyre_digest_amqp_agent_online_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         reply_queue);
int
zyre_digest_amqp_agent_online_destructor (void *data);
static int
zyre_digest_amqp_agent_offline_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_digest_amqp_agent_offline_destructor (void *data);
static int
zyre_digest_amqp_agent_arrived_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method);
int
zyre_digest_amqp_agent_arrived_destructor (void *data);
static int
zyre_digest_amqp_agent_returned_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method);
int
zyre_digest_amqp_agent_returned_destructor (void *data);
static int
zyre_digest_amqp_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_digest_amqp_agent__zyre_backend_unbind_destructor (void *data);
static int
zyre_digest_amqp_agent__http_access_module_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal);
int
zyre_digest_amqp_agent__http_access_module_unbind_destructor (void *data);
static int
zyre_digest_amqp_agent_open_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context);
int
zyre_digest_amqp_agent_open_destructor (void *data);
static int
zyre_digest_amqp_agent_after_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context);
int
zyre_digest_amqp_agent_after_destructor (void *data);
static int
zyre_digest_amqp_agent_close_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context);
int
zyre_digest_amqp_agent_close_destructor (void *data);
//  Function definitions                                                       

static int
zyre_digest_amqp_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_destroy_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((zyre_digest_amqp_agent_destroy_t *) data)-> file;
    line = ((zyre_digest_amqp_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_announce_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    smt_log_t *    log)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_announce_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_announce_cache);
    _message->portal                    = portal;
    _message->log                       = log;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_announce_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_announce_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;
smt_log_t * log;

    portal = ((zyre_digest_amqp_agent_announce_t *) data)-> portal;
    log = ((zyre_digest_amqp_agent_announce_t *) data)-> log;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_before_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_before_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_before_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_before_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_before_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;
http_access_context_t * context;

    portal = ((zyre_digest_amqp_agent_before_t *) data)-> portal;
    context = ((zyre_digest_amqp_agent_before_t *) data)-> context;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_send_request_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         user,
    char *         realm)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_send_request_t
        *_message;
        
    //  Possess code for send request
    

    user = icl_mem_strdup (user);
    realm = icl_mem_strdup (realm);
    
    

    _message = icl_mem_cache_alloc (s_send_request_cache);
    _message->user                      = user;
    _message->realm                     = realm;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_send_request_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_send_request_destructor (void *data)
{
    int
        rc = 0;
char *  user;
char *  realm;

    user = ((zyre_digest_amqp_agent_send_request_t *) data)-> user;
    realm = ((zyre_digest_amqp_agent_send_request_t *) data)-> realm;



    icl_mem_strfree (&user);
    icl_mem_strfree (&realm);
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_online_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         reply_queue)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_online_t
        *_message;
        
    //  Possess code for online
    

    
        reply_queue = icl_mem_strdup (reply_queue);
      
    
    

    _message = icl_mem_cache_alloc (s_online_cache);
    _message->portal                    = portal;
    _message->reply_queue               = reply_queue;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_online_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_online_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * reply_queue;

    portal = ((zyre_digest_amqp_agent_online_t *) data)-> portal;
    reply_queue = ((zyre_digest_amqp_agent_online_t *) data)-> reply_queue;



    
        icl_mem_strfree (&reply_queue);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_offline_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_offline_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_offline_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_offline_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_offline_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_digest_amqp_agent_offline_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_arrived_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_arrived_t
        *_message;
        
    //  Possess code for arrived
    

    
        method = zyre_peer_method_link (method);
      
    
    

    _message = icl_mem_cache_alloc (s_arrived_cache);
    _message->portal                    = portal;
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_arrived_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_arrived_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
zyre_peer_method_t * method;

    portal = ((zyre_digest_amqp_agent_arrived_t *) data)-> portal;
    method = ((zyre_digest_amqp_agent_arrived_t *) data)-> method;



    
        zyre_peer_method_unlink (&method);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_returned_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_returned_t
        *_message;
        
    //  Possess code for returned
    

    
        method = zyre_peer_method_link (method);
      
    
    

    _message = icl_mem_cache_alloc (s_returned_cache);
    _message->portal                    = portal;
    _message->method                    = method;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_returned_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_returned_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
zyre_peer_method_t * method;

    portal = ((zyre_digest_amqp_agent_returned_t *) data)-> portal;
    method = ((zyre_digest_amqp_agent_returned_t *) data)-> method;



    
        zyre_peer_method_unlink (&method);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_digest_amqp_agent__zyre_backend_unbind_t
        *_message;
        

    _message = icl_mem_cache_alloc (s__zyre_backend_unbind_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent__zyre_backend_unbind_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent__zyre_backend_unbind_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_digest_amqp_agent__zyre_backend_unbind_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent__http_access_module_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal)
{
    int
        rc = 0;
    zyre_digest_amqp_agent__http_access_module_unbind_t
        *_message;
        

    _message = icl_mem_cache_alloc (s__http_access_module_unbind_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent__http_access_module_unbind_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent__http_access_module_unbind_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;

    portal = ((zyre_digest_amqp_agent__http_access_module_unbind_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_open_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_open_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_open_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_open_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_open_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;
http_access_context_t * context;

    portal = ((zyre_digest_amqp_agent_open_t *) data)-> portal;
    context = ((zyre_digest_amqp_agent_open_t *) data)-> context;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_after_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_after_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_after_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_after_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_after_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;
http_access_context_t * context;

    portal = ((zyre_digest_amqp_agent_after_t *) data)-> portal;
    context = ((zyre_digest_amqp_agent_after_t *) data)-> context;


    icl_mem_free (data);
    return rc;
}


static int
zyre_digest_amqp_agent_close_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_access_module_t *  portal,
    http_access_context_t *  context)
{
    int
        rc = 0;
    zyre_digest_amqp_agent_close_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_close_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_digest_amqp_agent_close_destructor);
    
    return rc;
}

int
zyre_digest_amqp_agent_close_destructor (void *data)
{
    int
        rc = 0;
http_access_module_t * portal;
http_access_context_t * context;

    portal = ((zyre_digest_amqp_agent_close_t *) data)-> portal;
    context = ((zyre_digest_amqp_agent_close_t *) data)-> context;


    icl_mem_free (data);
    return rc;
}


int
zyre_digest_amqp_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_announce (
    smt_thread_t * thread,
    http_access_module_t * portal,
    smt_log_t *           log)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_announce_send (
                thread->reply_queue, announce_m_event,
                portal,
                log);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_before (
    smt_thread_t * thread,
    http_access_module_t * portal,
    http_access_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_before_send (
                thread->reply_queue, before_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_send_request (
    smt_thread_t * thread,
    char *                user,
    char *                realm)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_send_request_send (
                thread->reply_queue, send_request_m_event,
                user,
                realm);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_online (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                reply_queue)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_online_send (
                thread->reply_queue, online_m_event,
                portal,
                reply_queue);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_offline (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_offline_send (
                thread->reply_queue, offline_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_arrived (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_arrived_send (
                thread->reply_queue, arrived_m_event,
                portal,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_returned (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_returned_send (
                thread->reply_queue, returned_m_event,
                portal,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent__zyre_backend_unbind (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent__zyre_backend_unbind_send (
                thread->reply_queue, _zyre_backend_unbind_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent__http_access_module_unbind (
    smt_thread_t * thread,
    http_access_module_t * portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent__http_access_module_unbind_send (
                thread->reply_queue, _http_access_module_unbind_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_open (
    smt_thread_t * thread,
    http_access_module_t * portal,
    http_access_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_open_send (
                thread->reply_queue, open_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_after (
    smt_thread_t * thread,
    http_access_module_t * portal,
    http_access_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_after_send (
                thread->reply_queue, after_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_digest_amqp_agent_close (
    smt_thread_t * thread,
    http_access_module_t * portal,
    http_access_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_digest_amqp_agent_manager);
        rc = zyre_digest_amqp_agent_close_send (
                thread->reply_queue, close_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

void
zyre_digest_amqp_agent_term (void)
{

}

int 
zyre_digest_amqp_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_destroy_t));
    s_announce_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_announce_t));
    s_before_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_before_t));
    s_send_request_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_send_request_t));
    s_online_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_online_t));
    s_offline_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_offline_t));
    s_arrived_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_arrived_t));
    s_returned_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_returned_t));
    s__zyre_backend_unbind_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent__zyre_backend_unbind_t));
    s__http_access_module_unbind_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent__http_access_module_unbind_t));
    s_open_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_open_t));
    s_after_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_after_t));
    s_close_cache = icl_cache_get (sizeof (zyre_digest_amqp_agent_close_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, zyre_digest_amqp_agent_term);
    
    return rc;
}

void
zyre_digest_amqp_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
zyre_digest_amqp_agent_class_thread_new (
    zyre_digest_amqp_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (zyre_digest_amqp_agent_manager,
                             zyre_digest_amqp_agent_catcher,
                             zyre_digest_amqp_agent_class_destroy);
                             

#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "zyre_digest_amqp_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (zyre_digest_amqp_agent_class_context_t));
        ((zyre_digest_amqp_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)

        tcb->zyre_digest_amqp = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
zyre_digest_amqp_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == zyre_digest_amqp_agent_manager);
                                                 //  Ensure correct manager    

    //  First deal with shutdown request.  These are asynchronous.             
    if (thread->shutdown_request) {
        //  Cancel any outstanding requests
        smt_thread_purge (thread);
        
        thread->shutdown_request = FALSE;
        if (! thread->shutting_down) {
            thread->shutting_down     = TRUE;
            thread->signal_raised     = FALSE;
            thread->_exception_raised = FALSE;
            thread->_next_event       = shutdown_event;
            thread->module            = 0;
        }
    }
    
    //  Convert signal to exception
    if (thread->signal_raised) {
        //  Cancel any outstanding requests
        smt_thread_purge (thread);
        
        thread->signal_raised = FALSE;
        thread->_exception_raised = TRUE;
        thread->_exception_event  = thread->signal_event;
    }

    //  Return straight away if there are pending operations.  This can happen
    //  if a thread gets woken at just the wrong moment.
    if (thread->monitor
    ||  thread->pending_count)
        return SMT_SLEEPING;

    //  Collect method before testing for exception because method may
    //  provoke an exception.
    if ((!thread->_exception_raised)
    &&    thread->module == SMT_TERM_MODULE
    &&    thread->_next_event == SMT_NULL_EVENT
    &&    smt_thread_method_accept (thread) == SMT_EMPTY)
        return SMT_SLEEPING;
        
    //  Finally trap exception and convert to a normal event.                  
    if (thread->_exception_raised) {
        thread->_exception_raised = FALSE;
        thread->_next_event       = thread->_exception_event;
        thread->_exception_event  = SMT_NULL_EVENT;
        thread->module            = 0;
    }

    if (thread->module == SMT_TERM_MODULE)
        switch (thread->place) {
            case 4:
            case 18:
            case 31:
                thread->place = SMT_TERM_PLACE;
                break;
            case 10:
            case 14:
            case 15:
            case 16:
            case 8:
            case 9:
            case 7:
            case 11:
            case 5:
            case 6:
            case 13:
            case 12:
                thread->place = 2;
                break;
            case 30:
            case 28:
            case 29:
            case 26:
            case 24:
            case 25:
            case 3:
            case 27:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
                thread->place = 17;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)

#undef  tcb
}
            }
            thread->place = 2;
            if (thread->_next_event == SMT_NULL_EVENT
            &&  smt_thread_method_accept (thread) == SMT_EMPTY) {
                thread->module = SMT_TERM_MODULE;
                return SMT_SLEEPING;
            }
        }
        else
        if (thread->place < 17)                 //  Main state
            thread->place = 2;
        else
            thread->place = 17;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case announce_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case before_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case send_request_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case online_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case offline_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case arrived_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case returned_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case _http_access_module_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case open_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                case after_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 15; break;
                case close_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 16; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 17:                        //  shutting down state                 
{
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 18; break;
                case announce_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 19; break;
                case before_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 20; break;
                case send_request_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 21; break;
                case online_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 22; break;
                case offline_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 23; break;
                case arrived_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 24; break;
                case returned_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 25; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 26; break;
                case _http_access_module_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 27; break;
                case open_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 28; break;
                case after_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 29; break;
                case close_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 30; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 31; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 31)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 18:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_destroy (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_free (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
#endif
                    rc = action_unnamed_3 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 4:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 4:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_destroy (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
#endif
                    rc = action_free (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 4);
#endif
                    rc = action_unnamed_4 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 4:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 5:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_announce (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
#endif
                    rc = action_unnamed_6 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_before (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_unnamed_8 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 7:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
#endif
                    rc = action_send_request (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 10);
#endif
                    rc = action_unnamed_10 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 8:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_online (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 12);
#endif
                    rc = action_unnamed_12 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 9:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
#endif
                    rc = action_offline (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 14);
#endif
                    rc = action_unnamed_14 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 10:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
#endif
                    rc = action_arrived (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 16);
#endif
                    rc = action_unnamed_16 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 11:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
#endif
                    rc = action_returned (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 18);
#endif
                    rc = action_unnamed_18 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 12:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action__zyre_backend_unbind (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 20);
#endif
                    rc = action_unnamed_20 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 13:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 21);
#endif
                    rc = action__http_access_module_unbind (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 22);
#endif
                    rc = action_unnamed_22 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 14:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 23);
#endif
                    rc = action_open (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 24);
#endif
                    rc = action_unnamed_24 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 15:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 25);
#endif
                    rc = action_after (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 26);
#endif
                    rc = action_unnamed_26 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 16:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 27);
#endif
                    rc = action_close (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 2:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 28);
#endif
                    rc = action_unnamed_28 (thread);

#if (defined (SMT_ACTION_LIMIT))
                    if (icl_atomic_dec32 (&smt_actions_remaining) == 0) {
                        icl_console_print ("BREAKING!!!");
                        abort ();
                    }
#endif
                    
                    if (rc == SMT_BREAK) {
                        rc = SMT_OK;
                        break;
                    }
                    if (rc != SMT_OK)
                        return rc;
                    
                    thread->module++;
            
                    if (thread->pending_count
                    ||  thread->_exception_raised
                    ||  thread->signal_raised
                    ||  thread->shutdown_request
                    ||  smt_break_requested)
                        break;

                case 3:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
    }

    if (thread->_next_event == SMT_TERM_EVENT) {
        //  Because we optimise links, we need to grab ourselves one now.
        thread = smt_thread_link (thread);
        smt_thread_destroy (thread_p);
        return SMT_FINISHED;
    }
    
    return SMT_OK;
}

static int
zyre_digest_amqp_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
zyre_digest_amqp_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "zyre_digest_amqp_agent",
                 class_thread_name);

#endif
    if (--((zyre_digest_amqp_agent_class_context_t *) thread->context)->links == 0)
        icl_mem_free (thread->context);
    return 0;
}


static void
find_thread_state_next_state (
    int             *thread_type,
    smt_state_t     *state_id,
    smt_event_t     *event_id,
    smt_state_t     *nextstate_id,
    smt_thread_t    *thread)
{
    *thread_type  = 0;
    *state_id     = 0;
    *event_id     = 0;
    *nextstate_id = 0;
    
      {
        *thread_type = 1;
        if (thread->place < 17)
          {
            *state_id = 1;
            switch (thread->place) {
                case 3: *event_id = 1;   *nextstate_id = 2;   break;
                case 4: *event_id = 2;   break;
                case 5: *event_id = 3;   *nextstate_id = 1;   break;
                case 6: *event_id = 4;   *nextstate_id = 1;   break;
                case 7: *event_id = 5;   *nextstate_id = 1;   break;
                case 8: *event_id = 6;   *nextstate_id = 1;   break;
                case 9: *event_id = 7;   *nextstate_id = 1;   break;
                case 10: *event_id = 8;   *nextstate_id = 1;   break;
                case 11: *event_id = 9;   *nextstate_id = 1;   break;
                case 12: *event_id = 10;   *nextstate_id = 1;   break;
                case 13: *event_id = 11;   *nextstate_id = 1;   break;
                case 14: *event_id = 12;   *nextstate_id = 1;   break;
                case 15: *event_id = 13;   *nextstate_id = 1;   break;
                case 16: *event_id = 14;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 18: *event_id = 2;   break;
                case 19: *event_id = 3;   *nextstate_id = 2;   break;
                case 20: *event_id = 4;   *nextstate_id = 2;   break;
                case 21: *event_id = 5;   *nextstate_id = 2;   break;
                case 22: *event_id = 6;   *nextstate_id = 2;   break;
                case 23: *event_id = 7;   *nextstate_id = 2;   break;
                case 24: *event_id = 8;   *nextstate_id = 2;   break;
                case 25: *event_id = 9;   *nextstate_id = 2;   break;
                case 26: *event_id = 10;   *nextstate_id = 2;   break;
                case 27: *event_id = 11;   *nextstate_id = 2;   break;
                case 28: *event_id = 12;   *nextstate_id = 2;   break;
                case 29: *event_id = 13;   *nextstate_id = 2;   break;
                case 30: *event_id = 14;   *nextstate_id = 2;   break;
                case 31: *event_id = 1;   break;
            }
          }
      }
}

//  Action functions                                                           


static void
report_unrecognised_event_error (smt_thread_t *thread)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
    char
        num_buffer[8],
        *event_name_or_number;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
    if (thread->_next_event >= 0
    &&  thread->_next_event <  tblsize (event_name))
        event_name_or_number = (char *) event_name[thread->_next_event];
    else {
        apr_snprintf (num_buffer, sizeof (num_buffer), "%u", (unsigned) thread->_next_event);
        event_name_or_number = num_buffer;
    }
    icl_console_print ("zyre_digest_amqp_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
                       event_name_or_number,
                       thread_name [thread_type],
                       thread->id,
                       state_name  [state_id]);
    abort ();
}

static void
report_state_machine_error (smt_thread_t *thread)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
    icl_console_print ("State machine error: Event: %s Thread: %s, state: %s",
              event_name  [event_id],
              thread_name [thread_type],
              state_name  [state_id]);
}

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_DIGEST_AMQP_AGENT))

static void
animate_start_new_event (smt_thread_t *thread, smt_event_t saveevent_id)
{
    int
        thread_type;
    smt_state_t
        state_id;
    smt_event_t
        event_id;
    smt_state_t
        nextstate_id;
        
    find_thread_state_next_state (&thread_type,
                                  &state_id,
                                  &event_id,
                                  &nextstate_id,
                                  thread);
                                  
  icl_console_print ("%4lu> %-15s/%-15s %s:",
            thread->id,
            "zyre_digest_amqp_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "zyre_digest_amqp_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "zyre_digest_amqp_agent",
              thread_name [find_thread_type (thread->place)],
              action_name [action_id]);
}

static int
find_thread_type (smt_place_t place)
{
    int
        thread_type = 0;
        
        thread_type = 1;
    return thread_type;
}

#endif
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_DIGEST_AMQP_AGENT)       ||  defined (ZYRE_DIGEST_AMQP_AGENT_TRACE))
static void s_dump (
    icl_os_thread_t thread,
    apr_time_t      time,
    qbyte           info)
{
    smt_thread_id_t
        thread_id = info / 0x10000;
    smt_place_t
        state_or_event_or_action = info % 0x10000;
    int
        action_id;
    smt_event_t
        event_id;
    smt_state_t
        state_id;
        
    if (state_or_event_or_action > laststate + lastevent) {
        action_id = state_or_event_or_action - laststate - lastevent;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s           + %s",
                                       thread_id,
                                       "zyre_digest_amqp_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "zyre_digest_amqp_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "zyre_digest_amqp_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_DESTROY))
    icl_stats_inc ("zyre_digest_amqp_agent_destroy", &s_zyre_digest_amqp_agent_destroy_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_access_module_t
    *http_access_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (self->http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&self->http_access_module_list);
}

{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    //  Destroy own portals
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_list);
    //  Destroy own portal factories
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_factory_list))) {
        zyre_backend->client_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
    ipr_looseref_list_destroy (&self->zyre_backend_factory_list);
}
}

self->portal = NULL;
zyre_backend_unlink (&self->backend);
smt_log_unlink (&self->log);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_free (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_FREE))
    icl_stats_inc ("zyre_digest_amqp_agent_free", &s_zyre_digest_amqp_agent_free_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_digest_amqp object");
    zyre_digest_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_digest_amqp_free (self);
    self = NULL;
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_3 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_3))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_3", &s_zyre_digest_amqp_agent_unnamed_3_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_4 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_4))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_4", &s_zyre_digest_amqp_agent_unnamed_4_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_announce (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ANNOUNCE))
    icl_stats_inc ("zyre_digest_amqp_agent_announce", &s_zyre_digest_amqp_agent_announce_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
smt_log_t *
    log;

    portal = announce_m->portal;
    log = announce_m->log;
        {
//  We  don't link to the portal since the portal wraps this object and
//  destroys it.  The portal receives responses back from us when we're
//  invoked asynchronously.  Sorry this is kind of complex... in a portal
//  request handler, 'portal' is the portal that sent us the request.
//  In the 'arrived' method we get a request from one portal and send a
//  response to a different one, namely this one back to http_server:
self->portal = portal;

self->log = smt_log_link (log);
smt_log_print (log, "I: Zyre Digest-AMQP access module loaded");
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_6 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_6))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_6", &s_zyre_digest_amqp_agent_unnamed_6_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_before (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_BEFORE))
    icl_stats_inc ("zyre_digest_amqp_agent_before", &s_zyre_digest_amqp_agent_before_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = before_m->portal;
    context = before_m->context;
        {
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_8 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_8))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_8", &s_zyre_digest_amqp_agent_unnamed_8_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_send_request (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_SEND_REQUEST))
    icl_stats_inc ("zyre_digest_amqp_agent_send_request", &s_zyre_digest_amqp_agent_send_request_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
char * 
    user;
char * 
    realm;

    user = send_request_m->user;
    realm = send_request_m->realm;
        {
amq_content_basic_t
    *content;                       //  Content to post
char
    *body;                          //  Formatted message body

if (self->connected) {
    //  we need a private queue for responses back from server...
    body = ipr_str_format (
        "<digest-amqp version=\"1.0\">"
            "<request"
            " user=\"%s\""
            " realm=\"%s\""
            " algorithm=\"MD5\""
            " reply_to=\"%s\""
            " />"
        "</digest-amqp>", user, realm, self->reply_queue);

    content = amq_content_basic_new ();
    amq_content_basic_set_body (content, body, strlen (body), icl_mem_free);
    //  Send to default exchange, with service name as routing key
    zyre_backend_request_forward (self->backend,
        NULL, "Digest-AMQP", content, TRUE, TRUE);
    amq_content_basic_unlink (&content);
    smt_log_print (self->log, "I: sent Digest-AMQP request for '%s:%s'", user, realm);
}
else
    smt_log_print (self->log, "W: could not send Digest-AMQP request for '%s:%s', not connected",
        user, realm);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_10 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_10))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_10", &s_zyre_digest_amqp_agent_unnamed_10_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_online (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ONLINE))
    icl_stats_inc ("zyre_digest_amqp_agent_online", &s_zyre_digest_amqp_agent_online_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
char *
    reply_queue;

    portal = online_m->portal;
    reply_queue = online_m->reply_queue;
        {
smt_log_print (self->log,
    "I: Digest-AMQP now peered to OpenAMQ server on %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = TRUE;
icl_shortstr_cpy (self->reply_queue, reply_queue);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_12 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_12))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_12", &s_zyre_digest_amqp_agent_unnamed_12_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_offline (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_OFFLINE))
    icl_stats_inc ("zyre_digest_amqp_agent_offline", &s_zyre_digest_amqp_agent_offline_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;

    portal = offline_m->portal;
        {
smt_log_print (self->log,
    "I: Digest-AMQP unpeered from OpenAMQ server at %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = FALSE;
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_14 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_14))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_14", &s_zyre_digest_amqp_agent_unnamed_14_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_arrived (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_ARRIVED))
    icl_stats_inc ("zyre_digest_amqp_agent_arrived", &s_zyre_digest_amqp_agent_arrived_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = arrived_m->portal;
    method = arrived_m->method;
        {
//  We got a response back from the Digest-AMQP service.  Parse it for
//  a username, realm, and digest and ok, send those credentials to the
//  http_server.
//
asl_reader_t
    reader;                         //  Body reader
ipr_bucket_t
    *bucket;                        //  Body bucket
ipr_xml_t
    *xml_root = NULL,
    *response;
char
    *user,
    *realm,
    *digest;

amq_content_basic_set_reader (method->content, &reader, 4096);
bucket = amq_content_basic_replay_body (method->content, &reader);
xml_root = ipr_xml_parse_bucket (bucket);
response = ipr_xml_find_item (xml_root, "/digest-amqp/response");
if (response) {
    user   = ipr_xml_attr_get (response, "user", NULL);
    realm  = ipr_xml_attr_get (response, "realm", NULL);
    digest = ipr_xml_attr_get (response, "digest", NULL);
    if (user && realm && digest) {
        icl_shortstr_t
            key;
        icl_shortstr_fmt (key, "%s:%s", user, realm);
        http_access_module_response_new_password (self->portal, key, digest, TRUE);
    }
    ipr_xml_unlink (&response);
}
ipr_bucket_unlink (&bucket);
ipr_xml_destroy (&xml_root);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_16 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_16))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_16", &s_zyre_digest_amqp_agent_unnamed_16_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_returned (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_RETURNED))
    icl_stats_inc ("zyre_digest_amqp_agent_returned", &s_zyre_digest_amqp_agent_returned_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = returned_m->portal;
    method = returned_m->method;
        {
icl_console_print ("I: Digest-AMQP service is not running");
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_18 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_18))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_18", &s_zyre_digest_amqp_agent_unnamed_18_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action__zyre_backend_unbind (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT__ZYRE_BACKEND_UNBIND))
    icl_stats_inc ("zyre_digest_amqp_agent__zyre_backend_unbind", &s_zyre_digest_amqp_agent__zyre_backend_unbind_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
zyre_backend_t *
    portal;

    portal = _zyre_backend_unbind_m->portal;
        {
if (portal->client_looseref) {
    ipr_looseref_destroy (&portal->client_looseref);
    zyre_backend_unlink (&portal);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_20 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_20))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_20", &s_zyre_digest_amqp_agent_unnamed_20_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action__http_access_module_unbind (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT__HTTP_ACCESS_MODULE_UNBIND))
    icl_stats_inc ("zyre_digest_amqp_agent__http_access_module_unbind", &s_zyre_digest_amqp_agent__http_access_module_unbind_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;

    portal = _http_access_module_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    http_access_module_unlink (&portal);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_22 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_22))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_22", &s_zyre_digest_amqp_agent_unnamed_22_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_open (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_OPEN))
    icl_stats_inc ("zyre_digest_amqp_agent_open", &s_zyre_digest_amqp_agent_open_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = open_m->portal;
    context = open_m->context;
        {
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_24 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_24))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_24", &s_zyre_digest_amqp_agent_unnamed_24_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_after (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_AFTER))
    icl_stats_inc ("zyre_digest_amqp_agent_after", &s_zyre_digest_amqp_agent_after_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = after_m->portal;
    context = after_m->context;
        {
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_26 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_26))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_26", &s_zyre_digest_amqp_agent_unnamed_26_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_close (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_CLOSE))
    icl_stats_inc ("zyre_digest_amqp_agent_close", &s_zyre_digest_amqp_agent_close_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_digest_amqp
http_access_module_t *
    portal;
http_access_context_t *
    context;

    portal = close_m->portal;
    context = close_m->context;
        {
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_28 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_DIGEST_AMQP_AGENT_UNNAMED_28))
    icl_stats_inc ("zyre_digest_amqp_agent_unnamed_28", &s_zyre_digest_amqp_agent_unnamed_28_stats);
#endif        
#define tcb ((zyre_digest_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

