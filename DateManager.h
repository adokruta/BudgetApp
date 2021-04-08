#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include "AuxiliaryMethods.h"
#include <time.h>
#include <conio.h>

using namespace std;

class DateManager
{
    static bool isTheDateCorrect(int year, int month, int day);
    static bool isYearLeap (int year);
    static bool isNumberOfDaysInMonthCorrect (int numberOfDays, int month, int year);
    static struct tm* setLocaltime();
    static struct tm* pointer;

public:
     DateManager()
    {
    };

    static char* getTodaysDate();
    static char* getUsersDate();
    static int changeTheDateToInt(char* date);
    static int returnLastDayInMonth (int month, int year);
    static char*  getDateOfTheLastDayOfTheCurrentMonth();
    static char* getDateOfTheLastDayOfThePreviousMonth();
    static char*  getDateOfTheFirstDayOfTheCurrentMonth();
    static char*  getDateOfTheFirstDayOfThePreviousMonth();

};

#endif
