cmake_minimum_required(VERSION 3.9)
project(capy_dispatchq)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTING "Enable creation of Eigen tests." OFF)

add_library(capy_dispatchq
        src/dispatchq.cc
        )

include_directories(include)

set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

#############################################################################
# Install                                                                   #
#############################################################################
if (NOT CMAKE_INSTALL_LIBDIR)
    set(CMAKE_INSTALL_LIBDIR  lib)
endif ()
if (NOT CMAKE_INSTALL_INCLUDEDIR)
    set(CMAKE_INSTALL_INCLUDEDIR  include)
endif ()

set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix "\${prefix}")
set(libdir "\${exec_prefix}/${CMAKE_INSTALL_LIBDIR}")
set(includedir "\${prefix}/${CMAKE_INSTALL_INCLUDEDIR}")

install (TARGETS capy_dispatchq DESTINATION lib)
install (FILES include/capy/dispatchq.h DESTINATION include/capy)

configure_file(capy-dispatchq.pc.in ${CMAKE_CURRENT_BINARY_DIR}/capy-dispatchq.pc @ONLY)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/capy-dispatchq.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
        )

if(BUILD_TESTING)
add_subdirectory(utests)
endif()
