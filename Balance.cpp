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
             delete date;
             date = NULL;

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


 vector <Expense> Balance :: loadExpensesFromFile()
 {
    Expense expense;

    CMarkup xml;

    bool fileExists = xml.Load( "expenses.xml" );

     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("Expense") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if(LOGGED_IN_USER_ID == atoi( MCD_2PCSZ(xml.GetData())))
        {
             expense.setuserId(LOGGED_IN_USER_ID);

             xml.FindElem( "expenseId" );
             expense.setCashFlowId(atoi( MCD_2PCSZ(xml.GetData())));

             xml.FindElem( "date" );
             char *date = new char[11];
             strcpy( date, xml.GetData().c_str() );
             expense.setDate(date);
             delete date;
             date = NULL;

             xml.FindElem( "item" );
             expense.setItem(xml.GetData());

             xml.FindElem( "amount" );
             expense.setAmount(xml.GetData());

             expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
 return expenses;
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

 void Balance :: showExpenses()
{
    for(int i=0; i<expenses.size(); i++)
    {
        cout << endl << expenses[i].getuserId() << endl;
        cout << expenses[i].getCashFlowId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl << endl;
        getch();
    }
}


    void Balance :: showTheCurrentMonthBalance()
    {
        char* todaySDate = getTodaysDate();

       sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
        {
            return changeTheDateToInt(income1.getDate()) < changeTheDateToInt(income2.getDate());
           /* for(int i=0; i<11; i++)
            {
                if((*income1.getDate()+i != *income2.getDate()+i))
                {
                    return (*income1.getDate()+i < *income2.getDate()+i);
                }

            }
*/
        }
        );
        getch();
        showIncomes();
        getch();




    }

    char* Balance :: getTodaysDate()
     {
        time_t myTime;
        struct tm *pointer;
        time( &myTime );
        pointer = localtime( &myTime );
        char *date = asctime( pointer );
        strftime( date, 11, "%Y-%m-%d", pointer );

        return date;
     }

     int Balance :: changeTheDateToInt (char* date)
     {
         string year="0000", month="00", day="00", alldate;
         int dateByNr;

         for(int i=0; i<4; i++)
         {
             year[i] = *(date+i);
         }

          for(int i=0; i<2; i++)
         {
             month[i] = *(date+i+5);
         }

          for(int i=0; i<2; i++)
         {
             day[i] = *(date+i+8);
         }



     alldate = year + month + day;

     return dateByNr = atoi(alldate.c_str());
     }

