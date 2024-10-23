#include "ClearUpdateBox.h"
#include "DrivingUpdateBox.h"
#include "ExhaustUpdateBox.h"
#include "JIaQi1699.h"
int main()
{
    Car *car_JIaQi1699 = new JIaQi1699("JiaQi1699");
    // 升级盒子
    UpdateBox *clearBox = new ClearUpdateBox;
    UpdateBox *driveBox = new DrivingUpdateBox;
    UpdateBox *exhaustBox = new ExhaustUpdateBox;

    // 层层装饰
    clearBox->updateToCar(car_JIaQi1699);
    driveBox->updateToCar(clearBox);
    exhaustBox->updateToCar(driveBox);

    // 查看功能
    exhaustBox->function();

    // 析构
    delete car_JIaQi1699;
    delete clearBox;
    delete driveBox;
    delete exhaustBox;

    return 0;
}