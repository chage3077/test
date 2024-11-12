#ifndef FEMALEMEMBER_H
#define FEMALEMEMBER_H
#include "AbstructMember.h"
class FemaleMember : public AbstructMember
{
private:
    /* data */
public:
    using AbstructMember::AbstructMember;
    void accept(AbstructAction *action) override;
};
#endif