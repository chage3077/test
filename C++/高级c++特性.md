# Lambda表达式
lambda表达式是一个匿名函数，可以定义在函数体中，也可以定义在函数参数中。

    lambda表达式的格式：
    [捕获变量](参数列表) 可选限定符-> 返回类型 
    { 
        body函数体
    }
    捕获变量：捕捉外部作用域的变量
    参数列表：函数需要使用的变量
    返回类型：函数的返回值类型
```cpp
int main()
{
    int x = 10;
    int y = 20;
    auto p = [x,y](int a,int b)->int
    {
        return x  + y + a + b;
    }
}
```
