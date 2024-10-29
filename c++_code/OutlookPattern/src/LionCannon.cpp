#include "LionCannon.h"

LionCannon::LionCannon()
{
    // 给子系统开辟内存
    m_aimLockSystem = new AimLockSystem;
    m_cannonShootSystem = new CannonShootSystem;
    m_cokeSystem = new CokeSystem;
    m_covertSystem = new CovertSystem;
    m_windCannonSystem = new WindCannonSystem;
}

LionCannon::~LionCannon()
{
    // 释放内存
    delete m_aimLockSystem;
    delete m_cannonShootSystem;
    delete m_cokeSystem;
    delete m_covertSystem;
    delete m_windCannonSystem;
}

void LionCannon::lockAndaim()
{
    // 调用子系统
    m_cokeSystem->imitCoke();
    m_covertSystem->convertCokeToEnergy();
    m_aimLockSystem->AimLock();
}

void LionCannon::fire()
{
    // 开火
    m_cannonShootSystem->cannonFire();
    m_windCannonSystem->windcannonFire();
}
