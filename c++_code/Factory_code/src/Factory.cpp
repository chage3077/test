// #include "Factory.h"
// #include "Dog.h"
// #include "Cat.h"
//简单工厂模式实现的代码
// Animal *Factory::createAnimal(Type type)
// {
//     Animal *ptr = nullptr;
//     switch (type)
//     {
//     case Type::Dog:
//         ptr = new Dog;
//         break;
//     case Type::Cat:
//         ptr = new Cat;
//         break;
//     default:
//         break;
//     }
//     return ptr;
// }