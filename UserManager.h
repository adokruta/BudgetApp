#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    AuxiliaryMethods auxiliaryMethods;

    User getNewUserData();
    int getNewUserId();
    bool loginExist(string login);
    void saveUserToFile(User user);
    vector <User> loadUsersFromFile();

public:

    UserManager()
    {
        loggedInUserId = 0;
        users = loadUsersFromFile();
    };

    void registerUser();
    void loginUser ();
    int getLoggedInUserId();
    void logoutUser();
    void changePassword();
    bool isUserLoggedIn();
};

#endif
