cmake_minimum_required(VERSION 3.10)
project(Cplusplus_Jenkins)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug symbols for debugging
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -pedantic")

# Add executable
add_executable(Cplusplus_Jenkins app/main.cpp app/utils.cpp)

# Optional: Print build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ flags: ${CMAKE_CXX_FLAGS}")


# Download GoogleTest (FetchContent)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include GoogleTest module for gtest_discover_tests
include(GoogleTest)

# Add .o file to tests
add_executable(run_tests tests/test_main.cpp app/utils.cpp)
target_link_libraries(run_tests GTest::gtest_main)

# Register test in Gtest
include(CTest)
enable_testing()
gtest_discover_tests(run_tests)