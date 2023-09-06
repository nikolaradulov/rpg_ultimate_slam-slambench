
set(SOURCES
  feature_initializer.cpp
  feature_tracker.cpp
  frontend_api.cpp
  frontend_base.cpp
  frontend_gflags.cpp
  frontend_logging.cpp
  frontend_vio.cpp
  keyframe_selection.cpp
  landmarks_reprojector.cpp
  refinement.cpp
  stereo_matcher.cpp
  track_extractor.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${ze_vio_frontend_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC "imp_features" "imp_correspondence" "ze_vio_common")

