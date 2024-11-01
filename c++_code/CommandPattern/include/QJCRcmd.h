#ifndef QJCRCMD_H
#define QJCRCMD_H
#include "AbstructCommand.h"
class QJCRcmd : public AbstructCommand
{
private:
    /* data */
public:
    using AbstructCommand::AbstructCommand;
    void execute() override;
    string name() override;
};
#endif