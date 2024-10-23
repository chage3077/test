#include "ClearUpdateBox.h"

void ClearUpdateBox::function()
{
    m_car->function(); // 输出基础的功能
    cout << "The new function: auto clearing!" << endl;
}