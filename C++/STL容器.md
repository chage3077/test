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
sort(d1.begin(),d1.end()); // 传入迭代器区间
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
## stack容器
    先进后出的数据结构

```cpp
// 构造
stack<T> stk;

// 入栈
stk.push(elem);

// 出栈
stk.pop();

// 查看栈顶元素
stk.top();

// 监测栈是否为空
stk.empty();

// 监测栈的大小
stk.size();
```
## queue容器
    先进先出的数据结构
    一端只能添加数据，另一端只能删除数据
    并且只能访问两端的数据，不能遍历队列
* queue接口
```cpp
// 构造
queue<T> q;
queue(const queue& q);

// 入队
q.push(elem);

// 出队
q.top();

// 查看队头
q.front();
// 查看队尾
q.back();

// 监测队列是否为空
q.empty();

// 查看队列的大小
q.size();
```
## List容器
    STL中的链表list是一种双向循环链表

    对任意的位置进行快速插入或删除元素

    链表的节点拥有prev、next指针域和data数据域

    链表的存储方式不是连续的内存空间，因此list的迭代器只支持前移和后移，不能随便跳跃，只支持++，不支持+1

    list中的迭代器不会随着插入和删除操作而失效，但是在vector中每次删除和插入元素可能会重新开辟内存空间，这样就会使原来的迭代器失效
* list的构造
```cpp
list<int> l1; // 默认构造
list<int> l2(n, elem); // n个elem构造
list<int> l3(l2); // 拷贝构造
list<int> l4(v.begin(), v.end()); // 迭代器区间构造
```
* list的赋值和交换
```cpp
list<int> l1;
list<int> l2;
l2 = l1; // operator= 赋值
l1.assign(n, elem); // assign赋值:n个elem
l1.assign(v.begin(), v.end()); // assign赋值:迭代器区间

// 交换
l1.swap(l2);
```
* list的大小操作
```cpp
list<int> l1;
// 监测list的列表长度
l1.size();
// 监测list是否为空
l1.empty();
// 重新指定大小
l1.resize(n); // 重新指定长度为n,超出部分默认为0
l1.resize(n, elem); // 重新指定长度为n,超出部分用elem填充
```
* list的插入和删除操作
```cpp
// 插入
l1.push_back(elem); // 尾插
l1.push_front(elem); // 头插
l1.insert(pos, elem); // insert在pos位置插入elem
l1.insert(pos, n, elem); // 在pos位置插入n个elem

// 删除
l1.pop_back(); // 删除尾元素
l1.pop_front(); // 删除头元素
l1.erase(pos); // 删除pos位置的元素
l1.erase(beg, end); // 删除[beg, end)区间的元素
l1.clear(); // 删除所有元素

// 移除
l1.remove(elem); // 删除所有值为elem的元素,不用再使用迭代器去进行删除
```
* list数据存取

    对list数据进行存取
    list本质就是链表，不是连续线性空间存储数据，迭代器也不支持随机访问
```cpp
list<int> l1;
l1.front(); // 返回第一个元素
l1.back(); // 返回最后一个元素
```
* list的反转和排序
```cpp
bool myCompare(int v1,int v2)
{
    // 告诉迭代器怎么对比
    // 降序：第一个数大于第二个数
    return v1>v2;
}
```
```cpp
#include<algorithm>
list<int>li;
l1.reverse(); // 反转list
// 所有不支持随机访问迭代器是不可以使用标准算法的sort进行排序
//sort(l1.begin(),l1.end());
// 不支持随机访问迭代器的容器，内部会有对应的排序算法
li.sort(); // 默认从小到大，升序
l1.sort(mycompare)； // 根据myCompare方法实现降序
```
### 排序案例
    将Person自定义数据类型进行排序，Person中有姓名、年龄和身高
    排序规则：按照年龄进行升序排列，年龄相同按照身高进行降序
```cpp
class Person_sort
{
public:
	string m_name;
	int m_height;
	int m_age;

	Person_sort(string name,int height,int age):m_name(name),m_height(height),m_age(age){}
};
class ListSortExample
{
public:
	list<Person_sort>m_PersonLists;
	void createPerson();
	void printf();
	void sortPerson(); // 进行排序
	static bool comparePerson(Person_sort &p1, Person_sort &p2); // 对于自定义类型的list排序需要制定回调函数确定比较规则
};
void ListSortExample::createPerson()
{
	Person_sort p1("张小小", 175, 35);
	Person_sort p2("张中中", 180, 45);
	Person_sort p3("周笑", 170, 40);
	Person_sort p4("霍霍", 190, 25);
	Person_sort p5("张大大", 160, 35);
	Person_sort p6("张坤", 200, 35);

	m_PersonLists.push_back(p1);
	m_PersonLists.push_back(p2);
	m_PersonLists.push_back(p3);
	m_PersonLists.push_back(p4);
	m_PersonLists.push_back(p5);
	m_PersonLists.push_back(p6);
}

void ListSortExample::printf()
{
	for (list<Person_sort>::const_iterator it = m_PersonLists.begin(); it != m_PersonLists.end(); it++)
	{
		cout << "姓名：" << it->m_name << ",年龄：" << it->m_age << ",身高：" << it->m_height << endl;
	}
}

void ListSortExample::sortPerson()
{
	cout << "排序前......." << endl;
	printf();
	cout << "排序后......." << endl;
	m_PersonLists.sort(comparePerson);
	printf();
}
bool ListSortExample::comparePerson(Person_sort& p1, Person_sort& p2)
{
	// 高级排序
	if (p1.m_age == p2.m_age)
	{
		// 年龄相同的情况下，身高按照降序排序
		return p1.m_height > p2.m_height;
	}
	// 按照年龄升序
	return p1.m_age < p2.m_age;
}

```
## set容器
    本质：二叉树，关联式容器，会自动排序
    set和multiset的区别：set不允许重复元素，multiset允许重复元素
* set的构造和赋值
```cpp
#include<set>
set<int> s1; // 默认构造
set<int> s2(s1); // 拷贝构造
```
* set的大小和交换
    
    set容器不支持resize方法
```cpp
set<int> s1;
// 返回容器中的数目
s1.size();

// 监测容器是否为空
s1.empty();

// 交换两个容器的元素
s1.swap(s2);
```
* set的插入和删除
```cpp
set<int> s1;
// 插入
s1.insert(elem); // 插入元素

// 删除
s1.erase(elem); // 删除值为elem的元素
s1.erase(pos); // 删除pos位置的元素,pos是迭代器
s1.erase(beg,end); // 删除区间[beg,end)区间的元素

// 清空
s1.clear();
```
* set查找和统计
```cpp
set<int> s1;
s1.find(elem); // 查找值为elem的元素，返回该元素的迭代器，若不存在返回s1.end()
s1.count(elem); // 查找值为elem的元素，返回值为1或0
```
* set和multiset区别
```cpp
// set不允许重复元素，multiset允许重复元素
// set插入的时候会返回插入的结果
set<int> s1;
pair<set<int>::iterator,bool> ret = s1.insert(elem); // ret保存结果
if(ret.second) // 获取pair的bool值
{
    cout << "插入成功" << endl;
}
else
{
    cout << "插入失败" << endl;
}
```
* set内置类型指定排序规则
    
    set默认排序进行为升序，如果需要指定其他的排序规则，可以使用仿函数进行更改规则。
```cpp
// 指定排序规则，由大到小，需要在插入数据前规定排序规则
// 利用仿函数，本质上是一个类型
class MyCompare
{
public:
    // 第一个小括号是重载符号
    // 第二个小括号是函数参数
    bool operator()(int a, int b) const
    {
        return a > b;
    }
}
set<int,MyCompare>s1;
s1.insert(1);
s1.insert(2);
s1.insert(3);
```
* set自定义类型指定排序规则

    在插入自定义数据类型时，都会指定排序的规则
```cpp
class comparePerson
{
public:
    bool operator()(const Person &a,const Person &b)
    {
        // 按照年龄降序
        return a.m_age > b.m_age;
    }
}
set<Person,comparePerson>s;
Person p1("小白",24);
Person p2("小黑",18);
Person p2("小红",24);
Person p2("小青",20);
s.insert(p1);
s.insert(p2);
s.insert(p3);
s.insert(p4);

// 遍历
for(set<Person,comparePerson>st = s.begin();st!=s.end();st++)
{
    cout<<"姓名："<<st->m_name<<" 年龄："<<st->m_age<<endl;
}
```
## pair对组
    成对出现的数据，利用对组可以返回两个数据
* 创建对组
```cpp
pair<type,type> p(value1,value2);
pair<type,type> p = make_pair(value1,value2);

// 例子：
pair<string,int> p("Tom",15);
cout << "姓名：" <<p.first << "，年龄：" << p.second << endl;
```
## map容器
    map容器中所有的元素为pair
    pair中一个是key值（索引值），一个是value值（实值）
    所有元素都会根据元素的key值进行排序

    关联式容器，底层由二叉树实现

    map不允许重复的key值，multimap允许重复的key值
* map的构造
```cpp
#include<map>
map<T1,T2> m; // 默认构造
map<T1,T2> m1(m); // 拷贝构造

m.insert(pair<T1,T2>(key,value)) // pair<T1,T2>(key,value)是匿名对组

void printf(map<T1,T2> &m)
{
    for(map<T1,T2>::iterator i=m.begin();i!=m.end();i++)
    {
        cout << "Key:" << i->first << " Value:" << i->second << endl;
    }
    cout<<endl;
}
```
* map的大小和交换
```cpp
map<T1,T2> m1;
// 查看map的大小
m1.size();

// 判断map是否为空
m1.empty();

// 交换两个map
m1.swap(m2);
```
* map的插入和删除
```cpp
map<T1,T2> m1;

// 插入元素
m1.insert(pair<T1,T2>(key,value));
m1.insert(make_pair(key,value));
m1.insert(map<T1,T2>::value_type(key,value));
m1[key]=value; // map已经重载[]，若不存在该key，则会返回默认值为0，所以[]不建议插入，最好是使用[]访问到value值

// 删除元素
m1.erase(m1.begin());
m1.erase(key); // 删除指定key的元素
m1.erase(m1.begin(),m1.end());
m1.clear();
```
* map的查找和统计
```cpp
map<T1,T2>m;
// 查找，返回一个迭代器
// 找不到就返回m.end()
map<T1,T2>::iterator pos = m.find(key);

// 统计
m.count(key); // 查找key值存在的个数，map只能是0或1，而multimap就会出现超过1的情况
```
* map的排序

    只能按照key的值从小到大排序

    如果想改变排序规则，需要使用仿函数
```cpp
// 内置类型的排序规则
class MyCompare
{
public:
    bool operator()(int a,int b) const
    {
        // 降序排列
        return a > b;
    }
};
void test()
{
    map<int,int,MyCompare>m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(3,20));
    m.insert(make_pair(5,30));
    m.insert(make_pair(7,40));
}

// 自定义类型的排序规则
class MyCompare
{
public:
    bool operator()(Person &p1,Person &p2) const
    {
        return p1.m_age > p2.m_age;
    }
};
void test_Person()
{
    map<Person,int,MyCompare>m;
    Person p1("Tom",10);
    Person p2("Jack",20);
    Person p3("Mike",30);
    m.insert(make_pair(p1,10));
    m.insert(make_pair(p2,20));
    m.insert(make_pair(p3,30));

    for(map<Person,int,MyCompare>::iterator i=m.begin();i!=m.end();i++)
    {
        //....
    }
}
```
### 案例：员工分组
    拥有十个员工ABCDEFGHIJ，10名员工进入公司后，需要指定员工在哪个部门工作

    员工的信息：姓名、工资组成；部门分为：策划、美术、研发

    随机给10名员工分配部门和工资

    通过multimap进行插入信息key(部门编号)和value(员工信息)

    分部门显示员工信息
```cpp
#define MEISHU 0
#define CEHUA 1
#define YANFA 2
class Staff
{
public:
    string m_name;
    int m_salary;
    int m_deptId;

    Staff()
    {

    }
    Staff(string name, int salary, int deptId):
    m_name(name), m_salary(salary), m_deptId(deptId)
    {

    }
};
class MyCompare
{
public:
    bool operator()(Staff &s1, Staff &s2) const
    {
        // 按照工资降序排
        return s1.m_salary > s2.m_salary;
    }
};
class StaffMgr
{
public:
    vector<Staff> m_staffVector;
    multimap<int, Staff，MyCompare> m_staffMap; // key为部门编号，value为员工信息
    void CreateStaff()
    {
        string str = "ABCDEFGHIJ";
        for(int i = 0; i < 10; i++)
        {
            Staff staff;
            staff.m_name = string("员工") + str[i];

            staff.m_salary = rand() % 10000 + 10000; // 10000-19999

            m_staffVector.push_back(staff);
        }
    }
    void SetGrounp()
    {
        for(vector<Staff>::iterator it = m_staffVector.begin(); it != m_staffVector.end(); it++)
        {
            // 产生随机部门编号
            int index = rand() % 3;
            it->m_deptId = index;
            // 放入multimap容器
            m_StaffMap.insert(make_pair(index, *it));
        }
    }
    void ShowAllStaff()
    {
        // 分部门打印
        // 美术部门起始位置
        auto mit = m_StaffMap.find(0);
        // 策划部门起始位置
        auto mit2 = m_StaffMap.find(1);
        // 研发部门起始位置
        auto mit3 = m_StaffMap.find(2);

        for(;mit!=mit2;++mit)
        {
            cout << "部门：" << mit->first << "员工姓名：" << mit->second.m_name << "员工薪资：" << mit->second.m_salary << endl;
        }
        for(;mit2!=mit3;++mit2)
        {
            cout << "部门：" << mit->first << "员工姓名：" << mit->second.m_name << "员工薪资：" << mit->second.m_salary << endl;
        }
        for(;mit3!=m_StaffMap.end();++mit3)
        {
            cout << "部门：" << mit->first << "员工姓名：" << mit->second.m_name << "员工薪资：" << mit->second.m_salary << endl;
        }
    }
};
```
# STL函数对象
    重载函数调用操作符operator()的类，其对象称为函数对象
    函数对象重载()，行为类似函数调用，也叫仿函数
    特点：
    1.可以像普通函数那样调用，有参数，有返回值
    2.函数对象可以拥有自己的状态（例如成员属性记录状态）
    3.函数对象可以作为参数传递
```cpp
class MyAdd
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};
// 函数对象可以存储自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        m_Count = 0;
    }
    void operator()(string test)
    {
        cout<<test<<endl;
        m_Count++;
    }
    int m_Count = 0; // 函数对象自己内部的状态
}
// 函数对象可以作为参数传递
// 这个函数需要传入一个函数对象作为参数，有点像回调函数
void doPrint(MyPrint &myPrint,string test)
{
    myPrint(test);
}
int main()
{
    MyAdd myAdd; // 函数对象
    myAdd(11,22);

    MyPrint myPrint;
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    myPrint("hello world");
    cout<<"myPrint调用了"<<myPrint.m_Count<<"次"<<endl; // 查看函数对象的次数，次数属于函数对象内部的一个状态

    // 函数对象作为参数传递
    doPrint(myPrint,"hello world");
}
```
## 一元谓词
    前提：仿函数返回值为bool
    定义：仿函数传入的参数只有一个时称为一元谓词（Predicate）

```cpp
// 输出大于5的元素
class Greater5
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void test(vector<int> &v)
{
    // Greater5()是一个匿名的函数对象
    // find_if返回一个迭代器，符合条件的元素位置
    // 只能找到第一个大于5的元素，因为找到之后就退出了
    vecttor<int>::iterator it = find_if(v.begin(), v.end(), Greater5());
    if(it == v.end())
    {
        cout << "没有大于5的元素" << endl;
    }
    else
    {
        cout << "找到大于5的元素：" << *it << endl;
    }
}
```
## 二元谓词
    前提：仿函数返回值为bool
    定义：仿函数传入的参数有2个时称为二元谓词（Predicate）
```cpp
// 使用函数对象改变算法策略
class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test(vector<int> &v)
{
    // MyCompare()匿名对象，仿函数改变算法策略
    sort(v.begin(), v.end(), MyCompare());
}
```
# STL内建仿函数
    STL提供了一些函数对象，有算术仿函数、关系仿函数和逻辑仿函数

    这些仿函数用法和普通函数用法相同
    需要引入头文件#include<functional>
## 算术防函数
    实现四则运算
```cpp
#include<functional>
// negate取反仿函数
negate<int>n;
n(10); // 像普通函数那样调用
// plus加法仿函数
plus<int>p; // 只能同种数据类型相加，所以传递一个int类型即可
p(10, 20);
// 减法
minus<T>m;
// 乘法
multiply<T>m;
// 除法
divide<T>d;
// 取模
modulus<T>m;
```
## 关系仿函数
```cpp
// 使用内建的关系仿函数
void test(vector<int>&v)
{
    // greater<int>()就是内建的仿函数，一个匿名对象
    // greater是大于
    sort(v.begin(),v.end(),greater<int>());
    // less是小于
    sort(v.begin(),v.end(),less<int>());   
}
// 等于
equal_to<T> n;
// 不等于
not_equal_to<T> n;
// 大于等于
greater_equal<T> n;
// 小于等于
less_equal<T> n;
```
## 逻辑仿函数
```cpp
// 逻辑非
logical_not<T> n;
void test(vector<bool>&v)
{
    // 取反参数v的元素
    vector<bool>v2;
    v2.resize(v.size()); // 一定要开辟空间
    // 搬运
    // logical_not<bool>()匿名对象
    transform(v.begin(),v2.begin(),logical_not<bool>());
}
```
# STL算法
    主要由头文件<algorithm>、<functional>、<numeric>组成
    algorithm：包含多种算法，范围大
    functional：包含一些函数对象，定义了一些模板类
    numeric：包含一些数值算法，如 accumulate
## 遍历算法
* for_each遍历
```cpp
// 普通函数
void print(int val)
{
    cout << val << " ";
}
class Print
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
// for_each遍历
void test01(vector<int> &v)
{
    for_each(v.begin(),v.end(),print); // 传入普通函数

    for_each(v.begin(),v.end(),Print()); // 传入函数对象
}
```
* transform算法
```cpp
class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }
};
void test02(vector<int> &v)
{
    vector<int> targetVec;
    targetVec.resize(v.size());
    // transform搬运
    // 仿函数实现每个元素的数据处理
    transform(v.begin(),v.end(),targetVec.begin(),Transform());
}
```
## 查找算法
* find算法

    查找指定元素的迭代器，找不到就返回end()迭代器
```cpp
// 查找内置数据类型
void find_innerData(vector<int> &v)
{
    // 查找是否有5这个元素
    vector<int>::iterator it = find(v.begin(),v.end(),5);

    if(it != v.end())
    {
        cout << "找到5，位置是：" << distance(v.begin(),it) << endl;
    }
    else
    {
        cout << "未找到5" << endl;
    }
}
// 查找自定义数据类型
class Person
{
public:
    bool operator==(const Person &p1,const  Person &p2)
    {
        if(p1.age == p2.age&&p1.name == p2.name)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string name;
    int age;
};
void find_outData(vector<Person> &v,Person &p)
{
    // 自定义Person没有重载==
    // 需要重载==，底层find才能知道如何对比
    vector<Person>::iterator it = find(v.begin(),v.end(),p);

    if(it != v.end())
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}
```
* find_if
    
    按照条件查找，返回对应的迭代器,参数需要传入仿函数
```cpp
// 仿函数
class GreaterFive
{
    bool operator()(int v)
    {
        if(v>5)
            return true;
        return false;
    }
};
// 查找内置数据类型
void find_if_innerData(vector<int> &v)
{
    // 查找大于5的元素
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

    if(it != v.end())
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}
// 查找自定义数据类型
class Person
{
    string name;
    int age;
};
class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.age > 20;
    }
}
void find_if_selfData(vector<Person> &v)
{
    find_if(v.begin(), v.end(), Greater20());
    if(it != v.end())
    {
        cout << "找到" << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}
```
* adjacent_find

    查找相邻重复元素
    传回来的是第一个重复元素的迭代器位置

    adjacent_find(begin, end);
* binary_search

    查找指定元素是否存在，返回bool值

    无序序列不可使用，结果未知

    bool binary_search(begin, end, value);
* count统计元素的个数
```cpp
// 统计内置数据类型
void test(vector<int> &v,int value)
{
    int num = count(v.begin(), v.end(), value);
}
class Person
{
    string m_Name;
    int m_Age;
    bool operator==(const Person &p)
    {
        if(this->m_Age == p.m_Age&&this->m_Name == p.m_Name)
        {
            return true;
        }
        return false;
    }
};
// 统计自定义数据类型
void test(vector<Person> &v,Person& p)
{
    int  num = count(v.begin(), v.end(), p);
}
```
* count_if

    按照条件统计元素个数

    count_if(v.begin(), v.end(),_Pred);
```cpp
class Person
{
    string m_Name;
    int m_Age;
};
class Greater20
{
    bool operator()(int val)
    {
        return val > 20;
    }
};
class Greater20age
{
public:
    bool operator()(const Person &p)
    {
        return p.m_Age > 20;
    }
};
// 统计内置数据类型
void test(vector<int> &v)
{
    int num = count_if(v.begin(), v.end(),Greater20());
}
// 统计自定义数据类型
void test02(vector<Person> &v)
{
    int num = count_if(v.begin(), v.end(),Greater20age());
}
```
## 常用排序算法
* sort

    对容器内的元素进行排序

    sort(iterator beg, iterator end,_Pred);
```cpp
void test(vector<int> &v)
{
    // 默认为升序
    // 改变为降序,使用内建函数对象
    sort(v.begin(), v.end(), greater<int>());
}
```
* random_shuffle随机打乱算法
    随机打乱容器内元素的顺序
```cpp
void test(vector<int> &v)
{
    random_shuffle(v.begin(), v.end());
}
```
* merge合并两个容器

    两个容器必须是有序的，将两个有序的容器合并为一个新的有序容器(有序的方向要一致)
    
    目标容器必须分配好内存空间
```cpp
void test(vector<int> &v1, vector<int> &v2,vector<int> &targertVec)
{
    targetVec.resize(v1.size() + v2.size());
    // 合并之后存放到目标容器
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), targertVec.begin())；
}
```
* reverse
    反转指定范围的元素
```cpp
void test(vector<int> &v)
{
    reverse(v.begin(), v.end());
}
```
## 常用的拷贝和替换算法
* copy

    将指定范围内的元素拷贝到另一个容器中
```cpp
void test(vector<int> &v, vector<int> &targetVec)
{
    // 目标容器需要提前开辟空间
    targetVec.resize(v.size());
    copy(v.begin(), v.end(), targetVec.begin());
}
```
* replace

    将指定范围内的元素替换为指定元素
```cpp
void test(vector<int> &v,int oldVal, int newVal)
{
    replace(v.begin(), v.end(), oldVal, newVal);
}
```
* replace_if

    按照条件进行替换元素，满足条件的都进行替换

    需要传入谓词，谓词的作用就是条件判断
```cpp
class Greater10
{
public:
    bool operator()(int val)
    {
        return val > 10;
    }
};
void test(vector<int> &v, int newVal)
{
    replace_if(v.begin(), v.end(), Greater10(), newVal);
}
```
* swap

    互换两个容器的元素，两个容器的元素类型必须相同

```cpp
void test(vector<int> &v1, vector<int> &v2)
{
    swap(v1, v2);
}
```
## 常用算术生成算法
    包括accumulate和fill算法，需要包括头文件<numeric>
    accumulate:计算容器元素累积总和
    fill:填充容器元素
* accumulate
```cpp
#include<numeric>
int test(vector<int> &v)
{
    // 第三个参数是起始累加值
    int ret = accumulate(v.begin(), v.end(), 0);
    return ret;
}
```
* fill
```cpp
void test(vector<int> &v)
{
    // 一般用于后期填充数据
    fill(v.begin(), v.end(), 10);
}
```
## 常用集合的算法
    进行集合的算法，例如：交集、并集和差集
    set_intersection:求交集
    set_union:求并集
    sert_difference:求差集
* 获取交集set_intersection

    两个容器必须是有序的
```cpp
#inculde<algorithm>
void test(vector<int> &v1, vector<int> &v2,vector<int> &targetVec)
{
    // 目标容器需要提前开辟空间
    // 最特殊的情况就是大容器包含小容器
    targetVec.resize(min(v1.size(), v2.size()));

    // 还会返回一个迭代器，交集最后的迭代器（结束迭代器）
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), targetVec.begin());
}
```
* 获取并集set_union

    两个容器必须是有序的
```cpp
void test(vector<int>& v1, vector<int>& v2, vector<int>& targetVec)
{
    // 目标容器需要提前开辟空间
    // 最特殊的情况就是两个容器都没交集，开辟的空间就是他们元素的总和
    targetVec.resize(v1.size() + v2.size());
    // 获取并集
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), targetVec.begin());
}
```
* 获取差集set_difference
```cpp
void test(vector<int> &v1, vector<int> &v2, vector<int> &targetVec)
{
    // 目标容器需要提前开辟空间
    // 最特殊的情况就是两个容器都没有交集，取最大的容器来开辟空间
    targetVec.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), targetVec.begin());
}
```