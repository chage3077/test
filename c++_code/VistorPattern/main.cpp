#include "CaoMaoTeam.h"
#include "MaleMember.h"
#include "FemaleMember.h"
int main()
{
    // 时间随机数种子
    srand(time(NULL));
    vector<string> names{
        "Luff", "Geory", "Sam", "Joe", "Faker", "Bin", "Diusde"};
    CaoMaoTeam *team = new CaoMaoTeam;
    for (const auto &item : names)
    {
        team->addTeam(new MaleMember(item));
    }

    team->addTeam(new FemaleMember("Sally"));
    team->addTeam(new FemaleMember("Coke"));

    team->display();

    delete team;

    return 0;
}