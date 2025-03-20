cmake_minimum_required(VERSION 3.10)
project(FirstMAin)

set(CMAKE_CXX_STANDARD 17)

# Include the src directory (so headers can be found)
include_directories(${CMAKE_SOURCE_DIR}/non_ros/other_functions)
include_directories(${CMAKE_SOURCE_DIR}/non_ros)

add_executable(combined_main main.cpp functions.cpp other_functions/matrix.cpp) 
