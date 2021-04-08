#include "CashFlow.h"

    void CashFlow :: setuserId(int newUserId)
    {
       if (newUserId >=0)
            userId = newUserId;
    }

     void CashFlow :: setCashFlowId(int newCashFlowId)
    {
       if (newCashFlowId >=0)
            cashFlowId = newCashFlowId;
    }

    void CashFlow :: setDate(char *newDate)
    {

        for(int i=0; i<=10; i++)
        {
            date[i] = newDate[i];
        }
    }

    void CashFlow :: setItem(string newItem)
    {
        item = newItem;
    }

    void CashFlow :: setAmount(float newAmount)
    {
        amount = newAmount;
    }

    int CashFlow :: getuserId()
    {
        return userId;
    }

    int CashFlow :: getCashFlowId()
    {
        return cashFlowId;
    }

    char* CashFlow :: getDate()
    {
        return date;
    }

    string CashFlow :: getItem()
    {
        return item;
    }

    float CashFlow :: getAmount()
    {
        return amount;
    }
