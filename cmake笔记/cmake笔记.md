# 配置CMakeLists文件
```bash
# CMakeLists.txt常用的预定义变量:

# ${CMAKE_SOURCE_DIR} 指整个项目所在的目录，一般CMakeLists.txt文件也在这里面

# ${CMAKE_CURRENT_SOURCE_DIR} 指CMakeLists.txt所在的文件路径

# ${PROJECT_BINARY_DIR} 是CMake生成一系列文件的目录，如果是在build中cmake那就是对应的...../build

# ${PROJECT_NAME} 自定义的项目名


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
```
# cmake常用命令
1.指定项目构建目录，读取CMakeLists.txt文件生成构建文件
```bash
#需要新建一个build文件，在build文件下进行构建
cmake CMakeLists.txt所在的文件路径
```
2.对构建的文件进行编译
```bash
make -j8 # -j8给予cpu核数
```
3.安装执行文件</br>
将已经编译完成的程序文件、库文件和其他资源（如配置文件、文档等）复制到系统的适当目录中。通常，这些目录包括 /usr/local/bin
```bash
sudo make install
```