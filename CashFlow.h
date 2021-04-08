#ifndef CASHFLOW_H
#define CASHFLOW_H

#include <iostream>

using namespace std;

class CashFlow
{
    int userId;
    int cashFlowId;
    char date[11];
    string item;
    float amount;

public:

    void setuserId(int newUserId);
    void setCashFlowId(int newCashFlowId);
    void setDate(char *newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getuserId();
    int getCashFlowId();
    char* getDate();
    string getItem();
    float getAmount();
};

#endif
