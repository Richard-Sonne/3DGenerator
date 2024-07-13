cmake_minimum_required(VERSION 3.2)

project(3DGenerator)

add_subdirectory(adapter)
add_subdirectory(mesh_generator)
add_subdirectory(pointcloud_generator)
add_subdirectory(utils)


add_executable(${PROJECT_NAME} main.cpp)