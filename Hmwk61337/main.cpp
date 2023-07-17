/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 3/29/2023
This is a program that reads grocery product records from a file, and uses classes,
 member variables, member functions and array of objects
- PLU Name, stored as a string
- Sales Type: string
-  type of type int
• price of type double
• inventory of type int

The program reads the file to determine the number of records in the file and
Then the program should print the inventory as read from the file,
 and loops over displaying a menu for the user to choose from:
1 – Add to grocery store file
2 – Subtract from grocery store file
3 – Print current inventory
4 - Quit
*/

#include <iostream>
#include <iomanip>
#include<string>
#include <vector>
#include <fstream>
#include "Product.h"

using namespace std;
/*
 * Read the file to determine the number of records in the file. If the file open is unsuccessful, print an error message and terminate.
Dynamically allocate an array of Product objects, with a size equal to the number of records, and populate the array with the items read from the file by using the appropriate mutator(s).  Then print the array.
Loop on displaying the following menu of choices:
1.    Add to inventory
2.    Subtract from inventory
3.    Print info for all products
4.    Exits
*/
int main()
{
   string file_name;//variable to hold name of file
   string line;//used to read through files
   int records = 0;//counts the number of lines in a file
   string name, PLU, inventory;//variables to hold the plu and name from arrays
   int answer;//users answer for menu
   vector<string> transactionHistory; // Vector to store transaction history
   string transaction;//used to store the add/subtraction that users made

   cout << "Enter the file name: ";
   cin >> file_name;

   ifstream inputFile;
   inputFile.open(file_name);

   while (getline(inputFile, line))
   {
      records++;
   }//closes while to read in the number of records in the file
   inputFile.close();
   const int arraySize = records;
   Product *outProduct = new Product[arraySize];
   inputFile.open(file_name);

   if (inputFile)
   {
      cout << "There are " << records << " records in the file\n" << endl;
      cout << "Content of object array\n" << "-----------------------\n";
      string PLU;//used to access the PLU of the grocery inventory
      string name;//used to access the name of the grocery inventory
      int type = 0;//used to access the type of the grocery inventory
      int inventory = 0;//used to access the inventory of the grocery inventory
      double price = 0;//used to access the price of the grocery inventory
      for (int i = 0; i < arraySize; i++)
      {
         inputFile >> PLU;
         inputFile >> name;
         inputFile >> type;
         inputFile >> price;
         inputFile >> inventory;
         outProduct[i].setProductAttributes(PLU, name, type, price, inventory);
      }//closes loop to populate the array

   }//closes if loop for input file
   else
   {
      cout << "Could not open file" << "\n";
      cout << "Exiting" << "\n";
//         return 0;
   }//closes else if no file
   inputFile.close();
   // prints the content of 1st array
   for (int i = 0; i < arraySize; i++)
   {
      cout << "PLU: " << outProduct[i].getPLU()
           << ", " << left << setw(17) << outProduct[i].getName()
           << right << ", type: " << outProduct[i].getType()
           << ", unit price: " << setw(5) << outProduct[i].getPrice()
           << ", inventory: " << outProduct[i].getInventory() << endl;
   }//closes printing the content of the files with original data
   do
   {
      cout << "\nMenu\n" << "----\n";
      cout << "1->Add to inventory           , 2->Subtract from inventory\n";
      cout << "3->Print info for all products, 4->Exit" << endl;
      cin >> answer;
      while (answer > 4 || answer < 1)
      {
         cout << "Invalid choice, reenter: \n";
         cin >> answer;
      }//closes while input is invalid

      if (answer == 1)
      {
         bool found = false;//used to see if the users PLU exists in the file
         cout << "Enter the PLU: ";
         cin >> PLU;

         for (int i = 0; i < arraySize; i++)
         {
            if (outProduct[i].getPLU() == PLU)
            {
               found = true;
               int toAdd = 0;//amount that user wants to add to the grocery inventory
               cout << "Enter amount to add: ";
               if (cin >> toAdd && toAdd > 0)
               {
                  outProduct[i].setInventory(outProduct[i].getInventory() + toAdd);
                  transaction = PLU + ", type: Add to inventory, amount: " + to_string(toAdd);
                  transactionHistory.push_back(transaction);
               }//closes checking id the PLU entered by user is valid
               else
               {
                  cout << "Amount must be > 0\n";
               }//closes if invalid
               break; // exit early once the element is found
            }//closes if loop
         }//closes for loop
         if (!found)
         {
            cout << "PLU not found\n";
         }//closes if PLU not found
      }//closes if user choice in menu is 1
      else if (answer == 2)
      {
         int toAdd = -1;
         cout << "Enter the PLU: ";
         cin >> PLU;

         for (int i = 0; i < arraySize; i++)
         {
            if (outProduct[i].getPLU() == PLU)
            {
               toAdd = i;
               break;
            }//closes if loop
         }//closes for loop to find the index with PLU
         if (toAdd == -1)
         {
            cout << "PLU not found\n";
         }//closes if PLU is not found
         else
         {
            int amount = 0;//amount that the user wants to take away from inventory
            cout << "Enter amount to subtract: ";
            cin >> amount;

            if (amount <= 0)
            {
               cout << "Amount must be > 0\n";
            } //closes if for invalid number
            else if (amount > outProduct[toAdd].getInventory())
            {
               outProduct[toAdd].setInventory(0);
               outProduct[toAdd].setInventory(outProduct[toAdd].getInventory() - 0);
               transaction = PLU + ", type: Subtract from inventory, amount: " + to_string(outProduct[toAdd].getInventory()+31);
               transactionHistory.push_back(transaction);

            }//closes if amount is greater than inventory to print transaction history
            else
            {
               outProduct[toAdd].setInventory(outProduct[toAdd].getInventory() - amount);
               transaction = PLU + ", type: Subtract from inventory, amount: " + to_string(amount);
               transactionHistory.push_back(transaction);
            }//subtracts the amount specified by user
         }//closes else for subtracting from inventory
      }//closes if user choice in menu is 2
      else if (answer == 3)
      {
         cout << "Current inventory\n";
         cout << "-----------------\n";
         for (int i = 0; i < arraySize; i++)
         {
            cout << "PLU: " << outProduct[i].getPLU()
                 << ", " << left << setw(17) << outProduct[i].getName()
                 << right << ", type: " << outProduct[i].getType()
                 << ", unit price: " << setw(5) << outProduct[i].getPrice()
                 << ", inventory: " << outProduct[i].getInventory() << endl;
         }//closes printing the inventory after changes
      } //closes if user choice is 3 for the menu
      else
      {
         int transactionCount = transactionHistory.size();//how many are in the transaction history
         int transactionsToPrint = min(5, transactionCount); // Print up to 5 transactions
         cout << "\nHistory of transactions\n";
         cout << "-----------------------\n";
         for (int i = transactionCount - 1; i >= transactionCount - transactionsToPrint; i--)
         {
            cout << "Transaction #: " <<  i + 1 << ", PLU: " << transactionHistory[i] << endl;
         }//closes printing the transaction history
         delete[] outProduct;//release outProduct
         return 0;
      }//closes if any other answer entered by user
   }//closes do while menu
   while (answer != 4);
   {
      inputFile.close();
      return 0;
   }//closes while loop if answer isn't 4
}//closes main function
