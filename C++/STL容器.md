# STL容器
## 六大组件
    1.容器：存放元素的容器
    2.算法：进行查询、删除、排序等算法
    3.迭代器：连接算法和容器，必须使用迭代器才能访问容器内的元素
    4.仿函数
    5.适配器
    6.空间配置器
## vector容器
```cpp
template<class T>
void Vector_Test::myPrintf(T val)
{
	std::cout << val << std::endl;
}
void Vector_Test::test_vector()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

    // for_each：迭代器起始，迭代器结束，回调函数
	for_each(v.begin(), v.end(), myPrintf<int>);
}

// vector容器存放自定义数据类型
void Vector_Test::test_vector_person()
{
    vector<Person> v;
    v.push_back(Person("张三", 18));
    v.push_back(Person("李四", 19));
    v.push_back(Person("王五", 20));

    // 遍历容器中的数据
    // 可把迭代器看成一个指针
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->name << "，年龄：" << it->age << endl;
        // 此时每个迭代器取出来的是数据对象，则*it是Person对象
        // cout << "姓名：" << (*it).name << "，年龄：" << (*it).age << endl;
    }
}

// vector容器存放指针类型
void Vector_Test::test_vector_person_address()
{
    vector<Person*> v;

    Person p1("Tom", 18);
    Person p2("Jerry", 16);
    Person p3("Mike", 19);
    Person p4("Lucy", 17);

    // 存放地址
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    // 遍历
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 此时每个迭代器取出来的是指针，则*it是一个指向Person的指针
        cout << "姓名：" << (*it)->name << "，年龄：" << (*it)->age << endl;
    }
}

// vector嵌套vector容器
void Vector_Test::test_nested_vector()
{
    // 创建大容器
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 小容器添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 大容器添加小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器遍历所有数据
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 此时(*it)代表的是一个小容器vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}
```
* vector构造</br>
vector扩展的方式是动态扩展，需要重新释放内存，创建新的内存拷贝原来的数据。
```cpp
vector<int> v1; // 默认构造
vector<int> v2(v1.begin(), v1.end()); // 区间拷贝
vector<int> v3(n,elem); // n个elem构造
vector<int> v4(v3); // 拷贝构造
```
* vector赋值</br>
```cpp
vector<int> v1(10,10); // 10个10vector容器

vector<int> v2;
v2 = v1; // operater=赋值

vector<int> v3;
v3.assign(v1.begin(), v1.end()); // assign区间赋值

vector<int> v4;
v4.assign(n,elem); // assign n个elem赋值
```
* vector容器大小和容量</br>
```cpp
empty() // 判断容器是否为空
capacity() // 容器的容量
size() // 容器的大小(容器中元素的个数)
reserve(n) // 容器预留大小空间，防止频繁扩展,但是预留出来的空间不可访问
resize(n) // 容器大小重新指定为n，若n小于当前容器大小，则容器resize为n，多余的元素被删除，若n大于当前容器大小，则容器resize为n，新元素默认初始化
```
* vector容器插入和删除</br>
```cpp
push_back(elem) // 在容器尾部添加元素
pop_back() // 删除容器最后一个元素
insert(const_iterator pos, elem) // 在迭代器指定pos位置插入elem元素
insert(const_iterator pos,int count, elem) // 在迭代器指定pos位置插入count个elem元素
erase(const_iterator pos) // 删除迭代器指向的元素
erase(const_iterator start, const_iterator end) // 删除迭代器区间[start, end)的元素
claer() // 清空容器
```
* 数据存取
```cpp
vector<int> v1;
vi.at(0); // 用at方法访问元素
v1[0]; // 用[]方法访问元素
v1.front(); // 访问第一个元素
v1.back(); // 访问最后一个元素
```
* 互换容器
```cpp
// swap方法互换容器
v1.swap(v2);

// swap方法可以进行容器缩容，节省内存空间
vector<int> v1(1000000,19);
v1.resize(3); // 重新指定大小后，并不会改变容器的容量
// 经过以上操作后，v1的容量为1000000，大小为3，会发现占用了大量的内存，但是并没有使用，浪费内存空间
// vector<int>(v1)是一个匿名对象，匿名对象会在语句结束后自动销毁，所以使用swap方法进行缩容，会释放掉交换得到容器的多余空间
vector<int>(v1).swap(v1); // 使用swap方法进行缩容
```
## deque容器
deque容器相当于一个双端容器，头和尾都可以插入和删除元素，看上去像是一片连续的内存管理。但是deque容器内部是由一个中控器维护的，中控器负责维护不同的缓冲区，缓冲区可看成一个队列，头和尾都可以操作元素。
```cpp
// 头文件
#include <deque>
```
* deque构造函数
```cpp
// 遍历接口
void printf(const deque<T>& d)
{
    // 传入的参数是const的容器，所有使用的迭代器必须是只读的，即为const_iterator只读迭代器
    for(deque<T>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test()
{
    deque<int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }

    deque<int> d2(d1.begin(),d1.end()); // 区间初始化
    deque<int> d3(d1); // 拷贝构造
    deque<int> d4(10,10); // n个elem构造
}
```
* deque赋值操作
```cpp
deque<int> d1;
deque<int> d2;
d2 = d1; // operator=赋值

// assign赋值
d1.assign(10，10); 
d1.assign(d2.begin(),d2.end()); 
```
* deque大小操作
deque相对于vector是没有capacity的说法，没有容量的限制
```cpp
empty() // 判断deque是否为空
size() // 返回deque中元素的个数
reszie(n) // 重新指定大小，若n小于当前大小，则超出部分被删除，若n大于当前大小，则超出部分默认值为0
resize(n,elem) // 重新指定大小，若n小于当前大小，则超出部分被删除，若n大于当前大小，则超出部分默认值为elem
```
* deque插入和删除</br>
插入和删除指定的位置必须是迭代器
```cpp
// 插入操作
push_back(elem) // 在尾部插入元素
push_front(elem) // 在头部插入元素
insert(pos,elem) // 在pos位置插入elem元素 返回新数据的位置
insert(pos,n,elem) // 在pos位置插入n个elem元素
insert(pos,beg,end) // 在pos位置插入[beg,end)区间的数据] 无返回值

// 删除操作
pop_back() // 删除尾部元素
pop_front() // 删除头部元素
erase(beg,end) // 删除[beg,end)区间的数据 返回下一个数据的位置
erase(pos) // 删除pos位置的数据 返回下一个数据的位置
clear() // 删除所有数据
```
* deque数据存取
```cpp
deque<int> d1;
// 返回索引为idx的元素
d1.at(int idx)
d1[int idx]
// 获取第一个元素
d1.front()
// 获取最后一个元素
d1.back()
```
* deque排序操作
```cpp
// 使用STL通用的sort方法
#include<algorithm>
deque<int> d1;
sotrt(d1.begin(),d1.end()); // 传入迭代器区间
```
### 实例：评委打分
    有5名选手，ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分，取平均分。

    实现步骤：
    1.创建五名选手存放到一个容器中
    2.遍历容器，让用户输入10个评委的打分，并把分数保存到容器中
    3.对容器中的数据进行排序，去除最高和最低分
    4.计算平均分
* 实现——代码编写
```cpp
// 选手信息
class Person
{
public:
    string m_Name;
    float m_Score;
    Person(string name,float score):m_Name(name),m_Score(score){}
};
// 功能模块
// 1.创建5名选手
void createPerson(vector<Person>& v)
{
    Person p1("A",0.0);
    Person p2("B",0.0);
    Person p3("C",0.0);
    Person p4("D",0.0);
    Person p5("E",0.0);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
}
// 2.打分
void setScore(const vector<Person>& v)
{
    for(vector<Person>::const_iterator it = v.begin();it != v.end();it++)
    {
        deque<float> d;
        for(int i = 0;i < 10;i++)
        {
            float score = rand()%41 + 60; // 60~100分区间
            d.push_back(score);
        }

        // 排序
        sort(d.begin(),d.end());
        //  去掉最低分和最高分
        d.pop_front(); // 最低分
        d.pop_back(); // 最高分

        // 计算平均分
        int sum = 0;
        for(deque<float>::iterator dit = d.begin();dit != d.end();dit++)
        {
            sum += *dit;
        }
        float avg = sum / d.size();
        // 平均分赋值给选手
        it->m_score = avg;
    }
}
// 输出
void printf(const vector<Person>& v)
{
    for(vector<Person>::const_iterator it = v.begin();it != v.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 分数："<<it->m_Score<<endl;
    }
    cout << endl;
}
int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    vector<Person> v;
    createPerson(v);
    setScore(v);
    // 显示得分
    printf(v);
}
```

