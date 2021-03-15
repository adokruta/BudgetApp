#include "ExpenseManager.h"

void ExpenseManager :: saveExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

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
    xml.AddElem("amount", expense.getAmount());
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

    system ("cls");
    cout << "Is it for today?" << endl;
    cout << "If yes -> insert y, otherwise insert -> n" << endl;

    sign = AuxiliaryMethods :: loadCharacter();

    if(sign == 'y')
    {

       expense.setDate(setTodaysDate());

        expense.setItem(setItem());

        expense.setAmount(setAmount());

        saveExpenseToFile(expense);


    }
    else if(sign == 'n')
    {
        expense.setDate(setUsersDate());

        expense.setItem(setItem());

        expense.setAmount(setAmount());

        saveExpenseToFile(expense);
    }
    else
    {
        cout << "Please select character y/n ones again.";
    }


}
