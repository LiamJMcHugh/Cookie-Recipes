#include "Interface.h"
#include "CookieList.h"

#include <iostream>
using namespace std;
void displayMenu()
{
    cout << string(62, '*') << endl;
    cout << "                        COOKIE RECIPES" << endl;
    cout << string(62, '*') << endl << endl;
    cout << "Select one of the following:" << endl;
    cout << endl;
    cout << "    a. Print all recipes" << endl;
    cout << "    b. Print cookie recipe" << endl;
    cout << "    c. Print cookie calories" << endl;
    cout << "    d. Print limited calories" << endl;
    cout << "    e. To exit" << endl;
}
void processChoice(CookieList& cookieList)
{
    bool running = true;
    char input;
    while(running)
    {
        bool prompted = false;
        cout << endl << "Enter your choice: ";
        cin >> input;
        cout << endl;
        if(cookieList.isEmpty())
        {
            cout << "    => There are no recipes in the list" 
                 << endl << endl;
            cout << string(62, '=') << endl << endl;
            cout << "Please contact your administrator. Good bye!"
                 << endl;
            running = false;
            prompted = true;
        }
        if (!prompted)
        {
            switch (input)
            {
            case 'a':
                //print all recipes
                cout << endl << string(62, '-') << endl
                    << "    COOKIE RECIPES" << endl
                    << string(62, '-') << endl << endl;
                cookieList.printAllCookies();
                break;
            case 'b':
                size_t selection;
                cout << endl << string(62, '-') << endl
                    << "    COOKIE RECIPE" << endl
                    << string(62, '-') << endl;
                cout << endl << "Choose a cookie to"
                             << "view the recipe." << endl << endl;
                cookieList.printCookiesSelection();
                cout << endl << "Your choice: ";
                cin >> selection;
                cout << endl;
                cookieList.printRecipe(selection);
                cout << endl;
                break;
            case 'c':
                //print cookie calories
                cout << endl << string(62, '-') << endl
                    << "    COOKIE CALORIES" << endl
                    << string(62, '-') << endl << endl;
                cout << "Choose a cookie # to"
                     << "view number of calories." 
                     << endl << endl;
                cookieList.printCookiesSelection();
                cout << endl << "Your choice: ";
                cin >> selection;
                cout << endl;
                cookieList.printCalories(selection);
                cout << endl;
                break;
            case 'd':
                //print limited calories
                cout << endl << string(62, '-') << endl
                    << "    MAXIMUM CALORIES" << endl
                    << string(62, '-') << endl << endl;
                cout << "What is the maximum"
                     << "# of calories (100-200)? ";
                size_t cal;
                cin >> cal;
                cout << endl;
                cookieList.printLimitedCalories(cal);
                cout << endl << endl;
                break;
            case 'e':
                //exit
                prompted = true;
                running = false;
                cout << "Thank you for using our software."
                     << "Good bye!" << endl;
                break;
            default:
                //Not a selection
                cout << "    => Sorry that is not a selection." 
                     << endl << endl;
                cout << string(62, '=') << endl << endl;
                cout << "Would you like to try again (y/n)? ";
                cin >> input;
                cout << endl;
                prompted = true;
                if (input == 'y')
                    displayMenu();
                if (input == 'n' && running)
                {
                    cout << "Thank you for using our software." 
                         << "Good bye!" << endl;
                    running = false;
                }
            }
            if (!prompted)
            {
                cout << string(62, '=') << endl << endl;
                cout << "Would you to continue (y/n)? ";
                cin >> input;
                cout << endl;
                if (input == 'y')
                    displayMenu();
                if (input == 'n')
                {
                    cout << "Thank you for using our software." 
                         << "Good bye!" << endl;
                    running = false;

                }
            }
        }
    }
    
}