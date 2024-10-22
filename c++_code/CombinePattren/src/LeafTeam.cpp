#include "LeafTeam.h"
void LeafTeam::display()
{
    cout << "This is " << this->m_name << " , my boss is " << m_parent->getName() << endl;
}

LeafTeam::~LeafTeam()
{
    cout<<m_name<<" is broken!"<<endl;
}
