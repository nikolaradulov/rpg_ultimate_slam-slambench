cmake_minimum_required(VERSION 2.8.3)
project(kindr)


# Add all files to show up in QtCreator.
FILE(GLOB_RECURSE LibFiles "include/*")
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)


target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)

