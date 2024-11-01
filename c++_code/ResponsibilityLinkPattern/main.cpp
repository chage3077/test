#include "Fudaoyuan.h"
#include "Nianjizhuren.h"
#include "Yuanzhuren.h"
#include "Student.h"
int main()
{
    // 创建三个管理者
    AbstructManager *fudaoyuan = new Fudaoyuan;
    AbstructManager *nianjizhuren = new Nianjizhuren;
    AbstructManager *yuanzhuren = new Yuanzhuren;

    // 学生
    Student *student = new Student;

    // 绑定上级
    fudaoyuan->setNextManager(nianjizhuren);
    nianjizhuren->setNextManager(yuanzhuren);

    // 测试每个请求任务
    student->Request(taskType::chaxuefen, fudaoyuan);
    student->Request(taskType::qiangjia, fudaoyuan);
    student->Request(taskType::zhuanzhuanye, fudaoyuan);
    student->Request(taskType::xiuxue, fudaoyuan);
    student->Request(taskType::tuixue, fudaoyuan);

    student->Request(taskType::chaxuefen, nianjizhuren);
    student->Request(taskType::qiangjia, nianjizhuren);
    student->Request(taskType::zhuanzhuanye, nianjizhuren);
    student->Request(taskType::xiuxue, nianjizhuren);
    student->Request(taskType::tuixue, nianjizhuren);

    student->Request(taskType::chaxuefen, yuanzhuren);
    student->Request(taskType::qiangjia, yuanzhuren);
    student->Request(taskType::zhuanzhuanye, yuanzhuren);
    student->Request(taskType::xiuxue, yuanzhuren);
    student->Request(taskType::tuixue, yuanzhuren);

    // 释放资源
    delete fudaoyuan;
    delete nianjizhuren;
    delete yuanzhuren;
    delete student;

    return 0;
}