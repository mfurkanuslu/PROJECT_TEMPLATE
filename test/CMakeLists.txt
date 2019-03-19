find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

set(_TEST_FILES "test_dummy1.cpp" "test_dummy2.cpp")

add_executable(unittests ${_TEST_FILES})
target_link_libraries(unittests GTest::GTest GTest::Main)

include(GoogleTest)
gtest_discover_tests(unittests)
