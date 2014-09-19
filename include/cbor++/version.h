// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>
#ifndef HEADER_CBORPLUSPLUS_VERSION_H_INCLUDED
#define HEADER_CBORPLUSPLUS_VERSION_H_INCLUDED

#ifdef __cplusplus
#   define EXTERNC extern "C"
#else
#   define EXTERNC
#endif

EXTERNC int cborplusplus_version_major();
EXTERNC int cborplusplus_version_minor();
EXTERNC int cborplusplus_version_patch();

#endif
