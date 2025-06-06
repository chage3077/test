#include "ComputerRoom.h"

void ComputerRoom::setRoomId(int id)
{
    m_roomId = id;
}

int ComputerRoom::getRoomId()
{
    return m_roomId;
}

void ComputerRoom::setMaxNum(int num)
{
    m_maxNum = num;
}   

int ComputerRoom::getMaxNum()
{
    return m_maxNum;
}

ComputerRoom::ComputerRoom()
{
}

ComputerRoom::~ComputerRoom()
{
}
