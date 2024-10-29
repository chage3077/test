#include "Phonebugger.h"
#include "Speaker.h"
int main()
{
    // 直接交流
    Speaker *speaker = new Speaker;
    speaker->communicate();
    delete speaker;

    cout << "--------------------------" << endl;

    // 电话虫交流
    Phonebugger *phonebugger = new Phonebugger();
    // 打开权限
    phonebugger->setStart(true);
    // 开始交流
    phonebugger->communicate();
    // 释放资源
    delete phonebugger;

    return 0;
}