
set(SOURCES
  linearmemory.cpp
  image_raw.cpp
  )

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${imp_core_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PUBLIC ze_common)


