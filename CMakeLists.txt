cmake_minimum_required(VERSION 4.1)
project(OpenCV_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenCV_Project main.cpp)

find_package(OpenCV REQUIRED)

target_link_libraries(OpenCV_Project PRIVATE ${OpenCV_LIBS})