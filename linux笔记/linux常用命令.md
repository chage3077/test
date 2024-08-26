## Linux常用命令
我这里主要使用Ubuntu子系统进行处理
### 前提知道
```bash
#跳转命令
cd ../ #跳转到上级文件目录
cd ./xxx/xx # ./代表当前的文件目录，现在跳转到指定路径
```
### 文件的基本操作
* 查看绝对路径
```bash
pwd
```
* 查看文件夹里面的子文件：
```bash
ls 文件路径 # ll默认展示当前目录下的子文件信息（只展示文件名）

# 展示详细的子文件信息
ls -l 文件路径 
ll 文件路径

#展示所有的子文件详细信息（包括隐藏文件）
ls -la
```

* 创建文件夹
```bash
# 有权限的情况下
mkdir 文件夹名称 # 最后在需要创建文件夹的目录下使用

//无权限的情况下
sudo mkdir 文件夹名称 
```
* 删除文件夹
```bash
rm -rf 文件夹名称（指定路径）  # -r是递归删除,-f是强制删除，此命令在有权限的情况下可以删除一切
```
* 移动文件夹
```bash
# 没有权限都可以在前面添加sudo
mv 文件夹名称（指定路径）需要移动到的路径

#将file.txt文件移动到"/home/user/Documents"下
mv file.txt /home/user/Documents

#将文件 file.txt 移动到目录 /home/user/Documents 并重命名为 newfile.txt
mv file.txt /home/user/Documents/newfile.txt

#将目录 mydir 移动到 /home/user/Documents 中
mv mydir /home/user/Documents
```

## 安装编译器g++、cmake、git、文本编辑器vim
若下载超时，可以添加cmd代理。
```bash
#只是举个例子
set http_proxy=http://127.0.0.1:7890 & set https_proxy=http://127.0.0.1:7890
```
安装前进行包的更新，用于管理 .deb包的包管理
```bash
sudo apt update
```
* 安装git
```bash
sudo apt install git
```
* 安装cmake
```bash
sudo apt install cmake
```
* 安装g++
```bash
sudo apt install g++
```
* 安装vim
```bash
sudo apt-get install vim
```
## 修改系统文件配置
1.需要在ect目录下配置动态链接库文件路径
```bash
sudo vim ld.so.conf
# 按i进行修改
# 编辑文件: 在 Vim 编辑器中，你可以添加、修改或删除目录路径。添加的路径将会被 ldconfig 用来更新共享库缓存。例如，你可以添加一行 include /usr/local/lib 以包含 /usr/local/lib 目录。

# 为什么要添加/usr/local/lib目录呢？
# 因为我安装的动态链接库存到这个地址，在构建执行文件时可以通过这个路径找到动态链接库

#按esc回到命令模式

#输入:wq退出vim
```
2.更新共享库缓存: 编辑完成后，需要运行 ldconfig 来更新缓存，使新的目录路径生效。
```bash
sudo ldconfig
```