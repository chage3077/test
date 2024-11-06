cmake_minimum_required(VERSION 3.10) #设置cmake版本最低号
project(MediatorPatttern)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/exe)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(MediatorPatttern main.cpp ${SRC_LIST})

target_link_libraries(MediatorPatttern)