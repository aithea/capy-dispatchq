cmake_minimum_required(VERSION 3.9)
project(capy_dispatchq)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTING "Enable creation of Eigen tests." OFF)

add_library(capy_dispatchq
        src/dispatchq.cc
        )

include_directories(include)

#############################################################################
# Install                                                                   #
#############################################################################
install (TARGETS capy_dispatchq DESTINATION lib)
install (FILES include/capy/dispatchq.h DESTINATION include/capy)
set(CMAKE_CXX_FLAGS -pthread)

if(BUILD_TESTING)
add_subdirectory(utests)
endif()
