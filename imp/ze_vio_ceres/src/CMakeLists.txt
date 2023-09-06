

set(SOURCES
  vio_ceres_backend_interface.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${ze_vio_ceres_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC "ze_ceres_backend")


