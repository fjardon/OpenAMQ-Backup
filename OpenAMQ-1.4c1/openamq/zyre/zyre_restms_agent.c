/*---------------------------------------------------------------------------
    zyre_restms_agent.c - functions for zyre_restms_agent.

    Generated from zyre_restms_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "zyre_restms_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((zyre_restms_agent_destroy_t *) thread->method->data)

#define announce_m ((zyre_restms_agent_announce_t *) thread->method->data)

#define get_m ((zyre_restms_agent_get_t *) thread->method->data)

#define put_m ((zyre_restms_agent_put_t *) thread->method->data)

#define delete_m ((zyre_restms_agent_delete_t *) thread->method->data)

#define post_m ((zyre_restms_agent_post_t *) thread->method->data)

#define head_m ((zyre_restms_agent_head_t *) thread->method->data)

#define move_m ((zyre_restms_agent_move_t *) thread->method->data)

#define copy_m ((zyre_restms_agent_copy_t *) thread->method->data)

#define online_m ((zyre_restms_agent_online_t *) thread->method->data)

#define offline_m ((zyre_restms_agent_offline_t *) thread->method->data)

#define arrived_m ((zyre_restms_agent_arrived_t *) thread->method->data)

#define returned_m ((zyre_restms_agent_returned_t *) thread->method->data)

#define _zyre_backend_unbind_m ((zyre_restms_agent__zyre_backend_unbind_t *) thread->method->data)

#define _http_driver_module_unbind_m ((zyre_restms_agent__http_driver_module_unbind_t *) thread->method->data)

enum {
    shutdown_event                                 = 1,
    destroy_m_event                                = 2,
    announce_m_event                               = 3,
    get_m_event                                    = 4,
    put_m_event                                    = 5,
    delete_m_event                                 = 6,
    post_m_event                                   = 7,
    head_m_event                                   = 8,
    move_m_event                                   = 9,
    copy_m_event                                   = 10,
    online_m_event                                 = 11,
    offline_m_event                                = 12,
    arrived_m_event                                = 13,
    returned_m_event                               = 14,
    _zyre_backend_unbind_m_event                   = 15,
    _http_driver_module_unbind_m_event             = 16,
};

#define laststate                                  2
#define lastevent                                  16
#define lastplace                                  35

#define zyre_restms_agent_agent_name               "Zyre-Restms-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define announce_m_event_name                      "Announce-M"
#define get_m_event_name                           "Get-M"
#define put_m_event_name                           "Put-M"
#define delete_m_event_name                        "Delete-M"
#define post_m_event_name                          "Post-M"
#define head_m_event_name                          "Head-M"
#define move_m_event_name                          "Move-M"
#define copy_m_event_name                          "Copy-M"
#define online_m_event_name                        "Online-M"
#define offline_m_event_name                       "Offline-M"
#define arrived_m_event_name                       "Arrived-M"
#define returned_m_event_name                      "Returned-M"
#define _zyre_backend_unbind_m_event_name          "-Zyre-Backend-Unbind-M"
#define _http_driver_module_unbind_m_event_name    "-Http-Driver-Module-Unbind-M"

#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_3_action_name                      "Unnamed-3"
#define unnamed_4_action_name                      "Unnamed-4"
#define announce_action_name                       "Announce"
#define unnamed_6_action_name                      "Unnamed-6"
#define get_action_name                            "Get"
#define unnamed_8_action_name                      "Unnamed-8"
#define put_action_name                            "Put"
#define unnamed_10_action_name                     "Unnamed-10"
#define delete_action_name                         "Delete"
#define unnamed_12_action_name                     "Unnamed-12"
#define post_action_name                           "Post"
#define unnamed_14_action_name                     "Unnamed-14"
#define head_action_name                           "Head"
#define unnamed_16_action_name                     "Unnamed-16"
#define move_action_name                           "Move"
#define unnamed_18_action_name                     "Unnamed-18"
#define copy_action_name                           "Copy"
#define unnamed_20_action_name                     "Unnamed-20"
#define online_action_name                         "Online"
#define unnamed_22_action_name                     "Unnamed-22"
#define offline_action_name                        "Offline"
#define unnamed_24_action_name                     "Unnamed-24"
#define arrived_action_name                        "Arrived"
#define unnamed_26_action_name                     "Unnamed-26"
#define returned_action_name                       "Returned"
#define unnamed_28_action_name                     "Unnamed-28"
#define _zyre_backend_unbind_action_name           "-Zyre-Backend-Unbind"
#define unnamed_30_action_name                     "Unnamed-30"
#define _http_driver_module_unbind_action_name     "-Http-Driver-Module-Unbind"
#define unnamed_32_action_name                     "Unnamed-32"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
zyre_restms_agent_destroy_t;

typedef struct
  {
    http_driver_module_t *  portal;
    smt_log_t *    log;
  }
zyre_restms_agent_announce_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_get_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_put_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_delete_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_post_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_head_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_move_t;

typedef struct
  {
    http_driver_module_t *  portal;
    http_driver_context_t *  context;
  }
zyre_restms_agent_copy_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         reply_queue;
  }
zyre_restms_agent_online_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_restms_agent_offline_t;

typedef struct
  {
    zyre_backend_t *  portal;
    zyre_peer_method_t *  method;
  }
zyre_restms_agent_arrived_t;

typedef struct
  {
    zyre_backend_t *  portal;
    zyre_peer_method_t *  method;
  }
zyre_restms_agent_returned_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_restms_agent__zyre_backend_unbind_t;

typedef struct
  {
    http_driver_module_t *  portal;
  }
zyre_restms_agent__http_driver_module_unbind_t;

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        zyre_restms_t
            *zyre_restms;
    
} zyre_restms_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_announce_cache = NULL;
static icl_cache_t
    *s_get_cache = NULL;
static icl_cache_t
    *s_put_cache = NULL;
static icl_cache_t
    *s_delete_cache = NULL;
static icl_cache_t
    *s_post_cache = NULL;
static icl_cache_t
    *s_head_cache = NULL;
static icl_cache_t
    *s_move_cache = NULL;
static icl_cache_t
    *s_copy_cache = NULL;
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
    *s__http_driver_module_unbind_cache = NULL;

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
    get_m_event_name,
    put_m_event_name,
    delete_m_event_name,
    post_m_event_name,
    head_m_event_name,
    move_m_event_name,
    copy_m_event_name,
    online_m_event_name,
    offline_m_event_name,
    arrived_m_event_name,
    returned_m_event_name,
    _zyre_backend_unbind_m_event_name,
    _http_driver_module_unbind_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT)        ||  defined (BASE_TRACE)  || defined (BASE_TRACE_ZYRE_RESTMS_AGENT)   ||  defined (ZYRE_RESTMS_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    destroy_action_name,
    free_action_name,
    unnamed_3_action_name,
    unnamed_4_action_name,
    announce_action_name,
    unnamed_6_action_name,
    get_action_name,
    unnamed_8_action_name,
    put_action_name,
    unnamed_10_action_name,
    delete_action_name,
    unnamed_12_action_name,
    post_action_name,
    unnamed_14_action_name,
    head_action_name,
    unnamed_16_action_name,
    move_action_name,
    unnamed_18_action_name,
    copy_action_name,
    unnamed_20_action_name,
    online_action_name,
    unnamed_22_action_name,
    offline_action_name,
    unnamed_24_action_name,
    arrived_action_name,
    unnamed_26_action_name,
    returned_action_name,
    unnamed_28_action_name,
    _zyre_backend_unbind_action_name,
    unnamed_30_action_name,
    _http_driver_module_unbind_action_name,
    unnamed_32_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_DESTROY))
static icl_stats_t *s_zyre_restms_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_FREE))
static icl_stats_t *s_zyre_restms_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_3))
static icl_stats_t *s_zyre_restms_agent_unnamed_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_4))
static icl_stats_t *s_zyre_restms_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ANNOUNCE))
static icl_stats_t *s_zyre_restms_agent_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_6))
static icl_stats_t *s_zyre_restms_agent_unnamed_6_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_GET))
static icl_stats_t *s_zyre_restms_agent_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_8))
static icl_stats_t *s_zyre_restms_agent_unnamed_8_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_PUT))
static icl_stats_t *s_zyre_restms_agent_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_10))
static icl_stats_t *s_zyre_restms_agent_unnamed_10_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_DELETE))
static icl_stats_t *s_zyre_restms_agent_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_12))
static icl_stats_t *s_zyre_restms_agent_unnamed_12_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_POST))
static icl_stats_t *s_zyre_restms_agent_post_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_14))
static icl_stats_t *s_zyre_restms_agent_unnamed_14_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_HEAD))
static icl_stats_t *s_zyre_restms_agent_head_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_16))
static icl_stats_t *s_zyre_restms_agent_unnamed_16_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_MOVE))
static icl_stats_t *s_zyre_restms_agent_move_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_18))
static icl_stats_t *s_zyre_restms_agent_unnamed_18_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_COPY))
static icl_stats_t *s_zyre_restms_agent_copy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_20))
static icl_stats_t *s_zyre_restms_agent_unnamed_20_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ONLINE))
static icl_stats_t *s_zyre_restms_agent_online_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_22))
static icl_stats_t *s_zyre_restms_agent_unnamed_22_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_OFFLINE))
static icl_stats_t *s_zyre_restms_agent_offline_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_24))
static icl_stats_t *s_zyre_restms_agent_unnamed_24_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ARRIVED))
static icl_stats_t *s_zyre_restms_agent_arrived_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_26))
static icl_stats_t *s_zyre_restms_agent_unnamed_26_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_RETURNED))
static icl_stats_t *s_zyre_restms_agent_returned_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_28))
static icl_stats_t *s_zyre_restms_agent_unnamed_28_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT__ZYRE_BACKEND_UNBIND))
static icl_stats_t *s_zyre_restms_agent__zyre_backend_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_30))
static icl_stats_t *s_zyre_restms_agent_unnamed_30_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT__HTTP_DRIVER_MODULE_UNBIND))
static icl_stats_t *s_zyre_restms_agent__http_driver_module_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_32))
static icl_stats_t *s_zyre_restms_agent_unnamed_32_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    zyre_restms_agent_manager       (smt_thread_t **thread);
static int    zyre_restms_agent_catcher       (smt_thread_t *thread);
static int    zyre_restms_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ZYRE_RESTMS_AGENT)          ||  defined (ZYRE_RESTMS_AGENT_TRACE))
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
static int    action_get                      (smt_thread_t *thread);
static int    action_unnamed_8                (smt_thread_t *thread);
static int    action_put                      (smt_thread_t *thread);
static int    action_unnamed_10               (smt_thread_t *thread);
static int    action_delete                   (smt_thread_t *thread);
static int    action_unnamed_12               (smt_thread_t *thread);
static int    action_post                     (smt_thread_t *thread);
static int    action_unnamed_14               (smt_thread_t *thread);
static int    action_head                     (smt_thread_t *thread);
static int    action_unnamed_16               (smt_thread_t *thread);
static int    action_move                     (smt_thread_t *thread);
static int    action_unnamed_18               (smt_thread_t *thread);
static int    action_copy                     (smt_thread_t *thread);
static int    action_unnamed_20               (smt_thread_t *thread);
static int    action_online                   (smt_thread_t *thread);
static int    action_unnamed_22               (smt_thread_t *thread);
static int    action_offline                  (smt_thread_t *thread);
static int    action_unnamed_24               (smt_thread_t *thread);
static int    action_arrived                  (smt_thread_t *thread);
static int    action_unnamed_26               (smt_thread_t *thread);
static int    action_returned                 (smt_thread_t *thread);
static int    action_unnamed_28               (smt_thread_t *thread);
static int    action__zyre_backend_unbind     (smt_thread_t *thread);
static int    action_unnamed_30               (smt_thread_t *thread);
static int    action__http_driver_module_unbind  (smt_thread_t *thread);
static int    action_unnamed_32               (smt_thread_t *thread);
static int
zyre_restms_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
zyre_restms_agent_destroy_destructor (void *data);
static int
zyre_restms_agent_announce_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    smt_log_t *    log);
int
zyre_restms_agent_announce_destructor (void *data);
static int
zyre_restms_agent_get_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_get_destructor (void *data);
static int
zyre_restms_agent_put_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_put_destructor (void *data);
static int
zyre_restms_agent_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_delete_destructor (void *data);
static int
zyre_restms_agent_post_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_post_destructor (void *data);
static int
zyre_restms_agent_head_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_head_destructor (void *data);
static int
zyre_restms_agent_move_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_move_destructor (void *data);
static int
zyre_restms_agent_copy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context);
int
zyre_restms_agent_copy_destructor (void *data);
static int
zyre_restms_agent_online_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         reply_queue);
int
zyre_restms_agent_online_destructor (void *data);
static int
zyre_restms_agent_offline_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_restms_agent_offline_destructor (void *data);
static int
zyre_restms_agent_arrived_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method);
int
zyre_restms_agent_arrived_destructor (void *data);
static int
zyre_restms_agent_returned_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method);
int
zyre_restms_agent_returned_destructor (void *data);
static int
zyre_restms_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_restms_agent__zyre_backend_unbind_destructor (void *data);
static int
zyre_restms_agent__http_driver_module_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal);
int
zyre_restms_agent__http_driver_module_unbind_destructor (void *data);
//  Function definitions                                                       

static int
zyre_restms_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    zyre_restms_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_destroy_destructor);
    
    return rc;
}

int
zyre_restms_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((zyre_restms_agent_destroy_t *) data)-> file;
    line = ((zyre_restms_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_announce_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    smt_log_t *    log)
{
    int
        rc = 0;
    zyre_restms_agent_announce_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_announce_cache);
    _message->portal                    = portal;
    _message->log                       = log;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_announce_destructor);
    
    return rc;
}

int
zyre_restms_agent_announce_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
smt_log_t * log;

    portal = ((zyre_restms_agent_announce_t *) data)-> portal;
    log = ((zyre_restms_agent_announce_t *) data)-> log;


    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_get_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_get_t
        *_message;
        
    //  Possess code for get
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_get_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_get_destructor);
    
    return rc;
}

int
zyre_restms_agent_get_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_get_t *) data)-> portal;
    context = ((zyre_restms_agent_get_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_put_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_put_t
        *_message;
        
    //  Possess code for put
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_put_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_put_destructor);
    
    return rc;
}

int
zyre_restms_agent_put_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_put_t *) data)-> portal;
    context = ((zyre_restms_agent_put_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_delete_t
        *_message;
        
    //  Possess code for delete
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_delete_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_delete_destructor);
    
    return rc;
}

int
zyre_restms_agent_delete_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_delete_t *) data)-> portal;
    context = ((zyre_restms_agent_delete_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_post_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_post_t
        *_message;
        
    //  Possess code for post
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_post_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_post_destructor);
    
    return rc;
}

int
zyre_restms_agent_post_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_post_t *) data)-> portal;
    context = ((zyre_restms_agent_post_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_head_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_head_t
        *_message;
        
    //  Possess code for head
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_head_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_head_destructor);
    
    return rc;
}

int
zyre_restms_agent_head_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_head_t *) data)-> portal;
    context = ((zyre_restms_agent_head_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_move_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_move_t
        *_message;
        
    //  Possess code for move
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_move_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_move_destructor);
    
    return rc;
}

int
zyre_restms_agent_move_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_move_t *) data)-> portal;
    context = ((zyre_restms_agent_move_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_copy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal,
    http_driver_context_t *  context)
{
    int
        rc = 0;
    zyre_restms_agent_copy_t
        *_message;
        
    //  Possess code for copy
    

    
        assert (context);
        context = http_driver_context_link (context);
        
    
    

    _message = icl_mem_cache_alloc (s_copy_cache);
    _message->portal                    = portal;
    _message->context                   = context;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_copy_destructor);
    
    return rc;
}

int
zyre_restms_agent_copy_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;
http_driver_context_t * context;

    portal = ((zyre_restms_agent_copy_t *) data)-> portal;
    context = ((zyre_restms_agent_copy_t *) data)-> context;



    
        http_driver_context_unlink (&context);
        
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_online_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         reply_queue)
{
    int
        rc = 0;
    zyre_restms_agent_online_t
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
                          zyre_restms_agent_online_destructor);
    
    return rc;
}

int
zyre_restms_agent_online_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * reply_queue;

    portal = ((zyre_restms_agent_online_t *) data)-> portal;
    reply_queue = ((zyre_restms_agent_online_t *) data)-> reply_queue;



    
        icl_mem_strfree (&reply_queue);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_offline_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_restms_agent_offline_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_offline_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent_offline_destructor);
    
    return rc;
}

int
zyre_restms_agent_offline_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_restms_agent_offline_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_arrived_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;
    zyre_restms_agent_arrived_t
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
                          zyre_restms_agent_arrived_destructor);
    
    return rc;
}

int
zyre_restms_agent_arrived_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
zyre_peer_method_t * method;

    portal = ((zyre_restms_agent_arrived_t *) data)-> portal;
    method = ((zyre_restms_agent_arrived_t *) data)-> method;



    
        zyre_peer_method_unlink (&method);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent_returned_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;
    zyre_restms_agent_returned_t
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
                          zyre_restms_agent_returned_destructor);
    
    return rc;
}

int
zyre_restms_agent_returned_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
zyre_peer_method_t * method;

    portal = ((zyre_restms_agent_returned_t *) data)-> portal;
    method = ((zyre_restms_agent_returned_t *) data)-> method;



    
        zyre_peer_method_unlink (&method);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_restms_agent__zyre_backend_unbind_t
        *_message;
        

    _message = icl_mem_cache_alloc (s__zyre_backend_unbind_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent__zyre_backend_unbind_destructor);
    
    return rc;
}

int
zyre_restms_agent__zyre_backend_unbind_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_restms_agent__zyre_backend_unbind_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_restms_agent__http_driver_module_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    http_driver_module_t *  portal)
{
    int
        rc = 0;
    zyre_restms_agent__http_driver_module_unbind_t
        *_message;
        

    _message = icl_mem_cache_alloc (s__http_driver_module_unbind_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_restms_agent__http_driver_module_unbind_destructor);
    
    return rc;
}

int
zyre_restms_agent__http_driver_module_unbind_destructor (void *data)
{
    int
        rc = 0;
http_driver_module_t * portal;

    portal = ((zyre_restms_agent__http_driver_module_unbind_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


int
zyre_restms_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_announce (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    smt_log_t *           log)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_announce_send (
                thread->reply_queue, announce_m_event,
                portal,
                log);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_get (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_get_send (
                thread->reply_queue, get_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_put (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_put_send (
                thread->reply_queue, put_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_delete (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_delete_send (
                thread->reply_queue, delete_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_post (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_post_send (
                thread->reply_queue, post_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_head (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_head_send (
                thread->reply_queue, head_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_move (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_move_send (
                thread->reply_queue, move_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_copy (
    smt_thread_t * thread,
    http_driver_module_t * portal,
    http_driver_context_t * context)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_copy_send (
                thread->reply_queue, copy_m_event,
                portal,
                context);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_online (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                reply_queue)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_online_send (
                thread->reply_queue, online_m_event,
                portal,
                reply_queue);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_offline (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_offline_send (
                thread->reply_queue, offline_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_arrived (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_arrived_send (
                thread->reply_queue, arrived_m_event,
                portal,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent_returned (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    zyre_peer_method_t *  method)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent_returned_send (
                thread->reply_queue, returned_m_event,
                portal,
                method);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent__zyre_backend_unbind (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent__zyre_backend_unbind_send (
                thread->reply_queue, _zyre_backend_unbind_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_restms_agent__http_driver_module_unbind (
    smt_thread_t * thread,
    http_driver_module_t * portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_restms_agent_manager);
        rc = zyre_restms_agent__http_driver_module_unbind_send (
                thread->reply_queue, _http_driver_module_unbind_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

void
zyre_restms_agent_term (void)
{

}

int 
zyre_restms_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (zyre_restms_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (zyre_restms_agent_destroy_t));
    s_announce_cache = icl_cache_get (sizeof (zyre_restms_agent_announce_t));
    s_get_cache = icl_cache_get (sizeof (zyre_restms_agent_get_t));
    s_put_cache = icl_cache_get (sizeof (zyre_restms_agent_put_t));
    s_delete_cache = icl_cache_get (sizeof (zyre_restms_agent_delete_t));
    s_post_cache = icl_cache_get (sizeof (zyre_restms_agent_post_t));
    s_head_cache = icl_cache_get (sizeof (zyre_restms_agent_head_t));
    s_move_cache = icl_cache_get (sizeof (zyre_restms_agent_move_t));
    s_copy_cache = icl_cache_get (sizeof (zyre_restms_agent_copy_t));
    s_online_cache = icl_cache_get (sizeof (zyre_restms_agent_online_t));
    s_offline_cache = icl_cache_get (sizeof (zyre_restms_agent_offline_t));
    s_arrived_cache = icl_cache_get (sizeof (zyre_restms_agent_arrived_t));
    s_returned_cache = icl_cache_get (sizeof (zyre_restms_agent_returned_t));
    s__zyre_backend_unbind_cache = icl_cache_get (sizeof (zyre_restms_agent__zyre_backend_unbind_t));
    s__http_driver_module_unbind_cache = icl_cache_get (sizeof (zyre_restms_agent__http_driver_module_unbind_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, zyre_restms_agent_term);
    
    return rc;
}

void
zyre_restms_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
zyre_restms_agent_class_thread_new (
    zyre_restms_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (zyre_restms_agent_manager,
                             zyre_restms_agent_catcher,
                             zyre_restms_agent_class_destroy);
                             

#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "zyre_restms_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (zyre_restms_agent_class_context_t));
        ((zyre_restms_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)

        tcb->zyre_restms = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
zyre_restms_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == zyre_restms_agent_manager);
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
            case 20:
            case 35:
                thread->place = SMT_TERM_PLACE;
                break;
            case 11:
            case 15:
            case 16:
            case 17:
            case 18:
            case 9:
            case 10:
            case 8:
            case 12:
            case 7:
            case 6:
            case 5:
            case 14:
            case 13:
                thread->place = 2;
                break;
            case 34:
            case 33:
            case 32:
            case 31:
            case 29:
            case 27:
            case 28:
            case 3:
            case 30:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
                thread->place = 19;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)

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
        if (thread->place < 19)                 //  Main state
            thread->place = 2;
        else
            thread->place = 19;
    }

    switch (thread->place) {
        case 2:                         //  main state                          
{
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case announce_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case get_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case put_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case post_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case head_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case move_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case copy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case online_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case offline_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                case arrived_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 15; break;
                case returned_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 16; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 17; break;
                case _http_driver_module_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 18; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 19:                        //  shutting down state                 
{
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 20; break;
                case announce_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 21; break;
                case get_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 22; break;
                case put_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 23; break;
                case delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 24; break;
                case post_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 25; break;
                case head_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 26; break;
                case move_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 27; break;
                case copy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 28; break;
                case online_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 29; break;
                case offline_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 30; break;
                case arrived_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 31; break;
                case returned_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 32; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 33; break;
                case _http_driver_module_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 34; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 35; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
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
        case 32:
        case 33:
        case 34:
        case 35:
            switch (thread->module) {
                case 1:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    if (thread->place == 35)
                        thread->_next_event = SMT_TERM_EVENT;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 20:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_get (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
#endif
                    rc = action_put (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_delete (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
#endif
                    rc = action_post (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
#endif
                    rc = action_head (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
#endif
                    rc = action_move (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action_copy (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 21);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 23);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 25);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 27);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
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
        case 17:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 29);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 30);
#endif
                    rc = action_unnamed_30 (thread);

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
        case 18:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 31);
#endif
                    rc = action__http_driver_module_unbind (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 32);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 32);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
                    if (thread->animate)
                        animate_action (thread, 32);
#endif
                    rc = action_unnamed_32 (thread);

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
zyre_restms_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
zyre_restms_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (ZYRE_RESTMS_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "zyre_restms_agent",
                 class_thread_name);

#endif
    if (--((zyre_restms_agent_class_context_t *) thread->context)->links == 0)
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
        if (thread->place < 19)
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
                case 17: *event_id = 15;   *nextstate_id = 1;   break;
                case 18: *event_id = 16;   *nextstate_id = 1;   break;
            }
          }
        else
          {
            *state_id = 2;
            switch (thread->place) {
                case 20: *event_id = 2;   break;
                case 21: *event_id = 3;   *nextstate_id = 2;   break;
                case 22: *event_id = 4;   *nextstate_id = 2;   break;
                case 23: *event_id = 5;   *nextstate_id = 2;   break;
                case 24: *event_id = 6;   *nextstate_id = 2;   break;
                case 25: *event_id = 7;   *nextstate_id = 2;   break;
                case 26: *event_id = 8;   *nextstate_id = 2;   break;
                case 27: *event_id = 9;   *nextstate_id = 2;   break;
                case 28: *event_id = 10;   *nextstate_id = 2;   break;
                case 29: *event_id = 11;   *nextstate_id = 2;   break;
                case 30: *event_id = 12;   *nextstate_id = 2;   break;
                case 31: *event_id = 13;   *nextstate_id = 2;   break;
                case 32: *event_id = 14;   *nextstate_id = 2;   break;
                case 33: *event_id = 15;   *nextstate_id = 2;   break;
                case 34: *event_id = 16;   *nextstate_id = 2;   break;
                case 35: *event_id = 1;   break;
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
    icl_console_print ("zyre_restms_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_RESTMS_AGENT))

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
            "zyre_restms_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "zyre_restms_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "zyre_restms_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_RESTMS_AGENT)            ||  defined (ZYRE_RESTMS_AGENT_TRACE))
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
                                       "zyre_restms_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "zyre_restms_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "zyre_restms_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_DESTROY))
    icl_stats_inc ("zyre_restms_agent_destroy", &s_zyre_restms_agent_destroy_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
http_driver_module_t
    *http_driver_module;            //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->http_driver_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_driver_module = (http_driver_module_t *) ipr_looseref_pop (self->http_driver_module_list))) {
        http_driver_module->server_looseref = NULL;
        http_driver_module_destroy (&http_driver_module);
    }
}
ipr_looseref_list_destroy (&self->http_driver_module_list);
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

ipr_hash_table_destroy (&self->resources);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_FREE))
    icl_stats_inc ("zyre_restms_agent_free", &s_zyre_restms_agent_free_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_restms object");
    zyre_restms_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_restms_free (self);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_3))
    icl_stats_inc ("zyre_restms_agent_unnamed_3", &s_zyre_restms_agent_unnamed_3_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_4))
    icl_stats_inc ("zyre_restms_agent_unnamed_4", &s_zyre_restms_agent_unnamed_4_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ANNOUNCE))
    icl_stats_inc ("zyre_restms_agent_announce", &s_zyre_restms_agent_announce_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
smt_log_t *
    log;

    portal = announce_m->portal;
    log = announce_m->log;
        {
self->log = smt_log_link (log);
smt_log_print (log, "I: Zyre RestMS driver loaded at '%s'", portal->path);
smt_log_print (log, "I: - peering with AMQP server at '%s'",
    zyre_config_amqp_hostname (zyre_config));
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_6))
    icl_stats_inc ("zyre_restms_agent_unnamed_6", &s_zyre_restms_agent_unnamed_6_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_get (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_GET))
    icl_stats_inc ("zyre_restms_agent_get", &s_zyre_restms_agent_get_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = get_m->portal;
    context = get_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: GET resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_modified (resource, context->request)) {
            //  Use the Accept content type for our response
            http_response_set_content_type (context->response,
                http_request_get_header (context->request, "accept"));
            zyre_resource_request_get (resource, context);
            if (!context->replied)
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
        }
        else
            http_driver_context_reply_error (context, HTTP_REPLY_NOTMODIFIED, NULL);
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config) && !context->pending) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_8))
    icl_stats_inc ("zyre_restms_agent_unnamed_8", &s_zyre_restms_agent_unnamed_8_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_put (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_PUT))
    icl_stats_inc ("zyre_restms_agent_put", &s_zyre_restms_agent_put_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = put_m->portal;
    context = put_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: UPDATE resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_unmodified (resource, context->request))
            http_driver_context_reply_error (context, HTTP_REPLY_PRECONDITION,
                "resource was modified by another application");
        else {
            zyre_resource_request_put (resource, context);
            if (!context->replied)
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
        }
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_10))
    icl_stats_inc ("zyre_restms_agent_unnamed_10", &s_zyre_restms_agent_unnamed_10_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_delete (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_DELETE))
    icl_stats_inc ("zyre_restms_agent_delete", &s_zyre_restms_agent_delete_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = delete_m->portal;
    context = delete_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: DELETE resource '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        if (zyre_resource_unmodified (resource, context->request))
            http_driver_context_reply_error (context, HTTP_REPLY_PRECONDITION,
                "resource was modified by another application");
        else {
            //  The resource is the portal so we can't destroy it from
            //  within a request, or the request ends up trying to use a
            //  dead portal.  So we do it here, and the DELETE method
            //  just needs to verify the legitimacy of the request.
            zyre_resource_request_delete (resource, context);
            if (!context->failed) {
                //  Since we don't have a link to the resource, grab one
                //  Otherwise the destructor gets very unhappy
                resource = zyre_resource_link (resource);
                zyre_resource_detach_from_parent (resource);
                zyre_resource_destroy (&resource);
                http_driver_context_reply_success (context, HTTP_REPLY_OK);
            }
        }
    }
    else                            //  Idempotent delete -> OK
        http_driver_context_reply_success (context, HTTP_REPLY_OK);
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_12))
    icl_stats_inc ("zyre_restms_agent_unnamed_12", &s_zyre_restms_agent_unnamed_12_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_post (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_POST))
    icl_stats_inc ("zyre_restms_agent_post", &s_zyre_restms_agent_post_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = post_m->portal;
    context = post_m->context;
        {
zyre_resource_t
    *resource;

if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: POST to '%s'", context->request->pathinfo);

if (zyre_restms_check_path (context) == 0) {
    //  Pathinfo is URI key into resource table
    resource = ipr_hash_lookup (self->resources, context->request->pathinfo);
    if (resource) {
        if (zyre_config_restms_debug (zyre_config))
            icl_console_print ("R: - resource is a %s",
                zyre_resource_type_name (resource->type));
        zyre_resource_request_post (resource, context, self->resources, self->backend);
        if (!context->replied)
            http_driver_context_reply_success (context, HTTP_REPLY_OK);
    }
    else
        http_driver_context_reply_error (context, HTTP_REPLY_NOTFOUND,
            "URI does not match a known resource");
}
if (zyre_config_restms_debug (zyre_config)) {
    if (context && context->response)
        icl_console_print ("R: - reply %d %s",
            context->response->reply_code, context->response->reply_text);
    else
        icl_console_print ("R: - ERROR: context=%pp c->response=%pp",
            context, context->response);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_14))
    icl_stats_inc ("zyre_restms_agent_unnamed_14", &s_zyre_restms_agent_unnamed_14_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_head (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_HEAD))
    icl_stats_inc ("zyre_restms_agent_head", &s_zyre_restms_agent_head_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = head_m->portal;
    context = head_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "HEAD method is not allowed on this resource");
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_16))
    icl_stats_inc ("zyre_restms_agent_unnamed_16", &s_zyre_restms_agent_unnamed_16_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_move (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_MOVE))
    icl_stats_inc ("zyre_restms_agent_move", &s_zyre_restms_agent_move_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = move_m->portal;
    context = move_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "MOVE method is not allowed on this resource");
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_18))
    icl_stats_inc ("zyre_restms_agent_unnamed_18", &s_zyre_restms_agent_unnamed_18_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_copy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_COPY))
    icl_stats_inc ("zyre_restms_agent_copy", &s_zyre_restms_agent_copy_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;
http_driver_context_t *
    context;

    portal = copy_m->portal;
    context = copy_m->context;
        {
http_driver_context_reply_error (context, HTTP_REPLY_FORBIDDEN,
    "COPY method is not allowed on this resource");
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_20))
    icl_stats_inc ("zyre_restms_agent_unnamed_20", &s_zyre_restms_agent_unnamed_20_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ONLINE))
    icl_stats_inc ("zyre_restms_agent_online", &s_zyre_restms_agent_online_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
zyre_backend_t *
    portal;
char *
    reply_queue;

    portal = online_m->portal;
    reply_queue = online_m->reply_queue;
        {
smt_log_print (self->log,
    "I: RestMS handler now peered to OpenAMQ server on %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = TRUE;
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_22))
    icl_stats_inc ("zyre_restms_agent_unnamed_22", &s_zyre_restms_agent_unnamed_22_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_OFFLINE))
    icl_stats_inc ("zyre_restms_agent_offline", &s_zyre_restms_agent_offline_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
zyre_backend_t *
    portal;

    portal = offline_m->portal;
        {
smt_log_print (self->log,
    "I: RestMS handler unpeered from OpenAMQ server at %s",
    zyre_config_amqp_hostname (zyre_config));
self->connected = FALSE;
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_24))
    icl_stats_inc ("zyre_restms_agent_unnamed_24", &s_zyre_restms_agent_unnamed_24_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_ARRIVED))
    icl_stats_inc ("zyre_restms_agent_arrived", &s_zyre_restms_agent_arrived_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = arrived_m->portal;
    method = arrived_m->method;
        {
zyre_resource_t
    *pipe_res = NULL;
icl_shortstr_t
    pipe_path;
char
    *pipe_name;
//
//  The consumer tag should be in the form prefix:pipe-name
pipe_name = strchr (method->payload.basic_deliver.consumer_tag, ':');
if (pipe_name) {
    pipe_name++;                    //  Point to start of pipe name
    icl_shortstr_fmt (pipe_path, "/resource/%s", pipe_name);
    pipe_res = ipr_hash_lookup (self->resources, pipe_path);
}
if (zyre_config_restms_debug (zyre_config))
    icl_console_print ("R: - deliver message to pipe '%s' (%d bytes)",
        pipe_path, (int) ((amq_content_basic_t *) method->content)->body_size);

if (pipe_res) {
    zyre_resource_t
        *message_res,
        *content_res;

    //  Reach through to pipe object to grab message asynclet
    message_res = ((zyre_pipe_t *) (pipe_res->server_object))->asynclet;

    //  Create new content resource as child of message
    content_res = zyre_content__zyre_resource_new (NULL,
        message_res, self->resources, "content", "");
    zyre_restms__zyre_resource_bind (self, content_res);

    //  We provide the new resources with the AMQP method so they can
    //  process & store the AMQP content.  Not really what attach() was
    //  meant for but it's nicer than making a new portal method.
    zyre_resource_request_attach (message_res, NULL, method);
    zyre_resource_request_attach (content_res, NULL, method);
    zyre_resource_unlink (&content_res);

    //  Re-configure the pipe, which creates a new asynclet
    zyre_resource_request_configure (pipe_res, NULL, self->resources, self->backend);

    //  And now re-send the message if the clients is waiting
    zyre_resource_request_get (message_res, NULL);
}
else
    smt_log_print (self->log, "W: undeliverable message (tag='%s')",
        method->payload.basic_deliver.consumer_tag);
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_26))
    icl_stats_inc ("zyre_restms_agent_unnamed_26", &s_zyre_restms_agent_unnamed_26_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_RETURNED))
    icl_stats_inc ("zyre_restms_agent_returned", &s_zyre_restms_agent_returned_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
zyre_backend_t *
    portal;
zyre_peer_method_t *
    method;

    portal = returned_m->portal;
    method = returned_m->method;
        {
icl_console_print ("E: RestMS content not routable - abonormal");
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_28))
    icl_stats_inc ("zyre_restms_agent_unnamed_28", &s_zyre_restms_agent_unnamed_28_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT__ZYRE_BACKEND_UNBIND))
    icl_stats_inc ("zyre_restms_agent__zyre_backend_unbind", &s_zyre_restms_agent__zyre_backend_unbind_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
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
action_unnamed_30 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_30))
    icl_stats_inc ("zyre_restms_agent_unnamed_30", &s_zyre_restms_agent_unnamed_30_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action__http_driver_module_unbind (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT__HTTP_DRIVER_MODULE_UNBIND))
    icl_stats_inc ("zyre_restms_agent__http_driver_module_unbind", &s_zyre_restms_agent__http_driver_module_unbind_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_restms
http_driver_module_t *
    portal;

    portal = _http_driver_module_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    http_driver_module_unlink (&portal);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_32 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT)  ||  defined (BASE_STATS_ZYRE_RESTMS_AGENT_UNNAMED_32))
    icl_stats_inc ("zyre_restms_agent_unnamed_32", &s_zyre_restms_agent_unnamed_32_stats);
#endif        
#define tcb ((zyre_restms_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

