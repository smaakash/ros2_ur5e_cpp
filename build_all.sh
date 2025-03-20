#!/bin/bash
echo "Building standalone C++ code..."

cd non_ros/build
ls
cmake ..
make

echo "Build completed!"
