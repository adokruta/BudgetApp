#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>
//#include <vector>
//#include <windows.h>
#include <conio.h>
//#include <sstream>
//#include <time.h>

//#include "Markup.h"
//#include "User.h"
#include "AuxiliaryMethods.h"
//#include "CashFlow.h"
#include "DateManager.h"


using namespace std;

class CashFlowManager
{
    //string fileName;
    //bool isTheDateCorrect(int year, int month, int day);
    //bool isYearLeap (int year);
    //bool isNumberOfDaysInMonthCorrect (int numberOfDays, int month, int year);
   // int lastCashFlowId;

    protected:

    const int LOGGED_IN_USER_ID;
    //char* setTodaysDate();

    //char* setUsersDate();

    string setItem();
    string setAmount();
   // void saveCashFlowToFile(CashFlow cashFlow);

    AuxiliaryMethods auxiliaryMethods;

   // int getLastCashFlowId(string fileName);



public:

    CashFlowManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId)
    {
      //fileName = "CashFlow.xml";
      //lastCashFlowId = getLastCashFlowId(fileName);
    };

    //void addCashFlow();

};

#endif
