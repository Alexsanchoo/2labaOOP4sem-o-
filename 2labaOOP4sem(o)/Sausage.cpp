#include "Sausage.h"

void Sausage::setMeat(string meat)
{
	this->meat = meat;
}

void Sausage::setSort(string sort)
{
	this->sort = sort;
}

string Sausage::getMeat()
{
	return meat;
}

string Sausage::getSort()
{
	if (sort == "-") { throw 1; }	//���� ������ ����� ������� "-", �� �������� ����������
	return sort;
}
