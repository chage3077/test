# Linux常用命令
我这里主要使用Ubuntu子系统进行处理
## 前提知道
```bash
#跳转命令
cd ../ #跳转到上级文件目录
cd ./xxx/xx # ./代表当前的文件目录，现在跳转到指定路径
ctrl+c # 结束进程
```
## 文件的基本操作
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

# 无权限的情况下
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
* 重命名文件
```bash
mv 原文件名 新文件名
```
* 复制文件
```bash
cp 源文件或目录的路径 需要复制到的文件路径
```
* 共享文件夹</br>
在虚拟机VM可以配置共享文件夹，实现本地电脑与虚拟机系统文件的传输。
```bash
# 查询虚拟机系统下的共享文件夹
ls /mnt/hgfs
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

## 修改文件的权限
文件有三种权限，分别是 w=写(w=4) r=读(r=3) x=执行程序(x=1)</br>
有三种操作用户：</br>
* 超级用户--root:</br>拥有对系统的完全控制权限，可以执行所有操作，包括安装或删除软件、修改系统文件、管理其他用户等。root 用户通常用于执行需要提升权限的管理任务，通常通过命令 sudo 来临时提升普通用户权限以执行管理操作。</br>
* 普通用户--username:</br>
普通用户拥有自己的主目录（例如 /home/username），并且只对该目录及其创建的文件具有<b>完全控制权限</b>。普通用户无法直接执行需要超级用户权限的操作，这样设计是为了防止用户误操作影响系统稳定性。</br>
* 系统用户:</br>
系统用户是为系统服务或后台任务而创建的用户，通常不用于常见的系统用户包括 nobody、daemon、www-data（用于 web 服务器）、sshd（用于 SSH 守护进程）等。登录。这些用户通常没有交互式登录权限（例如通过终端登录），它们的存在主要是为了分离和管理系统进程的权限。系统用户通常有特定的 UID（用户 ID），如 0-999 或 1-999，用于区分它们与普通用户（普通用户的 UID 通常从 1000 开始）。
```bash
#修改文件的权限
chmod 777 文件名 # 三个数字分别代表三个用户的权限，利用加法进行计算权限数。此时7是最大值，可以进行读写执行操作
chmod -r 777 文件名 # 修个整个文件包括子文件的权限

chown 用户名 文件名 # 修改文件的所属用户(文件作者)
chown 用户名：用户组名 文件名 # 同时修改文件的用户和用户组，也可以使用-r
chown -r 用户名 文件名 # 递归操作

chgrp 用户组名 文件名 # 修改文件所在的用户组
chgrp -r 用户组名 文件名 # 递归操作

# 实例：
chown bob report.txt   # 更改所有者为 bob
chgrp staff report.txt # 更改用户组为 staff
chown bob:staff report.txt # 也可以同时修改
```

## 用户组
用户组是一种逻辑上的集合，用来组织和管理多个用户。每个用户可以属于一个或多个用户组。</br>
linux中有两种用户组：</br>
* 主组：每个用户都有一个默认的主组。用户创建文件时，该文件默认属于用户的主组。主组在用户的 /etc/passwd 文件条目中定义。
* 附加组：用户可以属于多个附加组，这些组是除了主组以外的其他组。附加组提供额外的权限，当用户需要访问不属于其主组的文件或资源时，可以通过附加组来实现。
```bash
# 查看当前用户所在的用户组
groups

# 指定查看用户所在的用户组
groups username

# 查看用户的详细信息
id username

# 添加用户组
sudo groupadd groupname

# 将用户添加到用户组
sudo usermod -aG groupname username # -aG是防止用户丢失先前的用户组

# 删除用户组
sudo groupdel groupname

# 删除用户组中的用户
sudo gpasswd -d 用户名 用户组名
sudo deluser 用户名 用户组名 # 适用于Ubuntu系统
```

## 进程
```bash
# 启动进程，直接输入进程名
./name_server # fdbus下的name_server进程，作用是解析fdbus通信

# 查询某个进程
ps -ef | grep 进程名

# 查询特定的进程信息
# pidin命令用于显示系统的进程信息
# 管道符号 | 将前一个命令的输出作为后一个命令的输入。也就是说，pidin 命令的输出会传递给 grep 进行处理
# grep是一个文本过滤工具，用于在文本中搜索符合特定模式的行。grep后面跟的参数指定了要搜索的关键词或正则表达式。
pidin | grep myprocess # 查找关于myprocess的所有进程
```

## 挂载
### 什么是挂载？
区分不同的逻辑路径对应不同的物理设备的机制就叫做挂载
```bash
# 显示当前的挂载点目录
df -h
# 指定的挂载点以读写模式重新挂载
# mount:用于挂载文件系统的命令
# -u:重新挂载已经挂载的文件系统（更新现有挂载）
# -w:以读写模式（write）挂载文件系统。缺省情况下，有些文件系统可能以只读方式挂载，因此需要明确指定读写模式
# /mnt:指定需要重新挂载的挂载点或目录（在这个例子中是 /mnt 目录）
mount -uw /mnt # 指定/mnt这个挂载点重新挂载

# 将挂载点的缓存写入到实际磁盘里
# 所有缓存的数据从内存写入到磁盘。它确保了所有的挂起的写操作都被提交到实际存储设备，以防数据丢失
sync
```

