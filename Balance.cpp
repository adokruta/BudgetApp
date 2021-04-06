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
            strcpy( date, xml.GetData().c_str());
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


void Balance :: showTheCurrentMonthBalance()
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

    int dateOfTheLastDayOfTheCurrentMonthNumerically = DateManager :: changeTheDateToInt(DateManager :: getDateOfTheLastDayOfTheCurrentMonth());

    int dateOfTheFirstDayOfTheCurrentMonthNumerically = DateManager :: changeTheDateToInt(DateManager :: getDateOfTheFirstDayOfTheCurrentMonth());

    sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
    {
        return DateManager :: changeTheDateToInt(income1.getDate()) < DateManager :: changeTheDateToInt(income2.getDate());
    }
        );

    sort( expenses.begin( ), expenses.end( ), [ ](   Expense& expense1,  Expense& expense2 )
    {
        return DateManager :: changeTheDateToInt(expense1.getDate()) < DateManager :: changeTheDateToInt(expense2.getDate());
    }
        );

    cout << "Incomes:" << endl;

    for (int i=0; i<incomes.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(incomes[i].getDate()) >= dateOfTheFirstDayOfTheCurrentMonthNumerically && DateManager :: changeTheDateToInt(incomes[i].getDate()) <= dateOfTheLastDayOfTheCurrentMonthNumerically)
        {
            cout << "Date: " << incomes[i].getDate() << "; " << "Item: " << incomes[i].getItem() << "; " << "Amount: " << incomes[i].getAmount() << endl;
            sumOfIncomes += atof((incomes[i].getAmount()).c_str());
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Expenses: " << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(expenses[i].getDate()) >= dateOfTheFirstDayOfTheCurrentMonthNumerically && DateManager :: changeTheDateToInt(expenses[i].getDate()) <= dateOfTheLastDayOfTheCurrentMonthNumerically)
        {
            cout << "Date: " << expenses[i].getDate() << "; " << "Item: " << expenses[i].getItem() << "; " << "Amount: " << expenses[i].getAmount() << endl;
            sumOfExpenses += atof((expenses[i].getAmount()).c_str());
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Balance: " << sumOfIncomes - sumOfExpenses << endl;

    getch();
}

void Balance :: showThePreviousMonthBalance()
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

    int dateOfTheLastDayOfThePreviousMonthNumerically = DateManager :: changeTheDateToInt(DateManager :: getDateOfTheLastDayOfThePreviousMonth());

    int dateOfTheFirstDayOfThePreviousMonthNumerically = DateManager :: changeTheDateToInt(DateManager :: getDateOfTheFirstDayOfThePreviousMonth());

    sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
    {
        return DateManager :: changeTheDateToInt(income1.getDate()) < DateManager :: changeTheDateToInt(income2.getDate());

    }
        );

    sort( expenses.begin( ), expenses.end( ), [ ](   Expense& expense1,  Expense& expense2 )
    {
        return DateManager :: changeTheDateToInt(expense1.getDate()) < DateManager :: changeTheDateToInt(expense2.getDate());
    }
        );


    cout << "Incomes:" << endl;

    for (int i=0; i<incomes.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(incomes[i].getDate()) >= dateOfTheFirstDayOfThePreviousMonthNumerically && DateManager :: changeTheDateToInt(incomes[i].getDate()) <= dateOfTheLastDayOfThePreviousMonthNumerically)
        {
            cout << "Date: " << incomes[i].getDate() << "; " << "Item: " << incomes[i].getItem() << "; " << "Amount: " << incomes[i].getAmount() << endl;
            sumOfIncomes += atof((incomes[i].getAmount()).c_str());
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Expenses: " << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(expenses[i].getDate()) >= dateOfTheFirstDayOfThePreviousMonthNumerically && DateManager :: changeTheDateToInt(expenses[i].getDate()) <= dateOfTheLastDayOfThePreviousMonthNumerically)
        {
            cout << "Date: " << expenses[i].getDate() << "; " << "Item: " << expenses[i].getItem() << "; " << "Amount: " << expenses[i].getAmount() << endl;
            sumOfExpenses += atof((expenses[i].getAmount()).c_str());
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Balance: " << sumOfIncomes - sumOfExpenses << endl;

    getch();
}

    void Balance :: showTheBalanceForTheSelectedPeriod()
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

    cout << "Enter the date of the beginning of the balance:  " << endl;

    int beginDateNumerically = DateManager :: changeTheDateToInt(DateManager :: getUsersDate());

    cout << "Enter the date of the end of the balance:  " << endl;

    int endDateNumerically = DateManager :: changeTheDateToInt(DateManager :: getUsersDate());


         sort( incomes.begin( ), incomes.end( ), [ ](   Income& income1,  Income& income2 )
    {
        return DateManager :: changeTheDateToInt(income1.getDate()) < DateManager :: changeTheDateToInt(income2.getDate());
    }
    );

          sort( expenses.begin( ), expenses.end( ), [ ](   Expense& expense1,  Expense& expense2 )
    {
        return DateManager :: changeTheDateToInt(expense1.getDate()) < DateManager :: changeTheDateToInt(expense2.getDate());
    }
    );

    cout << "Incomes: " << endl;

    for (int i=0; i<incomes.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(incomes[i].getDate()) >= beginDateNumerically && DateManager :: changeTheDateToInt(incomes[i].getDate()) <= endDateNumerically)
        {
            cout << "Date: " << incomes[i].getDate() << "; " << "Item: " << incomes[i].getItem() << "; " << "Amount: " << incomes[i].getAmount() << endl;
            sumOfIncomes += atof((incomes[i].getAmount()).c_str());
        }
    }


    cout << "---------------------------------------------" << endl;
    cout << "Expenses: " << endl;

    for (int i=0; i<expenses.size(); i++)
    {
        if(DateManager :: changeTheDateToInt(expenses[i].getDate()) >= beginDateNumerically && DateManager :: changeTheDateToInt(expenses[i].getDate()) <= endDateNumerically)
        {
            cout << "Date: " << expenses[i].getDate() << "; " << "Item: " << expenses[i].getItem() << "; " << "Amount: " << expenses[i].getAmount() << endl;
            sumOfExpenses += atof((expenses[i].getAmount()).c_str());
        }
    }

    cout << "---------------------------------------------" << endl;
    cout << "Sum of incomes: " << sumOfIncomes << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Sum of expenses: " << sumOfExpenses << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Balance: " << sumOfIncomes - sumOfExpenses << endl;

    getch();
}

