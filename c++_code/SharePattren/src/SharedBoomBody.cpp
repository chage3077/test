#include "SharedBoomBody.h"

void SharedBoomBody::move(int x, int y, int speed)
{
    cout << "The Boom is " << speed << "km/h to (" << x << "," << y << ")" << endl;
}

void SharedBoomBody::draw(int x, int y)
{
    cout << "At (" << x << "," << y << ") draw." << endl;
}
