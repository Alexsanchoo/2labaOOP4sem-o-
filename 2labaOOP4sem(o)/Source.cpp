#include<iostream>
#include<string>
#include<Windows.h>
#include "Shop.h"
#include "Functions.h"

using namespace std;

void term_func();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(term_func); //задаём собственную функцию завершения
	cin.exceptions(ios::failbit | ios::badbit); //включаем работу исключений для потока ввода


	string nameShop, beginTime, endTime;
	cout << "Введите название магазина: "; nameShop = nextValue<string>();
	cout << "Введите время начала работы в формате \"чч:мм\": "; beginTime = nextValue<string>();
	cout << "Введите время окончания работы в формате \"чч:мм\": "; endTime = nextValue<string>();
	Shop shop;
	try
	{
		shop = Shop(nameShop, beginTime, endTime);		//создаём объект магазин
	}
	catch (ExpShop e)
	{
		cerr << e.what() << endl;	//если время будет в неверном формате, то возникнет исключение
		exit(0);
	}


	Owner* owner = nullptr;
	string nameOwner, lastnameOwner;
	int ageOwner;
	cout << "Введите имя владельца: "; nameOwner = nextValue<string>();
	cout << "Введите фамилию владельца: "; lastnameOwner = nextValue<string>();
	cout << "Введите возраст владельца: "; ageOwner = nextValue<>();
	try
	{
		owner = new Owner(nameOwner, lastnameOwner, ageOwner);	//создаём владельца магазина
		shop.setOwner(owner);	//и передаём его в магазин
	}
	catch (bad_alloc e)
	{
		cerr << e.what() << endl;	//если возникнут проблемы с выделением памяти, то возникнет исключение
		exit(0);
	}


	system("cls");
	int choice = 0;
	while(choice != 5)
	{
		cout << "Выберите какой продукт вы хотите добавить: " << endl;
		cout << "1. Молоко;" << endl;
		cout << "2. Хлеб;" << endl;
		cout << "3. Колбасу;" << endl;
		cout << "4. Просмотреть добавленные продукты;" << endl;
		cout << "5. Выход;" << endl;
		cout << "Сделайте выбор: "; choice = nextValue<>();

		system("cls");
		switch (choice)
		{
		case 1:		//добавление молока в список продуктов
		{
			Product* product = new Milk();
			cout << "Введите вес продукта: "; product->setWeight(nextValue<double>());
			cout << "Введите производителя: "; product->setManufacturer(nextValue<string>());
			try
			{
				cout << "Введите процент жира молока: "; ((Milk*)product)->setFatPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//если процент введён не верно, то возникает исключение
			}
			try
			{
				cout << "Введите процент воды молока: "; ((Milk*)product)->setWaterPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//если процент введён не верно, то возникает исключение
			}

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 2: //добавление хлеба в список продуктов
		{
			Product* product = new Bread();
			cout << "Введите вес продукта: "; product->setWeight(nextValue<double>());
			cout << "Введите производителя: "; product->setManufacturer(nextValue<string>());
			try
			{
				cout << "Введите процент белков хлеба: "; ((Bread*)product)->setProteinPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//если процент введён не верно, то возникает исключение
			}
			try
			{
				cout << "Введите процент углеводов хлеба: "; ((Bread*)product)->setCarbohydratesPrecent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//если процент введён не верно, то возникает исключение
			}

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 3:	//добавление колбасы в список продуктов
		{
			Product* product = new Sausage();
			cout << "Введите вес продукта: "; product->setWeight(nextValue<double>());
			cout << "Введите производителя: "; product->setManufacturer(nextValue<string>());
			cout << "Введите вид мяса: "; ((Sausage*)product)->setMeat(nextValue<string>());
			cout << "Введите сорт колбасы: "; ((Sausage*)product)->setSort(nextValue<string>());

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 4:	//вывод список продуктов
		{
			try
			{
				shop.showProduct();
				system("pause>>void");
			}
			catch (...)
			{
				cout << endl << "Неверный сорт!" << endl;	//если сорт колбасы был введён не верно, то возникает
				term_func();								//исключение
			}
		}
			system("cls");
			break;

		case 5:
			break;

		default:
			cout << "Неверный выбор!" << endl << endl;
			break;
		}
	}



	delete owner;	//очищаем память
	return 0;
}

void term_func()	//собственная функция завершения работы
{
	cerr << endl << "Экстренное завершение программы!" << endl;
	exit(0);
}
