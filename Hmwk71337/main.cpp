/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 4/4/2023
Purpose of program: This program manages bank accounts entered by the user using classes, member variables,
member functions, static member variables, dynamic creation of objects, and pointers to objects.

The choices that the users have are:
1.    Create account
2.    Deposit to account
3.    Withdraw from account
4.    Display information for all accounts
5.    Delete owner
6.    Add owner
7.    Delete account
8.    Quit
 */
#include <iostream>
#include <iomanip>
#include<string>
#include <fstream>
#include "Account.h"

using namespace std;

const int MAX_NUM_ACCOUNTS = 4;//Statically define a global array of pointers to Account
// of size MAX_NUM_ACCOUNTS (set MAX_NUM_ACCOUNTS to 4)
Account *accountArray[MAX_NUM_ACCOUNTS];//dynamic array initialization

int main()
{
   // In main, initialize all the elements of the above array with nullptr
   //variable and pointer initialization
   int numberOwners = 0;// holds the number of owners
   int numAccounts = 0;// holds the number of accounts
   int accountNumber = 0;// holds the account number from owners
   int temp = 0;//used for checking withdrawls
   double amount = 0;//amount of money that the user enters
   int answer;//users choice for menu

   for (int i = 0; i < 4; i++)
   {
      accountArray[i] = nullptr;
   }   // closes set elements of account array to a null pointer

   do
   {
      cout << "Menu\n" << "----\n";
      cout << "1->Create account 2->Deposit   3->Withdraw     4->Display \n";
      cout << "5->Delete owner   6->Add owner 7->Delete accnt 8->Quit    " << endl;
      cin >> answer;
      while (answer > 8 || answer < 1)
      {
         cout << "Invalid choice, reenter: \n";
         cin >> answer;
      }//closes while input is invalid

      if (answer == 1)
      {
         if (numAccounts >= MAX_NUM_ACCOUNTS)
         {
            cout << "Max number of accounts reached, cannot add a new account\n";
         } //closes if max num of acc is reached
         else if (numAccounts < MAX_NUM_ACCOUNTS)
         {

            cout << "Enter number of owners: ";
            cin >> numberOwners;
            cout << "Enter amount: ";
            cin >> amount;
            cin.ignore();

            accountArray[numAccounts] = new Account(numberOwners, amount);

            for (int i = 0; i < numberOwners; i++)
            {
               Person tempPerson;
               cout << "Enter owner's name: ";
               getline(cin, tempPerson.name);
               cout << "Enter owner's DOB, month, day then year: ";
               cin >> tempPerson.DOB.month >> tempPerson.DOB.day >> tempPerson.DOB.year;
               cout << "Enter owner's address: ";
               cin.ignore();
               getline(cin, tempPerson.address);
               accountArray[numAccounts]->setOwner(i, tempPerson);
            }//closes populating the account owner array

            cout << "Account #" << accountArray[numAccounts]->getAccountNumber() << " created\n";
            numAccounts++;
         }//closes if num acc is less than the max
      }//closes if user choice is 1
      if (answer == 2)
      {
         cout << "Enter account number: ";
         cin >> accountNumber;
         //input validation
         bool accountFound = false;
         int index = 0;//used to find location of account number
         for (int i = 0; i < numAccounts; i++)
         {
            if (accountNumber == accountArray[i]->getAccountNumber())
            {
               accountFound = true;
               index = i;
               break;
            }//closes if acc found
         }//closes for loop to check acc number
         if (accountFound)
         {
            cout << "Enter amount: ";
            cin >> amount;

            //Checking to see if withdrawal went through
            int temp = 0;
            temp = accountArray[index]->deposit(amount);
            if (temp == 0)
               cout << "New balance is $" << fixed << setprecision(2) << accountArray[index]->getBalance() << endl;
            else
               cout << "Amount cannot be negative, deposit not executed\n";
         } //closes if acc found
         else
            cout << "No such account\n";
      }//closes if user choice is 2
      if (answer == 3)
      {
         cout << "Enter account number: ";
         cin >> accountNumber;

         bool accountFound = false;
         int index = 0;//used to find account number
         for (int i = 0; i < numAccounts; i++)
         {
            if (accountNumber == accountArray[i]->getAccountNumber())
            {
               accountFound = true;
               index = i;
               break;
            }//closes if acc found
         }//closes for loop
         if (accountFound)
         {
            cout << "Enter amount: ";
            cin >> amount;

            //Checking to see if withdrawal went through
            temp = accountArray[index]->withdraw(amount);
            if (temp == 0)
               cout << "New balance is $" << fixed << setprecision(2) << accountArray[index]->getBalance() << endl;
            else if (temp == 1)
               cout << "Insufficient balance, withdrawal not executed\n";
            else
               cout << "Amount cannot be negative, withdrawal not executed\n";
         }//closes if acc found
         else
         {
            cout << "No such account\n";
         }//closes if no acc
      }//closes if user choice is 3
      cout << fixed << setprecision(2);
      if (answer == 4)
      {
         for (int i = 0; i < numAccounts; i++)
         {
            cout << "Account Number: " << accountArray[i]->getAccountNumber();
            cout << "\n--------------\n";
            for (int ii = 0; ii < accountArray[i]->getNumOwners(); ii++)
            {
               cout << "*Name: " << accountArray[i]->getOwner(ii).name;
               cout << ", DOB: " << accountArray[i]->getOwner(ii).DOB.month << '/'
                    << accountArray[i]->getOwner(ii).DOB.day << '/'
                    << accountArray[i]->getOwner(ii).DOB.year << endl;
               cout << "Address: " << accountArray[i]->getOwner(ii).address << endl;
            }//closes printing out info for all accs
            cout << "*Balance: $" << accountArray[i]->getBalance() << " \n";
         }//closes printing out info
      }//closes if user choice is 4
      if (answer == 5)
      {
         exit(0);
         //delete owner
      }//closes if user choice is 5
      if (answer == 6)
      {
         exit(0);

         //add owner
      }//closes if user choice is 6
      if (answer == 7)
      {
         //delete
      }//closes if user choice is 7
      if (answer == 8)
      {
         exit(0);

         //end program
         exit(0);
      }//closes if user choice is 9
   }
   while (answer != 8);
   {
      return 0;
   }//closes while loop if answer isn't 8
}//closes main function


