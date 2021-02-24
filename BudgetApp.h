#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"


using namespace std;

class BudgetApp
{
    UserManager userManager;


public:

void registerUser();
void loginUser();
bool isUserLoggedIn();


};

#endif
