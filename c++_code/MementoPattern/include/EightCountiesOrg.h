#ifndef EIGHTCOUNTIESORG_H
#define EIGHTCOUNTIESORG_H
#include<iostream>
#include<string>
#include"History.h"
using namespace std;
// 历史的亲身经历者
class EightCountiesOrg
{
private:
    /* data */
    string m_msg;
public:
    void setStstus(string msg); // 八国联军真正做的坏事
    string getStatus(); // 获取从history解封装后的信息
    History* saveHistory(); // 记录历史：把数据封装成history对象
    void getStateFormHistory(History* history); // 得到历史消息：不负责加载历史消息，加载由记录者进行
    void acknowledge();
};
#endif