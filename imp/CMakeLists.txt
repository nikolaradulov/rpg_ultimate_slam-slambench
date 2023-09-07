cmake_minimum_required(VERSION 2.8.0)

project(ultimate_slam)
find_package(yaml-cpp REQUIRED)
find_package(opengv REQUIRED)
if(opengv_FOUND)
    message("OpenGV found: include: ${opengv_INCLUDE_DIR} lib: ${opengv_LIBRARIES}")
endif(opengv_FOUND)
message("YAML-CPP at ${YAML_CPP_INCLUDE_DIR} ${YAML_CPP_LIBRARIES}")
find_package (glog 0.6.0 REQUIRED)
if(glog_FOUND)
    message("glog found")
endif(glog_FOUND)
include_directories(${EIGEN3_INCLUDE_DIR} ${SLAMBENCH_INCLUDE_DIRS} ${YAML_CPP_INCLUDE_DIR})
set(CMAKE_CXX_FLAGS "-fPIC")


add_subdirectory(imp_bridge_opencv)
add_subdirectory(imp_core)
add_subdirectory(imp_correspondence)
add_subdirectory(imp_feature_matching)
add_subdirectory(imp_features)
add_subdirectory(imp_imgproc)

add_subdirectory(fast_neon)
add_subdirectory(kindr)
add_subdirectory(ze_cameras)
add_subdirectory(ze_common)
#add_subdirectory(ze_data_provider)
add_subdirectory(ze_geometry)
#add_subdirectory(ze_imu)
add_subdirectory(ze_vio_common)
add_subdirectory(ze_vio_frontend)
add_subdirectory(ze_ceres_backend)
add_subdirectory(ze_vio_ceres)
 
add_library(${PROJECT_NAME}-original SHARED ultimate_slam-library.cpp)
target_link_libraries(${PROJECT_NAME}-original PUBLIC "ze_vio_ceres" "ze_vio_common" "ze_vio_frontend" "${YAML_CPP_LIBRARIES}" "opengv" "glog::glog")
SET(SLAMBENCH_C_WRAPPER	-Wl,--whole-archive -L${WRAPPER_PATH} slambench-c-wrapper	-Wl,--no-whole-archive)
SET(NULL_FILE_PATH	${WRAPPER_PATH}/null.cpp)

#message("${EIGEN3_VERSION_MAJOR} ${EIGEN3_VERSION_MINOR} ${EIGEN3_VERSION_PATCH}")


#include_directories(${PROJECT_NAME}-original PUBLIC )

function(generate_slam_library library_name )

    add_library(${library_name}-library SHARED ${NULL_FILE_PATH})
    target_link_libraries(${library_name}-library PRIVATE ${SLAMBENCH_C_WRAPPER} ${library_name})
    SET_TARGET_PROPERTIES(${library_name}-library PROPERTIES LINK_FLAGS "${ARGN}")
    SET_TARGET_PROPERTIES(${library_name}-library PROPERTIES INSTALL_RPATH "${LIB_PATH}")
    install(TARGETS ${library_name}-library  DESTINATION  lib/)

endfunction()

generate_slam_library(${PROJECT_NAME}-original "-Wl,--disable-new-dtags")