#pragma once
#include<iostream>

using namespace std;

template<typename T = int>
T nextValue()	//������� ��� ����������� ������ ��������
{
	T value;
	while (true)
	{
		try
		{
			cin >> value;
			cin.ignore(1000, '\n');
			if (cin.gcount() > 1) throw runtime_error("extra characters");
			return value;
		}
		catch (ios_base::failure ex)
		{
			cout << "������! ������� ��� ���: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		catch (runtime_error ex)
		{
			cout << "������! ������� ��� ���: ";
		}
	}
}