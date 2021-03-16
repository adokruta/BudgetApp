#include "Balance.h"


 vector <Income> Balance :: loadIncomesFromFile()
 {
    Income income;

    CMarkup xml;

    bool fileExists = xml.Load( "incomes.xml" );

     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Income") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if(LOGGED_IN_USER_ID == atoi( MCD_2PCSZ(xml.GetData())))
        {
             income.setuserId(LOGGED_IN_USER_ID);

             xml.FindElem( "incomeId" );
             income.setCashFlowId(atoi( MCD_2PCSZ(xml.GetData())));

             xml.FindElem( "date" );
             char *date = new char[11];
             strcpy( date, xml.GetData().c_str() );
             income.setDate(date);
             //delete date;
             //date = NULL;

             xml.FindElem( "item" );
             income.setItem(xml.GetData());

             xml.FindElem( "amount" );
             income.setAmount(xml.GetData());


             incomes.push_back(income);
        }

        xml.OutOfElem();
    }

 return incomes;
 }

 void Balance :: showIncomes()
{
    for(int i=0; i<incomes.size(); i++)
    {
        cout << endl << incomes[i].getuserId() << endl;
        cout << incomes[i].getCashFlowId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl << endl;
        getch();
    }
}
