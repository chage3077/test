#include "HoerAgency.h"
#include "MaierAgency.h"
#include "XiaoFang.h"
#include "XiaoHong.h"
#include "XiaoMing.h"
int main()
{
    // 发布者
    NewsAgency *news_1 = new HoerAgency;
    NewsAgency *news_2 = new MaierAgency;
    // 订阅者
    XiaoMing *xiaoming = new XiaoMing(news_1, "xiaoming");
    XiaoFang *xiaofang = new XiaoFang(news_1, "xiaofang");
    XiaoHong *xiaohong = new XiaoHong(news_2, "xiaohong");

    // 发布者推送消息
    news_1->notify("Janpan fights to America");
    cout << "-------------------------------------" << endl;
    news_2->notify("Trump is loving Harles");

    // 释放资源
    delete news_1;
    delete news_2;
    delete xiaoming;
    delete xiaofang;
    delete xiaohong;

    return 0;
}