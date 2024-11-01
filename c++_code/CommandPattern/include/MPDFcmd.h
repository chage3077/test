#ifndef MPDFCMD_H
#define MPDFCMD_H
#include"AbstructCommand.h"
class MPDFcmd:public AbstructCommand
{
private:
    /* data */
public:
    using AbstructCommand::AbstructCommand; // 继承父类的构造函数
    void execute() override;
    string name() override;
};
#endif