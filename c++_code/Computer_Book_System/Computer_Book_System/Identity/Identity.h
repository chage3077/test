#ifndef IDENTITY_H
#define IDENTITY_H
#include <string>
#include <iostream>
using namespace std;
class Identity {
private:
    string m_name; // 用户名
    string m_pwd; // 密码
public:
    Identity(){}
    ~Identity(){}
    Identity(string name, string pwd):m_name(name), m_pwd(pwd) {}
    virtual void operMenu() = 0; // 纯虚函数，不同子类的操作菜单
    void setName(string &name)
    {
        m_name = name;
    }
    string getName()
    {
        return m_name;
    }
    void setPwd(string pwd)
    {
        m_pwd = pwd;
    }
    string getPwd()
    {
        return m_pwd;
    }

};
#endif