#include "ManagerTeam.h"
#include"LeafTeam.h"
#include<vector>
void clear(AbstructTeam* root)
{
    if(root == nullptr) // 递归停止操作
        return;
    if(root && root->hasChild()) // root不为空，且有孩子节点
    {
        // dynamic_cast可用于转换类型，主要用于继承关系之间的转换
        ManagerTeam* team = dynamic_cast<ManagerTeam*>(root);
        // 获取孩子节点
        list<AbstructTeam*> temp_list = team->getChilds();
        for(const auto& item : temp_list)
        {
            // 执行递归操作
            clear(item);
        }
    }
    delete root;
}
int main()
{
    // 创建根节点
    ManagerTeam* root = new ManagerTeam("XinHuaXiaoXue_TuanWei");
    ManagerTeam* jiaodao = new ManagerTeam("JiaoDaoChu");
    ManagerTeam* zhengjiao = new ManagerTeam("ZhengJiaoChu");
    // 创建子节点
    LeafTeam* jiaoxuezu = new LeafTeam("JiaoXueZu");
    LeafTeam* yantaozu = new LeafTeam("YanTaoZu");
    LeafTeam* houqingzu = new LeafTeam("HouQingZu");
    LeafTeam* baoweichu = new LeafTeam("BaoWeiChu");

    // 建立关联
    root->addChild(jiaodao);
    root->addChild(zhengjiao);
    jiaodao->addChild(jiaoxuezu);
    jiaodao->addChild(yantaozu);
    zhengjiao->addChild(houqingzu);
    zhengjiao->addChild(baoweichu);

    root->display();
    jiaodao->display();
    zhengjiao->display();

    clear(root);

}