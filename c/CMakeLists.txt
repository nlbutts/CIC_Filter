cmake_minimum_required (VERSION 3.5)
project (testCIC)

set ( CMAKE_CXX_FLAGS_RELEASE   "-std=gnu++1y -g -O3 -msse2 -ftree-vectorizer-verbose=2 -mtune=native")
set ( CMAKE_CXX_FLAGS_DEBUG     "-std=gnu++1y -g -O0")

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}" tclap-1.2.1/include)

# add the executable
add_executable(testCIC testCIC.cpp)
