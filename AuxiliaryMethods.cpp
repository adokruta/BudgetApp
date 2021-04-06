#include "AuxiliaryMethods.h"


string AuxiliaryMethods :: loadLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}

char AuxiliaryMethods :: selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadCharacter();

    return choice;
}

char AuxiliaryMethods :: loadCharacter()
{
    string enter = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "This is no single character. Please try again." << endl;
    }
    return sign;
}


char AuxiliaryMethods ::  selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Balance for the current month" << endl;
    cout << "4. Balance for the previous month" << endl;
    cout << "5. Balance for the selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = loadCharacter();

    return choice;
}

int  AuxiliaryMethods ::  wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

string AuxiliaryMethods :: changeCommaToPeriod( string wordToChange)
{
    for (int i=0; i <= wordToChange.size(); i++)
    {
        if (wordToChange[i] == ',')
        {
            wordToChange[i] = '.';
        }
    }

    return wordToChange;
}
