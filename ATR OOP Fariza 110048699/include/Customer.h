#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
    public :
    std::string username;
    std::string password;
    std::string name;
    char gender;
    std::string passportNum;
    std::string nationality;
    std::string dateOfBirth;
    std::string email;
    std::string contactNum;
    void personalInformation();
    void showPersonalInformation(std::string name, char gender, std::string nationality, std::string passportNum, std::string dateOfBirth, std::string email, std::string contactNum);
};

#endif // CUSTOMER_H
