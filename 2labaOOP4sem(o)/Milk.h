#pragma once
#include "Product.h"
#include "ExpShop.h"

class Milk :
	public Product
{
public:
	Milk(double fatPercent = 3.3, double waterPercent = 87.0, string name = "Молоко", double weight = 1.03,
		string manufacturer = "Снов") : fatPercent(fatPercent), waterPercent(waterPercent), Product(name, weight, manufacturer) {}
	Milk(const Milk& obj) : Product(obj), fatPercent(obj.fatPercent), waterPercent(obj.waterPercent) {}

	void setFatPercent(double percent) throw(ExpShop);
	void setWaterPercent(double percent) throw(ExpShop);

	double getFatPercent();
	double getWaterPercent();

private:
	double fatPercent;
	double waterPercent;
};

