#include "ExpShop.h"

string ExpShop::what()
{
	switch (code)
	{
	case 0:
		return "Ошибка!";

	case 1:
		return "Неверный формат времени!";

	case 2:
		return "Неверный процент!";

	default:
		return "Неизвестная ошибка!";
	}
}
