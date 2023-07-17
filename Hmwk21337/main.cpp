/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 2/15/2023
This is a program that reads grocery product records from a file, then stores the information in parallel arrays:
- PLU code: Product Look Up Code. Unique for each product, stored as a string.
- Product Name, stored as a string
- Product Sales Type: 0 = per unit, 1 = per pound
- Price per Pound or price per unit,
- Current Inventory Level (pounds or units).

The program reads the file to determine the number of records in the file and
dynamically allocates the necessary parallel arrays, with the appropriate size, and populates the arrays with the items from the file.
Then the program should print the inventory as read from the file, and loops over displaying a menu for the user to choose from:
1 – Checkout
2 – Print current inventory
3 – Quit
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>

using namespace std;
int readInventory(string fileName, int records, string *PLU, double *price, string *name, int *salesType, int *inventory);//displays initial amount populated from all arrays
double checkout(int records, string *PLU, double *price, int *inventory);//allows user to purchase items and will update arrays after user
// main will include the pointer arrays that the functions will dynamically allocate
//will also print current inventory for option 2 and will print updated inventory after exiting if user chooses 3
int main()
{
   string file_name;//variable to hold name of file
   string line;//used to read through files
   int records = 0;//counts the number of lines in a file
   string name, plu;//variables to hold the plu and name from arrays
   int answer;//users answer for menu

   cout << "Enter the file name: ";
   cin >> file_name;

   ifstream inputFile;
   inputFile.open(file_name);

   while (getline(inputFile, line))
   {
      records++;
   }//closes getline While

   inputFile.close();
   inputFile.open(file_name);


   string *arrplu = new string[records];//declaring the creation of pointer arrays
   string *arrName = new string[records];
   int *arrSalesType = new int[records];
   double *arrPrice = new double[records];
   int *arrInventory = new int[records];
   if (inputFile)
   {
      cout << "There are " << records << " records in the file\n" << endl;
      cout << "Inventory read from file\n" << "------------------------\n";

      readInventory(file_name, records, arrplu, arrPrice, arrName, arrSalesType, arrInventory);
   }//closes if loop for input file
   else
   {
      cout << "Could not open file" << "\n";
      cout << "Exiting" << "\n";
//         return 0;
   }//closes else if no file
   do
   {
      cout << "1 - Checkout\n";
      cout << "2 - Print current inventory\n";
      cout << "3 - Quit"<<endl;
      cin >> answer;
      while (answer >3 || answer < 1)
      {
         cout << "Invalid choice, reenter: \n";
         cin >> answer;
      }
      if (answer == 1)
      {
         checkout(records, arrplu, arrPrice, arrInventory);

      }
      else if (answer == 2)
      {
         cout << "Current inventory\n";
         cout << "-----------------\n" << endl;
         for (int i = 0; i < records; i++)
         {

            int firstTrailingZero;
            string currentPrice = to_string(arrPrice[i]);
            for (int j = currentPrice.length() - 1; j >= 0; j--)
            {
               if (currentPrice[j] == '0')
               {
                  continue;
               }//check to see if at index current price is 0
               else
               {
                  firstTrailingZero = j + 1;
                  //currentPrice[firstTrailingZero];
                  break;
               }//closes first trailing zero else
            }// closes for loop for finding trailing 0
            if ((arrplu[i].compare(("")) != 0))
            {
               cout << fixed << left;
               cout << setw(5) << "PLU: " << arrplu[i] << ", " << setw(17) << arrName[i] << ", " << setw(6) << "type: "
                    << arrSalesType[i] << ", " <<
                    setw(11) << "unit price:" << fixed << right << setw(6) << currentPrice.substr(0, firstTrailingZero)
                    << ", " << fixed << left << setw(11) << "inventory: " << arrInventory[i] << endl;
            }//closes for loop
         } //closes if loop for input file

      }//closes if user enters 2 for menu

      else
      {
         cout << "Exiting\n";
         inputFile.close();
         return 0;
      }//closes if any other answer entered by user

   } //closes do loop for menu
   while (answer != 3);
   {
      inputFile.close();
      delete[] arrplu;//release dynamic memory
      delete[] arrInventory;//release dynamic memory
      delete[] arrPrice;//release dynamic memory
      delete[] arrName;//release dynamic memory
      delete[] arrSalesType;//release dynamic memory


      return 0;
   }//closes do while loop

}//closes main function
/*This function reads from a file and populates parallel arrays. It takes as arguments the file name,
* and the pointers to the parallel arrays, as well as the number of records. It returns true if file open is successful,
* false otherwise.
* The parameters are:
• File name, string
• Number of records, int
• Pointer to PLU array, string
• Pointer to price array, double
• Pointer to product name array, string
• Pointer to product sales type array, int
• Pointer to inventory array, int
*/

int readInventory(string fileName, int records, string *PLU, string *name, int *type, double *price, int *inventory)
{
   ifstream inputFile;
   inputFile.open(fileName);
   int firstTrailingZero;//variable to check for trailing 0
   if (inputFile)
   {
      for (int i = 0; i < records; i++)
      {
         inputFile >> PLU[i];//read in PLU from array
         inputFile >> name[i];//read in name from array
         inputFile >> type[i];//read in sales type from array
         inputFile >> price[i];//read in price from array
         inputFile >> inventory[i];//read in inventory from array

            cout << fixed << left;
            cout << setw(5) << "PLU: " << PLU[i] << ", " << setw(17) << name[i] << ", " << setw(6) << "type: "
                 << type[i] << ", " <<
                 setw(11) << "unit price:" << fixed << right << setw(6) << price[i]
                 << ", " << fixed << left << setw(11) << "inventory: " << inventory[i] << endl;
         }//closes if line has null plu
      } //closes for loop for reading in array
   //closes if input file is open
   else
   {
      cout << "Could not open file" << "\n";
      cout << "Exiting" << "\n";
      return 0;
   }//closes else if no file
}//closes read inventory function

/*This function does the checkout. It takes as arguments the pointers to the parallel arrays,
* and the number of records in the inventory. It reads the PLU and numQuantity from the user,
* updates the data in the arrays to reflect the user's purchase, does input validation on the purchased numQuantity (> 0),
* asks the user to reenter as long as the numQuantity is <= 0. It prompts the user for more purchases.
* The user types a PLU of zero when done. The function returns the total purchase price.
* The parameters are:
• Number of records, int
• Pointer to PLU array, string
• Pointer to price array, double
• Pointer to inventory array, int
*/


double checkout(int records, string *PLU, double *price, int *inventory)
{
   double totalPrice = 0;// variable to hold price for user checkout
   string inputPlu = " ";//variable to hold the PLU the user wants for checkout
   int quantity;//number of items the user wants to purchase

   cout << "Enter PLU, 0 if done: ";
   cin >> inputPlu;
   while (inputPlu != "0")
   {

      bool found = false;
      int startIndex = -1;
      cout << "Enter quantity: ";
      cin >> quantity;

      if (quantity <= 0)
      {
         while (quantity <= 0)
         {
            cout << "Quantity must be positive, reenter: ";
            cin >> quantity;
         }//closes while loop to check if user inputs invalid number
         cout<<endl;

      }//closes if loop for input validation

      for (int i = 0; i < records; i++)
      {
         if (inputPlu == PLU[i])
         {
            startIndex = i;
            found = true;
         }//if check for new array to be equal to pointer
      }//closes for loop for check array
      if (found == false)
      {
         cout << "PLU not found\n" << endl;
      }//bool if plu entered by user does not exist
      else
      {
         if (quantity > inventory[startIndex])
         {
            quantity = inventory[startIndex];

         }//closes if for quantity and inventory array
         totalPrice += quantity * price[startIndex];
         inventory[startIndex] -= quantity;
      }//closes else if bool is true
      cout << "Enter PLU, 0 if done: ";
      cin >> inputPlu;
   }//closes top while loop
   cout << "Total is: $" << setprecision(1) << totalPrice << endl;
   return totalPrice;
}//closes checkout function
