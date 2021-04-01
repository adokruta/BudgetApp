#include "DateManager.h"

bool DateManager :: isTheDateCorrect(int year, int month, int day)
{
    time_t myTime;
    struct tm *pointer;
    time( &myTime );
    pointer = localtime( &myTime );

    if(year < 2000 || year > pointer->tm_year + 1900)
    {
        cout << "The date should be between 2000-01-01 and the last day of the current month. Try again." << endl;
        getch();
        return false;
    }

    if(month < 1 || month > 12)
      {
          cout << "Invalid month number. Enter a number from 1 to 12. " << endl;
          getch();
          return false;
      }

    if(!isNumberOfDaysInMonthCorrect(day, month, year))
    {
          cout << "Invalid day of the month. Check if the month has so many days." << endl;
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
    time_t myTime;
    struct tm *pointer;
    time( &myTime );
    pointer = localtime( &myTime );
    char *date = asctime( pointer );
    strftime( date, 11, "%Y-%m-%d", pointer );

    return date;
}


char* DateManager :: getUsersDate()
{
    time_t myTime;
    struct tm *pointer;
    time( &myTime );

    int year, month, day;

    do
    {
        system ("cls");
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
        cout << "The date is correct." << endl;
        getch();

        pointer = localtime(& myTime);
        pointer->tm_year = year - 1900;
        pointer->tm_mon = month - 1;
        pointer ->tm_mday = day;

        char *myDate = asctime( pointer );

        strftime( myDate,11, "%Y-%m-%d", pointer );

        cin.sync();

        return myDate;
    }

}
