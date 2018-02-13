<?xml?>
<!--
    Copyright (c) 1996-2009 iMatix Corporation

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at
    your option) any later version.

    This program is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    For information on alternative licensing for OEMs, please contact
    iMatix Corporation.
 -->
<class
    name      = "ipr_dir"
    comment   = "Directory management"
    version   = "1.0"
    script    = "icl_gen"
    >

<inherit class = "icl_object">
    <option name = "alloc" value = "cache" />
    <option name = "rwlock" value = "1" />
</inherit>

<import class = "icl_shortstr" />
<import class = "ipr_file"     />
<context>
    int filler;
</context>

<private>
</private>

<method name = "create" return = "rc">
    <doc>
    Create a new directory.  Returns 0 if the directory was created;
    -1 if there was an error.  Under Windows and OpenVMS, accepts directory
    names with '/'.  Will create multiple levels of directory if required.
    </doc>
    <argument name = "path to create" type = "char *">Directory path to create</argument>
    <declare name = "rc" type = "Bool" default = "0" />
    <local>
    icl_shortstr_t
        path;
#   if (defined (GATES_FILESYSTEM))
    char
        *char_ptr;
#   endif
    char
        *slash;
    </local>

    //  Get working copy so we can mangle it a little                          
    icl_shortstr_cpy (path, path_to_create);
#   if (defined (GATES_FILESYSTEM))
    for (char_ptr = path; *char_ptr; char_ptr++)
        if (*char_ptr == '/')
            *char_ptr = '\\\\';

    //  Handle \\system\drive specially
    if (path [0] == '\\\\' && path [1] == '\\\\') {
        slash = strchr (path + 2, '\\\\');
        if (slash)
            slash = strchr (slash + 1, '\\\\');
    }
    else
#   endif
    slash = strchr (path + 1, PATHEND);

    //  Create each component of directory as required                         
    FOREVER {                           //  Create any parent directories      
        if (slash)
            *slash = '\\0';             //  Cut at slash                       
        if (!ipr_file_is_directory (path)) {
#   if (defined (__UNIX__) || defined (__VMS_XOPEN) || defined (__OS2__))
            rc = mkdir (path, 0775);    //  User RWE Group RWE World RE        

#   elif (defined (WIN32))
            if (CreateDirectory (path, NULL))
                rc = 0;
            else
                rc = -1;
#   elif (defined (GATES_FILESYSTEM))
            rc = mkdir (path);          //  Protection?  What's that?          
#   else
            rc = -1;                    //  Not a known system                 
#   endif
            if (rc)                     //  End if error                       
                break;
        }
        if (slash == NULL)              //  End if last directory              
            break;
        *slash = PATHEND;               //  Restore path name                  
        slash = strchr (slash + 1, PATHEND);
    }
</method>

<method name = "remove" return = "rc">
    <doc>
    Remove a directory.  Returns 0 if the directory could be
    removed; -1 if there was an error.  Under MS-DOS and OpenVMS accepts
    a directory name in UNIX format, i.e. containing '/' delimiters.  The
    directory must be empty to be removed.
    </doc>
    <argument name = "path" type = "char *">Directory path to remove</argument>
    <declare name = "rc" type = "Bool" default = "0" />
#   if (defined (__UNIX__) || defined (__VMS_XOPEN) || defined (__OS2__))
    if (ipr_file_is_directory (path))
        rc = rmdir (path);
    else
        rc = -1;

#   elif (defined (GATES_FILESYSTEM))
    icl_shortstr_t
        copy_path;
    char
        *char_ptr;

    //  Check that directory exists                                            
    if (ipr_file_is_directory (path)) {
        icl_shortstr_cpy (copy_path, path);
        for (char_ptr = copy_path; *char_ptr; char_ptr++)
            if (*char_ptr == '/')
                *char_ptr = '\\\\';
#   if (defined (WIN32))
        if (RemoveDirectory (copy_path))
            rc = 0;
        else
            rc = -1;
#   else
        rc = rmdir (copy_path);
#   endif
    }
    else
        rc = -1;
#   else
    rc = -1;                            //  Unsupported platform               
#   endif
</method>

<method name = "selftest">
    assert (ipr_dir_create ("level1/level2/level3") == 0);
    assert (ipr_file_is_directory ("level1/level2/level3"));
    assert (ipr_dir_remove ("level1/level2/level3") == 0);
    assert (ipr_dir_remove ("level1/level2") == 0);
    assert (ipr_dir_remove ("level1") == 0);
</method>

</class>
