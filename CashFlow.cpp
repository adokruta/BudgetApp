#include "CashFlow.h"

    void CashFlow :: setuserId(int newUserId)
    {
       if (newUserId >=0)
            userId = newUserId;
    }
    void CashFlow :: setDate(char newDate[11])
    {
        date[11] = newDate[11];
    }
    void CashFlow :: setItem(string newItem)
    {
        item = newItem;
    }
    void CashFlow :: setAmount(string newAmount)
    {
        amount = newAmount;
    }

    int CashFlow :: getuserId()
    {
        return userId;
    }
    char CashFlow :: getDate()
    {
        return date[11];
    }
    string CashFlow :: getItem()
    {
        return item;
    }
    string CashFlow :: getAmount()
    {
        return amount;
    }
