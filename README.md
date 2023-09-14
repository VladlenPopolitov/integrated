# integrated
Project includes submodules of other GitHub projects


1) Add mimetic
  git submodule add https://github.com/VladlenPopolitov/mimetic external/mimetic
  git submodule update --init --recursive

  In CMakeLists.txt

add_subdirectory(external/mimetic)
target_include_directories(${PROJECT_NAME} PUBLIC external/mimetic)  
target_include_directories(${PROJECT_NAME} PUBLIC ${mimetic_BINARY_DIR}/include)  
target_link_libraries(${PROJECT_NAME}  mimetic)

2) Add Xerces

  git submodule add https://github.com/apache/xerces-c external/xercesc


3) Add picohttp

git submodule add https://github.com/VladlenPopolitov/picohttpparser external/xercesc/picohttpparser

4) add curl
git submodule add https://github.com/curl/curl external/curl