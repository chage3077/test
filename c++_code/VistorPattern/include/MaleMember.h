#ifndef MALEMEMBER_H
#define MALEMEMBER_H
#include "AbstructMember.h"
// 进行分类——男性子类
class MaleMember : public AbstructMember
{
private:
    /* data */
public:
    using AbstructMember::AbstructMember;
    void accept(AbstructAction *action) override;
};

#endif