#include "IncomeManager.h"


void IncomeManager :: saveIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load( fileName );

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

    do
        {
            system ("cls");
            cout << "Whether the income is for today?" << endl;
            cout << "If yes -> insert y" << endl;
            cout << "If no -> insert n" << endl;
            cout << "Your choice: ";

            sign = AuxiliaryMethods :: loadCharacter();

            if(sign == 'y')
                {
                   income.setDate(DateManager :: getTodaysDate());
                }
            else if(sign == 'n')
                {
                    income.setDate(DateManager :: getUsersDate());
                }
            else
                {
                    cout << "Please select character y/n.";
                    getch();
                }
        }
    while(sign != 'y' && sign != 'n');

    income.setItem(setItem());

    income.setAmount(setAmount());

    saveIncomeToFile(income);

    system ("cls");
    cout << "Income added";
    getch();
}
