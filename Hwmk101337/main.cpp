/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 4/28/2023
Purpose of program: This program outputs bank accounts and uses structures, classes, dynamic array creation,
and inheritance, virtual functions and base class pointers.
Reads user input and outputs based on the information such as account number, date, and amount to keep track of users accounts
Uses input validation to make sure amounts are correct:• Show an error message if the withdrawal amount is excessive (result in negative balance for a regular account or a balance less than MIN_BALANCE for a premium account). No withdrawal should be made in that case.
• Show an error message if any deposit or withdrawal amount is not >0. No transaction should be made in that case. The main function does the checking and prints the error message. This checking is on top of the checking done in the deposit function. In the context of this HW, the amount passed to the deposit function will always be > 0. However, the deposit function should still implement the checking, as the Account class may be used in a different context.
• Show an error message if the user tries to deposit to or withdraw from an account that has not been created
• Do not accept to create an account if the maximum number of accounts (MAX_NUM_ ACCOUNTS) has been reached
• Show an error message if the user attempts to create a regular account with an amount that is not > 0. The account is not created. The checking should be done in the main function.
• Show an error message if the user attempts to create a premium account with an amount less than MIN_BALANCE. The account is not created. The checking should be done in the main function.
*/
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "PremiumAccount.h"
#include "RegularAccount.h"

using namespace std;

//const int MAX_NUM_ACCOUNTS = 5;
//Account * accountArray[MAX_NUM_ ACCOUNTS];
//Loop on displaying the following menu of choices:
//1.    Create regular account (user will be prompted for name, date, amount)
//2.    Create premium account (user will be prompted for name,date, amount)
//3.    Deposit to account (user will be prompted for account number, date, amount)
//4.    Withdraw from account (user will be prompted for account number, date, amount)
//5.    Print info for all accounts
//6.    Quit
int main()
{
   int answer = 0;//user choice
   int numAcc = 0;//number of acc
   int accNum = 0;//account number
   int index = 0;//for linear search index

   double numAmount = 0;//amount to withdraw/deposit
   string name;//name of client
   string date;//date of transaction by client
   //bool check;
   const int MAX_NUM_ACCOUNTS = 5;//max num of acc
   Account *accountArray[MAX_NUM_ACCOUNTS];//dynamically allocate an array of accounts
   Date *tempDate = new Date;//date object
   tempDate->set(0, 0, 0, 0);//initialize

//menu that repeats after account manipulation is done
   while (answer != 6)
   {
      cout << "\n1->Create regular accnt, 2->Create premium accnt, 3->Deposit to accnt\n";
      cout << "4->Withdraw from accnt, 5->Print info accnts, 6->Quit\n";
      cin >> answer;

      switch (answer)
      {
         case 1:
            if (numAcc >= MAX_NUM_ACCOUNTS)
            {
               cout << "Max number of accounts reached, cannot add a new account\n";
            }//closes if the number of accounts is greater than the max number of accs
            else
            {
               cout << "Enter owner's name: ";
               cin >> name;
               cout << "Enter date, in the mm/dd/yyyy/hh format: ";
               cin >> date;
               cout << "Enter amount: ";
               cin >> numAmount;

               if (numAmount <= 0)
               {
                  cout << "Amount cannot be negative, account creation not executed\n";
                  break;
               }//closes if amount is negative
               Date *tempDay = new Date;//pointer to date obj
               tempDay->set(0, 0, 0, 0);//initialize to 0
               RegularAccount *newAcc = new RegularAccount(name, numAmount, *tempDay);//dynamic alloc newAcc
               //constructor take the args above
               accountArray[numAcc] = newAcc;//array of pointers
               numAcc++;
               cout << "Account created: \n";
               newAcc->print();
            }//closes account creation
            //closes case 2
            break;
         case 2:
            if (numAcc >= MAX_NUM_ACCOUNTS)
            {
               cout << "Max number of accounts reached, cannot add a new account\n";
            }//closes if number of accs are more than the max
            else
            {
               cout << "Enter owner's name: ";
               cin >> name;
               cout << "Enter date, in the mm/dd/yyyy/hh format: ";
               cin >> date;
               cout << "Enter amount: ";
               cin >> numAmount;

               if (numAmount <= 0)
               {
                  cout << "Amount cannot be negative, account creation not executed\n";
                  break;
               }//closes if amount is negative
               else if (numAmount < 1000)
               {
                  cout << "Insufficient amount, you need at least 1000.00 Galactic units to open a premium account\n";
                  break;
               }//closes if amt < 1000 for premium acc
               accountArray[numAcc] = new PremiumAccount(name, numAmount, *tempDate);//dynamic alloc for Premium

               cout << "Account created: \n";
               accountArray[numAcc]->print();
               numAcc++;
            }//closes case 2
            break;
         case 3:
            cout << "Enter account number: ";
            cin >> accNum;

            index = -1;  // set index to an invalid value
            for (int i = 0; i < numAcc; i++)
            {
               if (accNum == accountArray[i]->getAccountNumber())
               {
                  index = i;  // update index if account is found
                  break;
               }//closes if acc is found
            }//closes iterating through array to find acc

            if (index == -1)
            {  // account not found
               cout << "No such account\n";
               break;
            }//closes if acc is not found

            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> date;
            cout << "Enter amount: ";
            cin >> numAmount;

            if (accountArray[index]->deposit(numAmount, *tempDate))
            {
               cout << "Deposit executed: \n";
               accountArray[index]->print();
            }//closes if deposit is valid

            else
            {
               cout << "Amount cannot be negative, deposit not executed\n";
            }//closes if deposit is invalid
            //closes case 3
            break;

         case 4:
         {
            cout << "Enter account number: ";
            cin >> accNum;

            bool accountExists = false;//see if acc is found
            int index = 0;//set to 0, increments

            while (index < numAcc && !accountExists)
            {
               if (accNum == accountArray[index]->getAccountNumber())
               {
                  accountExists = true;
               } //closes if acc is found in array
               else
               {
                  index++;
               }//closes going to next index
            }//closes linear search

            if (accountExists)
            {
               cout << "Enter date, in the mm/dd/yyyy/hh format: ";
               cin >> date;
               cout << "Enter amount: ";
               cin >> numAmount;
               if (numAmount<0)
               {
                  cout << "Amount cannot be negative, withdraw not executed\n";
               }//closes if withdraw is invalid

               else if (accountArray[index]->withdraw(numAmount, *tempDate))
               {
                  cout << "Withdraw executed: \n";
                  accountArray[index]->print();
               }//closes if withdraw is valid
               /*
               else if (accountArray[index]->withdraw(5000.2, *tempDate))
               {
                  cout << "Amount cannot be negative, withdraw not executed\n";
                  accountArray[index]->print();
               }//closes if withdarw is valid*/
               else
               {
                  cout << "Insufficient balance, withdrawal not executed\n";
               }//closes if not enough balance
            }//finding acc for deposit/withdraw
            else
            {
               cout << "No such account\n";
            }//closes if no acc is matched
            break;
         }//closes case 4

         case 5:
            //Printing out all account information
            cout << "Accounts\n========\n";
            for (int i = 0; i < numAcc; i++)
            {
               cout << endl;
               accountArray[i]->print();
            }//closes printing accs
            //closes case 5
            break;
      }//closes switch cases
   }//closes while answer is not 6

   delete tempDate;//deallocation using delete
   tempDate = nullptr;//does not point to any valid memory
   exit(0);
}//closes main