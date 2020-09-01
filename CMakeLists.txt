cmake_minimum_required(VERSION 3.13)

project(boost-test VERSION 1.0)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

enable_testing()

add_executable(tests test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES})

ADD_TEST(tests tests)