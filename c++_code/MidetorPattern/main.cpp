#include "Chinese.h"
#include "America.h"
#include "Janpan.h"
#include "Australia.h"
#include "WorldGovt.h"
#include "RevoluAmy.h"
int main()
{
    // 中介
    WorldGovt *worldGovt = new WorldGovt;
    RevoluAmy *army = new RevoluAmy;
    // 国家
    Chinese *China = new Chinese(worldGovt);
    Australia *_Australia = new Australia(worldGovt);
    Janpan *_Janpan = new Janpan(army);
    America *_America = new America(army);
    // 添加
    worldGovt->addCountry(China);
    worldGovt->addCountry(_Australia);
    army->addCountry(_Janpan);
    army->addCountry(_America);

    China->declare("Hello, I am Chinese.Can you give me some money?", _Australia->getName());
    _Australia->declare("Hello, I am Australian.Can you give me some hotdog?", China->getName());
    _Janpan->declare("emmmmm,I want to use your plane.", _America->getName());
    _America->declare("Yes,can I fuck you?", _Janpan->getName());

    // 释放资源
    delete worldGovt;
    delete army;
    delete China;
    delete _Australia;
    delete _Janpan;
    delete _America;
    return 0;
}