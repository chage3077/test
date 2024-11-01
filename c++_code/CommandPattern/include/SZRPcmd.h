#ifndef SZRPCMD_H
#define SZRPCMD_H
#include"AbstructCommand.h"
class SZRPcmd:public AbstructCommand
{
private:
    /* data */
public:
    using AbstructCommand::AbstructCommand;
    void execute() override;
    string name() override;
};
#endif