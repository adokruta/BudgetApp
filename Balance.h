#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>
#include <time.h>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"


using namespace std;

class Balance
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    vector <Income> loadIncomesFromFile();
    vector <Expense> loadExpensesFromFile();
    void showIncomes();
    void showExpenses();
    char* getTodaysDate();
    static int changeTheDateToInt(char* date);

    void showTheCurrentMonthBalance();

public:
    Balance(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId)
    {
       incomes = loadIncomesFromFile();
       expenses = loadExpensesFromFile();
       //showIncomes();
       //showExpenses();
       showTheCurrentMonthBalance();

    };

};

#endif
