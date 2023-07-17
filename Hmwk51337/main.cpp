#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

struct Person
{
    string name;
    string address;
};

struct Account
{
    int accountNumber;
    Person ownerInfo;
    double balance;
};

// Function prototypes
void populateAccount(Account* accounts, int& numPopulated, int maxSize);
void printAccount(const Account& account);

int main()
{
   string userInput;
   int choice;
   int attempts = 1;
   int maxAccounts;
   int userNumber;

   cout << "Enter max number of accounts: ";
   while (attempts <= maxAccounts) {

      getline(cin, userInput);

      // Check if input is a number
      bool isNumber = true;
      for (char c : userInput) {
         if (!isdigit(c)) {
            isNumber = false;
            break;
         }
      }
      if (attempts == 5) {
         cout << "Too many unsuccessful attempts, exiting";
         return 0;
      }

      if (isNumber) {
         userNumber = stoi(userInput);
         if (userNumber > 0) {
            Account *accounts = new Account[maxAccounts];

            do
            {
               cout<<endl;
               cout << "Menu:\n";
               cout << "1->Enter data for specific account, 2->Display data for specific account\n";
               cout << "3->Display data for all accounts  , 4->Quit:\n";
               cin >> choice;

               if (choice == 1)
               {
                  cout << "answer is 1";

               }

               else {
                  attempts++;
                  while (choice != 1)
                  {
                     cout<<"Invalid choice, please reenter: ";
                     getline(cin, userInput);

                  }


               }

            } while (true);

            {
               return 0;
            }
         }
      }
      attempts++;
      cout << "Invalid value, please reenter: ";//<< endl;

   }

   return 0;
}

// Populates the accounts array with a new account
void populateAccount(Account accounts[], int& numAccounts, int maxAccounts) {
   string accountNum, balance;
   int attempts;

   // If there is no spot left for a new account, exit the function
   if (numAccounts >= maxAccounts) { // if there is no spot left for new account
      cout << "Cannot execute, array is full"<< endl;
      return;
   }

   // Prompt the user to enter an account number and validate it
   cout << "Enter account number: ";
   getline(cin, accountNum);
   attempts = 4;
   while (isValidAccountNum(accountNum) == false && attempts > 0) {
      cout << "Invalid value, please reenter: ";
      getline(cin, accountNum);
      attempts--;
   }
   if (isValidAccountNum(accountNum) == false) {
      cout << "Too many unsuccessful attempts, exiting";
      exit(EXIT_FAILURE);
   }
   // Check if there is an existed account number
   for (int i = 0; i < numAccounts; i++) {
      if (stoi(accountNum) == accounts[i].accountNumber) {
         cout << "Duplicate account number";
         exit(EXIT_FAILURE);
      }
   }

   cout << "Enter balance: ";
   getline(cin, balance);
   attempts = 4;
   while (isValidBalance(balance) == false && attempts > 0) {
      cout << "Invalid value, please reenter: ";
      getline(cin, balance);
      attempts--;
   }
   if (isValidBalance(balance) == false) {
      cout << "Too many unsuccessful attempts, exiting";
      exit(EXIT_FAILURE);
   }

   cout << "Enter owner's name: ";
   getline(cin, accounts[numAccounts].ownerInfo.name);

   cout << "Enter owner's address: ";
   getline(cin, accounts[numAccounts].ownerInfo.address);

   accounts[numAccounts].accountNumber = stoi(accountNum);
   accounts[numAccounts].balance = stod(balance);




   void printAccount(const Account& account) {
   cout << "Account #: " << account.accountNumber << endl;
   cout << "Owner's name: " << account.ownerInfo.name << endl;
   cout << "Owner's address: " << account.ownerInfo.address << endl;
   cout << "Balance: " << account.balance << endl;
}