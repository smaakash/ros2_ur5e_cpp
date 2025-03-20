#!/bin/bash
echo "Building standalone C++ code..."

# cd non_ros/build
# ls
# cmake ..
# make

# cd ..
# cd ..
cd ros_ur_ws
colcon build

echo "Build completed!"
