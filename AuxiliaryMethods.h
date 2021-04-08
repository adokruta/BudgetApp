#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
     static string loadLine();
     static char selectOptionFromMainMenu();
     static char loadCharacter();
     static char selectOptionFromUserMenu();
     static float loadFloatingPointNumber();
     static string changeCommaToPeriod(string wordToChange);
     static string floatToString (float number);
};

#endif
