## g++编译器常用指令
## 编译单个.cpp文件
```cpp
//在需要编译的cpp文件目录下
g++ -o 运行项目的名称 文件名.cpp
```
## 编译多个文件以及链接头文件
```cpp
//在整个项目的文件目录下
g++ -I 头文件的文件目录 -o 运行项目的名称 xxx1.cpp xxx2.cpp ....
//例如：
g++ -I include -o test src/function1.cpp src/function2.cpp src/function3.cpp

```