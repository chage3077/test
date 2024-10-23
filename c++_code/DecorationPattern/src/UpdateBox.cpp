#include "UpdateBox.h"

void UpdateBox::updateToCar(Car *car)
{
    m_car = car;             // 保存汽车型号
    m_name = car->getName(); // 保存汽车的名字
}