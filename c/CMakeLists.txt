cmake_minimum_required (VERSION 3.5)
project (testCIC)

set ( CMAKE_CXX_FLAGS "-std=gnu++1y -g")

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(testCIC testCIC.cpp)