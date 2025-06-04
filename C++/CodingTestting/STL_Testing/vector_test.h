#pragma once
#include<string>
#include<iostream>
class Person
{
public:
	std::string name;
	int age;

	Person(std::string _name,int _age)
	{
		name = _name;
		age = _age;
	}
};
class Vector_Test
{
public:
	Vector_Test();
	~Vector_Test();

	template<class T>
	void static myPrintf(T val);
	void test_vector();
	void test_vector_person();
	void test_vector_person_address();
	void test_nested_vector();

private:

};
template<class T>
void Vector_Test::myPrintf(T val)
{
	std::cout << val << std::endl;
}


