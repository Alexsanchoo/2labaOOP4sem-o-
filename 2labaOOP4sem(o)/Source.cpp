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
	set_terminate(term_func); //����� ����������� ������� ����������
	cin.exceptions(ios::failbit | ios::badbit); //�������� ������ ���������� ��� ������ �����


	string nameShop, beginTime, endTime;
	cout << "������� �������� ��������: "; nameShop = nextValue<string>();
	cout << "������� ����� ������ ������ � ������� \"��:��\": "; beginTime = nextValue<string>();
	cout << "������� ����� ��������� ������ � ������� \"��:��\": "; endTime = nextValue<string>();
	Shop shop;
	try
	{
		shop = Shop(nameShop, beginTime, endTime);		//������ ������ �������
	}
	catch (ExpShop e)
	{
		cerr << e.what() << endl;	//���� ����� ����� � �������� �������, �� ��������� ����������
		exit(0);
	}


	Owner* owner = nullptr;
	string nameOwner, lastnameOwner;
	int ageOwner;
	cout << "������� ��� ���������: "; nameOwner = nextValue<string>();
	cout << "������� ������� ���������: "; lastnameOwner = nextValue<string>();
	cout << "������� ������� ���������: "; ageOwner = nextValue<>();
	try
	{
		owner = new Owner(nameOwner, lastnameOwner, ageOwner);	//������ ��������� ��������
		shop.setOwner(owner);	//� ������� ��� � �������
	}
	catch (bad_alloc e)
	{
		cerr << e.what() << endl;	//���� ��������� �������� � ���������� ������, �� ��������� ����������
		exit(0);
	}


	system("cls");
	int choice = 0;
	while(choice != 5)
	{
		cout << "�������� ����� ������� �� ������ ��������: " << endl;
		cout << "1. ������;" << endl;
		cout << "2. ����;" << endl;
		cout << "3. �������;" << endl;
		cout << "4. ����������� ����������� ��������;" << endl;
		cout << "5. �����;" << endl;
		cout << "�������� �����: "; choice = nextValue<>();

		system("cls");
		switch (choice)
		{
		case 1:		//���������� ������ � ������ ���������
		{
			Product* product = new Milk();
			cout << "������� ��� ��������: "; product->setWeight(nextValue<double>());
			cout << "������� �������������: "; product->setManufacturer(nextValue<string>());
			try
			{
				cout << "������� ������� ���� ������: "; ((Milk*)product)->setFatPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//���� ������� ����� �� �����, �� ��������� ����������
			}
			try
			{
				cout << "������� ������� ���� ������: "; ((Milk*)product)->setWaterPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//���� ������� ����� �� �����, �� ��������� ����������
			}

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 2: //���������� ����� � ������ ���������
		{
			Product* product = new Bread();
			cout << "������� ��� ��������: "; product->setWeight(nextValue<double>());
			cout << "������� �������������: "; product->setManufacturer(nextValue<string>());
			try
			{
				cout << "������� ������� ������ �����: "; ((Bread*)product)->setProteinPercent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//���� ������� ����� �� �����, �� ��������� ����������
			}
			try
			{
				cout << "������� ������� ��������� �����: "; ((Bread*)product)->setCarbohydratesPrecent(nextValue<double>());
			}
			catch (ExpShop e)
			{
				cout << e.what() << endl;	//���� ������� ����� �� �����, �� ��������� ����������
			}

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 3:	//���������� ������� � ������ ���������
		{
			Product* product = new Sausage();
			cout << "������� ��� ��������: "; product->setWeight(nextValue<double>());
			cout << "������� �������������: "; product->setManufacturer(nextValue<string>());
			cout << "������� ��� ����: "; ((Sausage*)product)->setMeat(nextValue<string>());
			cout << "������� ���� �������: "; ((Sausage*)product)->setSort(nextValue<string>());

			shop.getProducts().push_back(product);
		}
			system("cls");
			break;

		case 4:	//����� ������ ���������
		{
			try
			{
				shop.showProduct();
				system("pause>>void");
			}
			catch (...)
			{
				cout << endl << "�������� ����!" << endl;	//���� ���� ������� ��� ����� �� �����, �� ���������
				term_func();								//����������
			}
		}
			system("cls");
			break;

		case 5:
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}



	delete owner;	//������� ������
	return 0;
}

void term_func()	//����������� ������� ���������� ������
{
	cerr << endl << "���������� ���������� ���������!" << endl;
	exit(0);
}
