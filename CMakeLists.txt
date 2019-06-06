cmake_minimum_required(VERSION 3.9)
project(capy_dispatchq)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTING "Enable creation of Eigen tests." OF)

add_library(capy_dispatchq
        src/capy_dispatchq.cpp
        )

include_directories(include)

#############################################################################
# Install                                                                   #
#############################################################################
install (TARGETS capy_dispatchq DESTINATION lib)
install (FILES include/capy_dispatchq.hpp DESTINATION include/capy)
set(CMAKE_CXX_FLAGS -pthread)

if(BUILD_TESTING)
add_subdirectory(utests)
endif()
