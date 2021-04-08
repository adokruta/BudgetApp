#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "Markup.h"
#include "DateManager.h"


using namespace std;

class Balance
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    vector <Income> loadIncomesFromFile();
    vector <Expense> loadExpensesFromFile();

public:
    Balance(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId)
    {
       incomes = loadIncomesFromFile();
       expenses = loadExpensesFromFile();
    };

    void showTheCurrentMonthBalance();
    void showThePreviousMonthBalance();
    void showTheBalanceForTheSelectedPeriod();
};

#endif
