cmake_minimum_required(VERSION 3.8)
project(force_control_module)
find_package(ament_cmake REQUIRED)

find_package(ur_rtde REQUIRED)
add_executable(real_time_controller src/ur5e_real_time_controller.cpp)
target_link_libraries(real_time_controller PRIVATE ur_rtde::rtde)


# Install the executable
install(TARGETS real_time_controller DESTINATION lib/${PROJECT_NAME})

# Install the launch file
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()