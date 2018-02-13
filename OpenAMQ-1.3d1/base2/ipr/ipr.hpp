/*---------------------------------------------------------------------------
    ipr_bits.hpp - ipr_bits component wrapper in C++

Implements a bitstring object.
    Generated from ipr_bits.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_bucket.hpp - ipr_bucket component wrapper in C++

    Defines a bucket, being a buffer of variable size as chosen at creation
    time.  Buckets can be passed in messages and freed by the recipient.
    Buckets are cached so that heavy new/destroy use is very cheap.  We
    use reference counting so that buckets can be freely passed between
    objects.
    Generated from ipr_bucket.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_config.hpp - ipr_config component wrapper in C++

    Generated from ipr_config.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_crc.hpp - ipr_crc component wrapper in C++

    The CRC module calculates a CCITT cyclic-redundancy code for a
    block of data or a series of data.  Use to calculate the check
    sum for a block of data or a series of data items.  Works with
    data and strings.
    Generated from ipr_crc.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_dict.hpp - ipr_dict component wrapper in C++

Implements a symbol-table dictionary.  The dictionary holds string
values indexed by string keys.  The string values are duplicated.
All access to the dictionary is unlocked, and dictionary items do
not use links, so the dictionary should not be used from multiple
threads in parallel.
    Generated from ipr_dict.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_dir.hpp - ipr_dir component wrapper in C++

    Generated from ipr_dir.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_file.hpp - ipr_file component wrapper in C++

Provides a general set of file and filename manipulation functions.
The maximum length of a filename is set at 255 characters, to fit in
an icl_shortstr_t.  All filenames should be defined using this type.
    Generated from ipr_file.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==1
#ifndef IPR_FILE_PHASE_1_INCLUDED
#define IPR_FILE_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_file.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_1_INCLUDED
#define   IPR_BUCKET_PHASE 1
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_1_INCLUDED
#define   IPR_STR_PHASE 1
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif

#endif
#endif

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==2
#ifndef IPR_FILE_PHASE_2_INCLUDED
#define IPR_FILE_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_2_INCLUDED
#define   IPR_BUCKET_PHASE 2
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_2_INCLUDED
#define   IPR_STR_PHASE 2
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif

#endif
#endif

#if !defined(IPR_FILE_PHASE) || IPR_FILE_PHASE==3
#ifndef IPR_FILE_PHASE_3_INCLUDED
#define IPR_FILE_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_BUCKET_PHASE_3_INCLUDED
#define   IPR_BUCKET_PHASE 3
#include  "ipr_bucket.hpp"
#undef    IPR_BUCKET_PHASE
#endif
#ifndef   IPR_STR_PHASE_3_INCLUDED
#define   IPR_STR_PHASE 3
#include  "ipr_str.hpp"
#undef    IPR_STR_PHASE
#endif


class IprFile
{
public:

    static icl_info <Bool>::cpp_type
    Exists (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int64_t>::cpp_type
    Size (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <time_t>::cpp_type
    Time (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <size_t>::cpp_type
    Lines (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <ipr_bucket_t *>::cpp_type
    Slurp (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int>::cpp_type
    Where (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path,
        icl_info <char *>::cpp_type_ref fullname);

    static icl_info <int>::cpp_type
    Delete (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <int>::cpp_type
    Rename (
        icl_info <char *>::cpp_type_ref newname,
        icl_info <char *>::cpp_type_ref oldname);

    static void
    Truncate (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    StripPath (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    SetPath (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref path);

    static icl_info <char *>::cpp_type
    SetExtension (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref extension);

    static icl_info <char *>::cpp_type
    Move (
        icl_info <char *>::cpp_type_ref directory,
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <Bool>::cpp_type
    IsDirectory (
        icl_info <char *>::cpp_type_ref filename);

    static icl_info <char *>::cpp_type
    Digest (
        icl_info <char *>::cpp_type_ref filename);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprFile ();
    IprFile (const IprFile&);
    IprFile &operator = (const IprFile&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_hash.hpp - ipr_hash component wrapper in C++

Implements a loose-reference hash with no locking, for use in
lock-free agents.
    Generated from ipr_hash.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_index.hpp - ipr_index component wrapper in C++

This class provides a mechanism for indexing objects.  An index is a number
from 0 to IPR_INDEX_MAX - 1. The class keeps indexes low by hashing across
a variable part of the index rather than across its full size.  Does not
support the retrieval of objects by their reference, only by index.
    Generated from ipr_index.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_log.hpp - ipr_log component wrapper in C++

    Generated from ipr_log.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==1
#ifndef IPR_LOG_PHASE_1_INCLUDED
#define IPR_LOG_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_log.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_1_INCLUDED
#define   IPR_FILE_PHASE 1
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_1_INCLUDED
#define   IPR_PROCESS_PHASE 1
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif

#endif
#endif

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==2
#ifndef IPR_LOG_PHASE_2_INCLUDED
#define IPR_LOG_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_2_INCLUDED
#define   IPR_FILE_PHASE 2
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_2_INCLUDED
#define   IPR_PROCESS_PHASE 2
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif

#endif
#endif

#if !defined(IPR_LOG_PHASE) || IPR_LOG_PHASE==3
#ifndef IPR_LOG_PHASE_3_INCLUDED
#define IPR_LOG_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_FILE_PHASE_3_INCLUDED
#define   IPR_FILE_PHASE 3
#include  "ipr_file.hpp"
#undef    IPR_FILE_PHASE
#endif
#ifndef   IPR_PROCESS_PHASE_3_INCLUDED
#define   IPR_PROCESS_PHASE 3
#include  "ipr_process.hpp"
#undef    IPR_PROCESS_PHASE
#endif


class IprLog
{
public:

    static icl_info <int>::cpp_type
    Cycle (
        icl_info <char *>::cpp_type_ref filename,
        icl_info <char *>::cpp_type_ref directory,
        icl_info <char *>::cpp_type_ref command);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprLog ();
    IprLog (const IprLog&);
    IprLog &operator = (const IprLog&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_looseref.hpp - ipr_looseref component wrapper in C++

    Allows classes to maintain lists of references to other classes without
    creating explicitly-typed classes for each case.  Uses a void * to refer
    to the target class.
    Generated from ipr_looseref.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_meter.hpp - ipr_meter component wrapper in C++

    The traffic rate meter tracks activity per time segment.
    Generated from ipr_meter.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_net.hpp - ipr_net component wrapper in C++

    The network module provides various higher-level network access
    functions built on the APR socket layer.
    Generated from ipr_net.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==1
#ifndef IPR_NET_PHASE_1_INCLUDED
#define IPR_NET_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_net.h"
#include "icl_info.hpp"


#ifndef   IPR_TOKEN_PHASE_1_INCLUDED
#define   IPR_TOKEN_PHASE 1
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif

#endif
#endif

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==2
#ifndef IPR_NET_PHASE_2_INCLUDED
#define IPR_NET_PHASE_2_INCLUDED


#ifndef   IPR_TOKEN_PHASE_2_INCLUDED
#define   IPR_TOKEN_PHASE 2
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif

#endif
#endif

#if !defined(IPR_NET_PHASE) || IPR_NET_PHASE==3
#ifndef IPR_NET_PHASE_3_INCLUDED
#define IPR_NET_PHASE_3_INCLUDED

#ifndef   IPR_TOKEN_PHASE_3_INCLUDED
#define   IPR_TOKEN_PHASE 3
#include  "ipr_token.hpp"
#undef    IPR_TOKEN_PHASE
#endif


class IprNet
{
public:

    static void
    GetAddr (
        icl_info <char *>::cpp_type_ref dest);

    static void
    GetHostname (
        icl_info <char *>::cpp_type_ref dest);

    static icl_info <Bool>::cpp_type
    ValidateAddr (
        icl_info <char *>::cpp_type_ref netaddr);

    static icl_info <Bool>::cpp_type
    Ping (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref defport);

    static icl_info <ipr_token_t *>::cpp_type
    PingList (
        icl_info <ipr_token_list_t *>::cpp_type_ref servers,
        icl_info <char *>::cpp_type_ref defport,
        icl_info <Bool>::cpp_type_ref cleanup);

    static icl_info <char *>::cpp_type
    LookupHost (
        icl_info <char *>::cpp_type_ref hostname,
        icl_info <char *>::cpp_type_ref address);

    static icl_info <char *>::cpp_type
    FmtDisplay (
        icl_info <char *>::cpp_type_ref external,
        icl_info <char *>::cpp_type_ref internal,
        icl_info <Bool>::cpp_type_ref opt_xlat);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprNet ();
    IprNet (const IprNet&);
    IprNet &operator = (const IprNet&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_process.hpp - ipr_process component wrapper in C++

    Generated from ipr_process.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_regexp.hpp - ipr_regexp component wrapper in C++

    Provides an interface to the PCRE library.  This is a snippet
    from the PCRE documentation:

    There are two different sets of meta-characters: those  that
    are  recognized anywhere in the pattern except within square
    brackets, and those that are recognized in square  brackets.
    Outside square brackets, the meta-characters are as follows:

           general escape character with several uses
    ^      assert start of subject (or line, in multiline mode)
    $      assert end of subject (or line, in multiline mode)
    .      match any character except newline (by default)
    [      start character class definition
    |      start of alternative branch
    (      start subpattern
    )      end subpattern
    ?      extends the meaning of (
           also 0 or 1 quantifier
           also quantifier minimizer
    *      0 or more quantifier
    +      1 or more quantifier
    {      start min/max quantifier

    Part of a pattern that is in square brackets is called a
    "character class".  In a character class the only meta-
    characters are:

           general escape character
    ^      negate the class, but only if the first character
    -      indicates character range
    ]      terminates the character class
    Generated from ipr_regexp.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_sasl.hpp - ipr_sasl component wrapper in C++

    Provides functions for working with SASL (simple authentication and
    security layer).
    Generated from ipr_sasl.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==1
#ifndef IPR_SASL_PHASE_1_INCLUDED
#define IPR_SASL_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_sasl.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==2
#ifndef IPR_SASL_PHASE_2_INCLUDED
#define IPR_SASL_PHASE_2_INCLUDED



#endif
#endif

#if !defined(IPR_SASL_PHASE) || IPR_SASL_PHASE==3
#ifndef IPR_SASL_PHASE_3_INCLUDED
#define IPR_SASL_PHASE_3_INCLUDED



class IprSasl
{
public:

    static icl_info <icl_longstr_t *>::cpp_type
    PlainEncode (
        icl_info <char *>::cpp_const_type_ref login,
        icl_info <char *>::cpp_const_type_ref password);

    static icl_info <int>::cpp_type
    PlainDecode (
        icl_info <icl_longstr_t *>::cpp_type_ref auth_data,
        icl_info <char *>::cpp_type_ref login,
        icl_info <char *>::cpp_type_ref password);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprSasl ();
    IprSasl (const IprSasl&);
    IprSasl &operator = (const IprSasl&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_stat.hpp - ipr_stat component wrapper in C++

    The statistics module is designed to capture information (raw integers)
    and process these into useful information.  The sample size is arbitrarily
    large.  Samples are double-precision floating point.
    Generated from ipr_stat.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_str.hpp - ipr_str component wrapper in C++

    Provides various string manipulation functions.
    Generated from ipr_str.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==1
#ifndef IPR_STR_PHASE_1_INCLUDED
#define IPR_STR_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_str.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_1_INCLUDED
#define   IPR_REGEXP_PHASE 1
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif

#endif
#endif

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==2
#ifndef IPR_STR_PHASE_2_INCLUDED
#define IPR_STR_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_2_INCLUDED
#define   IPR_REGEXP_PHASE 2
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif

#endif
#endif

#if !defined(IPR_STR_PHASE) || IPR_STR_PHASE==3
#ifndef IPR_STR_PHASE_3_INCLUDED
#define IPR_STR_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif
#ifndef   IPR_REGEXP_PHASE_3_INCLUDED
#define   IPR_REGEXP_PHASE 3
#include  "ipr_regexp.hpp"
#undef    IPR_REGEXP_PHASE
#endif


class IprStr
{
public:

    static icl_info <char *>::cpp_type
    Skip (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Wipe (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref ch);

    static icl_info <char *>::cpp_type
    Lower (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Upper (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Subch (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to);

    static icl_info <char *>::cpp_type
    Crop (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <char *>::cpp_type
    Filter (
        icl_info <char *>::cpp_type_ref string);

    static icl_info <int>::cpp_type
    Match (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <Bool>::cpp_type
    Prefixed (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix);

    static icl_info <char *>::cpp_type
    Defix (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref prefix);

    static icl_info <char *>::cpp_type
    Clean (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char>::cpp_type_ref from,
        icl_info <char>::cpp_type_ref to);

    static icl_info <Bool>::cpp_type
    Lexeq (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <int>::cpp_type
    Lexcmp (
        icl_info <char *>::cpp_type_ref string1,
        icl_info <char *>::cpp_type_ref string2);

    static icl_info <char *>::cpp_type
    Soundex (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref encoding);

    static icl_info <Bool>::cpp_type
    Matches (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern);

    static icl_info <char *>::cpp_type
    Random (
        icl_info <char *>::cpp_type_ref string,
        icl_info <char *>::cpp_type_ref pattern);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprStr ();
    IprStr (const IprStr&);
    IprStr &operator = (const IprStr&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_symbol.hpp - ipr_symbol component wrapper in C++

Implements a symbol table that holds arbitrary data, keyed by name.
Can be used directly, or inherited to create specific symbol table
structures.
    Generated from ipr_symbol.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_token.hpp - ipr_token component wrapper in C++

Provides string tokenisation functions.  Use this to split a string
into a list of words (delimited by spaces) so that each word can be
manipulated separately.
    Generated from ipr_token.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_xml.hpp - ipr_xml component wrapper in C++

    Implements XML objects.
    Generated from ipr_xml.icl by icl_gen using GSL/4.
    
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

/*---------------------------------------------------------------------------
    ipr_uid.hpp - ipr_uid component wrapper in C++

    Provides functions to access and maniuplate the current process
    user and group IDs.
    Generated from ipr_uid.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==1
#ifndef IPR_UID_PHASE_1_INCLUDED
#define IPR_UID_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_uid.h"
#include "icl_info.hpp"


#ifndef   ICL_SHORTSTR_PHASE_1_INCLUDED
#define   ICL_SHORTSTR_PHASE 1
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif

#endif
#endif

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==2
#ifndef IPR_UID_PHASE_2_INCLUDED
#define IPR_UID_PHASE_2_INCLUDED


#ifndef   ICL_SHORTSTR_PHASE_2_INCLUDED
#define   ICL_SHORTSTR_PHASE 2
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif

#endif
#endif

#if !defined(IPR_UID_PHASE) || IPR_UID_PHASE==3
#ifndef IPR_UID_PHASE_3_INCLUDED
#define IPR_UID_PHASE_3_INCLUDED

#ifndef   ICL_SHORTSTR_PHASE_3_INCLUDED
#define   ICL_SHORTSTR_PHASE 3
#include  "icl_shortstr.hpp"
#undef    ICL_SHORTSTR_PHASE
#endif


class IprUid
{
public:

    static icl_info <int>::cpp_type
    UserName (
        icl_info <uid_t>::cpp_type_ref uid,
        icl_info <char *>::cpp_type_ref name);

    static icl_info <int>::cpp_type
    GroupName (
        icl_info <uid_t>::cpp_type_ref gid,
        icl_info <char *>::cpp_type_ref name);

    static icl_info <int>::cpp_type
    SetRealUser (
        void);

    static icl_info <int>::cpp_type
    SetRootUser (
        void);

    static icl_info <int>::cpp_type
    SetRealGroup (
        void);

    static icl_info <int>::cpp_type
    SetRootGroup (
        void);

    static icl_info <int>::cpp_type
    GetUid (
        void);

    static icl_info <int>::cpp_type
    GetGid (
        void);

    static icl_info <int>::cpp_type
    RunAs (
        icl_info <char *>::cpp_type_ref user,
        icl_info <char *>::cpp_type_ref group);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprUid ();
    IprUid (const IprUid&);
    IprUid &operator = (const IprUid&);
};



#endif
#endif
/*---------------------------------------------------------------------------
    ipr_time.hpp - ipr_time component wrapper in C++

    Provides various date & time manipulation functions.
    Generated from ipr_time.icl by icl_gen using GSL/4.
    
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

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==1
#ifndef IPR_TIME_PHASE_1_INCLUDED
#define IPR_TIME_PHASE_1_INCLUDED

#include "base.h"
#include "icl_apr.h"
#include "ipr_time.h"
#include "icl_info.hpp"



#endif
#endif

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==2
#ifndef IPR_TIME_PHASE_2_INCLUDED
#define IPR_TIME_PHASE_2_INCLUDED



#endif
#endif

#if !defined(IPR_TIME_PHASE) || IPR_TIME_PHASE==3
#ifndef IPR_TIME_PHASE_3_INCLUDED
#define IPR_TIME_PHASE_3_INCLUDED



class IprTime
{
public:

    static void
    Iso8601 (
        icl_info <ipr_time_t>::cpp_const_type_ref time,
        icl_info <ipr_date_format_t>::cpp_const_type_ref format,
        icl_info <byte>::cpp_const_type_ref precision,
        icl_info <Bool>::cpp_const_type_ref utc,
        icl_info <char*>::cpp_type_ref buffer);

    static icl_info <long>::cpp_type
    Now (
        void);

    static void
    Selftest (
        void);

    static void
    Animate (
        icl_info <Bool>::cpp_type_ref enabled);
private:
    IprTime ();
    IprTime (const IprTime&);
    IprTime &operator = (const IprTime&);
};



#endif
#endif
