#include"Cat.h" // 注意头文件包含顺序
#include "CatFactory.h"
CatFactory::CatFactory()
{
}
Animal *CatFactory::createAnimal()
{
    return new Cat;
}

CatFactory::~CatFactory()
{
    std::cout<<"CatFactory has been broken...."<<std::endl;
}
