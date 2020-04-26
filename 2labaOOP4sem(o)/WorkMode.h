#pragma once
#include<string>
#include<regex>
#include "ExpShop.h"	//подключаем пользовательский класс исключений

using namespace std;

class WorkMode
{
public:
	WorkMode(string beginTime, string endTime) throw(ExpShop);
	WorkMode(int beginHours = 0, int beginMinutes = 0, int endHours = 0, int endMinutes = 0) :
		beginHours(beginHours), beginMinutes(beginMinutes), endHours(endHours), endMinutes(endMinutes) {}
	WorkMode(const WorkMode& obj) : beginHours(obj.beginHours), beginMinutes(obj.beginMinutes),
		endHours(obj.endHours), endMinutes(obj.endMinutes) {}

	void setBeginH(int hours);
	void setBeginM(int minutes);
	void setEndH(int hours);
	void setEndM(int minutes);

	int getBeginH();
	int getBeginM();
	int getEndH();
	int getEndM();


private:
	int beginHours;
	int beginMinutes;
	int endHours;
	int endMinutes;
	bool checkTime(int hours, int minutes);
};

