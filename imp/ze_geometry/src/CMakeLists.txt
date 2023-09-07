




set(SOURCES
  align_points.cpp
  align_poses.cpp
  clam.cpp
  line.cpp
  pose_optimizer.cpp
  ransac_relative_pose.cpp
  triangulation.cpp
  )

find_package(opengv REQUIRED)
add_library(${PROJECT_NAME} ${SOURCES} )
target_include_directories(${PROJECT_NAME} PUBLIC "${ze_geometry_SOURCE_DIR}/include" "${OpenGV_INCLUDE_DIR}")
target_link_libraries(${PROJECT_NAME} PUBLIC "${OpenGV_LIBRARIES}" "ze_common" "ze_cameras")
