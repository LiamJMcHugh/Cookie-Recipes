
#ifndef COOKIETYPE_H
#define COOKIETYPE_H

#include <string>

class CookieType
{
public:
	CookieType();
	CookieType(const std::string& newName, const size_t newCalories);

	std::string getName() const;
	size_t getCalories() const;
	void setName(const std::string& newName);
	void setCalories(const size_t newCalories);

	~CookieType();

private:
	std::string name;
	size_t calories;
};
#endif