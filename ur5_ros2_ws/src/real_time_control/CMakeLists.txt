cmake_minimum_required(VERSION 3.8)
project(real_time_control)

add_executable(controller src/force_control.cpp)
install(TARGETS controller DESTINATION lib/${PROJECT_NAME})