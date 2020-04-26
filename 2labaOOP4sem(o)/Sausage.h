#pragma once
#include "Product.h"
class Sausage :
	public Product
{
public:
	Sausage(string meat = "������", string sort = "������", string name = "�������", double weight = 0.45,
		string manufacturer = "����") : meat(meat), sort(sort), Product(name, weight, manufacturer) {}
	Sausage(const Sausage& obj) : meat(obj.meat), sort(obj.sort), Product(obj) {}

	void setMeat(string meat);
	void setSort(string sort);

	string getMeat();
	string getSort() throw(int);

private:
	string meat;
	string sort;
};

