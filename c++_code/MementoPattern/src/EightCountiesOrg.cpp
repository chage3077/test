#include "EightCountiesOrg.h"

void EightCountiesOrg::setStstus(string msg)
{
    m_msg = msg;
}

string EightCountiesOrg::getStatus()
{
    return m_msg;
}

History *EightCountiesOrg::saveHistory()
{
    History *history = new History(m_msg);
    return history;
}

void EightCountiesOrg::getStateFormHistory(History *history)
{
    m_msg = history->getHistory();
}

void EightCountiesOrg::acknowledge()
{
    cout << "We should find our mistake!" << endl;
}
