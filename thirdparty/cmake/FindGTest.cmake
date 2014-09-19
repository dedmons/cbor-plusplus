# - Try to find GoogleTest Lib
# Once done this will define
#  GTEST_FOUND - System has GTest
#  GTEST_INCLUDE_DIRS - The GTest include directories
#  GTEST_LIBRARIES - The libraries needed to use GTest
#  GTEST_DEFINITIONS - Compiler switches required for using GTest

find_path(GTEST_INCLUDE_DIR gtest/gtest.h)

find_library(GTEST_LIBRARY NAMES libgtest.a)

set(GTEST_LIBRARIES ${GTEST_LIBRARY} )
set(GTEST_INCLUDE_DIRS ${GTEST_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set GTEST_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GTest DEFAULT_MSG GTEST_LIBRARY GTEST_INCLUDE_DIR)

mark_as_advanced(GTEST_INCLUDE_DIR GTEST_LIBRARY)
