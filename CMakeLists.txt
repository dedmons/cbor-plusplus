# Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.

#
# Project Properties
#
CMAKE_MINIMUM_REQUIRED (VERSION 3.0)
PROJECT (cbor++)
SET (LIBRARY_NAME "CBOR++")
SET (LIBRARY_CODENAME "${PROJECT_NAME}")
SET (LIBRARY_COPYRIGHT_YEARS "2014")
SET (LIBRARY_VERSION_MAJOR 0)
SET (LIBRARY_VERSION_MINOR 1)
SET (LIBRARY_VERSION_PATCH 0)
SET (LIBRARY_VERSION_STRING "${LIBRARY_VERSION_MAJOR}.${LIBRARY_VERSION_MINOR}.${LIBRARY_VERSION_PATCH}")
SET (LIBRARY_VENDOR_ID "com.dedmonson")
SET (LIBRARY_VENDOR_NAME "Douglas Edmonson Jr")
SET (LIBRARY_VENDOR_URL "dedmonson.com")
SET (LIBRARY_ID "${LIBRARY_VENDOR_ID}.${PROJECT_NAME}")


#
# Debugging Options
#
SET (CMAKE_VERBOSE_MAKEFILE 0) # Use 1 for debugging, 0 for release


#
# Compiler Flags
#
SET (CMAKE_C_FLAGS "-Wall -pedantic")
SET (CMAKE_CXX_FLAGS "-Wall -pedantic -std=c++1y")

#
# Project Output Paths
#
SET (MAINFOLDER ${PROJECT_SOURCE_DIR})
SET (EXECUTABLE_OUTPUT_PATH "${MAINFOLDER}/bin")
SET (LIBRARY_OUTPUT_PATH "${MAINFOLDER}/lib")

#
# Project Search Paths
#
LIST (APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}")
LIST (APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/thirdparty")
SET (CMAKE_MODULE_PATH "${MAINFOLDER}/thirdparty/cmake")
INCLUDE_DIRECTORIES("${MAINFOLDER}/include")


#
# Include Libraries
#
FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
FIND_PACKAGE(GMock REQUIRED)
INCLUDE_DIRECTORIES(${GMOCK_INCLUDE_DIRS})

#
# Configure Files
#
FILE (GLOB_RECURSE CONFIGINPUTS1 include/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS2 include/*.h.in.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS3 src/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS4 src/*.h.in.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS5 test/*.in.h.cmake)
FILE (GLOB_RECURSE CONFIGINPUTS6 test/*.h.in.cmake)
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS1}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS2}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS3}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS4}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS5}")
LIST (APPEND CONFIGINPUTS "${CONFIGINPUTS6}")
FOREACH (CONFIGINPUT ${CONFIGINPUTS})
    STRING (REPLACE ".in.h.cmake" ".h" CONFIGOUTPUT1 "${CONFIGINPUT}")
    STRING (REPLACE ".h.in.cmake" ".h" CONFIGOUTPUT2 "${CONFIGOUTPUT1}")
    CONFIGURE_FILE ("${CONFIGINPUT}" "${CONFIGOUTPUT2}")
ENDFOREACH (CONFIGINPUT ${CONFIGINPUTS})

#
# Add Build Targets
#
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
