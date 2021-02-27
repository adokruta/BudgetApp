#include "UserManager.h"
#include <conio.h>


void UserManager :: registerUser()
{
    User user = getNewUserData();

    users.push_back(user);

    saveUserToFile(user);

    cout << endl << "Account created succesfully" << endl << endl;
    system("pause");
}

User UserManager :: getNewUserData()
{
    User user;
    user.setId( getNewUserId());

    string name;
    cout << "Enter your name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Enter your surname: ";
    cin >> surname;
    user.setSurname(surname);

    string login;
    do
    {
        cout << "Enter login: ";
        cin >> login;

        user.setLogin(login);

    } while (loginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager :: getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager :: loginExist(string login)
{
   for(int i=0; i < users.size(); i++)
   {
       if(users[i].getLogin() == login)
       {
           cout << endl << "There is a user with such login! Try another." << endl;
           return true;
       }
   }
    return false;
}

 void UserManager :: loginUser()
{
 if( !users.empty())
 {
    string login = "", password = "";

    system("cls");
    cout << "Enter login: ";
    login = auxiliaryMethods.loadLine();

   for(int i=0; i < users.size(); i++)
   {
        if ( users[i].getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password. Attempts left: " << numberOfAttempts << ": ";
                password = auxiliaryMethods.loadLine();

                if (users[i].getPassword() == password)
                {
                    loggedInUserId = users[i].getId();
                    cout << endl << "You have logged in!" << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wrong password was entered three times." << endl;
            system("pause");
            return;
        }

    }
    cout << "There is no user with such login." << endl;
    system("pause");
    return;

 }
 else
 {
     cout << "The file with users is empty. Please log in." << endl;
     system ("pause");
    return;
 }
}

 int UserManager :: getLoggedInUserId()
 {
     return loggedInUserId;
 }

void UserManager ::  changePassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = auxiliaryMethods.loadLine();

    for (int i=0; i <=users.size(); i++)
    {
        if (users[i].getId() == getLoggedInUserId())
        {
            users[i].setPassword(newPassword);
            cout << "The password has changed." << endl << endl;
            system("pause");
        }
    }

    CMarkup xml;
    User user;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        if(loggedInUserId == atoi( MCD_2PCSZ(xml.GetData())))
        {
            xml.FindElem( "password" );
            xml.SetData(newPassword);

            break;
        }
        xml.OutOfElem();
    }
    //xml.Save("users.xml");


}

bool UserManager ::  isUserLoggedIn()
{
    if(loggedInUserId > 0)
        return true;
    else
        return false;
}

 void UserManager :: logoutUser()
 {
     loggedInUserId = 0;
 }

 void UserManager :: saveUserToFile(User user)
 {
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save("users.xml");
 }

 vector <User> UserManager :: loadUsersFromFile()
 {
    User user;

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

     if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }

    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") )
    {
         xml.IntoElem();
         xml.FindElem( "userId" );
         user.setId(atoi( MCD_2PCSZ(xml.GetData())));

         xml.FindElem( "login" );
         user.setLogin(xml.GetData());

         xml.FindElem( "password" );
         user.setPassword(xml.GetData());

         xml.FindElem( "name" );
         user.setName(xml.GetData());

         xml.FindElem( "surname" );
         user.setSurname(xml.GetData());
         xml.OutOfElem();

         users.push_back(user);
    }

    return users;

 }

void UserManager :: showUsers()
{
    for(int i=0; i<users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl << endl;
    }
}
