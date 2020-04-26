#pragma once
#include<string>
#include <typeinfo>

using namespace std;

enum TypeProduct {MILK, BREAD, SAUSAGE};

class Product
{
public:
	Product(string name = "", double weight = 0.0, string manufacturer = "") : name(name), weight(weight), manufacturer(manufacturer) {}
	Product(const Product& obj) : name(obj.name), weight(obj.weight), manufacturer(obj.manufacturer) {}

	void setName(string name);
	void setWeight(double weight);
	void setManufacturer(string manufacturer);

	string getName();
	double getWeight();
	string getManufacturer();
	virtual TypeProduct getTypeProduct();	//функция для получения типа производного класса

protected:
	string name;
	double weight;
	string manufacturer;
};

