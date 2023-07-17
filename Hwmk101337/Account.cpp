//
// Created by 12102 on 4/28/2023.
//
//Account has the following member variables:
//private:
//• accountNumber of type int
//• ownerName of type string
//
//protected:
//• balance of type double
//• numberAccounts of type static int, initialized to zero
//• transactionHistory of type Transaction * // This variable is declared but not used in the basic version
//• numberTransactions of type int )// This variable is declared but not used in the basic version
//
//and the following member functions:
#include "Account.h"

#include <iomanip>
#include <iostream>

using namespace std;

int Account::numberAccounts = 0;//initialize to 0
//• Account(ownerName_, balance_, date_) is the constructor that initializes the account’s member variables ownerName and balance. balance_ is the amount deposited when the account is created. accountNumber is set to (numberAccounts+1000) and numberAccounts is incremented. transactionHistory is set to nullptr, numberTransactions set to zero. The date_ is only a place holder for the extra credit version and not used in the basic version.

Account::Account(string ownerName_, double balance_, Date date_)
{
   date_.getMonth();
   accountNumber = numberAccounts + 1000;
   numberAccounts++;
   ownerName = ownerName_;
   balance = balance_;
   //transactionHistory = nullptr;
   //transactionHistory->date = date_;
}
//public:
//• withdraw(amount, date_) a virtual member function to withdraw a specified amount from the account. The function should first check if there is sufficient balance in the account. If the balance is sufficient, withdrawal is processed and the function returns true. Otherwise the withdrawal is not made and the function returns false. If the withdrawal is made, the withdrawal amount is deducted from balance. The date_ is only a place holder for the extra credit version and not used in the basic version.

bool Account::withdraw(double amount, Date date_)
{
   date_.getMonth();

   if (balance >= amount)
   {
      balance -= amount;
      return true;
   }//closes if doable
   else if (amount<0)
   {
      return false;
   }//closes if cant be done
   return false;
}//closes withdraw
//• deposit(amount, date_) function to deposit a specified amount of money to the account. The function should first check if the deposit amount is positive. If it is positive, deposit is processed and the function returns true. Otherwise the deposit is not made and the function returns false. If the deposit is made, the amount is added to balance. The date_ is only a place holder for the extra credit version and not used in the basic version.

bool Account::deposit(double amount, Date date_)
{
   date_.getMonth();

   if (amount > 0)
   {
      balance += amount;
      return true;
   }//closes if doable
   else
   {
      return false;
   }//closes if cant be done
}//closes deposit
//• getAccountNumber(): An accessor function that returns the account number.

int Account::getAccountNumber() const
{
   return accountNumber;
}//closes getAccountNumber
//• getBalance(): An accessor function that returns the account balance.

double Account::getBalance() const
{
   return balance;
}//closes getBalance
//• getNumberAccounts(): A static member function that returns numberAccounts.

int Account::getNumberAccounts()
{
   return numberAccounts;
}//closes getNumberAccounts
//• print(): a virtual member function that prints accountNumber, ownerName, balance. This function is called in a few instances in main, including when the user chooses “print info for all accounts”.

void Account::print() const
{
   cout << fixed << setprecision(2) << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " << balance
        << " Galactic units\n";
}//closes Print