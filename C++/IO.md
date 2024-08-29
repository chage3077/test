# 简单文件输入/输出
## 写入到本地文本文件中
```cpp
// 包含下列头文件
#include<iostream> // 包含所需的ostream类
#include<fstream> // 包含所需的ofstream类处理文件
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
using namespace std; //使用std命名空间

// 1.在头文件iostream中预定义了cin这个istream对象，对于ifstream类需要自己定义一个对象。
ifstream readFile; 

// 2.关联文件
readFile.open("xxx.txt");

// 3.判断文件是否打开成功
if(!readFile.is_open())
{
    // 终止程序
    exit(EXIT_FAILURE); // exit()在头文件cstdlib定义，也包含EXIT_FAILURE预定义常量
}
```