#include "DrivingUpdateBox.h"

void DrivingUpdateBox::function()
{
    m_car->function(); // 输出基础的功能
    cout << "The new function: auto driving!" << endl;
}