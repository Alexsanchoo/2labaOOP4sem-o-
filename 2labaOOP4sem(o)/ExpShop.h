#pragma once
#include<string>

using namespace std;

class ExpShop
{
public:
	ExpShop(int code = 0) : code(code) {}
	string what();

private:
	int code;
};

