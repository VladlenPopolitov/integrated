cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 20)

project(Integrated VERSION 1.0.0)


file(GLOB all_src_files_list CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")
file(GLOB all_src_h_files_list CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*")
add_executable(${PROJECT_NAME} main.cpp ${all_src_files_list}  ${all_src_h_files_list})
# define tests
enable_testing()
message(${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)  

set(HAVE_GETTIMEOFDAY 0)
add_subdirectory(external/xercesc)
target_include_directories(${PROJECT_NAME} PUBLIC external/xercesc/src)  
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/external/xercesc/src)
target_link_libraries(${PROJECT_NAME}  xerces-c)

add_subdirectory(external/cryptopp)
target_include_directories(${PROJECT_NAME} PUBLIC external/cryptopp/cryptopp)  
target_link_libraries(${PROJECT_NAME}  cryptopp::cryptopp)

add_subdirectory(external/mimetic)
target_include_directories(${PROJECT_NAME} PUBLIC external/mimetic)  
target_include_directories(${PROJECT_NAME} PUBLIC ${mimetic_BINARY_DIR}/include)  
target_link_libraries(${PROJECT_NAME}  mimetic)

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/httpparser/picohttpparser)


aux_source_directory(SRC_DIR src)
aux_source_directory(BASICEXCEL_DIR src/BasicExcel)
aux_source_directory(DATABASES_DIR src/databases)
aux_source_directory(FILESOURCE_DIR src/filesource)
aux_source_directory(KEYS_DIR src/keys)
aux_source_directory(LIBXL_DIR src/libxl)
aux_source_directory(SCRIPTS_DIR src/scripts)

target_sources(${PROJECT_NAME}
               PRIVATE
               ${SRC_DIR}
		${BASICEXCEL_DIR}
		${DATABASES_DIR}
${FILESOURCE_DIR}
${KEYS_DIR}
${LIBXL_DIR}
${SCRIPTS_DIR}
)