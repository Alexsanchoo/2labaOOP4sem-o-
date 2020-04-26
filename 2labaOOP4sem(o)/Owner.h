#pragma once
#include<string>

using namespace std;

class Owner
{
public:
	Owner(string name = "", string lastname = "", int age = 0) : name(name), lastname(lastname), age(age) {}
	Owner(const Owner& obj) : name(obj.name), lastname(obj.lastname), age(obj.age) {}

	void setName(string name);
	void setLastname(string lastname);
	void setAge(int age);

	string getName();
	string getLastname();
	int getAge();

private:
	string name;
	string lastname;
	int age;
};

