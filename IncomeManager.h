#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

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
#include "Income.h"


using namespace std;

class IncomeManager : public CashFlowManager
{
    string fileName;
    int lastIncomeId;

    int getLastIncomeId(string fileName);


  public:

  IncomeManager(int loggedInUserId) : CashFlowManager(loggedInUserId)
      {
          fileName = "incomes.xml";
          lastIncomeId = getLastIncomeId(fileName);
      };

    void saveIncomeToFile(Income income);
    void addIncome();

};

#endif
