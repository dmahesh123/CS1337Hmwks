/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 4/25/2023
Purpose of program: This program outputs bank accounts and uses structures, classes, dynamic array creation, use of overloaded operators.
Reads a file and outputs based on the information such as account number, number of owners,owner’s name, owner’s DOB, owner’s address,
owner’s DOB, owner’s address, number of transactions,first transaction record and second transaction record
*/
#include <iostream>
#include <sstream>
#include<string>
#include "Date.h"
#include <fstream>
#include "Account.h" // assuming Account class is defined in a separate header file

using namespace std;

//functions described below main
bool readAccounts(string fname, Account accntPtr[], int numAccounts);

void sortFunction(Transaction *array, int numTransactions);

Date *getDate(string date1);

int getHour(string dateHour);

int getYear(string dateYear);

int getDay(string dateDay);

int getMonth(string date);

// Determine the number of account records in the file
//Dynamically create an array of Account of size equal to the number of accounts, to hold the Account objects (note this is an array of Account, not an array of pointers to Account)
//Call readAccounts to read data from the file and populate the array of Accounts.
//Read the populated array of Accounts to display for each account the account number,
// along with the data for all the owners, and the data for all the transactions.
// The owner data is the owner’s name, DOB and address. The transaction data is the transaction date,
// transaction type (account creation, deposit, withdrawal), and transaction amount. Additionally,
// the new balance resulting from each transaction is displayed. In the extra credit, the transactions
// should be listed by date, the oldest transaction being listed first.

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the month as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int main()
{
   string fileName;// holds the name of the file
   int numAccounts = 0; //holds the number of accounts

   string line;//holds the current line read
   // Prompt the user for a file name
   cout << "Enter the account file name: ";
   cin >> fileName;
   Account *accounts = nullptr;//pointer to an array of Account objects
   // new Account [numAccount];

   // Get number of records in the file
   ifstream inputFile;
   inputFile.open(fileName);
   // if the file cannot be opened, it returns 0
   if (!inputFile)
   {
      return 0;
   } // Closes if loop when is not inputFile
   // Find account number from "#"
   while (getline(inputFile, line))
   {
      if (line == "#")
      {
         numAccounts++;
      }
   } // Closes while loop
   accounts = new Account[numAccounts];
   inputFile.close();

   readAccounts(fileName, accounts, numAccounts);
   cout << "There are " << numAccounts << " accounts in the file" << endl << endl;

   // Print out the account information
   for (int i = 0; i < numAccounts; i++)
   {
      cout << "\nAccount Number: " << accounts[i].getAccountNumber() << endl;
      cout << "===============" << endl;
      for (int ind = 0; ind < accounts[i].getNumOwners(); ind++)
      {
         cout << "Name: " << accounts[i].getOwner(ind).name;
         cout << ", DOB: ";
         // print date
         Date date = accounts[i].getOwner(ind).DOB;
         date.print();

         cout << ", Address: " << accounts[i].getOwner(ind).address << endl << endl;
      }

      double amount = 0;// keeps track of the balance
      // Print transaction history
      cout << "Transaction history:" << endl;
      cout << "--------------------";
      for (int index = 0; index < accounts[i].getNumTransactions(); index++)
      {
         cout << "\nTransaction #" << index + 1;
         cout << endl << "Date: ";
         Transaction createTrans = accounts[i].getTransaction(index);
         createTrans.transactionDate.print();

         cout << ", type: ";
         int type = createTrans.type;

         // Read the choice of type from the user
         if (type == 1)
         {
            amount += createTrans.amount; // created account balance
            cout << "account creation";
         }
         else if (type == 2)
         {
            amount += createTrans.amount; // balance after deposit
            cout << "deposit";
         }
         else
         {
            amount -= createTrans.amount; // balance after withdrawal
            cout << "withdrawal";
         }
         cout << ", amount: " << createTrans.amount << ", new balance: " << amount << endl;
      } // Close for loop for transaction history
   } // Close for loop for account info.
   return 0;
} // Close main function

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the month as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getMonth(string date)
{
   string month = date.substr(0, 2);//extracts the month
   return stoi(month);
}//closes getMonth function
/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the day as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getDay(string dateDay)
{
   string dayString = dateDay.substr(3, 2);//extracts the day
   return stoi(dayString);
}//closes getDay function

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the year as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getYear(string dateYear)
{
   string year = dateYear.substr(6, 4);//extracts the year
   return stoi(year);
}//closes getYear function

/* This function takes as argument a string representing a date
in the mm/dd/yyyy/hh format and returns the hour as an int
The argument string is assumed properly formatted and no input validation
is required
*/
int getHour(string dateHour)
{
   string hours = dateHour.substr(11, 2);//extracts the hour
   return stoi(hours);
}//closes getHour function

//  dynamically allocates a new Date object using the default constructor,
//  and assigns its memory address to the pointer variable dateObject
Date *getDate(string date1)
{
   Date *dateObject = new Date;//Date object, date1
   //extracts the times
   int hour = getHour(date1);
   int day = getDay(date1);
   int month = getMonth(date1);
   int year = getYear(date1);

   dateObject->set(month, day, year, hour);
   return dateObject;
}//closes getDate funtion

/*In the extra credit version, after the array has been populated,
 * this function should sort the transactions array by date (oldest first).
It takes as arguments the file name, the array and the size of the array.*/
void sortFunction(Transaction *array, int numTransactions)
{
   int minIndex; // minIndex starts the sort and keeps track of the index the value is
   for (int start = 0; start < (numTransactions - 1); start++)
   {
      minIndex = start;
      for (int index = start + 1; index < numTransactions; index++)
      {
         if (array[index].transactionDate < array[minIndex].transactionDate)
         {
            minIndex = index;
         }
      }
      Transaction temp = array[minIndex];
      array[minIndex] = array[start];
      array[start] = temp;
   }
}
/* This function reads from an account file and populates an array of Account objects
 * (not an array of pointers to Account) with all the owners and transactions data read from the file.
 * The owner data is the owner’s name, DOB and address. The transaction data is the transaction date,
 * transaction type (account creation, deposit, withdrawal), and transaction amount. For each account,
 * the function should dynamically allocate an array of Transaction of size equal to the number of transactions,
 * assign the array’s address to transacPtr, and populate the array with the transaction data.
It returns true if file open is successful, false otherwise. It should close the file when done
*/
bool readAccounts(string fname, Account accntPtr[], int numAccounts)
{
   string line;//holds text from file
   int accNumber = 0;
   int ownersNum = 0;

   ifstream inputFile;
   inputFile.open(fname.c_str());
   if (!inputFile)
   {
      exit(0);
   } // Closes if loop when is not inputFile

   for (int iAcc = 0; iAcc < numAccounts; iAcc++)  // Loop over the accounts
   {
      getline(inputFile, line);
      getline(inputFile, line);
      int numTransactionsQ = stoi(line);
      accNumber = stoi(line);


      getline(inputFile, line);
      ownersNum = stoi(line);
      Transaction *array1 = new Transaction[numTransactionsQ];//Dynamically allocate w/ pointer for Transaction

      accntPtr[iAcc].setAccount(accNumber, ownersNum);

      for (int ownerIndex = 0; ownerIndex < ownersNum; ownerIndex++) // Loop over the owners for Account at accntIndex
      {
         Person *p = new Person;
         // owner's name
         getline(inputFile, line);
         p->name = line;
         string date1 = "";

         // owner DOB
         getline(inputFile, line);
         Date *DOB = getDate(line);
         p->DOB = *DOB;

         // owner address
         getline(inputFile, line);
         p->address = line;
         accntPtr[iAcc].setOwner(ownerIndex, *p);
      }
      getline(inputFile, line);
      // dynamically allocate an array of Transactions and assign address to transactionPtr
      int numTransactions = atoi(line.c_str()); // stoi and atoi is almost the same, except atoi returns 0
      Transaction *array = new Transaction[stoi(line)];
      accntPtr[iAcc].setNumTransactions(stoi(line));

      for (int transac = 0; transac < numTransactions; transac++)
      {
         getline(inputFile, line);
         std::stringstream ss(line);

         // Extract date, type, and amount using string manipulation functions
         std::string date = line.substr(0, line.find(' '));
         line.erase(0, line.find(' ') + 1);
         int type = stoi(line.substr(0, line.find(' ')));
         line.erase(0, line.find(' ') + 1);
         double amount = stod(line);

         array[transac].amount = amount;
         array[transac].transactionDate.set(getMonth(date), getDay(date), getYear(date), getHour(date));
         array[transac].type = type;
      }
      // Call the function to sort the transaction array by date, oldest date first (extra credit version only)
      sortFunction(array, numTransactions);
      accntPtr[iAcc].setTransacPtr(array);

   } // end of loop over accounts
   return true;
} // Close the function