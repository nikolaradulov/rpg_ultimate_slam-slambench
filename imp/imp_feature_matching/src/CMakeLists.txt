
set(SOURCES
  brute_force_matcher.cpp
  matching_types.cpp
  matching_viz.cpp
  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${imp_feature_matching_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC "ze_common" "imp_core" "imp_bridge_opencv" "imp_imgproc" "imp_features")
