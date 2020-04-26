#include "Shop.h"

Shop::Shop(const Shop& obj) : name(obj.name), owner(obj.owner), workMode(obj.workMode)
{
	for (size_t i = 0; i < obj.products.size(); i++)
	{
		products.push_back(obj.products[i]);
	}
}

void Shop::setName(string name)
{
	this->name = name;
}

void Shop::setOwner(Owner* owner)
{
	this->owner = owner;
}

string Shop::getName()
{
	return name;
}

Owner* Shop::getOwner()
{
	return owner;
}

WorkMode& Shop::getWorkMode()
{
	return workMode;
}

vector<Product*>& Shop::getProducts()
{
	return products;
}

void Shop::showProduct()
{
	if (products.empty())
	{
		cout << "��� ���������!" << endl;
		return;
	}

	for (size_t i = 0; i < products.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << "�������� ��������: " << products[i]->getName() << endl;
		cout << "��� ��������: " << products[i]->getWeight() << endl;
		cout << "�������� �������������: " << products[i]->getManufacturer() << endl;

		switch (products[i]->getTypeProduct())
		{
		case MILK:
			cout << fixed << setprecision(2) << "������� ����: " << ((Milk*)products[i])->getFatPercent() << "%" << endl;
			cout << fixed << setprecision(2) << "������� ����: " << ((Milk*)products[i])->getWaterPercent() << "%" << endl;
			break;

		case BREAD:
			cout << fixed << setprecision(2) << "������� �����: " << ((Bread*)products[i])->getProteinPercent() << "%" << endl;
			cout << fixed << setprecision(2) << "������� ���������: " << ((Bread*)products[i])->getCarbohydratesPercent() << "%" << endl;
			break;

		case SAUSAGE:
			cout << "��� ����: " << ((Sausage*)products[i])->getMeat() << endl;
			try
			{
				cout << "����: " << ((Sausage*)products[i])->getSort() << endl;
			}
			catch (int)	//���� ������� getSort() ����� ����������, �� ������� � ����. �����������
			{
				throw;
			}
			break;

		default:
			break;
		}
		cout << endl;
	}
}

Shop::~Shop()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		delete products[i];
	}
}
