cmake_minimum_required(VERSION 3.21)
project(jsonbenchmark)

set(CMAKE_CXX_STANDARD 17)

if (APPLE)
    set(OPENSSL_ROOT_DIR /usr/local/opt/openssl)
endif ()

add_subdirectory(Catch2)
add_subdirectory(fc)
add_subdirectory(rapidjson)

add_library(rapidjson INTERFACE)

target_include_directories(rapidjson INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/rapidjson/include)

add_executable(jsonbenchmark test.cpp)

target_link_libraries(jsonbenchmark Catch2WithMain fc rapidjson)
