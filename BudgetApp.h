#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "Balance.h"



using namespace std;

class BudgetApp
{
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    Balance *balance;

public:
BudgetApp()
{

};
~ BudgetApp()
{

}
void registerUser();
void loginUser();
bool isUserLoggedIn();
void logoutUser();
void changePassword();
void addIncome();
void addExpense();
void showCurrentMonthBalance();
void showPreviousMonthBalance();
void showBalanceForTheSelectedPeriod();

};

#endif
