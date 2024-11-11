#include "Fan.h"

void Fan::start(Weather weather)
{
    if (m_stratehy != nullptr)
    {
        delete m_stratehy;
        m_stratehy = nullptr;
    }
    switch (weather)
    {
    case Weather::cool:
        m_stratehy = new Level1;
        /* code */
        break;
    case Weather::normal:
        m_stratehy = new Level2;
        break;
    case Weather::hot:
        m_stratehy = new Level3;
        break;
    default:
        break;
    }
    m_stratehy->function();
}

Fan::~Fan()
{
    if (m_stratehy != nullptr)
        delete m_stratehy;
}
