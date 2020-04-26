#pragma once
#include "Product.h"
#include "ExpShop.h"

class Bread :
	public Product
{
public:
	Bread(double proteinPercent = 6.5, double carbohydratesPercent = 45.4, string name = "Хлеб", double weight = 1.00,
		string manufacturer = "Пекарь") : proteinPercent(proteinPercent), carbohydratesPercent(carbohydratesPercent),
		Product(name, weight, manufacturer) {}
	Bread(const Bread& obj) : proteinPercent(obj.proteinPercent), carbohydratesPercent(obj.carbohydratesPercent),
		Product(obj) {}

	void setProteinPercent(double percent) throw(ExpShop);
	void setCarbohydratesPrecent(double percent) throw(ExpShop);

	double getProteinPercent();
	double getCarbohydratesPercent();

private:
	double proteinPercent;
	double carbohydratesPercent;
};

