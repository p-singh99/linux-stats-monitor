cmake_minimum_required(VERSION 3.21.3)

# set the project name
project(stats-monitor)

# set the project name and version
project(stats-monitor VERSION 1.0)

# add headers and sensors
add_subdirectory(sensors)

# add the executable
add_executable(stats-monitor stats-monitor.cpp)

target_link_libraries(stats-monitor PUBLIC mem-sensor cpu-sensor)

