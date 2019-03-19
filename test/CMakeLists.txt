set(INSTALL_GTEST FALSE CACHE INTERNAL "" FORCE)
set(gtest_build_samples OFF CACHE INTERNAL "" FORCE)
set(gtest_build_tests OFF CACHE INTERNAL "" FORCE)
set(gtest_hide_internal_symbols ON CACHE BOOL "" FORCE)
set(gmock_build_samples OFF CACHE INTERNAL "" FORCE)
set(gmock_build_tests OFF CACHE INTERNAL "" FORCE)
if (WIN32 AND (NOT CYGWIN) AND (NOT MINGW))
    set(gtest_disable_pthreads ON CACHE INTERNAL "")
    set(gtest_force_shared_crt ON CACHE INTERNAL "")
else()
    set(THREADS_PREFER_PTHREAD_FLAG ON CACHE BOOL "")
endif()
add_subdirectory(external/googletest)

# gtest_SOURCE_DIR
# gtest_BINARY_DIR
# gmock_SOURCE_DIR
# gmock_BINARY_DIR
# googletest-distribution_SOURCE_DIR
# googletest-distribution_BINARY_DIR

# find_package(GTest REQUIRED)

set(_TEST_FILES "test_dummy1.cpp" "test_dummy2.cpp")

add_executable(unittests ${_TEST_FILES})
#target_include_directories(unittests PRIVATE ${GTEST_INCLUDE_DIRS})
#target_link_libraries(unittests PRIVATE ${GTEST_BOTH_LIBRARIES})
# target_link_libraries(unittests PRIVATE GTest::GTest GTest::Main)
target_link_libraries(unittests PRIVATE gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(unittests)
