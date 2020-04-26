#include "Milk.h"

void Milk::setFatPercent(double percent) 
{
	if (percent < 0.0 || percent > 100.0)
	{
		throw ExpShop(2);
	}
	fatPercent = percent;
}

void Milk::setWaterPercent(double percent)
{
	if (percent < 0.0 || percent > 100.0)
	{
		throw ExpShop(2);
	}
	waterPercent = percent;
}

double Milk::getFatPercent()
{
	return fatPercent;
}

double Milk::getWaterPercent()
{
	return waterPercent;
}
