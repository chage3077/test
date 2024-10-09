#include "Factory.h"
#include "CatFactory.h"
#include "DogFactory.h"
int main()
{
    // 创建简单工厂
    // Factory *factory = new Factory;
    // 创建子类对象
    // Animal *obj = factory->createAnimal(Type::Dog);
    // obj->Sound();
    // obj->Behavior();
    // obj = factory->createAnimal(Type::Cat);
    // obj->Sound();
    // obj->Behavior();

    // 创建父类指针
    Factory *base_fac = nullptr;
    Animal *ani_ptr = nullptr;

    base_fac = new DogFactory; // 基类工厂指向子类DogFactory
    ani_ptr = base_fac->createAnimal();
    ani_ptr->Sound();
    ani_ptr->Behavior();

    base_fac = new CatFactory;
    ani_ptr = base_fac->createAnimal();
    ani_ptr->Sound();
    ani_ptr->Behavior();

    delete base_fac;
    delete ani_ptr;
    return 0;
}