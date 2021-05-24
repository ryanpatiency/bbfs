/*
  Copyright (C) 2012 Joseph J. Pfeiffer, Jr., Ph.D. <pfeiffer@cs.nmsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  There are a couple of symbols that need to be #defined before
  #including all the headers.
*/

#ifndef _PARAMS_H_
#define _PARAMS_H_

// The FUSE API has been changed a number of times.  So, our code
// needs to define the version of the API that we assume.  As of this
// writing, the most current API version is 26
#define FUSE_USE_VERSION 26

// need this to get pwrite().  I have to use setvbuf() instead of
// setlinebuf() later in consequence.
#define _XOPEN_SOURCE 500
#define OPENED_MAX 18

// maintain bbfs state in here
#include <limits.h>
#include <stdio.h>

struct bb_state {
    FILE* logfile;
    char* rootdir;
    char active_drive[PATH_MAX];
    char* open_paths[OPENED_MAX];
    int to_buffer;
};

#define ABSTACT_DRIVE "/drive"
#define DRIVE1 "/driveb"
#define DRIVE2 "/drivec"
#define CHANGE_DRIVE "/drive/change_drive"
#define TO_BUFFER "/drive/to_buffer"
#define BB_DATA ((struct bb_state*)fuse_get_context()->private_data)

#endif
