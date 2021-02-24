#include <iostream>

#include "BudgetApp.h"

using namespace std;

int main()
{
    BudgetApp budgetApp;
    UserManager userManager;

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
    }


    return 0;
}
