//
// Created by 12102 on 4/3/2023.
//
#include <iostream>

using namespace std;

#include "Account.h"

int Account::accountCounter = 1000;
//public member functions:
// constructor which sets the accountNumber using the value of accountCounter, sets numOwners, dynamically creates an array
// of Person of the right size, and sets balance to amount. The function then increments accountCounter
Account::Account(int numberOwners, double amount)
{
   accountNumber = accountCounter;//assigns accountCounter to accountNumber
   numOwners = numberOwners;//assign numberOwners to numOwners
   ownerPtr = new Person[numberOwners];//allocates for ownerPtr
   balance = amount;//assigns balance to amount
   accountCounter++;//increments the accounts
}//closes Account
/*
 *  function to withdraw a specified amount from the account.
 *  The function should first check if the amount is > 0 and if there is
 *  sufficient balance in the account (greater or equal to the withdrawal amount).
 *  If so, withdrawal is processed and the function returns 0.
 *  Otherwise the withdrawal is not made and the function returns
 *  1 if the amount > balance, or 2 if the amount is <= 0
 */
int Account::withdraw(double amount)
{
   if (amount <= 0 || amount > balance)
   {
      return amount <= 0 ? 2 : 1;
   }//closes input validation
   balance -= amount;
   return 0;
}//closes withdraw
/*function to deposit a specified amount of money to the account.
 * The function should first check if the deposit amount is > 0.
 * If so, the deposit is processed and the function returns 0.
Otherwise the deposit is not made and the function returns 1.
*/
int Account::deposit(double amount)
{
   if (!(amount > 0))
   {
      return 1;
   }//closes input validation
   balance += amount;
   return 0;
}//closes deposit

//mutator which takes a Person as an argument and adds that Person as an owner of the account.
// A new array of the right size should be dynamically allocated,
// all the owner’s info from the current array should be copied to the new array
// and the current array released. You are not required to check that Person is
// already an owner of the account. The relative order of the owners should be preserved,
// and the newly added owner should be last in the new array.
void Account::addOwner(Person p)
{
   Person *newOwnerPtr = new Person[numOwners + 1];//allocates new pointer
   for (int i = 0; i < numOwners; i++)
   {
      newOwnerPtr[i] = ownerPtr[i];
   }//closes populating newOwnerPtr
   newOwnerPtr[numOwners] = p;

   delete[] ownerPtr;
   ownerPtr = newOwnerPtr;
   numOwners++;
}//closes addOwner

//A mutator function that assigns Person p to the co-owner at index ind of the ownerPtr array
void Account::setOwner(int ind, Person p)
{
   ownerPtr[ind] = p;
}//closes setOwner
// An accessor that returns the owner at index ind of the ownerPtr array. Return type is Person
Person Account::getOwner(int ind) const
{
   return ownerPtr[ind];
}//closes getOwner
// An accessor function that returns the account number.
int Account::getAccountNumber() const
{
   return accountNumber;
}//closes getAccountNumber
// An accessor function that returns the account balance.
double Account::getBalance() const
{
   return balance;
}//closes getBalance
//An accessor function that returns numOwners.
int Account::getNumOwners() const
{
   return numOwners;
}//closes getNumOwners
/*destructor which releases the array of Person dynamically created in the constructor
• withdraw(double amount) function to withdraw a specified amount from the account.
 The function should first check if the amount is > 0 and if there is sufficient balance in the account
 (greater or equal to the withdrawal amount). If so, withdrawal is processed and the function returns 0.
 Otherwise the withdrawal is not made and the function returns 1 if the amount > balance, or 2 if the amount is <= 0
 */
Account::~Account()
{
   delete[] ownerPtr;
}//closes ~Account