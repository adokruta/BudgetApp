#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
     static string konwerjsaIntNaString(int liczba);
     static string loadLine();
     static char selectOptionFromMainMenu();
     static char loadCharacter();
     string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
     int konwersjaStringNaInt(string liczba);
     string pobierzLiczbe(string tekst, int pozycjaZnaku);
     static char selectOptionFromUserMenu();
     static int wczytajLiczbeCalkowita();
     static char wybierzOpcjeZMenuEdycja();
     static string changeCommaToPeriod(string wordToChange);
};

#endif
