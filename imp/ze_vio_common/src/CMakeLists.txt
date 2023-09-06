

set(SOURCES
  frame.cpp
  nframe.cpp
  nframe_table.cpp
  nframe_utils.cpp
  imu_integrator.cpp
  landmark_table.cpp
  landmark_triangulation.cpp
  landmark_types.cpp
  landmark_utils.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${ze_vio_common_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC "imp_imgproc" "imp_features" "ze_geometry")

