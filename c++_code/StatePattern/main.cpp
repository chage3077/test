#include "Cooker.h"
#include <vector>
int main()
{
    Cooker *cooker = new Cooker;
    vector<int> time = {7, 9, 12, 14, 16, 18, 20};
    for (const auto it : time)
    {
        cooker->setClock(it);
        cooker->working();
    }
    delete cooker;
    return 0;
}