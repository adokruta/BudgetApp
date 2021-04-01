#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <conio.h>

#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "CashFlowManager.h"
#include "Expense.h"
#include "DateManager.h"

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
