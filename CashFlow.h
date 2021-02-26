#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

using namespace std;

class CashFlow
{
    int userId;
    char date[11];
    string item;
    string amount;


public:
    void setuserId(int newUserId);
    void setDate(char newDate[11]);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getuserId();
    char getDate();
    string getItem();
    string getAmount();


};

#endif
