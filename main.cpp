

#include "CookieType.h"
#include "Cookie.h"
#include "CookieList.h"
#include "Testing.h"
#include "Interface.h"
#include <iostream>

using namespace std;

int main()
{
	CookieList cookieList;
	createCookieList(cookieList);
	displayMenu();
	processChoice(cookieList);
}

