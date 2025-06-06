#ifndef COMPUTERROOM_H
#define COMPUTERROOM_H
#include<iostream>
using  namespace std;
class ComputerRoom
{
private:
    int m_roomId; // 机房id
    int m_maxNum; // 机房容量
public:
    void setRoomId(int id);
    int getRoomId();
    void setMaxNum(int num);
    int getMaxNum();
    ComputerRoom();
    ~ComputerRoom();
};

#endif