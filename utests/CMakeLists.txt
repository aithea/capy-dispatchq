 #############################################################################
 # unit test executables                                                     #
 #############################################################################

 add_executable(test_thread_pool test_queue.cpp)
 target_link_libraries(test_thread_pool capy_dispatchq)

 #############################################################################
 # run unit tests                                                            #
 #############################################################################

 add_custom_target(
         run_utests ALL
         ctest WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )

 add_dependencies(run_utests test_thread_pool)

 add_test (NAME test_thread_pool COMMAND test_thread_pool)

 if(BUILD_TESTING)
 enable_testing ()
 endif()
