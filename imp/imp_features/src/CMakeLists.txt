


set(SOURCES
  fast_detector.cpp
  feature_detector.cpp
  feature_descriptor.cpp
  occupancy_grid_2d.cpp
  opencv_detector_utils.cpp
  )



IF(DEFINED ENV{ARM_ARCHITECTURE})
  LIST(APPEND SOURCES fast_masked_neon.cpp)
ELSE()
  LIST(APPEND SOURCES fast_masked_sse.cpp)
ENDIF()
find_package(OpenCV REQUIRED)
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${imp_features_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC "ze_common" "imp_imgproc" "${OpenCV_LIBRARIES}" "fast" "ze_cameras")
