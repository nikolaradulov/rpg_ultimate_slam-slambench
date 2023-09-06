



set(SOURCES
  epipolar_matcher.cpp
  epipolar_sampling.cpp
  klt.cpp
  sparse_stereo.cpp
  )

IF(DEFINED ENV{ARM_ARCHITECTURE})
  LIST(APPEND SOURCES klt_neon.cpp)
ENDIF()

add_library(${PROJECT_NAME} ${SOURCES} )
target_include_directories(${PROJECT_NAME} PUBLIC "${imp_correspondence_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC "ze_common" "imp_core" "imp_imgproc" "imp_bridge_opencv" "ze_cameras" "ze_geometry")
