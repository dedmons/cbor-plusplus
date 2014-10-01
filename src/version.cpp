// Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.
#include <cbor++/version.h>
#include "libraryinfo.h"

EXTERNC int cborplusplus_version_major()
{
    return LIBRARY_VERSION_MAJOR;
}

EXTERNC int cborplusplus_version_minor()
{
    return LIBRARY_VERSION_MINOR;
}

EXTERNC int cborplusplus_version_patch()
{
    return LIBRARY_VERSION_PATCH;
}
