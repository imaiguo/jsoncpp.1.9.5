
cmake_minimum_required(VERSION 3.10)

project(jsonapp)
set(CMAKE_CXX_STANDARD 17)
set(JSONCPP_DIR D:/devtools/jsoncpp.19.5/lib/cmake/jsoncpp)
find_package(JSONCPP REQUIRED)

if(JSONCPP_FOUND)
    message ("jsoncpp found")
else()
    message (FATAL_ERROR "jsoncpp isnot found")
endif()

aux_source_directory(./ SRC)
include_directories(D:/devtools/jsoncpp.19.5/include)
add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC "D:/devtools/jsoncpp.19.5/lib")

target_link_libraries(${CMAKE_PROJECT_NAME} jsoncpp)

file(COPY D:/devtools/jsoncpp.19.5/bin/jsoncpp.dll DESTINATION ./)
file(COPY data.json DESTINATION ./)
