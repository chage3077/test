#include "Angel.h"
#include "Pacifist.h"
int main()
{
    AbstructRobot *robot = new Pacifist;
    robot->getInfo();
    cout << "---------------------------------------" << endl;
    robot = new Angel;
    robot->getInfo();
    delete robot;
    return 0;
}