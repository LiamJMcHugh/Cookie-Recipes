

//	Implementation of class CookieType

#include "CookieType.h"
using namespace std;

CookieType::CookieType()
{
	name = "undefined";
	calories = 0;
}

CookieType::CookieType(const string& newName, 
                       const size_t newCalories)
{
	name = newName;
	calories = newCalories;
}

string CookieType::getName() const
{
	return name;
}

size_t CookieType::getCalories() const
{
	return calories;
}

void CookieType::setName(const string& newName)
{
	name = newName;
}

void CookieType::setCalories(const size_t newCalories)
{
	calories = newCalories;
}

CookieType::~CookieType() {}