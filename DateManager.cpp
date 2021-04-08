#include "DateManager.h"

struct tm* DateManager :: setLocaltime()
{
    time_t myTime;
    tm *pointer;
    time( &myTime );

    return pointer = localtime( &myTime );
}

bool DateManager :: isTheDateCorrect(int year, int month, int day)
{
    tm* pointer = setLocaltime();

    if(year < 2000 || year > pointer->tm_year + 1900)
    {
        cout << "Invalid year number. The date should be between 2000-01-01 and the last day of the current month. Try again." << endl;
        getch();
        return false;
    }

    if(month < 1 || month > pointer ->tm_mon+1)
    {
        cout << "Invalid month number. The date should be between 2000-01-01 and the last day of the current month. Try again. " << endl;
        getch();
        return false;
    }

    if(!isNumberOfDaysInMonthCorrect(day, month, year))
    {
        cout << "Invalid day of the month. Check if the month has too many days." << endl;
        getch();
        return false;
    }

    else
        return true;
}

bool DateManager :: isYearLeap (int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

bool DateManager :: isNumberOfDaysInMonthCorrect (int numberOfDays, int month, int year)
{
    if ( month == 2 )
    {
        if ( isYearLeap(year) )
        {
            if (numberOfDays > 0 && numberOfDays < 30)
                return true;
            else
                return false;
        }
        else
        {
            if (numberOfDays > 0 && numberOfDays < 29)
                return true;
            else
                return false;
        }
    }

    else if ( month == 4 || month == 6 || month == 9 || month == 11 )
    {
        if (numberOfDays > 0 && numberOfDays < 31)
            return true;
        else
            return false;
    }

    else if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (numberOfDays > 0 && numberOfDays < 32)
            return true;
        else
            return false;
    }
}

char* DateManager :: getTodaysDate()
{
    tm* pointer = setLocaltime();

    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}


char* DateManager :: getUsersDate()
{
    tm *pointer = setLocaltime();

    int year, month, day;

    do
    {
        cout << "Enter the year: ";
        cin >> year;

        cout << "Enter the month: ";
        cin >> month;

        cout << "Enter the day: ";
        cin >> day;

        cout << endl;
    }
    while(!isTheDateCorrect(year, month, day));

    if(isTheDateCorrect(year, month, day))
    {
        pointer->tm_year = year - 1900;
        pointer->tm_mon = month - 1;
        pointer ->tm_mday = day;

        char *myDate = asctime( pointer );

        strftime( myDate,11, "%Y-%m-%d", pointer );

        cin.sync();

        return myDate;
    }

}

int DateManager :: changeTheDateToInt (char* date)
{
    string year="0000", month="00", day="00", wholeDate;

    int dateNumerically;

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

    wholeDate = year + month + day;

    return dateNumerically = atoi(wholeDate.c_str());
}

int DateManager :: returnLastDayInMonth (int month, int year)
{
    int lastDayInMonth = 0;

    if ( month == 2 )
    {
        if ( DateManager :: isYearLeap(year) )
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

char* DateManager :: getDateOfTheLastDayOfTheCurrentMonth()
{
    tm *pointer = setLocaltime();

    pointer -> tm_mday = returnLastDayInMonth(pointer->tm_mon+1, pointer->tm_year+1900);

    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}

char* DateManager :: getDateOfTheLastDayOfThePreviousMonth()
{
    tm *pointer = setLocaltime();

    pointer -> tm_mday = returnLastDayInMonth(pointer->tm_mon, pointer->tm_year+1900);
    pointer -> tm_mon --;

    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}

char* DateManager :: getDateOfTheFirstDayOfTheCurrentMonth()
{
    int i = 01;

    tm *pointer = setLocaltime();

    pointer -> tm_mday = i;

    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}

char* DateManager :: getDateOfTheFirstDayOfThePreviousMonth()
{
    int i = 01;

    tm *pointer = setLocaltime();

    pointer -> tm_mday = i;
    pointer -> tm_mon --;

    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}
