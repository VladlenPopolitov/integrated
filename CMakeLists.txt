cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 20)

project(Integrated VERSION 1.0.0)

add_executable(${PROJECT_NAME} main.cpp cryptopp_check.cpp cryptopp_check.h)
# define tests
enable_testing()

add_subdirectory(external/mimetic)
target_include_directories(${PROJECT_NAME} PUBLIC external/mimetic)  
target_include_directories(${PROJECT_NAME} PUBLIC ${mimetic_BINARY_DIR}/include)  
target_link_libraries(${PROJECT_NAME}  mimetic)

add_subdirectory(external/xercesc)
target_include_directories(${PROJECT_NAME} PUBLIC external/xercesc/src)  
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/external/xercesc/src)
target_link_libraries(${PROJECT_NAME}  xerces-c)

add_subdirectory(external/cryptopp)
target_include_directories(${PROJECT_NAME} PUBLIC external/cryptopp/cryptopp)  
#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/external/xercesc/src)
target_link_libraries(${PROJECT_NAME}  cryptopp::cryptopp)

