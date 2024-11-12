#ifndef HORROR_H
#define HORROR_H
#include "AbstructAction.h"
// 恐惧的行为
class HorrorAction : public AbstructAction
{
private:
    /* data */
public:
    // 被男人访问
    void maleDoing(MaleMember *male) override;
    // 被女人访问
    void femaleDoing(FemaleMember *female) override;
    void help();
    void thinking();
};

#endif