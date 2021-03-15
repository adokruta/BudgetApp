#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <time.h>

#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "CashFlowManager.h"
#include "Expense.h"


using namespace std;

class ExpenseManager : public CashFlowManager
{
    string fileName;
    int lastExpenseId;

    int getLastExpenseId(string fileName);


  public:

  ExpenseManager(int loggedInUserId) : CashFlowManager(loggedInUserId)
      {
          fileName = "expenses.xml";
          lastExpenseId = getLastExpenseId(fileName);
      };

    void saveExpenseToFile(Expense expense);
    void addExpense();

};

#endif
