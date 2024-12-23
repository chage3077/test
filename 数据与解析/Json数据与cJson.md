# 使用CJSON
要使用cJson解析器，需要在工程文件中添加cJson.c和cJson.h文件
```cpp
#include"./cJson.h"
```
# JSON语法规则
JSON对象是一个无序的键值对集合
* 以“{”开始，以“}”结束，允许嵌套使用
* 每个名称和值成对出现，名称和值之间用“:”分隔
* 键值对之间用“,”分隔
* 在这些字符前后允许存在无意义的空白符</br>

值可以有一下内容
* 一个新的json对象
* 数组：使用[]进行表示
* 数字：直接表示，可以是整数，也可以是浮点数
* 字符串：使用引号表示“”，c/c++一定要有\在引号前面，转义字符
```cpp
const char* ptr = {"{\"name\":\"xiaoming\",\"age\":18}"};
```
* 字面值：false、null、true中的一个（必须是小写）
```cpp
{
    "name":"xiaoming",
    "age":18
}
```
# CJSON解析器基础
### 使用CJSON解析器解析json数据流程
1.创建cJSON指针</br>
2.解析整段JSON数据，返回cJSON指针</br>
3.根据键值对的名称从链表取出对应的值，返回该键值对的地址</br>
4.根据类型提取相关值</br>
5.释放
```cpp
const char* json_data = {"{\"name\":\"xiaoming\",\"age\":18}"};
//1.创建cJSON指针
CJSON* json = nullptr;
//2.解析整段JSON数据，返回cJSON指针
json = CJSON_Parse(json_data);
if(!json)
{
    cout<<"error: "<< CJSON_GetErrorPtr()<< endl;
}
else
{
    cout<<"OK"<<endl;
    // 3.根据键值对的名称从链表取出对应的值，返回该键值对的地址
    cJSON* json_name = cJSON_GetObjectItem(json,"name");
    // 判断数据类型是否为cJSON宏定义的string
    if(json_name->type == cJSON_String)
    {
        cout<<"recv: "<< json_name->valuestring<<endl;
    }
    cJSON* json_age = cJSON_GetObjectItem(json,"age");
    if(json_age->type == cJSON_Number)
    {
        cout<<"recv: "<< json_age->valueint<<endl;
    }
    // 5.释放
    cJSON_Delete(json);
}
```
### 使用cJson解析器解析简单数组
1.创建cJSON指针</br>
2.解析整段JSON数据，返回cJSON指针</br>
3.根据键值对的名称从链表取出对应的值，返回该键值对的地址</br>
4.读取数组，先读取大小，在按序号读取</br>
5.释放
```cpp
const char* json_data = "[1,2,3,4]";
cJSON* root = cJson_Parse(json_data);
if(root == nullptr)
{
    // .....错误信息输出
    return;
}
if(cJSON_IsArray(root))
{
    // 获取数组大小
    int size = cJSON_GetArraySize(root);
    for(int i = 0; i<size; i++)
    {
        cJSON* item = cJSON_GetArrayItem(root,i);
        if(cJSON_IsNumber(item))
        {
            int value = item->valueint;
        }
    }
}
cJSON_Delete(root);
```

### 使用cJson解析器解析带键的二维数组
```cpp
const char* json_data = "{\"array\":[[1,2,3],[4,5,6]]}";
cJSON* root = cJson_Parse(json_data);
// 获取二维数组
cJSON* array = cJSON_GetObjectItem(root,"array");
// 获取行数
int rows = cJSON_GetArraySize(array);
for(int i =0; i<rows; i++)
{
    cJSON* rowJSON = cJSON_GetArrayItem(array,i);
    int cols = cJSON_GetArraySize(rowJSON);
    for(int j = 0; j<cols; j++)
    {
        int value = cJSON_GetArrayItem(rowJSON,j)->valueint;
    }
}
cJSON_Delete(root);
```

### 使用cJson解析器解析嵌套数据
* 读取指定的数据，一步一步读下去
```cpp
// 读取想要的内容
void read_one()
{
    const char* json_data = "{
    \"name\":\"xiaoming\",
    \"age\":18,
    \"address\":
        {
            \"city\":\"shanghai \",
            \"phone \":10086
        }
    }"
    cJSON* root = cJSON_Parse(json_data);
    if(root == nullptr)
    {
        // 错误处理
        return;
    }
    cJSON* address = cJSON_GetObjectItem(root,"address");
    cJSON* city = cJSON_GetObjectItem(address,"city");
    if(cJSON_IsString(city))
    {
        // ......
    }

    cJSON_Delete(root);
}
```
* 递归的方法
```cpp
void recursion_read(cJSON* root)
{
    if(root == nullptr)
    {
        return;
    }
    switch(root->type)
    {
    // 根节点先经过这里
    case cJSON_Object:
        cJSON* child = root->child;
        while(child!=nullptr)
        {
            // 开始处理子节点
            recursion_read(child);
            // 更新要处理的子节点（返回父级后）
            child = child->next;
        }
        break;
    case cJSON_Array:
    {
        int size = cJSON_GetArraySize(root);
        for(int i=0; i<size; i++)
        {
            cJSON* item = cJSON_GetArrayItem(root,i)
            // 递归（嵌套数组）
            recursion_read(item);
        }
    }
        break;
    case cJSON_String:
        cout << "String is: "<<root->valuestring<<endl;
        break;
    case cJSON_Number:
        cout << "Number is: "<<root->valueint<<endl;
        break;
    case cJSON_True:
        break;
    case cJSON_False:
        cout << "Error"<<endl;
        break;
    case cJSON_NULL:
        cout << "Empty"<<endl;
        break;
    default:
        break;
    }
}
```
# 创建JSON数据
```cpp
void createJSON()
{
    cJSON* root = cJSON_CreateObject(); // 创建根节点
    // 添加基本内容
    cJSON_AddStringToObject(root,"name","xiaoming"); // 添加字符串
    cJSON_AddNumberToObject(root,"age",18);

    // 添加嵌套
    cJSON* address = cJSON_CreateObject();
    cJSON_AddStringToObject(address,"city","changsha");
    cJSON_AddStringToObject(address,"home","kaifenglu");
    cJSON_AddItemToObject(address);

    // 添加数组
    cJSON* arry = cJSON_CreateArray();
    for(int i=o; i<5; i++)
    {
        cJSON_AddItemToArray(score,CJSON_CreateNumber(i));
    }
    cJSON_AddItemToObject(root,"arry",arry);
}
```
