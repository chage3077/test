#include "Fan.h"
int main()
{
    Fan *fan = new Fan;
    cout << "Today is so cool." << endl;
    fan->start(Weather::cool);
    cout << "Today is normal.Not cool not hot." << endl;
    fan->start(Weather::normal);
    cout << "Today is hot." << endl;
    fan->start(Weather::hot);

    delete fan;
    return 0;
}