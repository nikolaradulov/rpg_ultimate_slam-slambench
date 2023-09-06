




set(SOURCES
  cv_bridge.cpp
  cv_connector_pixel_types.cpp
  image_cv.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} )
find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC "${imp_bridge_opencv_SOURCE_DIR}/include" "${OpenCV_INCLUDE_DIR}")
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBRARIES} imp_core)

