cmake_minimum_required(VERSION 2.8.3)
project(ze_imu)


#############
# LIBRARIES #
#############
set(HEADERS
  include/ze/imu/imu_model.hpp
  include/ze/imu/imu_rig.hpp
  include/ze/imu/imu_intrinsic_model.hpp
  include/ze/imu/imu_noise_model.hpp
  include/ze/imu/accelerometer_model.hpp
  include/ze/imu/gyroscope_model.hpp
  include/ze/imu/imu_yaml_serialization.hpp
  include/ze/imu/imu_buffer.hpp
  include/ze/imu/imu_types.hpp
  )

set(SOURCES
    src/imu_model.cpp
    src/imu_rig.cpp
    src/imu_intrinsic_model.cpp
    src/imu_noise_model.cpp
    src/accelerometer_model.cpp
    src/gyroscope_model.cpp
    src/imu_yaml_serialization.cpp
    src/imu_buffer.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

