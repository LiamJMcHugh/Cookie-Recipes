#include "CookieList.h"
#include "Cookie.h"

#include <iostream>
using namespace std;


CookieList::CookieList()
{
    first = nullptr;
    last = first;
    count = 0;
}

void CookieList::addCookie(const Cookie& aCookie)
{
    if(last != nullptr)
    {
        last->setNext(new Node());
        last = last->getNext();
        last->setCookie(aCookie);
        last->setNext(nullptr);
    }
    
    else
    {
        first = new Node(aCookie, nullptr);
        last = first;
    }
    
    ++count;
}
void CookieList::addCookie(const string& newName, size_t newCalories,
	const set<string>& newIngredients, size_t newServings)
{   
    Cookie* aCookie = new Cookie(newName, newCalories, 
                                 newIngredients, newServings);
    if(last != nullptr)
    {
        last->setNext(new Node());
        last = last->getNext();
        last->setCookie(*aCookie);
        last->setNext(nullptr);
    }
    
    else
    {
        first = new Node(*aCookie, nullptr);
        last = first;
    }
    
    ++count;
}
	
size_t CookieList::getCount() const
{
    return count;
}

bool CookieList::isEmpty() const
{
    return count == 0;
}
bool CookieList::searchCookie(const string& aCookie) const
{ 
    Node* current = first;
    while(current != nullptr)
    {
        Cookie temp = current->getCookie();
        if(temp.getName() == aCookie)
            return true;
    } 
    return false; 
}

void CookieList::printAllCookies() const
{ 
    Node* current = first;
    while(current != nullptr)
    {
        Cookie temp = current->getCookie();
        cout << "    " << temp.getName() << endl;
        current = current->getNext();
    } 
    cout << endl;
}
void CookieList::clearList()
{
    Node* current = first;
    while(current != nullptr)
    {
        delete first;
        first = nullptr;
        current = first;
    }
    count = 0;
}

CookieList::CookieList(const CookieList& otherCookieList)
{ 
    first = nullptr;
    last = first;
    count = otherCookieList.count;
    
    Node* current = otherCookieList.first;
    while(current != nullptr)
    {
        addCookie(current->getCookie());
        current = current->getNext();
    }
}
CookieList& CookieList::operator=(const CookieList& 
                                  otherCookieList)
{ 
    if(isEmpty())
    {
        copyCallingObjIsEmpty(otherCookieList);
    }
    else if(count == otherCookieList.count)
    {
        copyObjectsSameLength(otherCookieList);
    }
    else if(count > otherCookieList.count)
    {
        copyCallingObjLonger(otherCookieList);
    }
    else if(count < otherCookieList.count)
    {
        copyCallingObjShorter(otherCookieList);
    } 
    return *this;
}
CookieList::~CookieList()
{
    clearList();
}

void CookieList::copyCallingObjIsEmpty(const CookieList& 
                                       otherCookieList)
{
    size_t length = otherCookieList.count;
    Node* otherCurrent = otherCookieList.first;
        while(otherCurrent != nullptr)
        {
            addCookie(otherCurrent->getCookie());
            otherCurrent = otherCurrent->getNext();
        }   
}
void CookieList::copyObjectsSameLength(const CookieList& 
                                       otherCookieList)
{
    Node* current = first;
    Node* otherCurrent = otherCookieList.first;
    while(current != nullptr)
    {
        current->setCookie(otherCurrent->getCookie());
        current = current->getNext();
        otherCurrent = otherCurrent->getNext();
    }   
}
void CookieList::copyCallingObjLonger(const CookieList& 
                                      otherCookieList)
{
    Node* current = first;
        Node* otherCurrent = otherCookieList.first;
        while(otherCurrent != nullptr)
        {
            current->setCookie(otherCurrent->getCookie());
            last = current;
            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }
        while(current != nullptr)
        {
            Node* temp = current;
            current = current->getNext();
            delete temp;
            temp = nullptr;
        }
        last->setNext(nullptr);
}
void CookieList::copyCallingObjShorter(const CookieList& 
                                       otherCookieList)
{ 
    Node* current = first;
        Node* otherCurrent = otherCookieList.first;
        while(current != nullptr)
        {
            current->setCookie(otherCurrent->getCookie());
            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }
        while(otherCurrent != nullptr)
        {
            addCookie(otherCurrent->getCookie());
            otherCurrent = otherCurrent->getNext();
        } 
}

void CookieList::printCookiesSelection() const
{
    size_t num = count;
    Node* current = first;
    for(size_t i = 1; i <= num; ++i)
    {
        Cookie temp;
        temp = current->getCookie();
        cout << "    " << i << ": " << temp.getName() << endl;
        current = current->getNext();
    }
}
void CookieList::printRecipe(size_t cookieSelection) const
{
    Node* current = getCookieLocation(cookieSelection);
    Cookie temp = current->getCookie();
    temp.printRecipe();
}
Node* CookieList::getCookieLocation(size_t cookieSelection) const
{
    Node* current = first;
    for(size_t i = 1; i < cookieSelection; ++i)
    {
        current = current->getNext();
    }
    return current;
}

void CookieList::printLimitedCalories(size_t calories)
{
    Node* current = first;
    while(current != nullptr)
    {
        Cookie temp = current->getCookie();
        if(temp.getCalories() <= calories)
        {
            temp.printCalories();
        }
        current = current->getNext();
    }
} 
void CookieList::printCalories(size_t cookieSelection) const
{
    Node* current = getCookieLocation(cookieSelection);
    Cookie temp = current->getCookie();
    temp.printCalories();
}
