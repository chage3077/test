#include <iostream>
#include "Generalization.h"
using namespace std;


    Animal::Animal(){
        cout<<"Animal created."<<endl;
    }
   
    Animal::~Animal(){
        cout<<"Animal destroyed."<<endl;
    }
    
    void Animal::speak(){
        cout<<"Animal sound!"<<endl;
    }

//子类Dog公开继承父类Animal

    Dog::Dog(){
        cout<<"Dog created."<<endl;
    }
    
    Dog::~Dog(){
        cout<<"Dog destroyed."<<endl;
    }

    //重写父类的虚函数
    void Dog:: speak() {
        cout<<"oioioi,I'm a dog."<<endl;
    }
