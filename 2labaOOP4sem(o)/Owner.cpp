#include "Owner.h"

void Owner::setName(string name)
{
	this->name = name;
}

void Owner::setLastname(string lastname)
{
	this->lastname = lastname;
}

void Owner::setAge(int age)
{
	this->age = age;
}

string Owner::getName()
{
	return name;
}

string Owner::getLastname()
{
	return lastname;
}

int Owner::getAge()
{
	return age;
}
