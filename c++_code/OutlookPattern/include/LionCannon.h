#ifndef LIONCANNON_H
#define LIONCANNON_H
#include "AimLockSystem.h"
#include "CannonShootSystem.h"
#include "CokeSystem.h"
#include "CovertSystem.h"
#include "WindCannonSystem.h"
// 集成子系统，向上提供接口
class LionCannon
{
private:
    /* data */
    AimLockSystem *m_aimLockSystem = nullptr;
    CannonShootSystem *m_cannonShootSystem = nullptr;
    CokeSystem *m_cokeSystem = nullptr;
    CovertSystem *m_covertSystem = nullptr;
    WindCannonSystem *m_windCannonSystem = nullptr;

public:
    LionCannon(/* args */);
    ~LionCannon();
    // 向上提供接口
    void lockAndaim();
    void fire();
};
#endif