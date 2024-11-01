#ifndef ABSTRUCTCOMMAND_H
#define ABSTRUCTCOMMAND_H
#include "Cook.h"
class AbstructCommand
{
private:
    /* data */
protected:
    Cook *m_cooker = nullptr;

public:
    AbstructCommand(Cook *cooker) : m_cooker(cooker) {}; // 绑定命令执行者
    virtual void execute() = 0;
    virtual string name() = 0;
    virtual ~AbstructCommand() {};
};
#endif