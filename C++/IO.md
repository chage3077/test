# 简单文件输入/输出
## 写入到本地文本文件中
```cpp
// 包含下列头文件
#include<iostream> // 包含所需的ostream类
#include<fstream> // 包含所需的ofstream类处理文件
#include<cstring>
using namespace std; //使用std命名空间

// 1.在头文件iostream中预定义了cout这个ostream对象，对于ofstream类需要自己定义一个对象。
ofstream outFile; 

// 2.使用open方法关联相关文件
outFile.open("xxx.txt");

// 3.利用<<、endl写入文件中
// 开始写
    out << "automoblie: " << automobile << endl;
    out << "year: " << year << endl;
    out << "a_price: " << a_price << endl;
    out << "d_price: " << d_price << endl;
// 4.关闭文件
outFile.close(); 
```
## 读取本地文件
```cpp
// 包含下列头文件
#include<iostream> // 包含所需的ostream类
#include<fstream> // 包含所需的ifstream类处理文件
#include<cstring>
#include<cstdlib> // 包含exit()方法
using namespace std; //使用std命名空间

// 1.在头文件iostream中预定义了cin这个istream对象，对于ifstream类需要自己定义一个对象。
ifstream in; 

// 2.关联文件
in.open("xxx.txt");

// 3.判断文件是否打开成功
if(!in.is_open())
{
    // 终止程序
    exit(EXIT_FAILURE); // exit()在头文件cstdlib定义，也包含EXIT_FAILURE预定义常量
}
string data
getline(in,data); // 将文件内的字符串读取到data中
cout << data << endl;

// 对于读取文件时遇到的问题进行判断
while(in.good()) // 没有任何错误时返回true
{
    // 进行读取
}
if(in.eof()) // 到达文件尾
    // 处理逻辑
else if(in.fail()) // 中间出现类型不匹配，fail设置为true
    // 处理逻辑
else
    // 其他类型错误

//关闭文件
in.close();
```