#ifndef ABSTRUCTACTION_H
#define ABSTRUCTACTION_H
class MaleMember;
class FemaleMember;
class AbstructAction
{
private:
    /* data */
public:
    // 被男人访问
    virtual void maleDoing(MaleMember *male) = 0;
    // 被女人访问
    virtual void femaleDoing(FemaleMember *female) = 0;
    virtual ~AbstructAction() {}
};

#endif