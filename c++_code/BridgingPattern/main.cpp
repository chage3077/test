#include "CaoMaoTeam.h"
#include "SmokerTeam.h"
#include "HaninkShip.h"
#include "HaijunShip.h"
int main()
{
    // 草帽团海贼
    CaoMaoTeam *caomaoTeam = new CaoMaoTeam("CaoMaoTeam");
    // 人
    Person *xiaojiao = new Person("XiaoJiao", "22", "doctor", "pirate");
    Person *Jone = new Person("Jone", "25", "leader", "pirate");
    Person *Fanzi = new Person("Fanzi", "54", "cooker", "pirate");
    Person *Aiannel = new Person("Aiannel", "25", "fighter", "pirate");
    // 添加团队
    caomaoTeam->addPerson(xiaojiao);
    caomaoTeam->addPerson(Jone);
    caomaoTeam->addPerson(Fanzi);
    caomaoTeam->addPerson(Aiannel);
    // 船
    HaninkShip *haninkShip = new HaninkShip(caomaoTeam);
    haninkShip->show();
    haninkShip->feature();
    cout << "----------------------------------" << endl;
    // 海军
    SmokerTeam *smokerTeam = new SmokerTeam("SmokerTeam");
    // 人
    Person *Kim = new Person("Kim", "30", "leader", "policeman");
    Person *Naxi = new Person("Nanxi", "28", "cook", "policeman");
    Person *Nandi = new Person("Nandi", "45", "doctor", "policeman");
    Person *Ubanten = new Person("Ubanten", "29", "fighter", "policeman");
    // 添加团队
    smokerTeam->addPerson(Kim);
    smokerTeam->addPerson(Naxi);
    smokerTeam->addPerson(Nandi);
    smokerTeam->addPerson(Ubanten);
    // 船
    HaijunShip *haijunShip = new HaijunShip(smokerTeam);
    haijunShip->show();
    haijunShip->feature();

    // 释放内存(团队里的人内存会随着团队内存释放而释放)
    // 草帽团
    delete caomaoTeam;
    delete haninkShip;
    // 海军
    delete smokerTeam;
    delete haijunShip;
    return 0;
}