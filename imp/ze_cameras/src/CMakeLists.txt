


#############
# LIBRARIES #
#############
set(HEADERS
  include/ze/cameras/camera.hpp
  include/ze/cameras/camera_impl.hpp
  include/ze/cameras/camera_models.hpp
  include/ze/cameras/camera_rig.hpp
  include/ze/cameras/camera_utils.hpp
  include/ze/cameras/camera_yaml_serialization.hpp
  )

set(SOURCES
  camera.cpp
  camera_rig.cpp
  camera_utils.cpp
  camera_yaml_serialization.cpp
  camera_impl.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "${OpenCV_INCLUDE_DIR}" "${ze_cameras_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBRARIES} "ze_common" "imp_core" "imp_bridge_opencv")
