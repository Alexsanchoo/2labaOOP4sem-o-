#include "WorkMode.h"

WorkMode::WorkMode(string beginTime, string endTime)
{
	bool isBeginTimeCorrect = regex_match(beginTime, regex("\\d{1,2}:\\d{1,2}"));
	bool isEndTimeCorrect = regex_match(endTime, regex("\\d{1,2}:\\d{1,2}"));
	if (isBeginTimeCorrect && isEndTimeCorrect)
	{
		beginHours = atoi(beginTime.substr(0, 2).c_str());
		beginMinutes = atoi(beginTime.substr(3, 2).c_str());
		endHours = atoi(endTime.substr(0, 2).c_str());
		endMinutes = atoi(endTime.substr(3, 2).c_str());
		if (!checkTime(beginHours, beginMinutes) || !checkTime(endHours, endMinutes))	//если время не верное,
		{																			//то вызываем исключение
			throw ExpShop(1);
		}
	}
	else
	{
		throw ExpShop(1);
	}
}

void WorkMode::setBeginH(int hours)
{
	beginHours = hours;
}

void WorkMode::setBeginM(int minutes)
{
	beginMinutes = minutes;
}

void WorkMode::setEndH(int hours)
{
	endHours = hours;
}

void WorkMode::setEndM(int minutes)
{
	endMinutes = minutes;
}

int WorkMode::getBeginH()
{
	return beginHours;
}

int WorkMode::getBeginM()
{
	return beginMinutes;
}

int WorkMode::getEndH()
{
	return endHours;
}

int WorkMode::getEndM()
{
	return endMinutes;
}

bool WorkMode::checkTime(int hours, int minutes)
{
	if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
		return false;
	return true;
}
