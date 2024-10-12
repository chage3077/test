cmake_minimum_required(VERSION 3.10) #设置cmake版本最低号
project(Mytest) #定义项目名称


#设置c++标准
set(CMAKE_CXX_STANDARD 11)

#搜集cpp、h文件路径
file(GLOB_RECURSE SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

# 将头文件放入编译器里面
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#添加可执行文件
add_executable(Mytest main.cpp ${SRC_LIST})

# # #链接库
# target_link_libraries(Mytest)