
# OpenMP
find_package(OpenMP QUIET)
if (OPENMP_FOUND)
  message(STATUS "OpenMP found")
  add_definitions(-DUSE_OPENMP)
endif ()


set(SOURCES
  estimator.cpp
  homogeneous_point_error.cpp
  homogeneous_point_parameter_block.cpp
  homogeneous_point_local_parameterization.cpp
  imu_error.cpp
  local_parameterization_additional_interfaces.cpp
  map.cpp
  marginalization_error.cpp
  pose_error.cpp
  pose_parameter_block.cpp
  pose_local_parameterization.cpp
  relative_pose_error.cpp
  speed_and_bias_error.cpp
  speed_and_bias_parameter_block.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES})
set(CERES_LIBRARIES
    ${CERES_LIBRARY_DIR}/libceres.so
    ${CERES_LIBRARY_DIR}/libceres.so.1
    ${CERES_LIBRARY_DIR}/libceres.so.1.12.0
)

find_package(glog 0.6.0 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC "${ze_ceres_backend_SOURCE_DIR}/include" "${CERES_INCLUDE_DIR}")
message("CERES at : ${CERES_INCLUDE_DIR}")
target_link_libraries(${PROJECT_NAME} PUBLIC "ze_common" "ze_vio_common" "${CERES_LIBRARIES}" "ze_vio_frontend" "glog::glog")