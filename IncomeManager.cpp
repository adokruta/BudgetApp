#include "IncomeManager.h"


void IncomeManager :: saveIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }


    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("userId", income.getuserId());
    xml.AddElem("incomeId", income.getCashFlowId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", income.getAmount());
    xml.Save("incomes.xml");

    lastIncomeId++;

}

int IncomeManager :: getLastIncomeId(string fileName)
{
    CMarkup xml;

    bool fileExists = xml.Load( fileName );

    if(!fileExists)
    {
        return lastIncomeId = 0;
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
         xml.FindChildElem( "incomeId" );
         lastIncomeId = atoi(MCD_2PCSZ(xml.GetChildData()));
    }
    return lastIncomeId;
}

void IncomeManager :: addIncome()
{
    Income income;

    income.setuserId(LOGGED_IN_USER_ID);

    income.setCashFlowId(lastIncomeId + 1);

    char sign;

    system ("cls");
    cout << "Is it for today?" << endl;
    cout << "If yes -> insert y, otherwise insert -> n" << endl;

    sign = AuxiliaryMethods :: loadCharacter();

    if(sign == 'y')
    {

        income.setDate(setTodaysDate());

        income.setItem(setItem());

        income.setAmount(setAmount());

        saveIncomeToFile(income);


    }
    else if(sign == 'n')
    {
        income.setDate(setUsersDate());

        income.setItem(setItem());

        income.setAmount(setAmount());

        saveIncomeToFile(income);
    }
    else
    {
        cout << "Please select character y/n ones again.";
    }


}
