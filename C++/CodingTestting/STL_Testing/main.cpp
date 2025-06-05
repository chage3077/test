// STL_Testing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "vector_test.h"
#include"JudgeMarking.h"
#include"ListSortExample.h"
#include"StaffMgr.h"
int main()
{
    //Vector_Test* vector_test = new Vector_Test();
    //// 测试Vector填充int数据
    //std::cout << "测试Vector填充int数据...." << std::endl;
    //vector_test->test_vector();
    //// 测试Vectort填充自定义数据
    //std::cout << "测试Vectort填充自定义数据...." << std::endl;
    //vector_test->test_vector_person();
    //// 测试vector填充地址
    //std::cout << "测试vector填充地址...." << std::endl;
    //vector_test->test_vector_person_address();
    //// 测试vector嵌套
    //std::cout << "测试vector嵌套...." << std::endl;
    //vector_test->test_nested_vector();

    //delete vector_test;

    // 案例：评委打分
    // 随机数种子
    /*srand((unsigned int)time(NULL));
    vector<Player> players;
    JudgeMarking judgeMarking;
    judgeMarking.cratePlayer(players);
    judgeMarking.setScore(players);
    judgeMarking.printf_score(players);*/

    // 案例：list的高级排序
    /*ListSortExample listSortExample;
    listSortExample.createPerson();
    listSortExample.sortPerson();*/

    // 案例：map容器员工分组
    srand((unsigned int)time(NULL));
    StaffMgr staffMgr;
    staffMgr.createStaff();
    staffMgr.setGrounp();
    staffMgr.showAllStaffs();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
