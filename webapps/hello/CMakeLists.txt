project(hello)
cmake_minimum_required(VERSION 2.8)
set(WEB_APP_CALASSOMYS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../WebAppCalassomys)
include_directories(${WEB_APP_CALASSOMYS_PATH}/include)
add_subdirectory(${WEB_APP_CALASSOMYS_PATH} webapp)
aux_source_directory(src SRC_LIST)
add_library(${PROJECT_NAME} SHARED ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} WebAppCalassomys )

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -std=c++11")
endif()
