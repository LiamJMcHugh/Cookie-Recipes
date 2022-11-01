
//	Implementation of the class Cookie
#include "Cookie.h"

using namespace std;

Cookie::Cookie()
{
	numOfServings = 0;
}

Cookie::Cookie(const string& newName,
	const size_t newCalories,
	const set<string>& newIngredients,
	const size_t newServings)
	: CookieType(newName, newCalories)
{
	ingredients = newIngredients;
	numOfServings = newServings;
}

size_t Cookie::getServings() const
{
	return numOfServings;
}

set<string> Cookie::getIngredients()
{
	return ingredients;
}

const Cookie& Cookie::getCookie() const
{
	return *this;
}

void Cookie::setServings(const size_t newServings)
{
	numOfServings = newServings;
}

void Cookie::setIngredients(const vector<string>& 
                            vectorIngredients)
{
	for (auto iter = vectorIngredients.begin(); 
	     iter != vectorIngredients.end(); ++iter)
	{
		ingredients.insert(*iter);
	}
}

void Cookie::printRecipe() const
{
	cout << "    Recipe for " << CookieType::getName() 
		<< endl << "        Servings: " << numOfServings << endl;	
		printIngredients();
}

void Cookie::printIngredients() const
{
	cout << "        Ingredients: ";
	auto checkIter = ingredients.begin();
	for (auto iter = ingredients.begin(); 
	     iter != ingredients.end(); ++iter)
	{
		cout << *iter;
		++checkIter;
		if(checkIter != ingredients.end())
		cout << ", ";
	}
	cout << endl;
}

void Cookie::printCalories() const
{
	cout << "    " << CookieType::getName()
		<< " (calories: " << CookieType::getCalories() 
		<< ")" << endl;
}

Cookie::~Cookie() {}


