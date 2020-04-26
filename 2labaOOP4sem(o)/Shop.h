#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Owner.h"
#include "Product.h"
#include "WorkMode.h"
#include "Milk.h"
#include "Bread.h"
#include "Sausage.h"

using namespace std;

class Shop
{
public:
	Shop(string name = "Домашний", string beginTime = "9:00", string endTime = "19:00") : name(name), 
		workMode(WorkMode(beginTime, endTime)) {}
	Shop(const Shop& obj);

	void setName(string name);
	void setOwner(Owner* owner);
	string getName();
	Owner* getOwner();
	WorkMode& getWorkMode();
	vector<Product*>& getProducts();
	void showProduct();

	~Shop();

private:
	string name;
	Owner *owner = nullptr;
	WorkMode workMode;
	vector<Product*> products;
};

