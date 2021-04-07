#include "ExpenseManager.h"


void ExpenseManager :: saveExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load( fileName );

    if (!fileExists)
        {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Expenses");
        }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("userId", expense.getuserId());
    xml.AddElem("expenseId", expense.getCashFlowId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", AuxiliaryMethods :: floatToString(expense.getAmount()));
    xml.Save("expenses.xml");

    lastExpenseId++;
}

int ExpenseManager :: getLastExpenseId(string fileName)
{
    CMarkup xml;

    bool fileExists = xml.Load( fileName );

    if(!fileExists)
        {
            return lastExpenseId = 0;
        }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
        {
             xml.FindChildElem( "expenseId" );
             lastExpenseId = atoi(MCD_2PCSZ(xml.GetChildData()));
        }
    return lastExpenseId;
}

void ExpenseManager :: addExpense()
{
    Expense expense;

    expense.setuserId(LOGGED_IN_USER_ID);

    expense.setCashFlowId(lastExpenseId + 1);

    char sign;

    do
        {
            system ("cls");
            cout << "Whether the expense is for today?" << endl;
            cout << "If yes -> insert y" << endl;
            cout << "If no -> insert n" << endl;
            cout << "Your choice: ";

            sign = AuxiliaryMethods :: loadCharacter();

            if(sign == 'y')
                {
                   expense.setDate(DateManager :: getTodaysDate());
                }
            else if(sign == 'n')
                {
                    expense.setDate(DateManager :: getUsersDate());
                }
            else
                {
                    cout << "Please select character y/n.";
                    getch();
                }
        }
    while(sign != 'y' && sign != 'n');

    expense.setItem(setItem());

    expense.setAmount(setAmount());

    saveExpenseToFile(expense);

    system ("cls");
    cout << "Income added";
    getch();
}
