#ifndef ANGERACTION_H
#define ANGERACTION_H
#include "AbstructAction.h"
// 生气的行为
class AngerAction : public AbstructAction
{
private:
    /* data */
public:
    // 被男人访问
    void maleDoing(MaleMember *male) override;
    // 被女人访问
    void femaleDoing(FemaleMember *female) override;
    void fight();
    void warn();
};

#endif