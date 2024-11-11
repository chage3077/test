#include "Cooker.h"

Cooker::Cooker()
{
    m_state = new MorningState;
}

void Cooker::working()
{
    m_state->working(this);
}

void Cooker::setState(AbstractState *state)
{
    if(m_state!=nullptr)
    {
        delete m_state;
        m_state = nullptr;
    }
    m_state = state;
}

int Cooker::getClock()
{
    return m_clock;
}

void Cooker::setClock(int clock)
{
    m_clock = clock;
}
