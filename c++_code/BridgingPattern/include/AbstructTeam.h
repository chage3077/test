#ifndef ABSTRUCTTEAM_H
#define ABSTRUCTTEAM_H
#include <iostream>
#include <string>
#include <map>
using namespace std;
// 定义团队里的成员变量——人
struct Person
{
    string name;    // 人名
    string age;     // 年龄
    string ability; // 职责
    string job;     // 职业

    Person(string p_name, string p_age, string p_ability, string p_jop)
    {
        this->name = p_name;
        this->age = p_age;
        this->ability = p_ability;
        this->job = p_jop;
    }
};
// 定义实现层——团队
class AbstructTeam
{
private:
    /* data */
protected:
    map<string, Person *> m_teamMap; // 用于存储团队里面的人
    string m_name;                   // 用于记录团队的名字
public:
    AbstructTeam(string name) : m_name(name) {};
    string getName();
    void addPerson(Person *person); // 把人添加到团队中
    void showTeam();                // 把团队的信息展示出来
    virtual void teamGoal() = 0;    // 明确该团队的目标
    virtual ~AbstructTeam();
};
#endif