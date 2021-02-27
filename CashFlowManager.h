#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <time.h>

#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class CashFlowManager
{
    const int LOGGED_IN_USER_ID;
    string fileName;
    bool isTheDateCorrect();

    AuxiliaryMethods auxiliaryMethods;



public:

    CashFlowManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId)
    {

    };



};

#endif
