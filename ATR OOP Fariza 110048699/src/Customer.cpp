#include "Customer.h"
#include <string>
#include <iostream>

using namespace std;


void Customer :: personalInformation() //input user personal information for administrator book, register member and book ticket without login
{
    cout << "\tREGISTRATION" << endl;
    cout << endl;
    cout << "Username\t\t : ";
    cin.ignore();
    getline(cin, username);
    cout << "Password\t\t : ";
    cin >> password;
    cout << "Name\t\t\t : ";
    cin.ignore();
    getline(cin, name);
    cout << "Gender\nMale(M) or Female (F)    : ";
    cin >> gender;
    cout << "Nationality\t\t : ";
    cin >> nationality;
    cout << "Passport Number/IC\t : ";
    cin >> passportNum;
    cout << "Date of birth (dd/mm/yy) : ";
    cin >> dateOfBirth;
    cout << "Email adress\t\t : ";
    cin >> email;
    cout << "Phone number\t\t : ";
    cin >> contactNum;
    //Show information to be check
    cout << "\nBelow are the entered information." << endl;
    cout << endl;
    cout << "Username\t: " << username << endl;
    cout << "Password\t: " << password << endl;
    cout << endl;
    showPersonalInformation(name, gender, nationality, passportNum, dateOfBirth, email, contactNum);
}

void Customer :: showPersonalInformation(string name, char gender, string nationality, string passportNum, string dateOfBirth, string email, string contactNum)
{
    cout << "Name\t\t\t: " << name << endl;
    cout << "Gender\t\t\t: " << gender << endl;
    cout << "Nationality\t\t: " << nationality << endl;
    cout << "Passport Number/IC\t: " << passportNum << endl;
    cout << "Date of Birth\t\t: " << dateOfBirth << endl;
    cout << "Email adress\t\t: " << email << endl;
    cout << "Contact No\t\t: " << contactNum << endl;
}
