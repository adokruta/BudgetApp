#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp;
    //UserManager userManager;

   while (true)
    {
        if (!budgetApp.isUserLoggedIn())
        {
           char choice = AuxiliaryMethods :: selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetApp.registerUser();
                break;
            case '2':
                budgetApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the MENU." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
             char choice = AuxiliaryMethods :: selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                cout << "Add income";
                //budgetApp.();
                break;
            case '2':
                cout << "Add expense";
                //budgetApp.();
                break;
            case '3':
                cout << "Show balance";
               // budgetApp.();
                break;
            case '4':
                cout << "Show balance from previous month";
               // budgetApp.();
                break;
            case '5':
                cout << "Show balance from selected period";
               // budgetApp.();
                break;
            case '6':
                cout << "Change password";
                //budgetApp.();
                break;
            case '7':
                cout << "Log out";
               // budgetApp.();
                break;
            }
        }
    }


    return 0;
}
