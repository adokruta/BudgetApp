#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "CashFlowManager.h"


using namespace std;

class BudgetApp
{
    UserManager userManager;
    CashFlowManager *cashFlowManager;


public:
BudgetApp()
{
    cashFlowManager = NULL;
};
~ BudgetApp()
{
    delete cashFlowManager;
    cashFlowManager = NULL;
}
void registerUser();
void loginUser();
bool isUserLoggedIn();
void logoutUser();
void changePassword();
void addCashFlow();


};

#endif
