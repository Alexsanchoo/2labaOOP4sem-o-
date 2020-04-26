#include "Product.h"
#include "Milk.h"
#include "Bread.h"
#include "Sausage.h"

void Product::setName(string name)
{
	this->name = name;
}

void Product::setWeight(double weight)
{
	this->weight = weight;
}

void Product::setManufacturer(string manufacturer)
{
	this->manufacturer = manufacturer;
}

string Product::getName()
{
	return name;
}

double Product::getWeight()
{
	return weight;
}

string Product::getManufacturer()
{
	return manufacturer;
}

TypeProduct Product::getTypeProduct()
{
	if (typeid(*this) == typeid(Milk))
	{
		return MILK;
	}
	else if (typeid(*this) == typeid(Bread))
	{
		return BREAD;
	}
	else if (typeid(*this) == typeid(Sausage))
	{
		return SAUSAGE;
	}
}
