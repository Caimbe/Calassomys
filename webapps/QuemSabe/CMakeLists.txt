project(QuemSabe)
cmake_minimum_required(VERSION 2.8)
set(WEB_APP_CALASSOMYS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../../WebAppCalassomys)
include_directories(src ${WEB_APP_CALASSOMYS_PATH}/include)
add_subdirectory(${WEB_APP_CALASSOMYS_PATH} webapp)
aux_source_directory(src SRC)
aux_source_directory(src/dao DAO)
aux_source_directory(src/entity ENTITY)
aux_source_directory(src/model MODEL)
list(APPEND FULL_SRC
    ${SRC}
    ${ENTITY}
    ${DAO}
    ${MODEL} )
add_library(${PROJECT_NAME} SHARED ${FULL_SRC})
target_link_libraries(${PROJECT_NAME} WebAppCalassomys mysqlcppconn booster )

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -std=c++11")
endif()
