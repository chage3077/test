#include "LoginManager.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

using namespace std;
LoginManager::LoginManager()
{
    m_person = nullptr;
}

LoginManager::~LoginManager()
{
}

void LoginManager::login(string filename, int type, MenuMgr *menuMgr)
{
    // 根据不同的类型进行登录
    // 读文件
    ifstream ifs;
    ifs.open(filename, ios::in);

    // 判断文件是否存在
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接收数据
    int id;
    string name;
    string pwd;

    // 判断身份
    if (type == 1)
    {
        cout << "请输入学号：" << endl;
        cin >> id;
    }
    else if (type == 2)
    {
        cout << "请输入工号：" << endl;
        cin >> id;
    }
    cout << "请输入用户名：" << endl;
    cin >> name;
    cout << "请输入密码：" << endl;
    cin >> pwd;

    int fId = 0;  // 从文件中读取的id
    string fName; // 从文件中获取的用户名
    string fPwd;  // 从文件中获取的密码
    // 身份认证
    if (type == 1)
    {
        // 学生身份验证
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 遇到空格会跳过
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "学生登录成功！" << endl;
                ifs.close(); // 关闭文件
                system("pause");
                system("cls");
                m_person = new Student(fId, fName, fPwd); // 父类指针指向子类
                // 进入学生的子菜单
                menuMgr->showStudentMenu(m_person);
                return;
            }
        }
    }
    else if (type == 2)
    {
        // 教师身份验证
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) // 遇到空格会跳过
        {
            if (fId == id && fName == name && fPwd == pwd)
            {
                cout << "教师登录成功！" << endl;
                ifs.close(); // 关闭文件
                system("pause");
                system("cls");
                m_person = new Teacher(fId, fName, fPwd); // 父类指针指向子类
                // 进入教师的子菜单
                menuMgr->showTeacherMenu(m_person);
                return;
            }
        }
    }
    else if (type == 3)
    {
        // 管理员身份验证
        while (ifs >> fName && ifs >> fPwd) // 遇到空格会跳过
        {
            if (fName == name && fPwd == pwd)
            {
                cout << "管理员登录成功！" << endl;
                ifs.close(); // 关闭文件
                system("pause");
                system("cls");
                m_person = new Manager(fName, fPwd); // 父类指针指向子类
                // 进入管理员的子菜单
                menuMgr->showManagerMenu(m_person);
                return;
            }
        }
    }
    cout << "验证登陆失败！" << endl;
    system("pause");
    system("cls");

    return;
}
