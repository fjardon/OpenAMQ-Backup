/*---------------------------------------------------------------------------
    zyre_backend_amqp_agent.c - functions for zyre_backend_amqp_agent.

    Generated from zyre_backend_amqp_agent.smt by smt_gen.gsl using GSL/4.

    
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
#include "zyre_backend_amqp_agent.h"

#define class_main_state                           1
#define class_shutting_down_state                  2

#define destroy_m ((zyre_backend_amqp_agent_destroy_t *) thread->method->data)

#define start_m ((zyre_backend_amqp_agent_start_t *) thread->method->data)

#define stop_m ((zyre_backend_amqp_agent_stop_t *) thread->method->data)

#define pipe_create_m ((zyre_backend_amqp_agent_pipe_create_t *) thread->method->data)

#define pipe_delete_m ((zyre_backend_amqp_agent_pipe_delete_t *) thread->method->data)

#define feed_create_m ((zyre_backend_amqp_agent_feed_create_t *) thread->method->data)

#define feed_delete_m ((zyre_backend_amqp_agent_feed_delete_t *) thread->method->data)

#define join_create_m ((zyre_backend_amqp_agent_join_create_t *) thread->method->data)

#define join_delete_m ((zyre_backend_amqp_agent_join_delete_t *) thread->method->data)

#define address_post_m ((zyre_backend_amqp_agent_address_post_t *) thread->method->data)

#define forward_m ((zyre_backend_amqp_agent_forward_t *) thread->method->data)

#define online_partial_m ((zyre_backend_amqp_agent_online_partial_t *) thread->method->data)

#define online_final_m ((zyre_backend_amqp_agent_online_final_t *) thread->method->data)

#define _zyre_backend_unbind_m ((zyre_backend_amqp_agent__zyre_backend_unbind_t *) thread->method->data)

enum {
    monitor_event                                  = 1,
    shutdown_event                                 = 2,
    destroy_m_event                                = 3,
    start_m_event                                  = 4,
    stop_m_event                                   = 5,
    pipe_create_m_event                            = 6,
    pipe_delete_m_event                            = 7,
    feed_create_m_event                            = 8,
    feed_delete_m_event                            = 9,
    join_create_m_event                            = 10,
    join_delete_m_event                            = 11,
    address_post_m_event                           = 12,
    forward_m_event                                = 13,
    online_partial_m_event                         = 14,
    online_final_m_event                           = 15,
    _zyre_backend_unbind_m_event                   = 16,
};

#define laststate                                  2
#define lastevent                                  16
#define lastplace                                  35

#define zyre_backend_amqp_agent_agent_name         "Zyre-Backend-Amqp-Agent"

#define class_thread_name                          "Class"

#define main_state_name                            "Main"
#define shutting_down_state_name                   "Shutting-Down"

#define monitor_event_name                         "Monitor"
#define shutdown_event_name                        "Shutdown"
#define destroy_m_event_name                       "Destroy-M"
#define start_m_event_name                         "Start-M"
#define stop_m_event_name                          "Stop-M"
#define pipe_create_m_event_name                   "Pipe-Create-M"
#define pipe_delete_m_event_name                   "Pipe-Delete-M"
#define feed_create_m_event_name                   "Feed-Create-M"
#define feed_delete_m_event_name                   "Feed-Delete-M"
#define join_create_m_event_name                   "Join-Create-M"
#define join_delete_m_event_name                   "Join-Delete-M"
#define address_post_m_event_name                  "Address-Post-M"
#define forward_m_event_name                       "Forward-M"
#define online_partial_m_event_name                "Online-Partial-M"
#define online_final_m_event_name                  "Online-Final-M"
#define _zyre_backend_unbind_m_event_name          "-Zyre-Backend-Unbind-M"

#define monitor_action_name                        "Monitor"
#define destroy_action_name                        "Destroy"
#define free_action_name                           "Free"
#define unnamed_4_action_name                      "Unnamed-4"
#define unnamed_5_action_name                      "Unnamed-5"
#define start_action_name                          "Start"
#define unnamed_7_action_name                      "Unnamed-7"
#define stop_action_name                           "Stop"
#define unnamed_9_action_name                      "Unnamed-9"
#define pipe_create_action_name                    "Pipe-Create"
#define unnamed_11_action_name                     "Unnamed-11"
#define pipe_delete_action_name                    "Pipe-Delete"
#define unnamed_13_action_name                     "Unnamed-13"
#define feed_create_action_name                    "Feed-Create"
#define unnamed_15_action_name                     "Unnamed-15"
#define feed_delete_action_name                    "Feed-Delete"
#define unnamed_17_action_name                     "Unnamed-17"
#define join_create_action_name                    "Join-Create"
#define unnamed_19_action_name                     "Unnamed-19"
#define join_delete_action_name                    "Join-Delete"
#define unnamed_21_action_name                     "Unnamed-21"
#define address_post_action_name                   "Address-Post"
#define unnamed_23_action_name                     "Unnamed-23"
#define forward_action_name                        "Forward"
#define unnamed_25_action_name                     "Unnamed-25"
#define online_partial_action_name                 "Online-Partial"
#define unnamed_27_action_name                     "Unnamed-27"
#define online_final_action_name                   "Online-Final"
#define unnamed_29_action_name                     "Unnamed-29"
#define _zyre_backend_unbind_action_name           "-Zyre-Backend-Unbind"
#define unnamed_31_action_name                     "Unnamed-31"

#define the_next_event                             thread->_next_event
#define exception_raised                           thread->_exception_raised

typedef struct
  {
    char *         file;
    size_t         line;
  }
zyre_backend_amqp_agent_destroy_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_backend_amqp_agent_start_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_backend_amqp_agent_stop_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         pipe_type;
    char *         pipe_name;
  }
zyre_backend_amqp_agent_pipe_create_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         pipe_name;
  }
zyre_backend_amqp_agent_pipe_delete_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         feed_type;
    char *         feed_name;
  }
zyre_backend_amqp_agent_feed_create_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         feed_name;
  }
zyre_backend_amqp_agent_feed_delete_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         pipe_name;
    char *         feed_name;
    char *         address;
  }
zyre_backend_amqp_agent_join_create_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         pipe_name;
    char *         feed_name;
    char *         address;
  }
zyre_backend_amqp_agent_join_delete_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         address;
    char *         feed_name;
    amq_content_basic_t *  content;
  }
zyre_backend_amqp_agent_address_post_t;

typedef struct
  {
    zyre_backend_t *  portal;
    char *         exchange;
    char *         routing_key;
    amq_content_basic_t *  content;
    Bool           mandatory;
    Bool           immediate;
  }
zyre_backend_amqp_agent_forward_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_backend_amqp_agent_online_partial_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_backend_amqp_agent_online_final_t;

typedef struct
  {
    zyre_backend_t *  portal;
  }
zyre_backend_amqp_agent__zyre_backend_unbind_t;


static void s_terminate_peering (zyre_backend_amqp_t *self);
static void s_synchronize_pipe  (ipr_hash_t *hash, void *argument);
static void s_synchronize_feed  (ipr_hash_t *hash, void *argument);
static void s_destroy_pipe      (ipr_hash_t *hash, void *argument);
static void s_destroy_feed      (ipr_hash_t *hash, void *argument);

static icl_cache_t
    *s_class_context_cache = NULL;

typedef struct {
    int
        links;

        zyre_backend_amqp_t
            *zyre_backend_amqp;
    
} zyre_backend_amqp_agent_class_context_t;

static icl_cache_t
    *s_destroy_cache = NULL;
static icl_cache_t
    *s_start_cache = NULL;
static icl_cache_t
    *s_stop_cache = NULL;
static icl_cache_t
    *s_pipe_create_cache = NULL;
static icl_cache_t
    *s_pipe_delete_cache = NULL;
static icl_cache_t
    *s_feed_create_cache = NULL;
static icl_cache_t
    *s_feed_delete_cache = NULL;
static icl_cache_t
    *s_join_create_cache = NULL;
static icl_cache_t
    *s_join_delete_cache = NULL;
static icl_cache_t
    *s_address_post_cache = NULL;
static icl_cache_t
    *s_forward_cache = NULL;
static icl_cache_t
    *s_online_partial_cache = NULL;
static icl_cache_t
    *s_online_final_cache = NULL;
static icl_cache_t
    *s__zyre_backend_unbind_cache = NULL;

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
    monitor_event_name,
    shutdown_event_name,
    destroy_m_event_name,
    start_m_event_name,
    stop_m_event_name,
    pipe_create_m_event_name,
    pipe_delete_m_event_name,
    feed_create_m_event_name,
    feed_delete_m_event_name,
    join_create_m_event_name,
    join_delete_m_event_name,
    address_post_m_event_name,
    forward_m_event_name,
    online_partial_m_event_name,
    online_final_m_event_name,
    _zyre_backend_unbind_m_event_name
};

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT)   ||  defined (BASE_TRACE)  || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT)   ||  defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
static const char *action_name [] = {
    "<NULL>",
    monitor_action_name,
    destroy_action_name,
    free_action_name,
    unnamed_4_action_name,
    unnamed_5_action_name,
    start_action_name,
    unnamed_7_action_name,
    stop_action_name,
    unnamed_9_action_name,
    pipe_create_action_name,
    unnamed_11_action_name,
    pipe_delete_action_name,
    unnamed_13_action_name,
    feed_create_action_name,
    unnamed_15_action_name,
    feed_delete_action_name,
    unnamed_17_action_name,
    join_create_action_name,
    unnamed_19_action_name,
    join_delete_action_name,
    unnamed_21_action_name,
    address_post_action_name,
    unnamed_23_action_name,
    forward_action_name,
    unnamed_25_action_name,
    online_partial_action_name,
    unnamed_27_action_name,
    online_final_action_name,
    unnamed_29_action_name,
    _zyre_backend_unbind_action_name,
    unnamed_31_action_name
};
#endif

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
static Bool
    s_animate = FALSE;
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_MONITOR))
static icl_stats_t *s_zyre_backend_amqp_agent_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_DESTROY))
static icl_stats_t *s_zyre_backend_amqp_agent_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FREE))
static icl_stats_t *s_zyre_backend_amqp_agent_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_4))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_4_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_5))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_5_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_START))
static icl_stats_t *s_zyre_backend_amqp_agent_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_7))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_7_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_STOP))
static icl_stats_t *s_zyre_backend_amqp_agent_stop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_9))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_9_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_PIPE_CREATE))
static icl_stats_t *s_zyre_backend_amqp_agent_pipe_create_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_11))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_11_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_PIPE_DELETE))
static icl_stats_t *s_zyre_backend_amqp_agent_pipe_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_13))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_13_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FEED_CREATE))
static icl_stats_t *s_zyre_backend_amqp_agent_feed_create_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_15))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_15_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FEED_DELETE))
static icl_stats_t *s_zyre_backend_amqp_agent_feed_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_17))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_17_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_JOIN_CREATE))
static icl_stats_t *s_zyre_backend_amqp_agent_join_create_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_19))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_19_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_JOIN_DELETE))
static icl_stats_t *s_zyre_backend_amqp_agent_join_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_21))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_21_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ADDRESS_POST))
static icl_stats_t *s_zyre_backend_amqp_agent_address_post_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_23))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_23_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FORWARD))
static icl_stats_t *s_zyre_backend_amqp_agent_forward_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_25))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_25_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ONLINE_PARTIAL))
static icl_stats_t *s_zyre_backend_amqp_agent_online_partial_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_27))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_27_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ONLINE_FINAL))
static icl_stats_t *s_zyre_backend_amqp_agent_online_final_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_29))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_29_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT__ZYRE_BACKEND_UNBIND))
static icl_stats_t *s_zyre_backend_amqp_agent__zyre_backend_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_31))
static icl_stats_t *s_zyre_backend_amqp_agent_unnamed_31_stats = NULL;
#endif

#ifdef __cplusplus
extern "C" {
#endif

//  Function prototypes                                                        

static int    zyre_backend_amqp_agent_manager  (smt_thread_t **thread);
static int    zyre_backend_amqp_agent_catcher  (smt_thread_t *thread);
static int    zyre_backend_amqp_agent_class_destroy  (smt_thread_t *thread);
static void   find_thread_state_next_state    (int          *thread_type,
                                               smt_state_t  *state_id,
                                               smt_event_t  *event_id,
                                               smt_state_t  *nextstate_id,
                                               smt_thread_t *thread);
static void   report_unrecognised_event_error (smt_thread_t *thread);
static void   report_state_machine_error      (smt_thread_t *thread);

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
static void   animate_start_new_event         (smt_thread_t *thread,
                                               smt_event_t  saveevent_id);
static void   animate_action                  (smt_thread_t *thread_id,
                                               int          action_id);
static int    find_thread_type                (smt_place_t  place);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT)    ||  defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
static void   s_dump                          (icl_os_thread_t apr_os_thread,
                                               apr_time_t      time,
                                               qbyte           info);

#endif

static int    action_monitor                  (smt_thread_t *thread);
static int    action_destroy                  (smt_thread_t *thread);
static int    action_free                     (smt_thread_t *thread);
static int    action_unnamed_4                (smt_thread_t *thread);
static int    action_unnamed_5                (smt_thread_t *thread);
static int    action_start                    (smt_thread_t *thread);
static int    action_unnamed_7                (smt_thread_t *thread);
static int    action_stop                     (smt_thread_t *thread);
static int    action_unnamed_9                (smt_thread_t *thread);
static int    action_pipe_create              (smt_thread_t *thread);
static int    action_unnamed_11               (smt_thread_t *thread);
static int    action_pipe_delete              (smt_thread_t *thread);
static int    action_unnamed_13               (smt_thread_t *thread);
static int    action_feed_create              (smt_thread_t *thread);
static int    action_unnamed_15               (smt_thread_t *thread);
static int    action_feed_delete              (smt_thread_t *thread);
static int    action_unnamed_17               (smt_thread_t *thread);
static int    action_join_create              (smt_thread_t *thread);
static int    action_unnamed_19               (smt_thread_t *thread);
static int    action_join_delete              (smt_thread_t *thread);
static int    action_unnamed_21               (smt_thread_t *thread);
static int    action_address_post             (smt_thread_t *thread);
static int    action_unnamed_23               (smt_thread_t *thread);
static int    action_forward                  (smt_thread_t *thread);
static int    action_unnamed_25               (smt_thread_t *thread);
static int    action_online_partial           (smt_thread_t *thread);
static int    action_unnamed_27               (smt_thread_t *thread);
static int    action_online_final             (smt_thread_t *thread);
static int    action_unnamed_29               (smt_thread_t *thread);
static int    action__zyre_backend_unbind     (smt_thread_t *thread);
static int    action_unnamed_31               (smt_thread_t *thread);
static int
zyre_backend_amqp_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line);
int
zyre_backend_amqp_agent_destroy_destructor (void *data);
static int
zyre_backend_amqp_agent_start_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_backend_amqp_agent_start_destructor (void *data);
static int
zyre_backend_amqp_agent_stop_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_backend_amqp_agent_stop_destructor (void *data);
static int
zyre_backend_amqp_agent_pipe_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_type,
    char *         pipe_name);
int
zyre_backend_amqp_agent_pipe_create_destructor (void *data);
static int
zyre_backend_amqp_agent_pipe_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name);
int
zyre_backend_amqp_agent_pipe_delete_destructor (void *data);
static int
zyre_backend_amqp_agent_feed_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         feed_type,
    char *         feed_name);
int
zyre_backend_amqp_agent_feed_create_destructor (void *data);
static int
zyre_backend_amqp_agent_feed_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         feed_name);
int
zyre_backend_amqp_agent_feed_delete_destructor (void *data);
static int
zyre_backend_amqp_agent_join_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name,
    char *         feed_name,
    char *         address);
int
zyre_backend_amqp_agent_join_create_destructor (void *data);
static int
zyre_backend_amqp_agent_join_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name,
    char *         feed_name,
    char *         address);
int
zyre_backend_amqp_agent_join_delete_destructor (void *data);
static int
zyre_backend_amqp_agent_address_post_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         address,
    char *         feed_name,
    amq_content_basic_t *  content);
int
zyre_backend_amqp_agent_address_post_destructor (void *data);
static int
zyre_backend_amqp_agent_forward_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         exchange,
    char *         routing_key,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate);
int
zyre_backend_amqp_agent_forward_destructor (void *data);
static int
zyre_backend_amqp_agent_online_partial_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_backend_amqp_agent_online_partial_destructor (void *data);
static int
zyre_backend_amqp_agent_online_final_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_backend_amqp_agent_online_final_destructor (void *data);
static int
zyre_backend_amqp_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal);
int
zyre_backend_amqp_agent__zyre_backend_unbind_destructor (void *data);
//  Function definitions                                                       

static int
zyre_backend_amqp_agent_destroy_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    char *         file,
    size_t         line)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_destroy_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_destroy_cache);
    _message->file                      = file;
    _message->line                      = line;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_destroy_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_destroy_destructor (void *data)
{
    int
        rc = 0;
char * file;
size_t line;

    file = ((zyre_backend_amqp_agent_destroy_t *) data)-> file;
    line = ((zyre_backend_amqp_agent_destroy_t *) data)-> line;


    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_start_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_start_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_start_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_start_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_start_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_backend_amqp_agent_start_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_stop_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_stop_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_stop_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_stop_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_stop_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_backend_amqp_agent_stop_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_pipe_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_type,
    char *         pipe_name)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_pipe_create_t
        *_message;
        
    //  Possess code for pipe create
    

    
        pipe_type = icl_mem_strdup (pipe_type);
        pipe_name = icl_mem_strdup (pipe_name);
      
    
    

    _message = icl_mem_cache_alloc (s_pipe_create_cache);
    _message->portal                    = portal;
    _message->pipe_type                 = pipe_type;
    _message->pipe_name                 = pipe_name;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_pipe_create_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_pipe_create_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * pipe_type;
char * pipe_name;

    portal = ((zyre_backend_amqp_agent_pipe_create_t *) data)-> portal;
    pipe_type = ((zyre_backend_amqp_agent_pipe_create_t *) data)-> pipe_type;
    pipe_name = ((zyre_backend_amqp_agent_pipe_create_t *) data)-> pipe_name;



    
        icl_mem_free (pipe_type);
        icl_mem_free (pipe_name);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_pipe_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_pipe_delete_t
        *_message;
        
    //  Possess code for pipe delete
    

    
        pipe_name = icl_mem_strdup (pipe_name);
      
    
    

    _message = icl_mem_cache_alloc (s_pipe_delete_cache);
    _message->portal                    = portal;
    _message->pipe_name                 = pipe_name;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_pipe_delete_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_pipe_delete_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * pipe_name;

    portal = ((zyre_backend_amqp_agent_pipe_delete_t *) data)-> portal;
    pipe_name = ((zyre_backend_amqp_agent_pipe_delete_t *) data)-> pipe_name;



    
        icl_mem_free (pipe_name);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_feed_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         feed_type,
    char *         feed_name)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_feed_create_t
        *_message;
        
    //  Possess code for feed create
    

    
        feed_type = icl_mem_strdup (feed_type);
        feed_name = icl_mem_strdup (feed_name);
      
    
    

    _message = icl_mem_cache_alloc (s_feed_create_cache);
    _message->portal                    = portal;
    _message->feed_type                 = feed_type;
    _message->feed_name                 = feed_name;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_feed_create_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_feed_create_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * feed_type;
char * feed_name;

    portal = ((zyre_backend_amqp_agent_feed_create_t *) data)-> portal;
    feed_type = ((zyre_backend_amqp_agent_feed_create_t *) data)-> feed_type;
    feed_name = ((zyre_backend_amqp_agent_feed_create_t *) data)-> feed_name;



    
        icl_mem_free (feed_type);
        icl_mem_free (feed_name);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_feed_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         feed_name)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_feed_delete_t
        *_message;
        
    //  Possess code for feed delete
    

    
        feed_name = icl_mem_strdup (feed_name);
      
    
    

    _message = icl_mem_cache_alloc (s_feed_delete_cache);
    _message->portal                    = portal;
    _message->feed_name                 = feed_name;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_feed_delete_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_feed_delete_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * feed_name;

    portal = ((zyre_backend_amqp_agent_feed_delete_t *) data)-> portal;
    feed_name = ((zyre_backend_amqp_agent_feed_delete_t *) data)-> feed_name;



    
        icl_mem_free (feed_name);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_join_create_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name,
    char *         feed_name,
    char *         address)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_join_create_t
        *_message;
        
    //  Possess code for join create
    

    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    
    

    _message = icl_mem_cache_alloc (s_join_create_cache);
    _message->portal                    = portal;
    _message->pipe_name                 = pipe_name;
    _message->feed_name                 = feed_name;
    _message->address                   = address;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_join_create_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_join_create_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * pipe_name;
char * feed_name;
char * address;

    portal = ((zyre_backend_amqp_agent_join_create_t *) data)-> portal;
    pipe_name = ((zyre_backend_amqp_agent_join_create_t *) data)-> pipe_name;
    feed_name = ((zyre_backend_amqp_agent_join_create_t *) data)-> feed_name;
    address = ((zyre_backend_amqp_agent_join_create_t *) data)-> address;



    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_join_delete_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         pipe_name,
    char *         feed_name,
    char *         address)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_join_delete_t
        *_message;
        
    //  Possess code for join delete
    

    
        pipe_name = icl_mem_strdup (pipe_name);
        feed_name = icl_mem_strdup (feed_name);
        address = icl_mem_strdup (address);
      
    
    

    _message = icl_mem_cache_alloc (s_join_delete_cache);
    _message->portal                    = portal;
    _message->pipe_name                 = pipe_name;
    _message->feed_name                 = feed_name;
    _message->address                   = address;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_join_delete_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_join_delete_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * pipe_name;
char * feed_name;
char * address;

    portal = ((zyre_backend_amqp_agent_join_delete_t *) data)-> portal;
    pipe_name = ((zyre_backend_amqp_agent_join_delete_t *) data)-> pipe_name;
    feed_name = ((zyre_backend_amqp_agent_join_delete_t *) data)-> feed_name;
    address = ((zyre_backend_amqp_agent_join_delete_t *) data)-> address;



    
        icl_mem_free (pipe_name);
        icl_mem_free (feed_name);
        icl_mem_free (address);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_address_post_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         address,
    char *         feed_name,
    amq_content_basic_t *  content)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_address_post_t
        *_message;
        
    //  Possess code for address post
    

    
        address = icl_mem_strdup (address);
        feed_name = icl_mem_strdup (feed_name);
        content = amq_content_basic_link (content);
      
    
    

    _message = icl_mem_cache_alloc (s_address_post_cache);
    _message->portal                    = portal;
    _message->address                   = address;
    _message->feed_name                 = feed_name;
    _message->content                   = content;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_address_post_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_address_post_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * address;
char * feed_name;
amq_content_basic_t * content;

    portal = ((zyre_backend_amqp_agent_address_post_t *) data)-> portal;
    address = ((zyre_backend_amqp_agent_address_post_t *) data)-> address;
    feed_name = ((zyre_backend_amqp_agent_address_post_t *) data)-> feed_name;
    content = ((zyre_backend_amqp_agent_address_post_t *) data)-> content;



    
        icl_mem_free (address);
        icl_mem_free (feed_name);
        amq_content_basic_unlink (&content);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_forward_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal,
    char *         exchange,
    char *         routing_key,
    amq_content_basic_t *  content,
    Bool           mandatory,
    Bool           immediate)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_forward_t
        *_message;
        
    //  Possess code for forward
    

    
        exchange = icl_mem_strdup (exchange);
        routing_key = icl_mem_strdup (routing_key);
        content = amq_content_basic_link (content);
      
    
    

    _message = icl_mem_cache_alloc (s_forward_cache);
    _message->portal                    = portal;
    _message->exchange                  = exchange;
    _message->routing_key               = routing_key;
    _message->content                   = content;
    _message->mandatory                 = mandatory;
    _message->immediate                 = immediate;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_forward_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_forward_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;
char * exchange;
char * routing_key;
amq_content_basic_t * content;
Bool mandatory;
Bool immediate;

    portal = ((zyre_backend_amqp_agent_forward_t *) data)-> portal;
    exchange = ((zyre_backend_amqp_agent_forward_t *) data)-> exchange;
    routing_key = ((zyre_backend_amqp_agent_forward_t *) data)-> routing_key;
    content = ((zyre_backend_amqp_agent_forward_t *) data)-> content;
    mandatory = ((zyre_backend_amqp_agent_forward_t *) data)-> mandatory;
    immediate = ((zyre_backend_amqp_agent_forward_t *) data)-> immediate;



    
        icl_mem_free (exchange);
        icl_mem_free (routing_key);
        amq_content_basic_unlink (&content);
      
    
    

    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_online_partial_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_online_partial_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_online_partial_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_online_partial_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_online_partial_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_backend_amqp_agent_online_partial_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent_online_final_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_backend_amqp_agent_online_final_t
        *_message;
        

    _message = icl_mem_cache_alloc (s_online_final_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent_online_final_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent_online_final_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_backend_amqp_agent_online_final_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


static int
zyre_backend_amqp_agent__zyre_backend_unbind_send (
    smt_method_queue_t *_queue,
    smt_event_t        _event,
    zyre_backend_t *  portal)
{
    int
        rc = 0;
    zyre_backend_amqp_agent__zyre_backend_unbind_t
        *_message;
        

    _message = icl_mem_cache_alloc (s__zyre_backend_unbind_cache);
    _message->portal                    = portal;

    rc = smt_method_send (_queue,           //  The queue
                          _event,           //  The event
                          SMT_PRIORITY_NORMAL,
                          SMT_OK,           //  Always OK
                          _message,         //  The message
                          zyre_backend_amqp_agent__zyre_backend_unbind_destructor);
    
    return rc;
}

int
zyre_backend_amqp_agent__zyre_backend_unbind_destructor (void *data)
{
    int
        rc = 0;
zyre_backend_t * portal;

    portal = ((zyre_backend_amqp_agent__zyre_backend_unbind_t *) data)-> portal;


    icl_mem_free (data);
    return rc;
}


int
zyre_backend_amqp_agent_destroy (
    smt_thread_t * thread,
    char *                file,
    size_t                line)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_destroy_send (
                thread->reply_queue, destroy_m_event,
                file,
                line);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_start (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_start_send (
                thread->reply_queue, start_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_stop (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_stop_send (
                thread->reply_queue, stop_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_pipe_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_type,
    char *                pipe_name)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_pipe_create_send (
                thread->reply_queue, pipe_create_m_event,
                portal,
                pipe_type,
                pipe_name);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_pipe_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_pipe_delete_send (
                thread->reply_queue, pipe_delete_m_event,
                portal,
                pipe_name);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_feed_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                feed_type,
    char *                feed_name)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_feed_create_send (
                thread->reply_queue, feed_create_m_event,
                portal,
                feed_type,
                feed_name);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_feed_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                feed_name)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_feed_delete_send (
                thread->reply_queue, feed_delete_m_event,
                portal,
                feed_name);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_join_create (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name,
    char *                feed_name,
    char *                address)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_join_create_send (
                thread->reply_queue, join_create_m_event,
                portal,
                pipe_name,
                feed_name,
                address);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_join_delete (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                pipe_name,
    char *                feed_name,
    char *                address)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_join_delete_send (
                thread->reply_queue, join_delete_m_event,
                portal,
                pipe_name,
                feed_name,
                address);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_address_post (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                address,
    char *                feed_name,
    amq_content_basic_t * content)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_address_post_send (
                thread->reply_queue, address_post_m_event,
                portal,
                address,
                feed_name,
                content);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_forward (
    smt_thread_t * thread,
    zyre_backend_t *      portal,
    char *                exchange,
    char *                routing_key,
    amq_content_basic_t * content,
    Bool                  mandatory,
    Bool                  immediate)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_forward_send (
                thread->reply_queue, forward_m_event,
                portal,
                exchange,
                routing_key,
                content,
                mandatory,
                immediate);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_online_partial (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_online_partial_send (
                thread->reply_queue, online_partial_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent_online_final (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent_online_final_send (
                thread->reply_queue, online_final_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}

int
zyre_backend_amqp_agent__zyre_backend_unbind (
    smt_thread_t * thread,
    zyre_backend_t *      portal)
{
    int
        rc = 0;

    //  Trying to send to a null of zombied thread returns an error            
    if (thread && !thread->zombie) {
        assert (thread->manager == zyre_backend_amqp_agent_manager);
        rc = zyre_backend_amqp_agent__zyre_backend_unbind_send (
                thread->reply_queue, _zyre_backend_unbind_m_event,
                portal);
    }
    else
        rc = -1;
        
    return rc;
}


static void
s_terminate_peering (zyre_backend_amqp_t *self)
{
    //  Stop peer agent thread if it's still alive
    if (self->peer_agent_thread) {
        if (!self->peer_agent_thread->zombie)
            zyre_peer_agent_connection_close (self->peer_agent_thread);
        smt_thread_unlink (&self->peer_agent_thread);
    }
    if (self->connected) {
        self->connected = FALSE;
        self->offlined  = TRUE;
        if (self->portal)
            zyre_backend_response_offline (self->portal);
    }
}

static void s_synchronize_pipe (ipr_hash_t *hash, void *argument)
{
    ipr_looseref_t
        *looseref;
    zyre_amqp_join_t
        *join;                          //  Each join for pipe
    zyre_backend_amqp_t
        *self = (zyre_backend_amqp_t *) argument;
    zyre_amqp_pipe_t
        *pipe = (zyre_amqp_pipe_t *) hash->data;

    zyre_peer_agent_restms_pipe_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe->type, pipe->name);

    //  Synchronize all joins for this pipe
    looseref = ipr_looseref_list_first (pipe->joins);
    while (looseref) {
        join = ((zyre_amqp_join_t *) looseref->object);
        zyre_peer_agent_restms_join_create (
            self->peer_agent_thread,
            self->channel_nbr,
            join->pipe_name, join->feed_name, join->address);
        looseref = ipr_looseref_list_next (&looseref);
    }
}

static void s_synchronize_feed (ipr_hash_t *hash, void *argument)
{
    zyre_backend_amqp_t
        *self = (zyre_backend_amqp_t *) argument;
    zyre_amqp_feed_t
        *feed = (zyre_amqp_feed_t *) hash->data;

    zyre_peer_agent_restms_feed_create (
        self->peer_agent_thread,
        self->channel_nbr,
        feed->type, feed->name);
}

static void s_destroy_pipe (ipr_hash_t *hash, void *argument)
{
    zyre_amqp_pipe_t
        *pipe = (zyre_amqp_pipe_t *) hash->data;
    zyre_amqp_join_t
        *join;                          //  Each join for pipe

    //  Destroy all joins for this pipe
    while ((join = (zyre_amqp_join_t *) ipr_looseref_pop (pipe->joins)))
        zyre_amqp_join_destroy (&join);

    zyre_amqp_pipe_destroy (&pipe);
}

static void s_destroy_feed (ipr_hash_t *hash, void *argument)
{
    zyre_amqp_feed_t
        *feed = (zyre_amqp_feed_t *) hash->data;
    zyre_amqp_feed_destroy (&feed);
}

void
zyre_backend_amqp_agent_term (void)
{

}

int 
zyre_backend_amqp_agent_init (void)
{
    int
        rc = SMT_OK;                    //  Return code

    s_class_context_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_class_context_t));
    s_destroy_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_destroy_t));
    s_start_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_start_t));
    s_stop_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_stop_t));
    s_pipe_create_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_pipe_create_t));
    s_pipe_delete_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_pipe_delete_t));
    s_feed_create_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_feed_create_t));
    s_feed_delete_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_feed_delete_t));
    s_join_create_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_join_create_t));
    s_join_delete_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_join_delete_t));
    s_address_post_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_address_post_t));
    s_forward_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_forward_t));
    s_online_partial_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_online_partial_t));
    s_online_final_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent_online_final_t));
    s__zyre_backend_unbind_cache = icl_cache_get (sizeof (zyre_backend_amqp_agent__zyre_backend_unbind_t));

    //  Initialise basic stuff.
    smt_initialise ();
    
    {

    }
    icl_system_register (NULL, zyre_backend_amqp_agent_term);
    
    return rc;
}

void
zyre_backend_amqp_agent_animate (Bool animate)
{
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
    s_animate = animate;
#endif
}

smt_thread_t *
zyre_backend_amqp_agent_class_thread_new (
    zyre_backend_amqp_t * self)
{
    smt_thread_t
        *thread;

    thread = smt_thread_new (zyre_backend_amqp_agent_manager,
                             zyre_backend_amqp_agent_catcher,
                             zyre_backend_amqp_agent_class_destroy);
                             

#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    thread->trace = icl_trace_new (ICL_TRACE_SIZE);
#endif

    if (thread) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
        thread->animate = s_animate;
        if (s_animate)
            icl_console_print ("%4lu> %-15s/%-15s <Created>",
                thread->id,
                "zyre_backend_amqp_agent",
                class_thread_name);
#endif

        thread->place   = 1;
        thread->context = icl_mem_cache_alloc (s_class_context_cache);
        memset (thread->context, 0, sizeof (zyre_backend_amqp_agent_class_context_t));
        ((zyre_backend_amqp_agent_class_context_t *) thread->context)->links = 1;
        thread->event_name = event_name;
{
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)

        tcb->zyre_backend_amqp = self;
    
#undef  tcb
}
    }
    return thread;
}


static int
zyre_backend_amqp_agent_manager (smt_thread_t **thread_p)
{
    smt_thread_t
        *thread = *thread_p;
        
    int
        rc;
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))

    smt_event_t
        saveevent_id = SMT_NULL_EVENT;
#endif
        
    assert (thread->manager == zyre_backend_amqp_agent_manager);
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
            case 5:
            case 21:
            case 35:
                thread->place = SMT_TERM_PLACE;
                break;
            case 12:
            case 15:
            case 16:
            case 13:
            case 18:
            case 9:
            case 14:
            case 11:
            case 6:
            case 10:
            case 8:
            case 7:
            case 3:
            case 17:
                thread->place = 2;
                break;
            case 34:
            case 33:
            case 29:
            case 32:
            case 31:
            case 26:
            case 30:
            case 28:
            case 4:
            case 20:
            case 27:
            case 22:
            case 23:
            case 24:
            case 25:
                thread->place = 19;
                break;
        }    
    else
    if (thread->module == 0) {
        if (thread->place == 1) { //                Class thread
            if (!thread->shutting_down) {
{
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)

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
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 3; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 4; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 5; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 6; break;
                case stop_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 7; break;
                case pipe_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 8; break;
                case pipe_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 9; break;
                case feed_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 10; break;
                case feed_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 11; break;
                case join_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 12; break;
                case join_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 13; break;
                case address_post_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 14; break;
                case forward_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 15; break;
                case online_partial_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 16; break;
                case online_final_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 17; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 1);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 18; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
        case 19:                        //  shutting down state                 
{
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)

#undef  tcb
}
            switch (thread->_next_event) {
                case SMT_NULL_EVENT:    //  In multi-thread mode, accidental   
                    break;              //  awakening is possible.             
                case monitor_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 1);
#endif
                    thread->place = 20; break;
                case destroy_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 3);
#endif
                    thread->place = 21; break;
                case start_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 4);
#endif
                    thread->place = 22; break;
                case stop_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 5);
#endif
                    thread->place = 23; break;
                case pipe_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 6);
#endif
                    thread->place = 24; break;
                case pipe_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 7);
#endif
                    thread->place = 25; break;
                case feed_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 8);
#endif
                    thread->place = 26; break;
                case feed_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 9);
#endif
                    thread->place = 27; break;
                case join_create_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 10);
#endif
                    thread->place = 28; break;
                case join_delete_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 11);
#endif
                    thread->place = 29; break;
                case address_post_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 12);
#endif
                    thread->place = 30; break;
                case forward_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 13);
#endif
                    thread->place = 31; break;
                case online_partial_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 14);
#endif
                    thread->place = 32; break;
                case online_final_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 15);
#endif
                    thread->place = 33; break;
                case _zyre_backend_unbind_m_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 16);
#endif
                    thread->place = 34; break;
                case shutdown_event:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 2);
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + laststate + 2);
#endif
                    thread->place = 35; break;
                default:
                    report_unrecognised_event_error (thread);
                    return SMT_THREAD_ERROR;
            };
            if (thread->_next_event != SMT_NULL_EVENT) {
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                saveevent_id = thread->_next_event;
#endif
                thread->_next_event = SMT_NULL_EVENT;
                thread->module = 1;
            }
            break;
    }
                                  
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
    if (thread->animate && thread->module == 1)
        animate_start_new_event (thread, saveevent_id);
#endif

    switch (thread->place) {
        case 3:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 1);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 1);
#endif
                    rc = action_monitor (thread);

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

                case 2:                         //  After actions              
                    thread->module = SMT_TERM_MODULE;
                    break;
                default:
                    report_state_machine_error (thread);
                    return SMT_THREAD_ERROR;
        }
        break;
        case 4:
        case 20:
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
        case 21:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 4);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 2);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 2);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 3);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 3);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 5);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 5);
#endif
                    rc = action_unnamed_5 (thread);

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
        case 6:
            switch (thread->module) {
                case 1:
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 6);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 6);
#endif
                    rc = action_start (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 7);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 7);
#endif
                    rc = action_unnamed_7 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 8);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 8);
#endif
                    rc = action_stop (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 9);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 9);
#endif
                    rc = action_unnamed_9 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 10);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 10);
#endif
                    rc = action_pipe_create (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 11);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 11);
#endif
                    rc = action_unnamed_11 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 12);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 12);
#endif
                    rc = action_pipe_delete (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 13);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 13);
#endif
                    rc = action_unnamed_13 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 14);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 14);
#endif
                    rc = action_feed_create (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 15);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 15);
#endif
                    rc = action_unnamed_15 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 16);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 16);
#endif
                    rc = action_feed_delete (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 17);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 17);
#endif
                    rc = action_unnamed_17 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 18);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 18);
#endif
                    rc = action_join_create (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 19);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 19);
#endif
                    rc = action_unnamed_19 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 20);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 20);
#endif
                    rc = action_join_delete (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 21);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 21);
#endif
                    rc = action_unnamed_21 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 22);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 22);
#endif
                    rc = action_address_post (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 23);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 23);
#endif
                    rc = action_unnamed_23 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 24);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 24);
#endif
                    rc = action_forward (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 25);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 25);
#endif
                    rc = action_unnamed_25 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 26);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 26);
#endif
                    rc = action_online_partial (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 27);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 27);
#endif
                    rc = action_unnamed_27 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 28);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 28);
#endif
                    rc = action_online_final (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 29);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 29);
#endif
                    rc = action_unnamed_29 (thread);

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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 30);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 30);
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
                    icl_trace_record (
                        NULL, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
                    icl_trace_record (
                        thread->trace, s_dump, thread->id * 0x10000 + laststate + lastevent + 31);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
                    if (thread->animate)
                        animate_action (thread, 31);
#endif
                    rc = action_unnamed_31 (thread);

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
zyre_backend_amqp_agent_catcher (smt_thread_t *thread)
{
    return SMT_OK;
}


static int    
zyre_backend_amqp_agent_class_destroy (smt_thread_t *thread)
{
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (NULL, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
    //  Don't trust thread->os_thread while destroying thread.
    icl_trace_record (thread->trace, s_dump, thread->id * 0x10000 + 0);
#endif
#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))
    if (thread->animate)
        icl_console_print ("%4lu> %-15s/%-15s <Destroyed>",
                  thread->id,
                  "zyre_backend_amqp_agent",
                 class_thread_name);

#endif
    if (--((zyre_backend_amqp_agent_class_context_t *) thread->context)->links == 0)
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
                case 3: *event_id = 1;   *nextstate_id = 1;   break;
                case 4: *event_id = 2;   *nextstate_id = 2;   break;
                case 5: *event_id = 3;   break;
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
                case 20: *event_id = 1;   *nextstate_id = 2;   break;
                case 21: *event_id = 3;   break;
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
                case 35: *event_id = 2;   break;
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
    icl_console_print ("zyre_backend_amqp_agent: Unrecognised event '%s' in '%s' thread number: %u, state: %s",
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

#if (defined (BASE_ANIMATE) || defined (BASE_ANIMATE_ZYRE_BACKEND_AMQP_AGENT))

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
            "zyre_backend_amqp_agent",
            thread_name [thread_type],
            state_name [state_id]);
  icl_console_print ("%4lu> %-15s/%-15s    (--) %-32s->%s",
            thread->id,
            "zyre_backend_amqp_agent",
            thread_name [thread_type],
            event_name [event_id != SMT_NULL_EVENT ? event_id : saveevent_id],
            nextstate_id ? state_name [nextstate_id] : "");
}

static void
animate_action (smt_thread_t *thread, int action_id)
{
    icl_console_print ("%4lu> %-15s/%-15s           + %s",
              thread->id,
              "zyre_backend_amqp_agent",
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
#if (defined (BASE_TRACE) || defined (BASE_TRACE_ZYRE_BACKEND_AMQP_AGENT)      ||  defined (ZYRE_BACKEND_AMQP_AGENT_TRACE))
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
                                       "zyre_backend_amqp_agent",
                                       action_name [action_id]);
    }
    else
    if (state_or_event_or_action > laststate) {
        event_id = state_or_event_or_action - laststate;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s    (--) %-32s",
                                       thread_id,
                                       "zyre_backend_amqp_agent",
                                       event_name [event_id]);
    }
    else {
        state_id = state_or_event_or_action;
        icl_console_print_thread_time (thread, time,
                                       "%4lu> %-15s %s:",
                                       thread_id,
                                       "zyre_backend_amqp_agent",
                                       state_id ? state_name [state_id] : "<Destroyed>");
    }
}

#endif
static int
action_monitor (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_MONITOR))
    icl_stats_inc ("zyre_backend_amqp_agent_monitor", &s_zyre_backend_amqp_agent_monitor_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            
#define self tcb->zyre_backend_amqp

        {
//  Terminate the peering if the application asked for it, or the
//  peer agent thread was closed from the network side.
if (self->peer_agent_thread && (!self->enabled || self->peer_agent_thread->zombie))
    s_terminate_peering (self);
else
//  Connect the peering if we're not already connected but the app
//  has for the peering to become active.
if (!self->peer_agent_thread && self->enabled)
    self->peer_agent_thread = zyre_peer_agent_connection_thread_new (
        self->portal,               //  Callback for incoming methods
        zyre_config_amqp_hostname (zyre_config),
        "/",                        //  Virtual host
        self->auth_data,
        "Zyre peering",             //  Instance name
        zyre_config_amqp_trace   (zyre_config),
        zyre_config_amqp_timeout (zyre_config),
        zyre_config_amqp_debug   (zyre_config));

//  Peering monitor runs once per second
smt_timer_request_delay (self->thread, 1000 * 1000, monitor_event);
        }
        
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_destroy (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_DESTROY))
    icl_stats_inc ("zyre_backend_amqp_agent_destroy", &s_zyre_backend_amqp_agent_destroy_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
{
zyre_backend_t
    *zyre_backend;                  //  Portal object

if (icl_atomic_cas32 ((volatile qbyte *) &self->zyre_backend_stopped, TRUE, FALSE) == FALSE) {
    while ((zyre_backend = (zyre_backend_t *) ipr_looseref_pop (self->zyre_backend_list))) {
        zyre_backend->server_looseref = NULL;
        zyre_backend_destroy (&zyre_backend);
    }
}
ipr_looseref_list_destroy (&self->zyre_backend_list);
}

{
zyre_peer_method_t
    *method;                        //  Queue.Bind method

self->portal = NULL;
s_terminate_peering (self);
icl_longstr_destroy (&self->auth_data);

while ((method = (zyre_peer_method_t *) ipr_looseref_pop (self->messages)))
    zyre_peer_method_unlink (&method);
ipr_looseref_list_destroy (&self->messages);
ipr_hash_table_apply   (self->feed_table, s_destroy_feed, NULL);
ipr_hash_table_apply   (self->pipe_table, s_destroy_pipe, NULL);
ipr_hash_table_destroy (&self->pipe_table);
ipr_hash_table_destroy (&self->feed_table);
}
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FREE))
    icl_stats_inc ("zyre_backend_amqp_agent_free", &s_zyre_backend_amqp_agent_free_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
char *
    file;
size_t
    line;

    file = destroy_m->file;
    line = destroy_m->line;
        {
if (self->links == 0) {
    icl_console_print ("E: missing link on zyre_backend_amqp object");
    zyre_backend_amqp_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
}
if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
    zyre_backend_amqp_free (self);
    self = NULL;
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_4 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_4))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_4", &s_zyre_backend_amqp_agent_unnamed_4_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_5 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_5))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_5", &s_zyre_backend_amqp_agent_unnamed_5_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_start (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_START))
    icl_stats_inc ("zyre_backend_amqp_agent_start", &s_zyre_backend_amqp_agent_start_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = start_m->portal;
        {
ipr_config_t
    *config;                        //  Current server config file
char
    *login = "peering";             //  Local user name for credentials

config = ipr_config_dup (zyre_peer_config_table (zyre_peer_config));
ipr_config_locate (config, "/config/security", "plain");
if (config->located)
    ipr_config_locate (config, "user", login);
if (config->located) {
    icl_longstr_destroy (&self->auth_data);
    self->auth_data = ipr_sasl_plain_encode (login, ipr_config_get (config, "password", ""));
}
else {
    smt_log_print (http_server->alert_log,
        "E: login credentials for '%s' not defined - cannot connect", login);
    smt_log_print (http_server->alert_log,
        "E: please check security section in configuration, and restart");
    exit (EXIT_FAILURE);
}
ipr_config_destroy (&config);

//  We  don't link to the portal since the portal wraps this object and
//  destroys it.  The portal receives responses back from the smt thread
//  in zyre_peer_agent.
self->portal = portal;
self->enabled = TRUE;

//  Launch monitor to do actual connection
smt_timer_request_delay (self->thread, 100 * 1000, monitor_event);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_7 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_7))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_7", &s_zyre_backend_amqp_agent_unnamed_7_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_stop (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_STOP))
    icl_stats_inc ("zyre_backend_amqp_agent_stop", &s_zyre_backend_amqp_agent_stop_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = stop_m->portal;
        {
//  Tell monitor to disconnect, if connected
self->enabled = FALSE;
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_9 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_9))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_9", &s_zyre_backend_amqp_agent_unnamed_9_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_pipe_create (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_PIPE_CREATE))
    icl_stats_inc ("zyre_backend_amqp_agent_pipe_create", &s_zyre_backend_amqp_agent_pipe_create_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_type;
char *
    pipe_name;

    portal = pipe_create_m->portal;
    pipe_type = pipe_create_m->pipe_type;
    pipe_name = pipe_create_m->pipe_name;
        {
zyre_amqp_pipe_t
    *pipe;

assert (ipr_hash_lookup (self->pipe_table, pipe_name) == NULL);
pipe = zyre_amqp_pipe_new (pipe_type, pipe_name);
ipr_hash_insert (self->pipe_table, pipe_name, pipe);
if (self->connected)
    zyre_peer_agent_restms_pipe_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_type, pipe_name);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_11 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_11))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_11", &s_zyre_backend_amqp_agent_unnamed_11_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_pipe_delete (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_PIPE_DELETE))
    icl_stats_inc ("zyre_backend_amqp_agent_pipe_delete", &s_zyre_backend_amqp_agent_pipe_delete_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;

    portal = pipe_delete_m->portal;
    pipe_name = pipe_delete_m->pipe_name;
        {
zyre_amqp_pipe_t
    *pipe;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
if (self->connected)
    zyre_peer_agent_restms_pipe_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name);
ipr_hash_delete (self->pipe_table, pipe_name);
zyre_amqp_pipe_destroy (&pipe);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_13 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_13))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_13", &s_zyre_backend_amqp_agent_unnamed_13_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_feed_create (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FEED_CREATE))
    icl_stats_inc ("zyre_backend_amqp_agent_feed_create", &s_zyre_backend_amqp_agent_feed_create_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    feed_type;
char *
    feed_name;

    portal = feed_create_m->portal;
    feed_type = feed_create_m->feed_type;
    feed_name = feed_create_m->feed_name;
        {
zyre_amqp_feed_t
    *feed;

assert (ipr_hash_lookup (self->feed_table, feed_name) == NULL);
feed = zyre_amqp_feed_new (feed_type, feed_name);
ipr_hash_insert (self->feed_table, feed_name, feed);
if (self->connected)
    zyre_peer_agent_restms_feed_create (
        self->peer_agent_thread,
        self->channel_nbr,
        feed_type, feed_name);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_15 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_15))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_15", &s_zyre_backend_amqp_agent_unnamed_15_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_feed_delete (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FEED_DELETE))
    icl_stats_inc ("zyre_backend_amqp_agent_feed_delete", &s_zyre_backend_amqp_agent_feed_delete_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    feed_name;

    portal = feed_delete_m->portal;
    feed_name = feed_delete_m->feed_name;
        {
zyre_amqp_feed_t
    *feed;

feed = ipr_hash_lookup (self->feed_table, feed_name);
assert (feed);
if (self->connected)
    zyre_peer_agent_restms_feed_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        feed_name);
ipr_hash_delete (self->feed_table, feed_name);
zyre_amqp_feed_destroy (&feed);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_17 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_17))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_17", &s_zyre_backend_amqp_agent_unnamed_17_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_join_create (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_JOIN_CREATE))
    icl_stats_inc ("zyre_backend_amqp_agent_join_create", &s_zyre_backend_amqp_agent_join_create_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;
char *
    feed_name;
char *
    address;

    portal = join_create_m->portal;
    pipe_name = join_create_m->pipe_name;
    feed_name = join_create_m->feed_name;
    address = join_create_m->address;
        {
zyre_amqp_pipe_t
    *pipe;
zyre_amqp_join_t
    *join;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
assert (zyre_amqp_pipe_join_lookup (pipe, feed_name, address) == NULL);
join = zyre_amqp_join_new (pipe_name, feed_name, address);
join->pipe_ref = ipr_looseref_queue (pipe->joins, join);
if (self->connected)
    zyre_peer_agent_restms_join_create (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name, feed_name, address);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_19 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_19))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_19", &s_zyre_backend_amqp_agent_unnamed_19_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_join_delete (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_JOIN_DELETE))
    icl_stats_inc ("zyre_backend_amqp_agent_join_delete", &s_zyre_backend_amqp_agent_join_delete_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    pipe_name;
char *
    feed_name;
char *
    address;

    portal = join_delete_m->portal;
    pipe_name = join_delete_m->pipe_name;
    feed_name = join_delete_m->feed_name;
    address = join_delete_m->address;
        {
zyre_amqp_pipe_t
    *pipe;
zyre_amqp_join_t
    *join;

pipe = ipr_hash_lookup (self->pipe_table, pipe_name);
assert (pipe);
join = zyre_amqp_pipe_join_lookup (pipe, feed_name, address);
assert (join);
if (self->connected)
    zyre_peer_agent_restms_join_delete (
        self->peer_agent_thread,
        self->channel_nbr,
        pipe_name, feed_name, address);

//  Pipe must still exist
ipr_looseref_destroy (&join->pipe_ref);
zyre_amqp_join_destroy (&join);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_21 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_21))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_21", &s_zyre_backend_amqp_agent_unnamed_21_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_address_post (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ADDRESS_POST))
    icl_stats_inc ("zyre_backend_amqp_agent_address_post", &s_zyre_backend_amqp_agent_address_post_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    address;
char *
    feed_name;
amq_content_basic_t *
    content;

    portal = address_post_m->portal;
    address = address_post_m->address;
    feed_name = address_post_m->feed_name;
    content = address_post_m->content;
        {
zyre_peer_method_t
    *method;
zyre_amqp_feed_t
    *feed;

feed = ipr_hash_lookup (self->feed_table, feed_name);
if (*feed_name)
    assert (feed);                  //  Default feed is not defined

if (*feed_name && feed->as_queue) {
    method = zyre_peer_method_new_basic_publish (
        0,                          //  Ticket
        NULL,                       //  Default exchange
        feed_name,                  //  Routing key is queue name
        FALSE,                      //  Not mandatory
        FALSE);                     //  Not immediate
}
else
    method = zyre_peer_method_new_basic_publish (
        0,                          //  Ticket
        feed_name,                  //  Feed exchange
        address,                    //  Routing key is address
        FALSE,                      //  Not mandatory
        FALSE);                     //  Not immediate

method->content = amq_content_basic_link (content);

//  We send the message if we can, else we queue it for later
if (self->connected) {
    zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    zyre_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_23 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_23))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_23", &s_zyre_backend_amqp_agent_unnamed_23_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_forward (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_FORWARD))
    icl_stats_inc ("zyre_backend_amqp_agent_forward", &s_zyre_backend_amqp_agent_forward_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;
char *
    exchange;
char *
    routing_key;
amq_content_basic_t *
    content;
Bool
    mandatory;
Bool
    immediate;

    portal = forward_m->portal;
    exchange = forward_m->exchange;
    routing_key = forward_m->routing_key;
    content = forward_m->content;
    mandatory = forward_m->mandatory;
    immediate = forward_m->immediate;
        {
zyre_peer_method_t
    *method;

//  Create a Basic.Publish method
method = zyre_peer_method_new_basic_publish (
    0, exchange, routing_key, mandatory, immediate);
method->content = amq_content_basic_link (content);

//  We only hold forwards if the connection is currently down
if (self->connected) {
    zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
    zyre_peer_method_unlink (&method);
}
else
    ipr_looseref_queue (self->messages, method);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_25 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_25))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_25", &s_zyre_backend_amqp_agent_unnamed_25_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_online_partial (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ONLINE_PARTIAL))
    icl_stats_inc ("zyre_backend_amqp_agent_online_partial", &s_zyre_backend_amqp_agent_online_partial_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = online_partial_m->portal;
        {
self->channel_nbr = 1;
zyre_peer_agent_channel_open (self->peer_agent_thread, self->channel_nbr);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_27 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_27))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_27", &s_zyre_backend_amqp_agent_unnamed_27_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

static int
action_online_final (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_ONLINE_FINAL))
    icl_stats_inc ("zyre_backend_amqp_agent_online_final", &s_zyre_backend_amqp_agent_online_final_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = online_final_m->portal;
        {
zyre_peer_method_t
    *method;                        //  Method to send to peer server

if (!self->connected) {
    self->connected = TRUE;
    self->offlined = FALSE;

    //  Create first feeds, then pipes, then joins on AMQP server
    ipr_hash_table_apply (self->feed_table, s_synchronize_feed, self);
    ipr_hash_table_apply (self->pipe_table, s_synchronize_pipe, self);

    //  Forward all pending messages to AMQP server
    while ((method = (zyre_peer_method_t *) ipr_looseref_pop (self->messages))) {
        zyre_peer_agent_push (self->peer_agent_thread, self->channel_nbr, method);
        zyre_peer_method_unlink (&method);
    }
    //  Create private queue for internal request-response
    zyre_peer_agent_queue_declare (
        self->peer_agent_thread, self->channel_nbr, 0, self->queue,
        FALSE, FALSE, TRUE, TRUE, TRUE, NULL);
    zyre_peer_agent_basic_consume (
        self->peer_agent_thread, self->channel_nbr, 0, self->queue,
        NULL, TRUE, TRUE, TRUE, TRUE, NULL);
}
zyre_backend_response_online (self->portal, self->queue);
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_29 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_29))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_29", &s_zyre_backend_amqp_agent_unnamed_29_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT__ZYRE_BACKEND_UNBIND))
    icl_stats_inc ("zyre_backend_amqp_agent__zyre_backend_unbind", &s_zyre_backend_amqp_agent__zyre_backend_unbind_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{


#define self tcb->zyre_backend_amqp
zyre_backend_t *
    portal;

    portal = _zyre_backend_unbind_m->portal;
        {
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    zyre_backend_unlink (&portal);
}
        }
#undef self
            
}
#undef  tcb
    return _rc;
}

static int
action_unnamed_31 (smt_thread_t *thread)
{
    int
        _rc = SMT_OK;

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT)  ||  defined (BASE_STATS_ZYRE_BACKEND_AMQP_AGENT_UNNAMED_31))
    icl_stats_inc ("zyre_backend_amqp_agent_unnamed_31", &s_zyre_backend_amqp_agent_unnamed_31_stats);
#endif        
#define tcb ((zyre_backend_amqp_agent_class_context_t *) thread->context)
{

            //  Force release of method immediately
            smt_method_destroy (&thread->method);
        
}
#undef  tcb
    return _rc;
}

