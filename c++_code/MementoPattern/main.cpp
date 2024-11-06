#include "EightCountiesOrg.h"
#include "History.h"
#include "Recorder.h"
#include <vector>
int main()
{
    vector<string> vec_msg{
        "They killed people.",
        "They fired our houses.",
        "They stole our much money.",
        "They broke our many spenlid places."};

    // 经历者
    EightCountiesOrg *eightCountiesOrg = new EightCountiesOrg;
    Recorder *recorder = new Recorder;
    // 封装八国联军做的恶行,由recoder对象进行保存
    for (int i = 0; i < vec_msg.size(); i++)
    {
        eightCountiesOrg->setStstus(vec_msg.at(i));
        recorder->addHistory(i, eightCountiesOrg->saveHistory());
    }
    // 让八国联军承认他们的恶行
    eightCountiesOrg->acknowledge();
    for (int i = 0; i < vec_msg.size(); i++)
    {
        eightCountiesOrg->getStateFormHistory(recorder->getHistory(i));
        cout << "They says :" << eightCountiesOrg->getStatus() << endl;
    }

    return 0;
    delete eightCountiesOrg;
    delete recorder;
}