#include "CashFlowManager.h"

string CashFlowManager :: setItem()
{
    string item;
    system ("cls");
    cout <<"What kind of item is it?" << endl;
    item = AuxiliaryMethods :: loadLine();
    return item;
}

float CashFlowManager :: setAmount()
{
    float amount;
    system ("cls");
    cout << "Specify the amount." << endl;
    amount = AuxiliaryMethods :: loadFloatingPointNumber();
    return amount;
}


