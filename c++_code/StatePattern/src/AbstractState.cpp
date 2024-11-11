#include "AbstractState.h"
#include "Cooker.h"
void MorningState::working(Cooker *cooker)
{
    // 得到当前的时间
    int time = cooker->getClock();
    // 判断时间点
    if (time < 8)
        cout << "The clock is : " << time << ".Is going to prepare breakfast." << endl;
    else if (time > 8 && time < 11)
        cout << "The clock is : " << time << ". Is going to prepare food." << endl;
    else
    {
        // 切换另一个状态
        cooker->setState(new NoonState);
        cooker->working();
    }
}

void NoonState::working(Cooker *cooker)
{
    // 得到当前的时间
    int time = cooker->getClock();
    // 判断时间点
    if (time < 13)
        cout << "The clock is : " << time << ".Is going to prepare lunch." << endl;
    else
    {
        // 切换另一个状态
        cooker->setState(new AfternoonState);
        cooker->working();
    }
}

void AfternoonState::working(Cooker *cooker)
{
    // 得到当前的时间
    int time = cooker->getClock();
    // 判断时间点
    if (time < 15)
        cout << "The clock is : " << time << ".Is going to prepare cake." << endl;
    else if (time > 15 && time < 18)
        cout << "The clock is : " << time << ". Is going to prepare foot." << endl;
    else
    {
        // 切换另一个状态
        cooker->setState(new NightState);
        cooker->working();
    }
}

void NightState::working(Cooker *cooker)
{
    // 得到当前的时间
    int time = cooker->getClock();
    // 判断时间点
    if (time < 19)
        cout << "The clock is : " << time << ".Is going to eat dinner." << endl;
    else
        cout << "The clock is : " << time << ". Is going to sleep." << endl;
}
