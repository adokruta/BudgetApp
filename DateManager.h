#ifndef DATEMANAGER_H
#define DATEMANAGER_H


#include "AuxiliaryMethods.h"
#include <time.h>
#include <conio.h>


using namespace std;

class DateManager
{

public:

    static bool isTheDateCorrect(int year, int month, int day);
    static bool isYearLeap (int year);
    static bool isNumberOfDaysInMonthCorrect (int numberOfDays, int month, int year);
    static char* getTodaysDate();
    static char* getUsersDate();



};

#endif
