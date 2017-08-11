include(FindPkgConfig)

if(Check_FIND_REQUIRED)
  set(_pkgconfig_REQUIRED "REQUIRED")
else(Check_FIND_REQUIRED)
  set(_pkgconfig_REQUIRED "")
endif()

if(CHECK_MIN_VERSION)
  PKG_SEARCH_MODULE(CHECK ${_pkgconfig_REQUIRED} check>=${CHECK_MIN_VERSION})
else(CHECK_MIN_VERSION)
  PKG_SEARCH_MODULE(CHECK ${_pkgconfig_REQUIRED} check)
endif()

# Look for CHECK include dir and libraries
if(NOT CHECK_FOUND AND NOT PKG_CONFIG_FOUND)
  find_path(CHECK_include_DIRS check.h)
  find_library(CHECK_LIBRARIES NAMES check)
  if(CHECK_include_DIRS AND CHECK_LIBRARIES)
    set(CHECK_FOUND 1)
    if(NOT Check_FIND_QUIETLY)
      message(STATUS "Found CHECK: ${CHECK_LIBRARIES}")
    endif(NOT Check_FIND_QUIETLY)
  else(CHECK_include_DIRS AND CHECK_LIBRARIES)
    if(Check_FIND_REQUIRED)
      message(FATAL_ERROR "Could NOT find CHECK")
    else(Check_FIND_REQUIRED)
      if(NOT Check_FIND_QUIETLY)
        message(STATUS "Could NOT find CHECK")
      endif(NOT Check_FIND_QUIETLY)
    endif(Check_FIND_REQUIRED)
  endif(CHECK_include_DIRS AND CHECK_LIBRARIES)
endif(NOT CHECK_FOUND AND NOT PKG_CONFIG_FOUND)

# Hide advanced variables from CMake GUIs
mark_as_advanced(CHECK_include_DIRS CHECK_LIBRARIES)
