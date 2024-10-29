#include "LionCannon.h"
int main()
{
    // 构建狮吼炮
    LionCannon* lionCannon = new LionCannon;

    // 先瞄准
    lionCannon->lockAndaim();
    // 开火
    lionCannon->fire();

    delete lionCannon;

    return 0;
}