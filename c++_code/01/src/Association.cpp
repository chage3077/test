#include <iostream>
#include "Association.h"

Car::Car(string m)
{
    model = m;
}
void Car::showCar()
{
    std::cout << "Car Model:" << model << endl;
}

Person::Person(string n, Car *c)
{
    name = n;
    car = c;
}

void Person::showPerson()
{
    cout << "Person: " << name << endl;
    if (car)
    {
        car->showCar(); // 通过单向关联访问car
    }
    else
    {
        std::cout << "No car owned." << endl;
    }
}
