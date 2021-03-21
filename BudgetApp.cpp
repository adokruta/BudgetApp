#include "BudgetApp.h"

void BudgetApp :: registerUser()
{
    userManager.registerUser();
}

void BudgetApp :: loginUser()
{
    userManager.loginUser();
    //if(userManager.isUserLoggedIn())
   // {
   //  cashFlowManager = new CashFlowManager(userManager.getLoggedInUserId());
   // }
}

bool BudgetApp :: isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetApp :: logoutUser()
{
    userManager.logoutUser();
//    delete cashFlowManager;
//    cashFlowManager = NULL;
}

void BudgetApp :: changePassword()
{
    userManager.changePassword();
}

void BudgetApp :: addIncome()
{
    incomeManager = new IncomeManager(userManager.getLoggedInUserId());
    incomeManager->addIncome();
    delete incomeManager;
    incomeManager = NULL;
}

void BudgetApp :: addExpense()
{
    expenseManager = new ExpenseManager(userManager.getLoggedInUserId());
    expenseManager->addExpense();
    delete expenseManager;
    expenseManager = NULL;
}

void BudgetApp :: showCurrentMonthBalance()
{
    balance = new Balance(userManager.getLoggedInUserId());
    balance -> showTheCurrentMonthBalance();
    delete balance;
    balance = NULL;
}

void BudgetApp :: showPreviousMonthBalance()
{
    balance = new Balance(userManager.getLoggedInUserId());
    balance -> showThePreviousMonthBalance();
    delete balance;
    balance = NULL;
}

void BudgetApp :: showBalanceForTheSelectedPeriod()
{
    balance = new Balance(userManager.getLoggedInUserId());
    balance -> showTheBalanceForTheSelectedPeriod();
    delete balance;
    balance = NULL;
}
