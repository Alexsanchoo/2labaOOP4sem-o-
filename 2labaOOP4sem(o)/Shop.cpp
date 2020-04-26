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
		cout << "Нет продуктов!" << endl;
		return;
	}

	for (size_t i = 0; i < products.size(); i++)
	{
		cout << "#" << i + 1 << endl;
		cout << "Название продукта: " << products[i]->getName() << endl;
		cout << "Вес продукта: " << products[i]->getWeight() << endl;
		cout << "Название производителя: " << products[i]->getManufacturer() << endl;

		switch (products[i]->getTypeProduct())
		{
		case MILK:
			cout << fixed << setprecision(2) << "Процент жира: " << ((Milk*)products[i])->getFatPercent() << "%" << endl;
			cout << fixed << setprecision(2) << "Процент воды: " << ((Milk*)products[i])->getWaterPercent() << "%" << endl;
			break;

		case BREAD:
			cout << fixed << setprecision(2) << "Процент белка: " << ((Bread*)products[i])->getProteinPercent() << "%" << endl;
			cout << fixed << setprecision(2) << "Процент углеводов: " << ((Bread*)products[i])->getCarbohydratesPercent() << "%" << endl;
			break;

		case SAUSAGE:
			cout << "Вид мяса: " << ((Sausage*)products[i])->getMeat() << endl;
			try
			{
				cout << "Сорт: " << ((Sausage*)products[i])->getSort() << endl;
			}
			catch (int)	//если функция getSort() выдаёт исключение, то передаём её след. обработчику
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
