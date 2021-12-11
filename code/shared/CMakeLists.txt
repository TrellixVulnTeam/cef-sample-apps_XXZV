# Copyright (c) 2017 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

#
# Source files.
#

# Sources shared by all executables.
set(SHARED_COMMON_SRCS
  app_factory.hpp
  main_util.cpp
  main_util.hpp
  )

# Main executable sources.
set(SHARED_SRCS
  ${SHARED_COMMON_SRCS}
  client_manager.cpp
  client_manager.hpp
  client_util.cpp
  client_util.hpp
  browser_util.cpp
  browser_util.hpp
  main.hpp
  resource_util.cpp
  resource_util.hpp
  )
set(SHARED_SRCS_LINUX
  client_util_linux.cpp
  main_linux.cpp
  resource_util_linux.cpp
  resource_util_posix.cpp
  )
# set(SHARED_SRCS_MAC
  # client_util_mac.mm
  # main_mac.mm
  # resource_util_mac.mm
  # resource_util_posix.cc
  # )
# set(SHARED_SRCS_WINDOWS
  # client_util_win.cc
  # main_win.cc
  # resource_util_win.cc
  # )
APPEND_PLATFORM_SOURCES(SHARED_SRCS)

# if(OS_MAC)
  # On macOS a separate helper executable is used for subprocesses.
  # set(SHARED_HELPER_SRCS
    # ${SHARED_COMMON_SRCS}
    # process_helper_mac.cc
    # process_helper_mac.h
    # )
# endif()


#
# Shared configuration.
#

# Target static library names.
set(SHARED_TARGET "shared")

# Logical target used to link the libcef library on Linux and Windows.
# On macOS the CEF framework is loaded dynamically at startup.
ADD_LOGICAL_TARGET("libcef_lib" "${CEF_LIB_DEBUG}" "${CEF_LIB_RELEASE}")

#
# Linux configuration.
#

# Static library target.
add_library(${SHARED_TARGET} STATIC ${SHARED_SRCS})
SET_EXAMPLE_LIBRARY_TARGET_PROPERTIES(${SHARED_TARGET})
add_dependencies(${SHARED_TARGET} libcef_dll_wrapper)
target_link_libraries(${SHARED_TARGET} libcef_lib libcef_dll_wrapper ${CEF_STANDARD_LIBS})

# Copy binary and resource files to the target output directory.
COPY_FILES("${SHARED_TARGET}" "${CEF_BINARY_FILES}" "${CEF_BINARY_DIR}" "${EXAMPLE_TARGET_OUT_DIR}")
COPY_FILES("${SHARED_TARGET}" "${CEF_RESOURCE_FILES}" "${CEF_RESOURCE_DIR}" "${EXAMPLE_TARGET_OUT_DIR}")

# Output a message about setting SUID permissions on the chrome-sandbox target.
SET_LINUX_SUID_PERMISSIONS("${SHARED_TARGET}" "${EXAMPLE_TARGET_OUT_DIR}/chrome-sandbox")
