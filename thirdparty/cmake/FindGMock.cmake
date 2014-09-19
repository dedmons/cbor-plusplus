# - Try to find GoogleMock Lib
# Once done this will define
#  GMOCK_FOUND - System has GMock
#  GMOCK_INCLUDE_DIRS - The GMock include directories
#  GMOCK_LIBRARIES - The libraries needed to use GMock
#  GMOCK_DEFINITIONS - Compiler switches required for using GMock

find_path(GMOCK_INCLUDE_DIR gmock/gmock.h)

find_library(GMOCK_LIBRARY NAMES libgmock.a)

set(GMOCK_LIBRARIES ${GMOCK_LIBRARY} )
set(GMOCK_INCLUDE_DIRS ${GMOCK_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set GMOCK_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GMock DEFAULT_MSG GMOCK_LIBRARY GMOCK_INCLUDE_DIR)

mark_as_advanced(GMOCK_INCLUDE_DIR GMOCK_LIBRARY)
