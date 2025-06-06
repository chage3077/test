cmake_minimum_required(VERSION 3.0)
project(ComputerRoom_Odering_System)
set(CXX_STANDARD 17)

# 搜素源文件
file(GLOB SRC ${CMAKE_SOURCE_DIR}/Identity/*.cpp
            ${CMAKE_SOURCE_DIR}/logic/loginFunction/*.cpp
            ${CMAKE_SOURCE_DIR}/menu/*.cpp
            ${CMAKE_SOURCE_DIR}/*.cpp
            ${CMAKE_SOURCE_DIR}/ComputerRoom/*.cpp
            ${CMAKE_SOURCE_DIR}/order/*.cpp)
# 包含头文件
include_directories(${CMAKE_SOURCE_DIR}/global)
include_directories(${CMAKE_SOURCE_DIR}/Identity)
include_directories(${CMAKE_SOURCE_DIR}/logic/loginFunction)
include_directories(${CMAKE_SOURCE_DIR}/menu)
include_directories(${CMAKE_SOURCE_DIR}/ComputerRoom)
include_directories(${CMAKE_SOURCE_DIR}/order)

# 生成可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 生成可执行文件，链接动态库
add_executable(ComputerRoom_Odering_System ${SRC})