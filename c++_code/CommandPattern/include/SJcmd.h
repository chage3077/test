#ifndef SJCMD_H
#define SJCMD_H
#include "AbstructCommand.h"
class SJcmd:public AbstructCommand
{
private:
    /* data */
public:
    using AbstructCommand::AbstructCommand;
    void execute() override;
    string name() override;
};
#endif