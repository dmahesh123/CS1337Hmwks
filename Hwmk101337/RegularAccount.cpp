//
// Created by 12102 on 4/28/2023.
//

#include "RegularAccount.h"
#include <iostream>
//Implement a RegularAccount class that is derived from the Account class.
//It has the following public members:
RegularAccount::RegularAccount(string ownerName_, double balance_, Date date_) : Account(ownerName_, balance_, date_)
{

}//clsoes RegularAccount
//• RegularAccount(ownerName_, balance_, date_) is the constructor which passes the arguments to the Account constructor
//• print(): overrides the print() of Account. This function prints the string “Regular account” then prints accountNumber,
// ownerName, balance. To print the accountNumber, ownerName, balance, call the print function of Account with this statement: this->Account::print();

void RegularAccount::print() const
{
   cout << "Regular account, ";
   this->Account::print();
}//closes print