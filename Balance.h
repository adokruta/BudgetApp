#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
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
    //vector <Expense> loadExpensesFromFile();
    void showIncomes();

public:
    Balance(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId)
    {
       incomes = loadIncomesFromFile();
       showIncomes();
    };

};

#endif
