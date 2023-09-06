cmake_minimum_required(VERSION 2.8.3)
project(ze_geometry)


# quick fix to gcc bug / boost defining literals
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  #  gcc < 4.9 only
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fext-numeric-literals")      
  endif()
endif()
add_subdirectory(src)