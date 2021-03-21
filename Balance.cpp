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

        int todayDate = changeTheDateToInt(todaySDate);

        char* lastDayInMonthDate = getLastDayInMonthDate();

        int lastDayInMonthDate2 = changeTheDateToInt(lastDayInMonthDate);

        char* firstDayInMonthDate = getFirstDayInMonthDate();

        int firstDayInMonthDate2 = changeTheDateToInt(firstDayInMonthDate);

        cout << firstDayInMonthDate2 << "    " << lastDayInMonthDate2 << endl;
        getch();



       sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
        {
            return changeTheDateToInt(income1.getDate()) < changeTheDateToInt(income2.getDate());

        }
        );

        for (int i=0; i<incomes.size(); i++)
        {
            if(changeTheDateToInt(incomes[i].getDate()) >= firstDayInMonthDate2 && changeTheDateToInt(incomes[i].getDate()) <= lastDayInMonthDate2)
            {
                cout << "Date: " << incomes[i].getDate() << "; " << "Item: " << incomes[i].getItem() << "; " << "Amount: " << incomes[i].getAmount() << endl;
            }
        }
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

         char* Balance :: getLastDayInMonthDate()
     {
        time_t myTime;
        struct tm *pointer;
        time( &myTime );
        pointer = localtime( &myTime );
        pointer -> tm_mday = returnLastDayInMonth(pointer->tm_mon+1, pointer->tm_year+1900);

        cout << "Powinien byæ ostatni dzieñ: " << pointer->tm_mday << endl;
        getch();

        char *date = asctime( pointer );
        strftime( date, 11, "%Y-%m-%d", pointer );

        return date;
     }

     char* Balance :: getLastDayInPreviousMonthDate()
     {
        time_t myTime;
        struct tm *pointer;
        time( &myTime );
        pointer = localtime( &myTime );
        pointer -> tm_mday = returnLastDayInMonth(pointer->tm_mon, pointer->tm_year+1900);
        pointer -> tm_mon --;

        cout << "Powinien byæ ostatni dzieñ: " << pointer->tm_mday << endl;
        getch();

        char *date = asctime( pointer );
        strftime( date, 11, "%Y-%m-%d", pointer );

        return date;
     }

          char* Balance :: getFirstDayInMonthDate()
     {
        int i = 01;
        time_t myTime;
        struct tm *pointer;
        time( &myTime );
        pointer = localtime( &myTime );
        pointer -> tm_mday = i;

        cout << "Powinien byæ pierwszy dzieñ: " << pointer->tm_mday << endl;

        char *date = asctime( pointer );
        strftime( date, 11, "%Y-%m-%d", pointer );

        return date;
     }

     char* Balance :: getFirstDayInPreviousMonthDate()
     {
        int i = 01;
        time_t myTime;
        struct tm *pointer;
        time( &myTime );
        pointer = localtime( &myTime );
        pointer -> tm_mday = i;
        pointer -> tm_mon --;

        cout << "Powinien byæ pierwszy dzieñ: " << pointer->tm_mday << endl;

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

int Balance :: returnLastDayInMonth (int month, int year)
{
    int lastDayInMonth = 0;

    if ( month == 2 )
        {
            if ( isYearLeap(year) )
                {
                    lastDayInMonth = 29;
                    return lastDayInMonth;
                }
            else
                {
                    lastDayInMonth = 28;
                    return lastDayInMonth;
                }
        }

    else if ( month == 4 || month == 6 || month == 9 || month == 11 )
        {
            lastDayInMonth = 30;
            return lastDayInMonth;
        }

     else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            lastDayInMonth = 31;
            return lastDayInMonth;
        }
}

bool Balance :: isYearLeap (int year)
{
 if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
 else
    return false;
}

 void Balance :: showThePreviousMonthBalance()
 {
        char* todaySDate = getTodaysDate();

        int todayDate = changeTheDateToInt(todaySDate);

        char* lastDayInPreviousMonthDate = getLastDayInPreviousMonthDate();

        int lastDayInPreviousMonthDate2 = changeTheDateToInt(lastDayInPreviousMonthDate);

        char* firstDayInPreviousMonthDate = getFirstDayInPreviousMonthDate();

        int firstDayInPreviousMonthDate2 = changeTheDateToInt(firstDayInPreviousMonthDate);

        cout << firstDayInPreviousMonthDate2 << "    " << lastDayInPreviousMonthDate2 << endl;
        getch();



       sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
        {
            return changeTheDateToInt(income1.getDate()) < changeTheDateToInt(income2.getDate());

        }
        );

        for (int i=0; i<incomes.size(); i++)
        {
            if(changeTheDateToInt(incomes[i].getDate()) >= firstDayInPreviousMonthDate2 && changeTheDateToInt(incomes[i].getDate()) <= lastDayInPreviousMonthDate2)
            {
                cout << "Date: " << incomes[i].getDate() << "; " << "Item: " << incomes[i].getItem() << "; " << "Amount: " << incomes[i].getAmount() << endl;
            }
        }
        getch();







 }
