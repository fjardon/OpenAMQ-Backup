/*---------------------------------------------------------------------------
    amq_content_basic.c - amq_content_basic component

    Generated from amq_content_basic.icl by icl_gen using GSL/4.
    
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
#include "amq_content_basic.h"          //  Definitions for our class

//  Shorthand for class type

#define self_t              amq_content_basic_t

//  Shorthands for class methods

#define self_new            amq_content_basic_new
#define self_annihilate     amq_content_basic_annihilate
#define self_record_header  amq_content_basic_record_header
#define self_replay_header  amq_content_basic_replay_header
#define self_record_body    amq_content_basic_record_body
#define self_set_reader     amq_content_basic_set_reader
#define self_replay_body    amq_content_basic_replay_body
#define self_set_body       amq_content_basic_set_body
#define self_get_body       amq_content_basic_get_body
#define self_save_body      amq_content_basic_save_body
#define self_set_routing_key  amq_content_basic_set_routing_key
#define self_get_class_id   amq_content_basic_get_class_id
#define self_get_weight     amq_content_basic_get_weight
#define self_get_body_size  amq_content_basic_get_body_size
#define self_get_exchange   amq_content_basic_get_exchange
#define self_get_routing_key  amq_content_basic_get_routing_key
#define self_get_producer_id  amq_content_basic_get_producer_id
#define self_set_content_type  amq_content_basic_set_content_type
#define self_get_content_type  amq_content_basic_get_content_type
#define self_set_content_encoding  amq_content_basic_set_content_encoding
#define self_get_content_encoding  amq_content_basic_get_content_encoding
#define self_set_headers    amq_content_basic_set_headers
#define self_get_headers    amq_content_basic_get_headers
#define self_set_delivery_mode  amq_content_basic_set_delivery_mode
#define self_get_delivery_mode  amq_content_basic_get_delivery_mode
#define self_set_priority   amq_content_basic_set_priority
#define self_get_priority   amq_content_basic_get_priority
#define self_set_correlation_id  amq_content_basic_set_correlation_id
#define self_get_correlation_id  amq_content_basic_get_correlation_id
#define self_set_reply_to   amq_content_basic_set_reply_to
#define self_get_reply_to   amq_content_basic_get_reply_to
#define self_set_expiration  amq_content_basic_set_expiration
#define self_get_expiration  amq_content_basic_get_expiration
#define self_set_message_id  amq_content_basic_set_message_id
#define self_get_message_id  amq_content_basic_get_message_id
#define self_set_timestamp  amq_content_basic_set_timestamp
#define self_get_timestamp  amq_content_basic_get_timestamp
#define self_set_type       amq_content_basic_set_type
#define self_get_type       amq_content_basic_get_type
#define self_set_user_id    amq_content_basic_set_user_id
#define self_get_user_id    amq_content_basic_get_user_id
#define self_set_app_id     amq_content_basic_set_app_id
#define self_get_app_id     amq_content_basic_get_app_id
#define self_set_sender_id  amq_content_basic_set_sender_id
#define self_get_sender_id  amq_content_basic_get_sender_id
#define self_set_headers_field  amq_content_basic_set_headers_field
#define self_wire_put       amq_content_basic_wire_put
#define self_wire_size      amq_content_basic_wire_size
#define self_wire_get       amq_content_basic_wire_get
#define self_wire_pending   amq_content_basic_wire_pending
#define self_chrono_set     amq_content_basic_chrono_set
#define self_chrono_add     amq_content_basic_chrono_add
#define self_chrono_get     amq_content_basic_chrono_get
#define self_selftest       amq_content_basic_selftest
#define self_count          amq_content_basic_count
#define self_terminate      amq_content_basic_terminate
#define self_show           amq_content_basic_show
#define self_destroy        amq_content_basic_destroy
#define self_alloc          amq_content_basic_alloc
#define self_free           amq_content_basic_free
#define self_link           amq_content_basic_link
#define self_unlink         amq_content_basic_unlink
#define self_cache_initialise  amq_content_basic_cache_initialise
#define self_cache_purge    amq_content_basic_cache_purge
#define self_cache_terminate  amq_content_basic_cache_terminate
#define self_show_animation  amq_content_basic_show_animation
#define self_new_in_scope   amq_content_basic_new_in_scope

#define amq_content_basic_annihilate(self)  amq_content_basic_annihilate_ (self, __FILE__, __LINE__)
static void
    amq_content_basic_annihilate_ (
amq_content_basic_t * ( * self_p ),     //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define amq_content_basic_alloc()       amq_content_basic_alloc_ (__FILE__, __LINE__)
static amq_content_basic_t *
    amq_content_basic_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define amq_content_basic_free(self)    amq_content_basic_free_ (self, __FILE__, __LINE__)
static void
    amq_content_basic_free_ (
amq_content_basic_t * self,             //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    amq_content_basic_cache_initialise (
void);

static void
    amq_content_basic_cache_purge (
void);

static void
    amq_content_basic_cache_terminate (
void);

Bool
    amq_content_basic_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_amq_content_basic_count = 0;
/*  -------------------------------------------------------------------------
    amq_content_basic_new

    Type: Component method
    Creates and initialises a new amq_content_basic_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_content_basic_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    amq_content_basic_t *
        self = NULL;                    //  Object reference

    self = amq_content_basic_alloc_ (file, line);
    if (self) {
        self->object_tag   = AMQ_CONTENT_BASIC_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, amq_content_basic_show_);
#endif

icl_atomic_inc32 ((volatile qbyte *) &s_amq_content_basic_count);

self->class_id    = 60;
self->weight      = 0;
self->body_size   = 0;
self->body_expect = 0;
self->body_data   = NULL;
self->immediate   = FALSE;
self->returned    = FALSE;
self->bucket_list = NULL;

strclr (self->exchange);
strclr (self->routing_key);
strclr (self->producer_id);
strclr (self->consumer_tag);
*self->content_type  = 0;
*self->content_encoding  = 0;
self->headers     = NULL;
self->delivery_mode  = 0;
self->priority    = 0;
*self->correlation_id  = 0;
*self->reply_to   = 0;
*self->expiration  = 0;
*self->message_id  = 0;
self->timestamp   = 0;
*self->type       = 0;
*self->user_id    = 0;
*self->app_id     = 0;
*self->sender_id  = 0;
}

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_content_basic_annihilate_ (
    amq_content_basic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    int
        history_last;
#endif

    amq_content_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = file;
    self->history_line  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = line;
    self->history_type  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = self->links;
#endif

    AMQ_CONTENT_BASIC_ASSERT_SANE (self);

icl_atomic_dec32 ((volatile qbyte *) &s_amq_content_basic_count);

ipr_bucket_list_destroy (&self->bucket_list);

icl_longstr_destroy (&self->headers);
if (self->body_data && self->free_fn) {
    (self->free_fn) (self->body_data);
    self->body_data = NULL;
}

}
/*  -------------------------------------------------------------------------
    amq_content_basic_record_header

    Type: Component method
    Records a content header, which must be provided as a bucket of data
    received from the network connection and formatted as an ASL content
    header frame.  The bucket size must not include the frame-end octet.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_record_header (
    amq_content_basic_t * self,         //  Not documented
    ipr_bucket_t * bucket               //  Bucket containing header
)
{
byte
    *data_ptr,                      //  Pointer into buffer data
    *data_limit;                    //  Limit of buffer data
size_t
    string_size;
dbyte
    property_flags = 0;
    int
        rc = 0;                         //  Return code

//
//  Check that frame is correctly terminated before decoding it
assert (bucket);
data_ptr = bucket->data;
data_limit = data_ptr + bucket->cur_size;

GET_SHORT (self->class_id,    data_ptr);
GET_SHORT (self->weight,      data_ptr);
GET_LLONG (self->body_expect, data_ptr);
GET_SHORT (property_flags,    data_ptr);

//  Now get content header property fields that are present
if (property_flags & 1 << 15) {
    GET_SSTR (self->content_type, data_ptr);
}
if (property_flags & 1 << 14) {
    GET_SSTR (self->content_encoding, data_ptr);
}
if (property_flags & 1 << 13) {
    GET_LSTR (self->headers, data_ptr);
}
if (property_flags & 1 << 12) {
    GET_OCTET (self->delivery_mode, data_ptr);
}
if (property_flags & 1 << 11) {
    GET_OCTET (self->priority, data_ptr);
}
if (property_flags & 1 << 10) {
    GET_SSTR (self->correlation_id, data_ptr);
}
if (property_flags & 1 << 9) {
    GET_SSTR (self->reply_to, data_ptr);
}
if (property_flags & 1 << 8) {
    GET_SSTR (self->expiration, data_ptr);
}
if (property_flags & 1 << 7) {
    GET_SSTR (self->message_id, data_ptr);
}
if (property_flags & 1 << 6) {
    GET_LLONG (self->timestamp, data_ptr);
}
if (property_flags & 1 << 5) {
    GET_SSTR (self->type, data_ptr);
}
if (property_flags & 1 << 4) {
    GET_SSTR (self->user_id, data_ptr);
}
if (property_flags & 1 << 3) {
    GET_SSTR (self->app_id, data_ptr);
}
if (property_flags & 1 << 2) {
    GET_SSTR (self->sender_id, data_ptr);
}
goto finished;

underflow:
    icl_console_print ("E: invalid content header");
    rc = -1;
finished:
    //  Return via normal function exit

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_replay_header

    Type: Component method
    Replays the content header, providing a bucket that the caller must
    unlink when finished sending.  For orthogonality with the replay_body
    method, the returned bucket does not contain a frame-end octet and
    the returned bucket cur_size does not account for this octet. The
    supplied bucket data has no frame-end; the caller must add this when
    sending a bucket on the wire.  The frame-end octet, while adding some
    measure of robustness against badly-framed frames, is in itself not
    a construct that leads to highly elegant code.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    amq_content_basic_replay_header (
    amq_content_basic_t * self          //  Reference to content
)
{
size_t
    string_size,
    header_size;
byte
    *data_ptr;
dbyte
    property_flags = 0;
    ipr_bucket_t *
        bucket;                         //  Bucket to hold header

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
//
//  Content header is 14 bytes plus optional properties
header_size = 14;
if (strused (self->content_type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_type);
    property_flags |= 1 << 15;
}
if (strused (self->content_encoding)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_encoding);
    property_flags |= 1 << 14;
}
if (self->headers && self->headers->cur_size) {
    header_size += ASL_LSTR_HSIZE + self->headers->cur_size;
    property_flags |= 1 << 13;
}
if (self->delivery_mode) {
    header_size += 1;
    property_flags |= 1 << 12;
}
if (self->priority) {
    header_size += 1;
    property_flags |= 1 << 11;
}
if (strused (self->correlation_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->correlation_id);
    property_flags |= 1 << 10;
}
if (strused (self->reply_to)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->reply_to);
    property_flags |= 1 << 9;
}
if (strused (self->expiration)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->expiration);
    property_flags |= 1 << 8;
}
if (strused (self->message_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->message_id);
    property_flags |= 1 << 7;
}
if (self->timestamp) {
    header_size += 8;
    property_flags |= 1 << 6;
}
if (strused (self->type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->type);
    property_flags |= 1 << 5;
}
if (strused (self->user_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->user_id);
    property_flags |= 1 << 4;
}
if (strused (self->app_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->app_id);
    property_flags |= 1 << 3;
}
if (strused (self->sender_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->sender_id);
    property_flags |= 1 << 2;
}
bucket = ipr_bucket_new (header_size);
bucket->cur_size = header_size;
data_ptr = bucket->data;
self->weight = 0;

PUT_SHORT (data_ptr, self->class_id);
PUT_SHORT (data_ptr, self->weight);
PUT_LLONG (data_ptr, self->body_size);
PUT_SHORT (data_ptr, property_flags);

//  Now put content header property fields that are present
if (strused (self->content_type))
    PUT_SSTR (data_ptr, self->content_type);
if (strused (self->content_encoding))
    PUT_SSTR (data_ptr, self->content_encoding);
if (self->headers && self->headers->cur_size)
    PUT_TABLE (data_ptr, self->headers);
if (self->delivery_mode)
    PUT_OCTET (data_ptr, self->delivery_mode);
if (self->priority)
    PUT_OCTET (data_ptr, self->priority);
if (strused (self->correlation_id))
    PUT_SSTR (data_ptr, self->correlation_id);
if (strused (self->reply_to))
    PUT_SSTR (data_ptr, self->reply_to);
if (strused (self->expiration))
    PUT_SSTR (data_ptr, self->expiration);
if (strused (self->message_id))
    PUT_SSTR (data_ptr, self->message_id);
if (self->timestamp)
    PUT_LLONG (data_ptr, self->timestamp);
if (strused (self->type))
    PUT_SSTR (data_ptr, self->type);
if (strused (self->user_id))
    PUT_SSTR (data_ptr, self->user_id);
if (strused (self->app_id))
    PUT_SSTR (data_ptr, self->app_id);
if (strused (self->sender_id))
    PUT_SSTR (data_ptr, self->sender_id);
if ((size_t) (data_ptr - bucket->data) != header_size) {
    icl_console_print ("E: internal error, processed=%d expected=%d",
    (size_t) (data_ptr - bucket->data), header_size);
    assert ((size_t) (data_ptr - bucket->data) == header_size);
}

    return (bucket);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_record_body

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Records a content body, which is a bucket of binary data.  Use this
    method to set the content body to a block of data coming from the
    network, from a file, or from a pipe.  The bucket must not contain
    any frame control data, (i.e. no frame-end octet).  The caller can
    unlink the bucket after this method, which takes possession of it.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_record_body (
    amq_content_basic_t * self,         //  Reference to object
    ipr_bucket_t * bucket               //  Bucket of raw data
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
if (self->body_data) {
    if (self->free_fn)
        (self->free_fn) (self->body_data);
    else
        self->body_data = NULL;
    self->body_size = 0;
}
if (!self->bucket_list)
    self->bucket_list = ipr_bucket_list_new ();
ipr_bucket_list_queue (self->bucket_list, bucket);
self->body_size += bucket->cur_size;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_reader

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Initialises a new reader. The caller should provide a reader structure
    in thread-safe memory, e.g. on the stack.  We use readers to replay a
    content body into buckets - the reader stores all context needed to
    correctly split and reform the content body into buckets of the desired
    size.  Use the set_reader method to initialise a reader, and then the
    replay_body method to replay buckets of body until there are none left.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_reader (
    amq_content_basic_t * self,         //  Reference to object
    asl_reader_t * reader,              //  Reader to initialise
    size_t frame_max                    //  Maximum frame size
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
//
assert (frame_max >= ASL_FRAME_MIN_SIZE);
memset (reader, 0, sizeof (*reader));
if (self->body_data)
    ;
else
if (self->bucket_list)
    reader->iterator = ipr_bucket_list_first (self->bucket_list);

reader->frame_max = frame_max;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_replay_body

    Type: Component method
    Provides a bucket holding the first frame of body data for the
    content.  If the content had no (more) body, returns a null. The
    caller supplies an initialised reader structure.  Call this method
    in a loop with the same reader structure until the method returns
    a null bucket.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    amq_content_basic_replay_body (
    amq_content_basic_t * self,         //  Reference to content
    asl_reader_t * reader               //  Reader to use
)
{
    ipr_bucket_t *
        bucket = NULL;                  //  Not documented

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
//
if (self->body_data) {
    size_t
        remainder;                  //  Amount of data remaining

    //  Check if there's any body data remaining
    remainder = (size_t) self->body_size - reader->processed;
    if (remainder > 0) {
        bucket = ipr_bucket_new (0);
        bucket->cur_size = min (reader->frame_max, remainder);
        bucket->data     = self->body_data + reader->processed;
        reader->processed += bucket->cur_size;
        reader->count++;
        //  Sanity check
        assert (reader->count < 999999);
    }
}
else {
    while (reader->iterator) {
        ipr_bucket_t
            *from_bucket;           //  Bucket we copy from
        size_t
            remainder;              //  Amount of data remaining

        from_bucket = reader->iterator->item;
        assert (from_bucket);

        //  Check if there's any bucket data remaining
        remainder = (size_t) from_bucket->cur_size - reader->processed;
        if (remainder > 0) {
            bucket = ipr_bucket_new (0);
            bucket->cur_size = min (reader->frame_max, remainder);
            bucket->data     = from_bucket->data + reader->processed;
            reader->processed += bucket->cur_size;
            reader->count++;
            //  Sanity check
            assert (reader->count < 999999);
            break;                  //  We have a bucket of data
        }
        else {
            //  Get next source bucket, until list ends
            reader->iterator  = ipr_bucket_list_next (&reader->iterator);
            reader->processed = 0;
        }
    }
}

    return (bucket);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_body

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the content body to a specified memory address.  The contents
    of the memory block are not copied.  You can specify a function (free()
    or an equivalent) to free the memory block when the message is
    destroyed.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_body (
    amq_content_basic_t * self,         //  Reference to object
    void * data,                        //  Data for message content
    size_t size,                        //  Length of message content
    icl_mem_free_fn * free_fn           //  Function to free the memory
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Free existing content if any
if (self->bucket_list)
    ipr_bucket_list_clear (self->bucket_list);
if (self->body_data && self->free_fn)
    (self->free_fn) (self->body_data);

//  Now point to provided body
self->body_data = data;
self->body_size = size;
self->free_fn   = free_fn;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_body

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Copies the content body to the application into a buffer provided by the
    application.  If the content was larger than the buffer limit, returns -1,
    else returns the number of content octets copied.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_get_body (
    amq_content_basic_t * self,         //  Reference to object
    byte * buffer,                      //  Buffer for message content
    size_t maxsize                      //  Maximum size of buffer
)
{
ipr_bucket_list_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
//
if (self->body_size <= maxsize) {
    if (self->body_data) {
        memcpy (buffer, self->body_data, (size_t) self->body_size);
        rc = (int) self->body_size;
    }
    else
    if (self->bucket_list) {
        iterator = ipr_bucket_list_first (self->bucket_list);
        while (iterator) {
            memcpy (buffer + rc, iterator->item->data, iterator->item->cur_size);
            rc += iterator->item->cur_size;
            iterator = ipr_bucket_list_next (&iterator);
        }
    }
}
else
    rc = -1;                        //  Buffer too small
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_save_body

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Writes the content body to a file as specified by the caller. No header
    properties are saved.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_save_body (
    amq_content_basic_t * self,         //  Reference to object
    char * filename                     //  File to save to
)
{
FILE
    *file_stream = NULL;
ipr_bucket_list_iter_t *
    iterator;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//

//
assert (filename);
file_stream = fopen (filename, "wb");

if (self->body_data)
    assert (fwrite (self->body_data, (size_t) self->body_size, 1, file_stream) == 1);
else {
    iterator = ipr_bucket_list_first (self->bucket_list);
    while (iterator) {
        assert (fwrite (iterator->item->data, (size_t) iterator->item->cur_size, 1,
            file_stream) == 1);
        iterator = ipr_bucket_list_next (&iterator);
    }
}
fclose (file_stream);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_routing_key

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Set the routing properties for the content. This is an internal
    method that stamps a content with the root exchange and routing key
    used for routing within the server. Calling this method from an
    application has no effect.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_routing_key (
    amq_content_basic_t * self,         //  Reference to object
    char * exchange,                    //  Root exchange
    char * routing_key,                 //  Routing key
    char * producer_id                  //  Producer connection id
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
icl_shortstr_cpy (self->exchange,    exchange);
icl_shortstr_cpy (self->routing_key, routing_key);
icl_shortstr_cpy (self->producer_id, producer_id);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_class_id

    Type: Component method
    -------------------------------------------------------------------------
 */

dbyte
    amq_content_basic_get_class_id (
    amq_content_basic_t * self          //  Object reference
)
{
    dbyte
        class_id;                       //  Not documented

//
class_id = self->class_id;

    return (class_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_weight

    Type: Component method
    -------------------------------------------------------------------------
 */

dbyte
    amq_content_basic_get_weight (
    amq_content_basic_t * self          //  Object reference
)
{
    dbyte
        weight;                         //  Not documented

//
weight = self->weight;

    return (weight);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_body_size

    Type: Component method
    -------------------------------------------------------------------------
 */

int64_t
    amq_content_basic_get_body_size (
    amq_content_basic_t * self          //  Object reference
)
{
    int64_t
        body_size;                      //  Not documented

//
body_size = self->body_size;

    return (body_size);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_exchange

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_exchange (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        exchange;                       //  Not documented

//
exchange = self->exchange;

    return (exchange);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_routing_key

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_routing_key (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        routing_key;                    //  Not documented

//
routing_key = self->routing_key;

    return (routing_key);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_producer_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_producer_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        producer_id;                    //  Not documented

//
producer_id = self->producer_id;

    return (producer_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_content_type

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_content_type (
    amq_content_basic_t * self,         //  Reference to object
    char * content_type,                //  MIME content type
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, content_type);
    _rc = amq_content_basic_set_content_type_v (self, content_type, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_content_type_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_content_type_v (
    amq_content_basic_t * self,         //  Reference to object
    char * content_type,                //  MIME content type
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->content_type, ICL_SHORTSTR_MAX, content_type, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_content_type

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_content_type (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        content_type;                   //  Not documented

//
content_type = self->content_type;

    return (content_type);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_content_encoding

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_content_encoding (
    amq_content_basic_t * self,         //  Reference to object
    char * content_encoding,            //  MIME content encoding
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, content_encoding);
    _rc = amq_content_basic_set_content_encoding_v (self, content_encoding, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_content_encoding_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_content_encoding_v (
    amq_content_basic_t * self,         //  Reference to object
    char * content_encoding,            //  MIME content encoding
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->content_encoding, ICL_SHORTSTR_MAX, content_encoding, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_content_encoding

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_content_encoding (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        content_encoding;               //  Not documented

//
content_encoding = self->content_encoding;

    return (content_encoding);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_headers

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_headers (
    amq_content_basic_t * self,         //  Reference to object
    icl_longstr_t * headers             //  Message header field table
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
icl_longstr_destroy (&self->headers);
if (headers)
    self->headers = icl_longstr_dup (headers);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_headers

    Type: Component method
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    amq_content_basic_get_headers (
    amq_content_basic_t * self          //  Object reference
)
{
    icl_longstr_t *
        headers;                        //  Not documented

//
headers = self->headers;

    return (headers);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_delivery_mode

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_delivery_mode (
    amq_content_basic_t * self,         //  Reference to object
    int delivery_mode                   //  Non-persistent (1) or persistent (2)
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
self->delivery_mode = (byte) delivery_mode;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_delivery_mode

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_get_delivery_mode (
    amq_content_basic_t * self          //  Object reference
)
{
    int
        delivery_mode;                  //  Not documented

//
delivery_mode = self->delivery_mode;

    return (delivery_mode);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_priority

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_priority (
    amq_content_basic_t * self,         //  Reference to object
    int priority                        //  The message priority, 0 to 9
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
self->priority = (byte) priority;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_priority

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_get_priority (
    amq_content_basic_t * self          //  Object reference
)
{
    int
        priority;                       //  Not documented

//
priority = self->priority;

    return (priority);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_correlation_id

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_correlation_id (
    amq_content_basic_t * self,         //  Reference to object
    char * correlation_id,              //  The application correlation identifier
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, correlation_id);
    _rc = amq_content_basic_set_correlation_id_v (self, correlation_id, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_correlation_id_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_correlation_id_v (
    amq_content_basic_t * self,         //  Reference to object
    char * correlation_id,              //  The application correlation identifier
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->correlation_id, ICL_SHORTSTR_MAX, correlation_id, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_correlation_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_correlation_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        correlation_id;                 //  Not documented

//
correlation_id = self->correlation_id;

    return (correlation_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_reply_to

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_reply_to (
    amq_content_basic_t * self,         //  Reference to object
    char * reply_to,                    //  The destination to reply to
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, reply_to);
    _rc = amq_content_basic_set_reply_to_v (self, reply_to, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_reply_to_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_reply_to_v (
    amq_content_basic_t * self,         //  Reference to object
    char * reply_to,                    //  The destination to reply to
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->reply_to, ICL_SHORTSTR_MAX, reply_to, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_reply_to

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_reply_to (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        reply_to;                       //  Not documented

//
reply_to = self->reply_to;

    return (reply_to);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_expiration

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_expiration (
    amq_content_basic_t * self,         //  Reference to object
    char * expiration,                  //  Message expiration specification
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, expiration);
    _rc = amq_content_basic_set_expiration_v (self, expiration, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_expiration_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_expiration_v (
    amq_content_basic_t * self,         //  Reference to object
    char * expiration,                  //  Message expiration specification
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->expiration, ICL_SHORTSTR_MAX, expiration, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_expiration

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_expiration (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        expiration;                     //  Not documented

//
expiration = self->expiration;

    return (expiration);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_message_id

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_message_id (
    amq_content_basic_t * self,         //  Reference to object
    char * message_id,                  //  The application message identifier
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, message_id);
    _rc = amq_content_basic_set_message_id_v (self, message_id, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_message_id_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_message_id_v (
    amq_content_basic_t * self,         //  Reference to object
    char * message_id,                  //  The application message identifier
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->message_id, ICL_SHORTSTR_MAX, message_id, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_message_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_message_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        message_id;                     //  Not documented

//
message_id = self->message_id;

    return (message_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_timestamp

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_timestamp (
    amq_content_basic_t * self,         //  Reference to object
    int64_t timestamp                   //  The message timestamp
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
self->timestamp = timestamp;
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_timestamp

    Type: Component method
    -------------------------------------------------------------------------
 */

int64_t
    amq_content_basic_get_timestamp (
    amq_content_basic_t * self          //  Object reference
)
{
    int64_t
        timestamp;                      //  Not documented

//
timestamp = self->timestamp;

    return (timestamp);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_type

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_type (
    amq_content_basic_t * self,         //  Reference to object
    char * type,                        //  The message type name
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, type);
    _rc = amq_content_basic_set_type_v (self, type, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_type_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_type_v (
    amq_content_basic_t * self,         //  Reference to object
    char * type,                        //  The message type name
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->type, ICL_SHORTSTR_MAX, type, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_type

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_type (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        type;                           //  Not documented

//
type = self->type;

    return (type);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_user_id

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_user_id (
    amq_content_basic_t * self,         //  Reference to object
    char * user_id,                     //  The creating user id
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, user_id);
    _rc = amq_content_basic_set_user_id_v (self, user_id, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_user_id_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_user_id_v (
    amq_content_basic_t * self,         //  Reference to object
    char * user_id,                     //  The creating user id
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->user_id, ICL_SHORTSTR_MAX, user_id, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_user_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_user_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        user_id;                        //  Not documented

//
user_id = self->user_id;

    return (user_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_app_id

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_app_id (
    amq_content_basic_t * self,         //  Reference to object
    char * app_id,                      //  The creating application id
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, app_id);
    _rc = amq_content_basic_set_app_id_v (self, app_id, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_app_id_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_app_id_v (
    amq_content_basic_t * self,         //  Reference to object
    char * app_id,                      //  The creating application id
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->app_id, ICL_SHORTSTR_MAX, app_id, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_app_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_app_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        app_id;                         //  Not documented

//
app_id = self->app_id;

    return (app_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_sender_id

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_sender_id (
    amq_content_basic_t * self,         //  Reference to object
    char * sender_id,                   //  Identifier of connection sending the message
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, sender_id);
    _rc = amq_content_basic_set_sender_id_v (self, sender_id, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_sender_id_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_sender_id_v (
    amq_content_basic_t * self,         //  Reference to object
    char * sender_id,                   //  Identifier of connection sending the message
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (self->sender_id, ICL_SHORTSTR_MAX, sender_id, args);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_get_sender_id

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    amq_content_basic_get_sender_id (
    amq_content_basic_t * self          //  Object reference
)
{
    char *
        sender_id;                      //  Not documented

//
sender_id = self->sender_id;

    return (sender_id);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_headers_field

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_headers_field (
    amq_content_basic_t * self,         //  Reference to object
    char * name,                        //  Field name
    char * value,                       //  Field value
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, value);
    _rc = amq_content_basic_set_headers_field_v (self, name, value, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_set_headers_field_v

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_set_headers_field_v (
    amq_content_basic_t * self,         //  Reference to object
    char * name,                        //  Field name
    char * value,                       //  Field value
va_list args                            //  Variable arguments
)
{
    asl_field_list_t
    *field_list;
icl_longstr_t
    *field_table;
icl_shortstr_t
    field_value;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
apr_vsnprintf (field_value, ICL_SHORTSTR_MAX, value, args);

field_list = asl_field_list_new (self->headers);
asl_field_assume (field_list, name, field_value);
field_table = asl_field_list_flatten (field_list);
asl_field_list_destroy (&field_list);
self_set_headers (self, field_table);
icl_longstr_destroy (&field_table);
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_wire_put

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Puts the content into a bucket provided by the user.  Returns -1 if the
    bucket was too small, zero if the content was successfully serialized.
    Wire data is formatted using X-DMP@wiki.amqp.org specifications.
    Content body is limited to 16M in size.

    [nnnn]                  full encoded size
    [n][exchange]           exchange name
    [n][routing key]        routing key
    [ff][property...]       header flags + properties
    [n]                     options octet
    [nnn][body]             content body
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_wire_put (
    amq_content_basic_t * self,         //  Reference to object
    ipr_bucket_t * bucket,              //  Bucket to fill
    byte options                        //  Options octet
)
{
byte
    *size_ptr,                      //  Offset where we stick chunk size
    *data_ptr;                      //  Current offset writing into data
size_t
    string_size,
    header_size,
    chunk_size;
dbyte
    property_flags = 0;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
//  We need sufficient space left in the bucket
if (bucket->max_size - bucket->cur_size >= amq_content_basic_wire_size (self)) {
    //  Allow four octets at start for encoded size
    size_ptr = bucket->data + bucket->cur_size;
    data_ptr = size_ptr + 4;

    //  Store exchange and routing key
    PUT_SSTR (data_ptr, self->exchange);
    PUT_SSTR (data_ptr, self->routing_key);

    //  Store [property flags] as 2 octets
    header_size = 0;
if (strused (self->content_type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_type);
    property_flags |= 1 << 15;
}
if (strused (self->content_encoding)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_encoding);
    property_flags |= 1 << 14;
}
if (self->headers && self->headers->cur_size) {
    header_size += ASL_LSTR_HSIZE + self->headers->cur_size;
    property_flags |= 1 << 13;
}
if (self->delivery_mode) {
    header_size += 1;
    property_flags |= 1 << 12;
}
if (self->priority) {
    header_size += 1;
    property_flags |= 1 << 11;
}
if (strused (self->correlation_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->correlation_id);
    property_flags |= 1 << 10;
}
if (strused (self->reply_to)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->reply_to);
    property_flags |= 1 << 9;
}
if (strused (self->expiration)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->expiration);
    property_flags |= 1 << 8;
}
if (strused (self->message_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->message_id);
    property_flags |= 1 << 7;
}
if (self->timestamp) {
    header_size += 8;
    property_flags |= 1 << 6;
}
if (strused (self->type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->type);
    property_flags |= 1 << 5;
}
if (strused (self->user_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->user_id);
    property_flags |= 1 << 4;
}
if (strused (self->app_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->app_id);
    property_flags |= 1 << 3;
}
if (strused (self->sender_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->sender_id);
    property_flags |= 1 << 2;
}
    PUT_SHORT (data_ptr, property_flags);
if (strused (self->content_type))
    PUT_SSTR (data_ptr, self->content_type);
if (strused (self->content_encoding))
    PUT_SSTR (data_ptr, self->content_encoding);
if (self->headers && self->headers->cur_size)
    PUT_TABLE (data_ptr, self->headers);
if (self->delivery_mode)
    PUT_OCTET (data_ptr, self->delivery_mode);
if (self->priority)
    PUT_OCTET (data_ptr, self->priority);
if (strused (self->correlation_id))
    PUT_SSTR (data_ptr, self->correlation_id);
if (strused (self->reply_to))
    PUT_SSTR (data_ptr, self->reply_to);
if (strused (self->expiration))
    PUT_SSTR (data_ptr, self->expiration);
if (strused (self->message_id))
    PUT_SSTR (data_ptr, self->message_id);
if (self->timestamp)
    PUT_LLONG (data_ptr, self->timestamp);
if (strused (self->type))
    PUT_SSTR (data_ptr, self->type);
if (strused (self->user_id))
    PUT_SSTR (data_ptr, self->user_id);
if (strused (self->app_id))
    PUT_SSTR (data_ptr, self->app_id);
if (strused (self->sender_id))
    PUT_SSTR (data_ptr, self->sender_id);

    //  Store options octet
    PUT_OCTET (data_ptr, options);

    //  Store 3-byte length and then content body
    data_ptr [0] = (byte) ((self->body_size >> 16) & 255);
    data_ptr [1] = (byte) ((self->body_size >> 8)  & 255);
    data_ptr [2] = (byte) ((self->body_size)       & 255);
    data_ptr += 3;
    amq_content_basic_get_body (self, data_ptr, (size_t) self->body_size);
    data_ptr += self->body_size;

    bucket->cur_size = data_ptr - bucket->data;

    chunk_size = data_ptr - size_ptr - 4;
    assert (chunk_size >= 12);
    PUT_LONG (size_ptr, chunk_size);
    assert (bucket->cur_size <= bucket->max_size);
}
else
    rc = -1;                        //  Sorry, we're full
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_wire_size

    Type: Component method
    Returns the size of the serialized content.
    -------------------------------------------------------------------------
 */

size_t
    amq_content_basic_wire_size (
    amq_content_basic_t * self          //  Not documented
)
{
dbyte
    property_flags = 0;
size_t
    header_size = 0;
    size_t
        rc;                             //  Not documented

//
header_size = 0;
if (strused (self->content_type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_type);
    property_flags |= 1 << 15;
}
if (strused (self->content_encoding)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->content_encoding);
    property_flags |= 1 << 14;
}
if (self->headers && self->headers->cur_size) {
    header_size += ASL_LSTR_HSIZE + self->headers->cur_size;
    property_flags |= 1 << 13;
}
if (self->delivery_mode) {
    header_size += 1;
    property_flags |= 1 << 12;
}
if (self->priority) {
    header_size += 1;
    property_flags |= 1 << 11;
}
if (strused (self->correlation_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->correlation_id);
    property_flags |= 1 << 10;
}
if (strused (self->reply_to)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->reply_to);
    property_flags |= 1 << 9;
}
if (strused (self->expiration)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->expiration);
    property_flags |= 1 << 8;
}
if (strused (self->message_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->message_id);
    property_flags |= 1 << 7;
}
if (self->timestamp) {
    header_size += 8;
    property_flags |= 1 << 6;
}
if (strused (self->type)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->type);
    property_flags |= 1 << 5;
}
if (strused (self->user_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->user_id);
    property_flags |= 1 << 4;
}
if (strused (self->app_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->app_id);
    property_flags |= 1 << 3;
}
if (strused (self->sender_id)) {
    header_size += ASL_SSTR_HSIZE + strlen (self->sender_id);
    property_flags |= 1 << 2;
}
rc = 12
    + strlen (self->exchange)
    + strlen (self->routing_key)
    + header_size
    + (size_t) self->body_size;

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_wire_get

    Type: Component method
    Gets a content from a bucket provided by the user.  Returns NULL if the
    bucket did not contain sufficient data, or a content was unsuccessfully
    de-serialized. Wire data is formatted using 6-DMP@wiki.amqp.org specs.
    Skips heartbeat frames (null contents) transparently.  If the options
    argument is not null, puts the options octet in that byte.
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_content_basic_wire_get (
    ipr_bucket_t * bucket,              //  Not documented
    size_t * offset,                    //  Starting, ending offset in bucket
    byte * options_p                    //  Options octet address
)
{
byte
    *body,                          //  Allocated content body blob
    *data_ptr;
uint
    size;
byte
    *data_limit;                    //  Limit of buffer data
size_t
    chunk_size = 0,
    string_size;
dbyte
    property_flags = 0;
byte
    options;
    amq_content_basic_t *
        content = NULL;                 //  New content

//
data_ptr = bucket->data + *offset;
data_limit = bucket->data + bucket->cur_size;
//  Get a non-zero chunk size - zero means heartbeat
while (chunk_size == 0)
    GET_LONG (chunk_size, data_ptr);
data_limit = data_ptr + chunk_size;

//  Guard against malformed data
if (data_limit > bucket->data + bucket->cur_size) {
    icl_console_print ("E: malformed Direct Mode data - chunk-size=%d at %d",
        chunk_size, (int) (data_ptr - bucket->data));
    ipr_bucket_dump (bucket, "");
    //  For now, we assert and die, should just reject the data
    assert (data_limit <= bucket->data + bucket->cur_size);
}
content = amq_content_basic_new ();
assert (content);
//  Get exchange and routing key
GET_SSTR (content->exchange, data_ptr);
GET_SSTR (content->routing_key, data_ptr);

//  Now get content header property fields that are present
GET_SHORT (property_flags, data_ptr);
if (property_flags & 1 << 15) {
    GET_SSTR (content->content_type, data_ptr);
}
if (property_flags & 1 << 14) {
    GET_SSTR (content->content_encoding, data_ptr);
}
if (property_flags & 1 << 13) {
    GET_LSTR (content->headers, data_ptr);
}
if (property_flags & 1 << 12) {
    GET_OCTET (content->delivery_mode, data_ptr);
}
if (property_flags & 1 << 11) {
    GET_OCTET (content->priority, data_ptr);
}
if (property_flags & 1 << 10) {
    GET_SSTR (content->correlation_id, data_ptr);
}
if (property_flags & 1 << 9) {
    GET_SSTR (content->reply_to, data_ptr);
}
if (property_flags & 1 << 8) {
    GET_SSTR (content->expiration, data_ptr);
}
if (property_flags & 1 << 7) {
    GET_SSTR (content->message_id, data_ptr);
}
if (property_flags & 1 << 6) {
    GET_LLONG (content->timestamp, data_ptr);
}
if (property_flags & 1 << 5) {
    GET_SSTR (content->type, data_ptr);
}
if (property_flags & 1 << 4) {
    GET_SSTR (content->user_id, data_ptr);
}
if (property_flags & 1 << 3) {
    GET_SSTR (content->app_id, data_ptr);
}
if (property_flags & 1 << 2) {
    GET_SSTR (content->sender_id, data_ptr);
}

//  Get options octet and return to caller
GET_OCTET (options, data_ptr);
if (options_p)
    *options_p = options;

//  Get 3-byte size and point to body
if (data_ptr + 3 > data_limit)
    goto underflow;
size = (data_ptr [0] << 16) + (data_ptr [1] << 8) + data_ptr [2];
data_ptr += 3;
//  Size must be equal to or less than remaining data
if (size > (uint) (data_limit - data_ptr))
    goto underflow;

body = icl_mem_alloc (size);
memcpy (body, data_ptr, size);
amq_content_basic_set_body (content, body, size, icl_mem_free);
data_ptr += size;

*offset = data_ptr - bucket->data;
goto finished;
underflow:
    amq_content_basic_unlink (&content);
finished:
    //  Return via normal function exit

    return (content);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_wire_pending

    Type: Component method
    Checks whether the supplied bucket holds a complete set of contents or not.
    If complete, returns 0.  Otherwise returns the number of octets that needs to
    be read in order to complete the bucket.  Data should be read into the bucket
    at bucket->cur_size.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_wire_pending (
    ipr_bucket_t * bucket               //  Not documented
)
{
byte
    *data_ptr;
byte
    *data_limit;                    //  Limit of buffer data
size_t
    chunk_size;
    int
        rc;                             //  Pending octets

data_ptr   = bucket->data;
data_limit = bucket->data + bucket->cur_size;
while (TRUE) {
    GET_LONG (chunk_size, data_ptr);
    data_ptr += chunk_size;
    if (data_ptr > data_limit) {
        rc = data_ptr - data_limit;
        goto finished;
    }
    else
    if (data_ptr == data_limit) {
        rc = 0;                 //  Finished on target
        goto finished;
    }
}
underflow:
    //  We get here if we could not get 4 bytes for a header
    rc = 4 - (data_limit - data_ptr);
    assert (rc > 0);
finished:
    //  Return via normal function exit

    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_chrono_set

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the content chronometer, a way of tracking the time spent
    processing contents through an architecture.  The chronometer records
    a series of timestamps and calculates the differences between these as
    a list of deltas, in milliseconds.  To use the chronometer, call the
    chrono_set() method on a new content, then call chrono_add() at each
    measuring point, and finally chrono_get() to return the list of deltas.
    The chronometer uses the correlation-id field (which is not very clean
    but simple and fast).
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_chrono_set (
    amq_content_basic_t * self          //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

#   define CHRONO_MARKER "Chrono-"
    //
    //  Reset the chronometer with the current time
    snprintf (self->correlation_id, ICL_SHORTSTR_MAX,
        CHRONO_MARKER "%llx", (long long unsigned int) apr_time_now ());
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_chrono_add

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Appends a delta to the chronometer, if the field has been properly set.
    If the field was not set, does nothing.  Always measures the delta from
    the initial start time so there is no accumulated rounding error.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_chrono_add (
    amq_content_basic_t * self          //  Reference to object
)
{
apr_time_t
    start_time;
int
    msecs;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
if (ipr_str_prefixed (self->correlation_id, CHRONO_MARKER)) {
    start_time = (apr_time_t) (strtoull (self->correlation_id + strlen (CHRONO_MARKER), NULL, 16));
    //  APR times are in usec, we chop down to msec to save bytes
    //  If the delta is above 60 seconds, it's stored as infinity
    msecs = (int) ((apr_time_now () - start_time) / 1000);
    if (msecs > 60000)
        msecs = 0xffff;
    icl_shortstr_fmt (self->correlation_id + strlen (self->correlation_id), " %x", msecs);
}
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_chrono_get

    Type: Component method
    Accepts a amq_content_basic_t reference and returns zero in case of success,
    1 in case of errors.
    Copies, into the provided short string, the list of deltas collected by
    the chronometer for the current content.  If the chronometer was not
    initialized, empties the provided string.  The deltas are formatted as
    decimal millisecond values, separated by spaces.  If the floor is not
    zero, measurements that are below the floor will be discarded.
    -------------------------------------------------------------------------
 */

int
    amq_content_basic_chrono_get (
    amq_content_basic_t * self,         //  Reference to object
    char * deltas,                      //  Holds deltas
    int floor                           //  Only if final delta GE this
)
{
apr_time_t
    start_time;
char
    *chrono_ptr,
    *delim = "";
int
    previous = 0,
    msecs = 0;
    int
        rc = 0;                         //  Return code

AMQ_CONTENT_BASIC_ASSERT_SANE (self);
if (!self->zombie) {

//
strclr (deltas);
chrono_ptr = self->correlation_id;
if (ipr_str_prefixed (self->correlation_id, CHRONO_MARKER)) {
    chrono_ptr += strlen (CHRONO_MARKER);
    start_time = (apr_time_t) (strtoull (chrono_ptr, &chrono_ptr, 16));
    while (*chrono_ptr) {
        assert (strlen (deltas) < ICL_SHORTSTR_MAX);
        msecs = strtoul (chrono_ptr, &chrono_ptr, 16);
        if (msecs >= 0xffff)
            msecs = 0;              //  Ignore/truncate overflows

        icl_shortstr_fmt (deltas + strlen (deltas),
            "%s%d", delim, max (msecs - previous, 0));
        delim = " ";
        previous = msecs;
    }
    //  Discard deltas if last figure was less than the floor
    if (msecs < floor)
        strclr (deltas);
}
}
else
    rc = -1;                        //  Return error on zombie object.


    return (rc);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_selftest (
void)
{
amq_content_basic_t
    *content;
icl_longstr_t
    *longstr;
ipr_bucket_t
    *bucket,
    *header,
    *body;
byte
    *test_data,                     //  Test data
    *test_copy;                     //  Copy of test data
size_t
    processed;                      //  Amount of data processed
asl_reader_t
    reader;                         //  Body reader
int
    test_size,                      //  Test data size
    times,
    count;                          //  Test counter
size_t
    offset;                         //  Serialization offset
icl_shortstr_t
    deltas;                         //  Chronometer deltas
byte
    options;

#   define TEST_CHUNK       16000
#   define TEST_DATA_SIZE   TEST_CHUNK*10+1    //  11 buckets

    //  Test 1
    //      - construct content explicitly from body and properties
    //      - replay into header and body buckets
    //
    content = amq_content_basic_new ();
    longstr = icl_longstr_new ("abc", TEST_CHUNK);

    amq_content_basic_set_body (content, "abc", TEST_CHUNK, NULL);
    amq_content_basic_set_content_type (content, "abc");
    amq_content_basic_set_content_encoding (content, "abc");
    amq_content_basic_set_headers (content, longstr);
    amq_content_basic_set_delivery_mode (content, 123);
    amq_content_basic_set_priority (content, 123);
    amq_content_basic_set_correlation_id (content, "abc");
    amq_content_basic_set_reply_to (content, "abc");
    amq_content_basic_set_expiration (content, "abc");
    amq_content_basic_set_message_id (content, "abc");
    amq_content_basic_set_timestamp (content, 123456789L);
    amq_content_basic_set_type (content, "abc");
    amq_content_basic_set_user_id (content, "abc");
    amq_content_basic_set_app_id (content, "abc");
    amq_content_basic_set_sender_id (content, "abc");
    icl_longstr_destroy (&longstr);

    //  We replay the content into a series of buckets
    //  A small content comes out as two buckets - header and body
    //
    amq_content_basic_set_reader (content, &reader, TEST_CHUNK);
    header = amq_content_basic_replay_header (content);
    body   = amq_content_basic_replay_body (content, &reader);
    assert (header);
    assert (body);
    //  Let try it a couple more times...
    assert (amq_content_basic_replay_body (content, &reader) == NULL);
    assert (amq_content_basic_replay_body (content, &reader) == NULL);
    amq_content_basic_unlink (&content);

    //  Test 2
    //      - construct content using header and body buckets
    //      - check that properties are correctly set
    //
    content = amq_content_basic_new ();
    amq_content_basic_record_header (content, header);
    amq_content_basic_record_body  (content, body);
    assert (streq (content->content_type, "abc"));
    assert (streq (content->content_encoding, "abc"));
    assert (content->headers);
    assert (content->headers->cur_size == TEST_CHUNK);
    assert (content->delivery_mode == 123);
    assert (content->priority == 123);
    assert (streq (content->correlation_id, "abc"));
    assert (streq (content->reply_to, "abc"));
    assert (streq (content->expiration, "abc"));
    assert (streq (content->message_id, "abc"));
    assert (content->timestamp == 123456789L);
    assert (streq (content->type, "abc"));
    assert (streq (content->user_id, "abc"));
    assert (streq (content->app_id, "abc"));
    assert (streq (content->sender_id, "abc"));
    amq_content_basic_unlink (&content);

    //  Test 3
    //      - record/replay body of several buckets
    //      - check we can record the same bucket many times
    //
    content = amq_content_basic_new ();
    amq_content_basic_record_header (content, header);
    for (count = 0; count < 10; count++)
        amq_content_basic_record_body (content, body);
    ipr_bucket_unlink (&header);
    ipr_bucket_unlink (&body);

    amq_content_basic_set_reader (content, &reader, TEST_CHUNK);
    while ((body = amq_content_basic_replay_body (content, &reader)))
        ipr_bucket_unlink (&body);
    assert (reader.count == 10);

    //  Test 4
    //      - replay body into smaller buckets
    //
    amq_content_basic_set_reader (content, &reader, TEST_CHUNK / 2);
    while ((body = amq_content_basic_replay_body (content, &reader)))
        ipr_bucket_unlink (&body);
    assert (reader.count == 20);
    amq_content_basic_unlink (&content);

    //  Test 5
    //      - set large content body and replay as buckets
    //      - write the body to a file
    //
    test_data = icl_mem_alloc (TEST_DATA_SIZE);
    memset (test_data, 0xAA, TEST_DATA_SIZE);

    content = amq_content_basic_new ();
    amq_content_basic_set_body (content, test_data, TEST_DATA_SIZE, icl_mem_free);
    amq_content_basic_set_reader (content, &reader, TEST_CHUNK);
    while ((body = amq_content_basic_replay_body (content, &reader)))
        ipr_bucket_unlink (&body);
    assert (reader.count == 11);
    amq_content_basic_save_body (content, "amq_content_basic.tst");
    assert (ipr_file_exists ("amq_content_basic.tst"));
    assert (ipr_file_size   ("amq_content_basic.tst") == content->body_size);
    ipr_file_delete ("amq_content_basic.tst");
    amq_content_basic_unlink (&content);

    //  Test 6
    //      - coalesce content into single large buffer
    //      - typically used to return data to application
    //
    test_data = icl_mem_alloc (TEST_DATA_SIZE);
    test_copy = icl_mem_alloc (TEST_DATA_SIZE);
    memset (test_data, 0xAA, TEST_DATA_SIZE);
    memset (test_copy, 0,    TEST_DATA_SIZE);
    processed = 0;

    content = amq_content_basic_new ();
    amq_content_basic_set_body (content, test_data, TEST_DATA_SIZE, icl_mem_free);
    amq_content_basic_set_reader (content, &reader, TEST_CHUNK);
    while ((body = amq_content_basic_replay_body (content, &reader))) {
        memcpy (test_copy + processed, body->data, body->cur_size);
        processed += body->cur_size;
        ipr_bucket_unlink (&body);
    }
    assert (processed == TEST_DATA_SIZE);
    assert (memcmp (test_data, test_copy, TEST_DATA_SIZE) == 0);
    amq_content_basic_unlink (&content);
    icl_mem_free (test_copy);

    //  Test 7
    //      - coalesce content into application buffer
    //      - using get_body

    content = amq_content_basic_new ();
    body = ipr_bucket_new (TEST_CHUNK);
    body->cur_size = TEST_CHUNK;
    memset (body->data, 0xAA, TEST_CHUNK);
    for (count = 0; count < 10; count++)
        amq_content_basic_record_body (content, body);
    ipr_bucket_unlink (&body);

    test_data = icl_mem_alloc (TEST_DATA_SIZE);
    assert (amq_content_basic_get_body (content, test_data, TEST_DATA_SIZE) == TEST_CHUNK * 10);
    amq_content_basic_unlink (&content);
    icl_mem_free (test_data);

    //  Test 8
    //      - empty content
    //
    content = amq_content_basic_new ();
    header = amq_content_basic_replay_header (content);
    amq_content_basic_record_header (content, header);
    ipr_bucket_unlink (&header);
    amq_content_basic_unlink (&content);

    //  Test 9
    //      - wire serialization
    //
    //  do 100k contents
    randomize ();
    for (times = 0; times < 1000; times++) {
        processed = 0;
        bucket = ipr_bucket_new ((1024 + 50) * 100);
        for (count = 0; count < 100; count++) {
            test_size = randomof (1023);
            test_size += 1;
            test_data = icl_mem_alloc (test_size);
            memset (test_data, 0xAA, test_size);
            content = amq_content_basic_new ();
            amq_content_basic_set_routing_key (content, "exchange", "routing key", 0);
            amq_content_basic_set_body (content, test_data, test_size, icl_mem_free);
            amq_content_basic_wire_put (content, bucket, 123);
            amq_content_basic_unlink (&content);
            processed++;
        }
        assert (amq_content_basic_wire_pending (bucket) == 0);
        offset = 0;
        content = amq_content_basic_wire_get (bucket, &offset, &options);
        while (content) {
            assert (streq (content->routing_key, "routing key"));
            assert (options == 123);
            amq_content_basic_unlink (&content);
            content = amq_content_basic_wire_get (bucket, &offset, &options);
            processed--;
        }
        assert (processed == 0);
        ipr_bucket_unlink (&bucket);
    }
    //  Test chronometer
    content = amq_content_basic_new ();
    amq_content_basic_chrono_set (content);
    apr_sleep (randomof (5000));
    amq_content_basic_chrono_add (content);
    apr_sleep (randomof (5000));
    amq_content_basic_chrono_add (content);
    apr_sleep (randomof (5000));
    amq_content_basic_chrono_add (content);
    apr_sleep (randomof (5000));
    amq_content_basic_chrono_get (content, deltas, 0);
    if (!isdigit (*deltas)) {
        icl_console_print ("E: deltas wrong: cid=%s dta=%s", content->correlation_id, deltas);
        assert (isdigit (*deltas));
    }
    amq_content_basic_unlink (&content);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    amq_content_basic_count (
void)
{
    qbyte
        count;                          //  Number of instances

count = (int) s_amq_content_basic_count;

    return (count);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_terminate (
void)
{


}
/*  -------------------------------------------------------------------------
    amq_content_basic_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    amq_content_basic_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    qbyte
        history_index;
#endif


self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <amq_content_basic zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    if (self->history_last > AMQ_CONTENT_BASIC_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % AMQ_CONTENT_BASIC_HISTORY_LENGTH;
        self->history_last %= AMQ_CONTENT_BASIC_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % AMQ_CONTENT_BASIC_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </amq_content_basic>\n");
#endif

}
/*  -------------------------------------------------------------------------
    amq_content_basic_destroy

    Type: Component method
    Destroys a amq_content_basic_t object. Takes the address of a
    amq_content_basic_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_destroy_ (
    amq_content_basic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    amq_content_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        amq_content_basic_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_system_panic ("amq_content_basic", "E: missing link on amq_content_basic object");
        amq_content_basic_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        amq_content_basic_free_ ((amq_content_basic_t *) self, file, line);
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_content_basic_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static amq_content_basic_t *
    amq_content_basic_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    amq_content_basic_t *
        self = NULL;                    //  Object reference

//  Initialise cache if necessary
if (!s_cache)
    amq_content_basic_cache_initialise ();

self = (amq_content_basic_t *) icl_mem_cache_alloc_ (s_cache, file, line);



    return (self);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_free

    Type: Component method
    Freess a amq_content_basic_t object.
    -------------------------------------------------------------------------
 */

static void
    amq_content_basic_free_ (
    amq_content_basic_t * self,         //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    int
        history_last;
#endif


    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = "free";
        self->history_links [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = self->links;
#endif

    self->object_tag = AMQ_CONTENT_BASIC_DEAD;
    icl_mem_free (self);
}
self = NULL;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

amq_content_basic_t *
    amq_content_basic_link_ (
    amq_content_basic_t * self,         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    int
        history_last;
#endif

    if (self) {
        AMQ_CONTENT_BASIC_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = "link";
        self->history_links [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = self->links;
#endif
    }

    return (self);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_unlink_ (
    amq_content_basic_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
    int
        history_last;
#endif

    amq_content_basic_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

    if (self) {
        AMQ_CONTENT_BASIC_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_system_panic ("amq_content_basic", "E: missing link on amq_content_basic object");
            amq_content_basic_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_AMQ_CONTENT_BASIC)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = file;
        self->history_line  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = line;
        self->history_type  [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % AMQ_CONTENT_BASIC_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            amq_content_basic_annihilate_ (self_p, file, line);
        amq_content_basic_free_ ((amq_content_basic_t *) self, file, line);
    }
    *self_p = NULL;
}
}
/*  -------------------------------------------------------------------------
    amq_content_basic_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    amq_content_basic_cache_initialise (
void)
{

s_cache = icl_cache_get (sizeof (amq_content_basic_t));
icl_system_register (amq_content_basic_cache_purge, amq_content_basic_cache_terminate);
}
/*  -------------------------------------------------------------------------
    amq_content_basic_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_content_basic_cache_purge (
void)
{

icl_mem_cache_purge (s_cache);

}
/*  -------------------------------------------------------------------------
    amq_content_basic_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    amq_content_basic_cache_terminate (
void)
{

s_cache = NULL;

}
/*  -------------------------------------------------------------------------
    amq_content_basic_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

amq_content_basic_animating = enabled;
}
/*  -------------------------------------------------------------------------
    amq_content_basic_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    amq_content_basic_new_in_scope_ (
    amq_content_basic_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

*self_p = amq_content_basic_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) amq_content_basic_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
}
//  Embed the version information in the resulting binary

char *EMBED__amq_content_basic_version_start  = "VeRsIoNsTaRt:ipc";
char *EMBED__amq_content_basic_component  = "amq_content_basic ";
char *EMBED__amq_content_basic_version    = "1.0 ";
char *EMBED__amq_content_basic_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *EMBED__amq_content_basic_filename   = "amq_content_basic.icl ";
char *EMBED__amq_content_basic_builddate  = "2010/10/06 ";
char *EMBED__amq_content_basic_version_end  = "VeRsIoNeNd:ipc";

