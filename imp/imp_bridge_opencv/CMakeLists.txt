cmake_minimum_required(VERSION 2.8.0)
project(imp_bridge_opencv)


if(${CMAKE_MAJOR_VERSION} VERSION_GREATER 3.0)
  cmake_policy(SET CMP0054 OLD)
endif(${CMAKE_MAJOR_VERSION} VERSION_GREATER 3.0)

add_subdirectory(src)