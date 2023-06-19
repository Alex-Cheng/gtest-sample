enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR})
add_headers_and_sources(gtest .)
add_executable(main_test ${gtest_headers} ${gtest_sources})
target_link_libraries(main_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(main_test)
