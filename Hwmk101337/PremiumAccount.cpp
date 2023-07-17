//
// Created by 12102 on 4/28/2023.
//


#include "PremiumAccount.h"
#include <iostream>

const double PremiumAccount::MIN_BALANCE = 1000;//min fot premium acc
//Implement a PremiumAccount class that is derived from the Account class.
//In addition to the inherited members, it has the following private member variables:
//• MIN_BALANCE of type static double, initialized to 1000. The customer of a premium account is required to maintain a balance of at least MIN_BALANCE galactic units.
//
PremiumAccount::PremiumAccount(string name, double amount, Date date_) : Account(name, amount, date_)
{

}
//and the following public member functions:
//• withdraw(amount, date): overrides the withdraw() of Account. The function should first check if the existing balance is greater or equal
// to the withdrawal amount + MIN_BALANCE. If so, withdrawal is processed and the function returns true.
// Otherwise the withdrawal is not made and the function returns false. If the withdrawal is made, the withdrawal amount is deducted from balance.
// The date_ is only a place holder for the extra credit version and not used in the basic version.
// then prints accountNumber, ownerName, balance. To print the accountNumber, ownerName, balance, call the print function of Account with this statement: this->Account::print();
//• PremiumAccount(name, amount) is the constructor which passes the arguments to the Account constructor

bool PremiumAccount::withdraw(double amount, Date date_)
{
   date_.getYear();
   if (balance >= (amount + 1000))
   {
      balance -= amount;
      return true;
   }//closes if doable
   return false;
}//closes withdraw
//• getMinBalance():A static member function that returns MIN_BALANCE

double PremiumAccount::getMinBalance()
{
   return MIN_BALANCE;
}//closes getMinBalance
//• print(): overrides the print() of Account. This function prints the string “Premium account”


void PremiumAccount::print() const
{
   cout << "Premium account, ";
   this->Account::print();
}//closes Print