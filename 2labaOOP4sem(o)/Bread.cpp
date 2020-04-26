#include "Bread.h"

void Bread::setProteinPercent(double percent) throw(ExpShop)	//������������� ����������, ��� ��� �������
{																//����� �������� ���������� ExpShop
	if (percent < 0.0 || percent > 100.0)	//���� ������� �� ������, �� ������ ����������
	{
		throw ExpShop(2);
	}
	proteinPercent = percent;
}

void Bread::setCarbohydratesPrecent(double percent) throw(ExpShop)
{
	if (percent < 0.0 || percent > 100.0)
	{
		throw ExpShop(2);
	}
	carbohydratesPercent = percent;
}

double Bread::getProteinPercent()
{
	return proteinPercent;
}

double Bread::getCarbohydratesPercent()
{
	return carbohydratesPercent;
}
