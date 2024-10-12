#ifndef ASSOCIATION_H
#define ASSOCIATION_H
#include <iostream>
#include <string>
using namespace std;
//1.单向关联
// Car 类定义
class Car {
public:
    string model;

    Car(string m);

    void showCar();
};

// Person 类定义
class Person {
private:
    Car* car;  // 单向关联：Person 知道 Car

public:
    string name;

    Person(string n, Car* c);

    void showPerson();
};
#endif