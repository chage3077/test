#include <iostream>
#include <cstring>
#include "Association.h"
#include "Generalization.h"

using namespace std;

// 测试指针函数
double pam(int lns);
double besty(int lns);
void estimate(int lines, double (*ptr)(int));
const double* f1(const double ar[],int n);
const double* f2(const double [],int);
const double* f3(const double *,int );


// 测试继承关系，多态
void test01()
{
    // 创建父类指针并且指向子类
    Animal *ptr = new Dog();
    // 调用子类里重写的函数
    ptr->speak();
}

// 测试关联关系
void test02()
{
    // 创建汽车、人对象
    Car car1("Toyota");
    Person p1("The_Shy", &car1);
    p1.showPerson();
}

void test03()
{

    cout << "What year was your house built?\n";
    int year;
    cin >> year; // 留下的回车换行符会留下在缓存区中
    // 加上cin.get()把回车换行符捕获
    cin.get();
    cout << "What is its street address?\n";
    char address[80];
    // 由于缓存区中存在回车换行符，cin.getline()会把回车换行符认为是一串空字符串，把空字符串存到address中，所有用户输入不了
    cin.getline(address, 80); // 79个字符加上'\0'
    cout << "Year built:" << year << endl;
    cout << "Address:" << address << endl;
    cout << "Done!\n";
}

void test04()
{
    char charr[20]; // 只是一个char数组
    string str;
    cout << "Length of string in charr before input:" << strlen(charr) << endl; // 计算charr的字符数量，根据'\0'进行终止，对于char数组没进行赋值，会一直寻找'/0'
    cout << "Length of string in str before input:" << str.size() << endl;      // 计算str的字符数量
    cout << "Enter a line of text:\n";
    // indicate maximum length
    cin.getline(charr, 20); // 输入读取整行charr，使用cin.getline读取20个字符
    cout << "You entered:" << charr << endl;
    cout << "Enter another line of text:\n";
    // cin now an argument;no length specifier

    getline(cin, str); // getline()是一个简单的函数，输入读取str，不能使用cin.getline(str,10)。因为cin.getline(char类型，读取字符数量)
    cout << "You entered:" << str << endl;
    cout << "Length of string in charr after input:" << strlen(charr) << endl;
    cout << "Length of string in str after input:" << str.size() << endl;
}
void testPointFunction()
{
    int code;
    cout << "How many lines of code do you need?" << endl;
    cin >> code;
    cout << "pam fuction: " << endl;
    estimate(code, pam);
    cout << "besty function: " << endl;
    estimate(code, besty);
}
void testPointFunction2()
{
    const double ar[3] = {1.11,2.22,3.33};
    // 创建函数指针
    const double* (*pt1)(const double*,int)=f1;
    //const double* (*pt2)(const double*,int)=f2;
    auto pt2=f2;// 利用auto自动匹配p2的类型，p2是函数指针
    auto pt3=f3;
    cout<<"Address      values\n";
    cout<<(*pt1)(ar,3)<<":\t\t"<<*((*pt1)(ar,3))<<endl; // 地址：f1(ar,3) 值：*(f1(ar,3))
    cout<<pt2(ar,3)<<":\t\t"<<*pt2(ar,3)<<endl; // 对于函数指针，pt2与*pt2等价
    cout<<pt3(ar,3)<<":\t\t"<<*pt3(ar,3)<<endl;
    // const double* (*pt3)(const double*,int)=f3;

    // pt是具有三个元素的数组，前面有一个*代表每一个元素都是指针，指针指向函数
    const double* (*pa[3])(const double *,int)={f1,f2,f3};
    auto pb = pa; // pa是数组名——地址，第一个元素的地址,所以pb是一个指针，第一个元素是f1——函数入口的地址，pb指向指针（指针的指针）
    // pb的类型：const double* (*(*pb))(const double*,int)=pa;
    for(int i =0;i<3;i++)
    {
        cout<<pa[i](ar,3)<<":\t"<<*(pa[i](ar,3))<<endl;
        cout<<(*pa[i])(ar,3)<<"\t"<<*((*pa[i])(ar,3))<<endl;
    }

}
void testYingYong()
{
    int rates = 101;
    int& rodents = rates; // 一定要在初始化时绑定引用，rodents只能是rates的引用，不能更改
    cout<<"rates = "<<rates;
    cout<<", rodents = "<< rodents<<endl;
    rodents++;
    cout<<"Now,rates = "<<rates;
    cout<<", roents = "<< rodents<<endl;
    cout<<"rate address = "<<&rates;
    cout<<", rodents address = "<< &rodents<<endl;
}
// 主函数入口
int main()
{
    // test01();

    // test02();

    // test03();

    // test04();
    //testPointFunction();

    //testPointFunction2();

    testYingYong();
    system("pause");

    return 0;
}

double pam(int lns)
{
    return 0.05f * lns;
}

double besty(int lns)
{
    return 0.03 * lns + 0.0004 * lns;
}

void estimate(int lines, double (*ptr)(int))
{
    cout << lines << "lines will take ";
    cout << (*ptr)(lines) << " hour(s)" << endl;
}

const double *f1(const double *ar, int n)
{
    return ar; // ar = &ar[0] = ar+0
}

const double *f2(const double ar[], int n)
{
    return ar+1; // ar+1 = &ar[1]
}

const double *f3(const double ar[], int n)
{
    return ar+2;
}
