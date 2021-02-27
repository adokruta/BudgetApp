#include "BudgetApp.h"

void BudgetApp :: registerUser()
{
    userManager.registerUser();
}

void BudgetApp :: loginUser()
{
    userManager.loginUser();
    if(userManager.isUserLoggedIn())
    {
     cashFlowManager = new CashFlowManager(userManager.getLoggedInUserId());
    }
}

bool BudgetApp :: isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetApp :: logoutUser()
{
    userManager.logoutUser();
    delete cashFlowManager;
    cashFlowManager = NULL;
}

void BudgetApp :: changePassword()
{
    userManager.changePassword();
}



