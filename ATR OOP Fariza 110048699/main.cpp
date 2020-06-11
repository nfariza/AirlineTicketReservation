/*PROGRAMMER : NUR FARIZA BINTI BAHARUDDIN
STUDENT ID : 110048699
AIRLINE TICKET RESERVATION

-IMPORTANT NOTICE-
This program will create a text file, and rewrite it.
Hence, it is advisable to use computer storage when running this program.
Running in CD-RW/DVD-RW may affect the disc if it is rewrite numerous times
Thank you. */

//list of header files
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Customer.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"

//list of subfunctions
void showMenu();
void member();
void flightMenu();
void bookingSummary();
void ticketConfirmation();
void invoiceSummary();
void flightTicket();
void showCustomerBasedOnFlight();

using namespace std;

//declare for writing to .txt file
ofstream file;

//global variables
string usernameMember, passwordMember, name, nationality, passportNum, email, contactNum;
int adult, child, infant, travelInsurance, chooseFlight, depart;
float baggage, totalBaggage, priceBaggage, dPriceTicket, iPriceTicket, GST, totalPurchases, totalPrice;
char buyTicket, gender, insurance;

//class Customer object
Customer c1;

//class DomesticFlight object
DomesticFlight d1;

//implementation of methods  for class DomesticFlight
void DomesticFlight :: flight() //list of available Domestic flights
{
    system("CLS");
    cout << "\t\t\t\t\t\t\t     AVAILABLE FLIGHT" << endl;
    cout << endl;
    cout << "Choice\tFlight No.\tOrigin\t\t\tDestination\t\tDepart date \tDepart time\tFare(Adult)\tFare(Children/Elderly)" << endl;
    cout << endl;
    for(int num=0;num<numOfFlight;num++) {
        cout << num+1 << "\t" <<  flightNumber[num] << "\t\t" << origin[num] << "\t" << destination[num] << "\t" << departDate[num] << "\t\t" << departTime[num] << "\t\tRM " << dFare[num] << "\t\tRM" << dFare[num] /2 << endl;
        cout << endl;
    }
}

void DomesticFlight :: dTicket()
{
    file << "\t" << "**********************************************" << endl;
    file << "\t" << "Origin      : " << d1.origin[depart-1] << endl;
    file << "\t" << "Destination : " << d1.destination[depart-1] << endl;
    file << "\t" << "Depart date : "<< d1.departDate[depart-1] << endl;
    file << "\t" << "Depart time : " << d1.departTime[depart-1] << endl;
    file << "\t" << "**********************************************" << endl;

}

//class InternationalFlight object
InternationalFlight i1;

//implementation of methods  for class InternationalFlight
void InternationalFlight :: flight() //list of available International flights
{
    system("CLS");
    cout << "\t\t\t\t\t\t\t     AVAILABLE FLIGHT" << endl;
    cout << endl;
    cout << "Choice\tFlight No.\tOrigin\t\t\tDestination\t\tDepart date \tDepart time\tFare(Adult)\tFare(Children/Elderly)" << endl << endl;
    for(int num=0;num<numOfFlight;num++) {
        cout << num+1 << "\t" <<  flightNumber[num] << "\t\t" << origin[num] << "\t" << destination[num] << "\t" << departDate[num] << "\t\t" << departTime[num] << "\t\tRM " << iFare[num] << "\t\tRM" << iFare[num] /2 << endl;
        cout << endl;
    }
}

void InternationalFlight :: iTicket()
{

    file << "\t" << "**********************************************" << endl;
    file << "\t" << "Origin      : " << i1.origin[depart-1] << endl;
    file << "\t" << "Destination : " << i1.destination[depart-1] << endl;
    file << "\t" << "Depart date : "<< i1.departDate[depart-1] << endl;
    file << "\t" << "Depart time : " << i1.departTime[depart-1] << endl;
    file << "\t" << "**********************************************" << endl;
}

// main function
int main()
{
    //local variables
    int exit=0, choice;
    char confirmInfo;

    //loop to return to main menu
    while(exit!=1) {
    system("CLS");
    //greet user and show menu
    cout << "**********************************" << endl;
    cout << "    WELCOME TO SAKURA AIRLINES" << endl;
    cout << "**********************************" << endl;
    cout << endl;

    showMenu();
    cin >> choice;
    //exit the program
    if(choice == 0) {
        cout << "Thank you. Have a nice day" << endl;
        exit = 1;
        break;
        }

    switch (choice)
    {
    case 1 :
        do {
        //register as a member
        system("CLS");
        c1.personalInformation(); //calling class Customer function
        cout << endl;
        cout << "Confirm that all the information are correct (Y/N) : ";
        cin >> confirmInfo;
        }while (confirmInfo == 'n' || confirmInfo == 'N');
        if (confirmInfo == 'y' || confirmInfo == 'Y')
        {
            cout << endl;
            cout << "Thank you for being a member for this company." << endl;
            cout << "You can now login" << endl;
        }
        else
        cout << "Invalid input" << endl;
        system("PAUSE");
        break;

    case 2 :
        //login as member
        usernameMember = "susan"; passwordMember = "susan123";
        usernameMember = c1.username; passwordMember = c1.password;

        system("CLS");
        cout << "\tLOGIN" << endl;
        cout << endl;
        cout << "username : ";
        cin >> usernameMember;
        cout << "password : ";
        cin >> passwordMember;

        if ((usernameMember == "susan" && passwordMember == "susan123") || (usernameMember == c1.username && passwordMember == c1.password))
        {
        cout << endl;
        cout << "LOGIN SUCCESS" << endl; //verified and validated login
        system("PAUSE");
        member(); //call member function (to show what members can do)
        }
        else{
        cout << "Invalid username or password" << endl;}
        system ("PAUSE");
        break;

    case 3 :
        //view available flights
        flightMenu();
        system("PAUSE");
        break;

    case 4 :
        //booking tickets
        flightMenu();
        //show booking summary
        bookingSummary();
        cout << "Do you want to purchase? (Y/N)" << endl;
        cin >> buyTicket;
        cout << endl;
        //proceed if customer want to buy
        if (buyTicket == 'Y' || buyTicket == 'y')
        {
            //if the customer does not login, enter personal details for booking tickets
            system("CLS");
            cout << "You are not logged in yet. Please enter your personal details" << endl;
            cout << endl;
            cout << "\tPERSONAL DETAILS" << endl;
            cout << "Name\t\t\t : ";
            cin.ignore();
            getline(cin, name);
            cout << "Gender\nMale(M) or Female (F)    : ";
            cin >> gender;
            cout << "Nationality\t\t : ";
            cin >> nationality;
            cout << "Passport Number/IC\t : ";
            cin >> passportNum;
            cout << "Email adress\t\t : ";
            cin >> email;
            cout << "Phone number\t\t : ";
            cin >> contactNum;
            system("PAUSE");
            //payment of tickets
            ticketConfirmation();
            //show customer's invoice
            system("CLS");
            cout << "\t\tINVOICE SUMMARY" << endl;
            cout << endl;
            cout << "Customer : " << name << endl;
            cout << endl;
            cout << "Adult : " << adult << endl;
            cout << "Child : " << child << endl;
            cout << "Infant : " << infant << endl;
            cout << endl;
            invoiceSummary();
            cout << endl;
            cout << "Your flight ticket will be downloaded automatically" << endl;
            system("PAUSE");
            //show customer tickets
            system("CLS");
            //write customer's tickets into ticket.txt
            file.open("ticket.txt");
            file << "\t" << "**********************************************" << endl;
            file << "\t" << "\t\tFLIGHT TICKET" << endl;
            file << "\t" << "**********************************************" << endl;
            file << "\t" << name << endl;
            file << "\t" << passportNum << endl;
            //flightTicket();
            file.close();
            string STRING;
            ifstream infile; //declaration to read .txt file
            infile.open("ticket.txt"); //show flight ticket
            while(!infile.eof()) //to enable it to read line by line
            {
                getline(infile,STRING);
                cout << STRING;
                cout << endl;
            }
            infile.close(); //close file
            system("PAUSE");
        }
        else if (buyTicket == 'N' || buyTicket == 'n')
        {
            break; //exit switch statements
        }
        else
        {
            cout << "Invalid input." << endl;
        }
        break;

    case 5 : //show list of customers based on flights
        showCustomerBasedOnFlight();
        break;

    default :
        cout << "Invalid input" << endl;
        system("PAUSE");
    }
    }
    return 0;
}

void showMenu()
{   //list of main menu
    cout << "1 - Register as a member" << endl;
    cout << "2 - Login" << endl;
    cout << "3 - View available flights" << endl;
    cout << "4 - Book flight ticket" << endl;
    cout << "5 - List of customers per flight" << endl;
    cout << "0 - Close the program" << endl;
}

void memberMenu ()
{   //list of member menu
    cout << "\tMEMBER MENU" << endl;
    cout << "1. View personal details" << endl;
    cout << "2. View available flights" << endl;
    cout << "3. Book flight tickets" << endl;
    cout << "4. List of customers per flight" << endl;
    cout << "0. Logout" << endl;
}

void member() //member menu
{
    //local variables
    int menuMember, exitMember=0;

    while (exitMember!=1){
    system("CLS");
    memberMenu();
    cin >> menuMember;
        //logout
        if(menuMember == 0) {
        cout << "Thank you. Have a nice day" << endl;
        exitMember = 1;
        break;
        }
            switch (menuMember) // member personal details
            {
            case 1 :
                //display personal details
                if (usernameMember == "susan" && passwordMember == "susan123")
                {
                system("CLS");
                cout << "\tPERSONAL DETAILS" << endl;
                cout << endl;
                cout << "Name\t\t : Susan Fletcher" << endl;
                cout << "Gender\t\t : Female" << endl;
                cout << "Nationality\t : American" << endl;
                cout << "Passport Number  : B34219087" << endl;
                cout << "Date Of Birth    : 01/01/1989" << endl;
                cout << "Email\t\t : susan@gmail.com" << endl;
                cout << "Contact No\t : +1 (360) 715-2017" << endl;
                cout << endl;
                }

                else if (usernameMember == c1.username && passwordMember == c1.password)
                {
                system ("CLS");
                cout << "\tPERSONAL DETAILS" << endl;
                cout << endl;
                c1.showPersonalInformation(c1.name, c1.gender, c1.nationality, c1.passportNum, c1.dateOfBirth, c1.email, c1.contactNum);
                }
                system("PAUSE");
                break;

            case 2 :
                //show available flights
                flightMenu();
                system("PAUSE");
                break;

            case 3 :
                flightMenu();
                //member book flight ticket
                bookingSummary();
                cout << "Do you want to purchase? (Y/N)" << endl;
                cin >> buyTicket;
                cout << endl;
                if (buyTicket == 'Y' || buyTicket == 'y')
                {
                system ("CLS");
                // the personal details will be selected according to the username and password
                if (usernameMember == "susan" && passwordMember == "susan123")
                {
                    cout << "\tPERSONAL DETAILS" << endl;
                    cout << endl;
                    cout << "Name\t\t : Susan Fletcher" << endl;
                    cout << "Gender\t\t : Female" << endl;
                    cout << "Nationality\t : American" << endl;
                    cout << "Passport Number  : B34219087" << endl;
                    cout << "Email\t\t : susan@gmail.com" << endl;
                    cout << "Contact No\t : +1 (360) 715-2017" << endl;
                    cout << endl;
                }

                else if (usernameMember == c1.username && passwordMember == c1.password)
                {
                    cout << "\tPERSONAL DETAILS" << endl;
                    cout << endl;
                    cout << "Name\t\t : " << c1.name << endl;
                    cout << "Gender\t\t : " << c1.gender << endl;
                    cout << "Nationality\t : " << c1.nationality << endl;
                    cout << "Passport Number  : " << c1.passportNum << endl;
                    cout << "Email\t\t : " << c1.email << endl;
                    cout << "Contact No\t : " << c1.contactNum << endl;
                }
                system ("PAUSE");
                //pay the flight tickets
                ticketConfirmation();
                //show invoice
                system("CLS");
                cout << "\t\tINVOICE SUMMARY" << endl;
                cout << endl;
                if (usernameMember == c1.username && passwordMember == c1.password)
                {
                cout << "Customer : " << c1.name << endl;
                cout << endl;
                }
                else if (usernameMember == "susan" && passwordMember == "susan123")
                {
                cout << "Customer : Susan Fletcher" << endl;
                cout << endl;
                }
                cout << "Adult : " << adult << endl;
                cout << "Child : " << child << endl;
                cout << "Infant : " << infant << endl;
                invoiceSummary();
                cout << endl;
                cout << "Your flight ticket will be downloaded automatically" << endl;
                system("PAUSE");
                //display tickets
                system("CLS");
                //write data into text files
                file.open("ticket.txt");
                if (usernameMember == "susan" && passwordMember == "susan123")
                {
                file << "\t" << "**********************************************" << endl;
                file << "\t" << "\t\tFLIGHT TICKET" << endl;
                file << "\t" << "**********************************************" << endl;
                file << "\t" << "Susan Fletcher" << endl;
                file << "\t" << "B34219087" << endl;
                }

                else if (usernameMember == c1.username && passwordMember == c1.password)
                {
                file << "\t" << "**********************************************" << endl;
                file << "\t" << "\t\tFLIGHT TICKET" << endl;
                file << "\t" << "**********************************************" << endl;
                file << "\t" << c1.name << endl;
                file << "\t" << c1.passportNum << endl;
                }
                flightTicket();
                file.close();
                string STRING;
                //read data from ticket.txt
                ifstream infile;
                infile.open("ticket.txt");
                while(!infile.eof()) //read data line by line
                {
                getline(infile,STRING);
                cout << STRING;
                cout << endl;
                }
                infile.close();
                system("PAUSE");
                }
                 else if (buyTicket == 'N' || buyTicket == 'n')
                {
                    break;
                }
                else
                {
                cout << "Invalid input." << endl;
                }
                break;

            case 4 :
                //show list of customers based on flights
                showCustomerBasedOnFlight();
                break;

            default :
                cout << "Invalid input" << endl;
                system("PAUSE");
            }
            }
}

void flightMenu()
{
    //flight menu
    system("CLS");
    cout << "\tAVAILABLE FLIGHTS" << endl << endl;
    cout << "1. Domestic Flight" << endl;
    cout << "2. International Flight" << endl;
    cin >> chooseFlight;

    if (chooseFlight==1){
        d1.flight();}
    else{
        i1.flight();}
}

void bookingSummary()
{
    cout << endl;
    cout << "Infant (12 months and below) : free of charge" << endl;
    cout << endl;
    cout << endl;
    cout << "Choose your flight. Please enter the number." << endl;
    cin >> depart; //choose flight
    cout << endl;
    //enter the number of passengers
    cout << "Adult  : ";
    cin >> adult;
    cout << "Child  : ";
    cin >> child;
    cout << "Infant : ";
    cin >> infant;
    system("PAUSE");
    //rules
    system("CLS");
    cout <<"\t\t\t\tRULES" << endl;
    cout << endl;
    cout << "1. All baggage is subject to search." << endl;
    cout << "2. We reserve the right to refuse any bag that has a size, weight or other condition" << endl;
    cout << "   that poses a safety or annoyance risk to other passengers and/or crew, or baggage that" << endl;
    cout << "   is unsuitable for transportation on the aircraft." << endl;
    cout << "3. Specific baggage check-in rules vary by airport and must be met accordingly. " << endl;
    cout << "   Please review airport Check-in Requirements for details." << endl;
    cout << "4. Baggage on our flights can be checked at Sakura's airport curbside check-in," << endl;
    cout << "   at any Sakura's airport kiosk or online via your computer or mobile phone." << endl;
    cout << "5. Please make sure your name is somewhere on your baggage." << endl;
    cout << "6. Baggage will only be checked to the destination on your ticket." << endl;
    cout << endl;
    cout << "The cost for the first 46 kg for each person is free. The subsequence cost for each kg is RM 20" << endl;
    cout << "Please enter the weight of your baggage : " << endl;
    //enter baggage weight
    cin >> baggage;
    cout << endl;
    cout << "Do you want to purchase travel insurance? \nThe cost for the travel insurance for each person is RM 10. \nYes (Y) or No (N): " << endl;
    //choose if want to buy insurance or not
    cin >> insurance;
    cout << endl;
    //show invoice before pay
    invoiceSummary();
}

void ticketConfirmation() //payment method
{
    //local variable
    int paymentMethod, CVV;
    string cardNumber, bankName, date;
    system("CLS");
    //choose method of payment
    cout << "Method of payment" << endl;
    cout << "1. Online banking" << endl;
    cout << "2. Debit card/Credit card" << endl;
    cout << endl;
    cout << "Each transaction has no service fee" << endl;
    cin >> paymentMethod;

    if (paymentMethod == 1)
    {
        system("CLS");
        //online banking
        cout << "Select your online banking site" << endl;
        cout << endl;
        cout << "1. Maybank2u" << endl;
        cout << "2. Cimb Clicks" << endl;
        cout << "3. Bank Islam" << endl;
        cout << "4. Public Bank" << endl;
        cout << "5. PayPal" << endl;
        cin >> bankName;
        cout << endl;
        cout << "Your payment will be directed to the bank website." << endl;
        cout << endl;
    }

    else if (paymentMethod == 2)
    {
        system("CLS");
        //payment by card
        cout << "Card number : ";
        cin >> cardNumber;
        cout << endl;
        cout << "Expire date (mm/yy) : ";
        cin >> date;
        cout << endl;
        cout << "CVV number : ";
        cin >> CVV;
    }
        system("PAUSE");
        system("CLS");
        cout << "Waiting for the response" << endl;
        cout << "........." << endl;
        cout << "Payment received" << endl;
        cout << endl;
        cout << "Thank you for purchasing with us. Have a nice trip." << endl;
        cout << endl;
        system("PAUSE");
}

void invoiceSummary ()
{
    //use alternative statements to calculate price baggage and travel insurance
    totalBaggage = baggage - ((adult + child) * 46);
    if (totalBaggage <= 0){
        cout << "Price of Baggage : RM 0" << endl;}
    else {
        priceBaggage = totalBaggage* 20;
        cout << "Price of Baggage : RM " << priceBaggage  << endl;}
    if (insurance=='Y' || insurance == 'y'){
        travelInsurance = 10 * (adult + child);
        cout << "Travel Insurance : RM " << travelInsurance << endl;}
    else if (insurance == 'N' || insurance == 'n'){
        cout << "Travel Insurance : RM 0" << endl;}

    if (chooseFlight==1) //Domestic flights
    {
        dPriceTicket = (adult * d1.dFare[depart-1]) + (child * (d1.dFare[depart-1]/2));
        cout << "Price of Tickets : RM " << dPriceTicket << endl;
        if (totalBaggage>0 && insurance=='Y'|| insurance=='y'){
            totalPurchases = dPriceTicket + priceBaggage + travelInsurance;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage<=0 && insurance=='Y'|| insurance=='y'){
            totalPurchases = dPriceTicket + travelInsurance;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage>0 && insurance=='N'|| insurance=='n'){
            totalPurchases = dPriceTicket + priceBaggage;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage<=0 && insurance=='N'|| insurance=='m'){
            totalPurchases = dPriceTicket;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        GST = totalPurchases * 0.06;
        cout << "GST 6%           : RM " << GST << endl;
        totalPrice = totalPurchases + GST;
        cout << "TOTAL PRICE      : RM " << totalPrice << endl;
        cout << endl;
    }

    else //International flights
    {
        iPriceTicket = (adult * i1.iFare[depart-1]) + (child * (i1.iFare[depart-1]/2));
        cout << "Price of Tickets : RM " << iPriceTicket << endl;
        if (totalBaggage>0 && insurance=='Y'|| insurance=='y'){
            totalPurchases = iPriceTicket + priceBaggage + travelInsurance;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage<=0 && insurance=='Y'|| insurance=='y'){
            totalPurchases = iPriceTicket + travelInsurance;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage>0 && insurance=='N'|| insurance=='n'){
            totalPurchases = iPriceTicket + priceBaggage;
            cout << "Total Purchases  : RM " << totalPurchases << endl;}
        else if (totalBaggage<=0 && insurance=='N'|| insurance=='m'){
            totalPurchases = iPriceTicket;
            cout << "Total Purchases : RM " << totalPurchases << endl;}
        GST = totalPurchases * 0.06;
        cout << "GST 6%           : RM " << GST << endl;
        totalPrice = totalPurchases + GST;
        cout << "TOTAL PRICE      : RM " << totalPrice << endl;
        cout << endl;
    }
}

void flightTicket()
{   //show flight ticket
    //Domestic
    if (chooseFlight==1)
    {
        d1.dTicket();
    }
    //International
    else if (chooseFlight==2)
    {
        i1.iTicket();
    }
}

void showCustomerBasedOnFlight()
{
    //local variables
    int flight, exitShowFlight=0;
    //show customer based on flights
    while (!exitShowFlight)
    {
    system("CLS");
    cout << endl;
    cout << "\tFLIGHT NUMBER" << endl;
    cout << endl;
    cout << "\t 1 . SA7001\n\t 2 . SA7002\n\t 3 . SA7003\n\t 4 . SA7004\n\t 5 . SA7005\n\t 6 . SA7006\n\t 7 . SA7007\n\t 8 . SA7008\n\t 9 . SA7009\n\t 10. SA7010\n\t 0 . Exit\n\t" << endl;
    cout << endl;
    cout << "Choose flight" << endl;
    cin >> flight;
    //return to main menu
    if(flight == 0) {
    cout << "Thank you. Have a nice day" << endl;
    exitShowFlight = 1;
    break;
        }
    switch (flight)
    {
    case 1 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7001" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin              " << "\t" << "Destination         " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "Rachel   " << "\t" << "B17239017      " << "\t" << "KUL-Kuala Lumpur    " << "\t" << "JHB-Johor Bahru     " << "\t" << "07/6/2018  " << endl;
        cout << "\t" << "Farid    " << "\t" << "M19135016      " << "\t" << "KCH-Kuching         " << "\t" << "KUL-Kuala Lumpur    " << "\t" << "10/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 2 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7002" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin              " << "\t" << "Destination         " << "\t" << "Depart date" << endl;
        cout << "************************************************************************************************************" << endl;
        cout << "\t" << "Kumar    " << "\t" << "M17251627      " << "\t" << "KUL-Kuala Lumpur    " << "\t" << "PEN-Penang          " << "\t" << "08/6/2018  " << endl;
        cout << "\t" << "Richard  " << "\t" << "CK9251013      " << "\t" << "PEN-Penang          " << "\t" << "TGG-Kuala Terengganu" << "\t" << "11/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 3 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7003" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin              " << "\t" << "Destination         " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "David    " << "\t" << "JH1294117      " << "\t" << "SZB-Subang          " << "\t" << "KBR-Kota  Bahru     " << "\t" << "08/6/2018  " << endl;
        cout << "\t" << "Chen     " << "\t" << "M19212038      " << "\t" << "JHB-Johor Bahru     " << "\t" << "KUL-Kuala Lumpur    " << "\t" << "12/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 4 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7004" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin             " << "\t" << "Destination        " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "Kim Tan  " << "\t" << "M72631842      " << "\t" << "LGK-Langkawi       " << "\t" << "KCH-Kuching        " << "\t" << "12/6/2018  " << endl;
        cout << "\t" << "Han Tze  " << "\t" << "M63724209      " << "\t" << "LGK-Langkawi       " << "\t" << "KCH-Kuching        " << "\t" << "12/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 5 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7005" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin             " << "\t" << "Destination        " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "John     " << "\t" << "S77163193      " << "\t" << "BKI-Kota Kinabalu  " << "\t" << "KCH-Kuching        " << "\t" << "09/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 6 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7006" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin          " << "\t" << "Destination     " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 7 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7007" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin          " << "\t" << "Destination     " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "Fatima   " << "\t" << "M81537302      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "LHR-London      " << "\t" << "10/6/2018  " << endl;
        cout << "\t" << "Ahmad    " << "\t" << "M09224382      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "LHR-London      " << "\t" << "10/6/2018  " << endl;
        cout << "\t" << "Rajindar " << "\t" << "IN8241632      " << "\t" << "AKL-Auckland    " << "\t" << "KUL-Kuala Lumpur" << "\t" << "14/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 8 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7008" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin          " << "\t" << "Destination     " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "Maria    " << "\t" << "AK9214527      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "AKL-Auckland    " << "\t" << "11/6/2018  " << endl;
        cout << "\t" << "William  " << "\t" << "AK9135016      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "AKL-Auckland    " << "\t" << "11/6/2018  " << endl;
        cout << "\t" << "Felicia  " << "\t" << "M29237984      " << "\t" << "LHR-London      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "15/6/2018  " << endl;
        cout << "\t" << "Ariana   " << "\t" << "C15517291      " << "\t" << "LHR-London      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "15/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 9 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7009" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name     " << "\t" << "Passport Number" << "\t" << "Origin          " << "\t" << "Destination     " << "\t" << "Depart date" << endl;
        cout << endl;
        cout << "\t" << "Fuad     " << "\t" << "M233392179     " << "\t" << "KUL-Kuala Lumpur" << "\t" << "NRT-Tokyo       " << "\t" << "16/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;

    case 10 :
        cout << "*****************************************************************************************************************" << endl;
        cout << "                                                        FLIGHT SA7010" << endl;
        cout << "*****************************************************************************************************************" << endl;
        cout << "\t" << "Name       " << "\t" << "Passport Number" << "\t" << "Origin          " << "\t" << "Destination     " << "\t" << "Depart date" << endl;
        cout << "\t" << "Sharifah   " << "\t" << "M97323385      " << "\t" << "ICN-Seoul       " << "\t" << "KUL-Kuala Lumpur" << "\t" << "13/6/2018  " << endl;
        cout << "\t" << "Sharifah   " << "\t" << "M97323385      " << "\t" << "KUL-Kuala Lumpur" << "\t" << "ICN-Seoul       " << "\t" << "16/6/2018  " << endl;
        cout << endl;
        cout << "*****************************************************************************************************************" << endl;
        break;
    default :
        cout << "Invalid Input" << endl;
    }
    system("PAUSE");
    }
}

