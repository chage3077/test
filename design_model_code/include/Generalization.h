#ifndef GENERALIZATION_H
#define GENERALIZATION_H
class Animal{// 父类
    public:
    Animal();
    //如果析构函数不是虚函数，这会导致在删除基类指针指向的派生类对象时，无法正确调用派生类Dog的析构函数，从而引发潜在的资源泄露问题。
    virtual ~Animal();
    virtual void speak();
};
//子类Dog公开继承父类Animal
class Dog:public Animal{
    public:
    Dog();
    
    ~Dog() override;

    //重写父类的虚函数
    void speak() override;
};

#endif //GENERALIZATION_H