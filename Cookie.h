

#ifndef COOKIE_H
#define COOKIE_H

//	Include the base class CookieType
#include "CookieType.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>

class Cookie : public CookieType
{
	public:
		Cookie();
		Cookie(const std::string& newName, 
				const size_t newCalories,
				const std::set<std::string>& newIngredients, 
				const size_t newServings);
		
		//	Accessor functions
		size_t getServings() const;
		//	return by value
		std::set<std::string> getIngredients();
		//	return constant reference to calling object
		const Cookie& getCookie() const;

		//	Mutator functions
		void setServings(const size_t newServings);
		void setIngredients(const std::vector<std::string>& 
		                    vectorIngredients);

		//  Print functions
		void printRecipe() const;
		void printIngredients() const;
		void printCalories() const;

		~Cookie();

	private:
		std::set<std::string> ingredients;
		size_t numOfServings;

};

#endif
