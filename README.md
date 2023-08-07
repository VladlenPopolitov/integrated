# integrated
Project includes submodules of other GitHub projects


1) Add mimetic
  git submodule add https://github.com/VladlenPopolitov/mimetic external/mimetic

  In CMakeLists.txt

add_subdirectory(external/mimetic)
target_include_directories(${PROJECT_NAME} PUBLIC external/mimetic)  
target_include_directories(${PROJECT_NAME} PUBLIC ${mimetic_BINARY_DIR}/include)  
target_link_libraries(${PROJECT_NAME}  mimetic)

2) Add Xerces

  git submodule add https://github.com/apache/xerces-c external/xercesc
