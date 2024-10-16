#ifndef SMOKERTEAM_H
#define SMOKERTEAM_H
#include "AbstructTeam.h"
class SmokerTeam : public AbstructTeam
{
private:
    /* data */
public:
    using AbstructTeam::AbstructTeam;
    void teamGoal() override;
};
#endif