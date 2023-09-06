




set(SOURCES
  image_pyramid.cpp
  half_sample.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES} )
target_include_directories(${PROJECT_NAME} PUBLIC ${imp_imgproc_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC imp_core)

