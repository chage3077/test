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