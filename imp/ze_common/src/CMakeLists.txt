




#############
# LIBRARIES #
#############


set(SOURCES
  csv_trajectory.cpp
  matrix.cpp
  random.cpp
  signal_handler.cpp
  test_utils.cpp
  test_thread_blocking.cpp
  thread_pool.cpp
  )


add_library(${PROJECT_NAME} ${SOURCES} )
find_package(glog 0.6.0 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC "${ze_common_SOURCE_DIR}/include" "{ze_common_SOURCE_DIR}/minkindr")
target_link_libraries(${PROJECT_NAME} PUBLIC "kindr" "glog::glog")

