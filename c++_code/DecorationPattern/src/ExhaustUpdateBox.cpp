#include "ExhaustUpdateBox.h"

void ExhaustUpdateBox::function()
{
    m_car->function(); // 输出基础的功能
    cout << "The new function: auto Exhaust!" << endl; // 输出新加的功能
}