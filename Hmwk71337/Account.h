
// Created by 12102 on 4/3/2023.
//
//#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

#ifndef HMWK71337_ACCOUNT_H
#define HMWK71337_ACCOUNT_H

#endif //HMWK71337_ACCOUNT_H
struct Date
{
    int month;
    int day;
    int year;
};

struct Person // stores account owner’s info
{
    string name;
    Date DOB;
    string address;
};

class Account
{
private:
    int accountNumber = 0;
    int numOwners = 0;
    Person *ownerPtr;
    double balance = 0;
    static int accountCounter;
public:
    Account(int numberOwners, double amount);

    ~Account();

    int withdraw(double amount);

    int deposit(double amount);

    void setOwner(int ind, Person p);

    Person getOwner(int ind) const;

    int getAccountNumber() const;

    double getBalance() const;

    int getNumOwners() const;



    void addOwner(Person);

    int delOwner(Person);
};

