#ifndef CASHFLOWMANAGER_H
#define CASHFLOWMANAGER_H

#include <iostream>

#include "AuxiliaryMethods.h"
#include "DateManager.h"


using namespace std;

class CashFlowManager
{
    protected:

    const int LOGGED_IN_USER_ID;
    string setItem();
    float setAmount();
    AuxiliaryMethods auxiliaryMethods;

public:

    CashFlowManager(int loggedInUserId): LOGGED_IN_USER_ID(loggedInUserId)
    {

    };

};

#endif
