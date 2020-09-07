cmake_minimum_required(VERSION 3.13)

project(boost-test VERSION 1.0)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

enable_testing()
add_compile_options( -fprofile-arcs -ftest-coverage -g -O0 )
add_link_options( -fprofile-arcs )

add_custom_target( coverage
        COMMAND lcov --zerocounters  --directory .
        COMMAND ctest
        COMMAND lcov --capture -b ${PROJECT_SOURCE_DIR} --directory ${PROJECT_BINARY_DIR} --quiet -o
                ${PROJECT_BINARY_DIR}/tests.info --no-external
        COMMAND genhtml --output-directory ${PROJECT_BINARY_DIR}/coverage --demangle-cpp
                --num-spaces 2 --sort --function-coverage --legend --quiet
                ${PROJECT_BINARY_DIR}/tests.info
        BYPRODUCTS tests.info coverage
        COMMENT "Building code coverage report in ${PROJECT_BINARY_DIR}/coverage"
    )

add_executable(tests test.cpp)
target_link_libraries(tests ${Boost_LIBRARIES})

ADD_TEST(tests tests)
