#include "ExpShop.h"

string ExpShop::what()
{
	switch (code)
	{
	case 0:
		return "������!";

	case 1:
		return "�������� ������ �������!";

	case 2:
		return "�������� �������!";

	default:
		return "����������� ������!";
	}
}
