/*
Author: Dharshini Mahesh
Compiler: GNU GCC
Date: 2/23/2023

 Write a program that performs input validation when reading grocery product records from a file.
 Each grocery product record consists of the following 5 items:
- PLU code: Product Look Up Code. Unique for each product, stored as a string.
- Product Name, stored as a string
- Product Sales Type: 0 = per unit, 1 = per pound
- Price per Pound or price per unit,
- Current Inventory Level (pounds or units).

 To contain valid data, the file must have only valid records. A record is valid if
• It has exactly 5 items on the same line
• The first item should be a PLU. It is valid if and only if it contains only letters or digits, and is 4 characters long
• The second item should be product name. It is valid if and only if the first character is a letter
• The third item should be a sales type. It is valid if and only if it is only one character, and the character is a 1 or a 0
• The fourth item should be a unit price. It is valid if and only if it contains only digits and at most one dot. If there is a dot, there are at most two digits after the dot
• The fifth item should be the inventory level. It is valid if and only if it contains only digits
In order to validate the individual items, each line has first to be broken into tokens, where a token is a string that
 corresponds to an item. The tokens are separated by one or more delimiters,
 where a delimiter is a space, a tab, a new line or a carriage return.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

bool isValidPrice(string);//checks to see if price in the file is correct, takes as input the price as a string, returns true if all aspects are true
string tokenize(string &);//returns token if found, based on a delimiter, uses a reference for string

int main()
{
   ifstream inFile;
   string fileName;//users file input name

   string line;//read line by line
   int tokensCount = 1;// tokens to print out each item in file
   bool fileIsValid = true;// used to check if file has invalid/valid entries

   cout << "Enter input file:";
   getline(cin, fileName);
   cout << "\n";

   cout << "Checking " << fileName << endl;
   cout << "---------";
   for (int i = 0; i < fileName.length(); i++)
   {
      cout << '-';
   }//ends for loop for printing right amount of lines under file name
   cout << endl << endl;

   inFile.open(fileName.c_str());
   if (!inFile)
   {
      cout << "Unable to open file";
      return 1;
   }//if check to see if file name is right

   while (getline(inFile, line))
   {
      tokensCount = 1;

      string plu = tokenize(line);// tokenize to read PLU
      string name = tokenize(line);// tokenize to read name
      string salesType = tokenize(line);// tokenize to read sales type
      string price = tokenize(line);// tokenize to read price
      string inventory = tokenize(line);// tokenize to read inventory
      string extra = tokenize(line);// tokenize to read extra lines

      if (fileIsValid != false)
      {
         if (plu.length() != 4 || !isalnum(plu[0]) || !isalnum(plu[1]) || !isalnum(plu[2]) || !isalnum(plu[3]))
         {
            cout << "Token #" << tokensCount++ << " is " << plu << ", " << "PLU is invalid\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if PLU is invalid
         else
         {
            cout << "Token #" << tokensCount++ << " is " << plu << ", " << "PLU is valid" << endl;

         }//closes else if PLU is valid

         if (!isalpha(name[0]))
         {
            cout << "Token #" << tokensCount++ << " is " << name << ", " << "Product name is invalid\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if name is invalid
         else
         {
            cout << "Token #" << tokensCount++ << " is " << name << ", " << "Product name is valid" << endl;

         }//closes if name is valid

         if (salesType != "0" && salesType != "1")
         {
            cout << "Token #" << tokensCount++ << " is " << salesType << ", " << "Sales type is invalid\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if sales type is invalid
         else
         {
            cout << "Token #" << tokensCount++ << " is " << salesType << ", " << "Sales type is valid" << endl;
         }//closes if sales type is valid

         if (!isValidPrice(price))
         {
            cout << "Token #" << tokensCount++ << " is " << price << ", " << "Price is invalid\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if price is invalid
         else
         {
            cout << "Token #" << tokensCount++ << " is " << price << ", " << "Price is valid" << endl;
         }//closes if price is valid

         if (inventory.empty())
         {
            cout << "Inventory is invalid, record has missing items\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if inventory field is invalid
         else
         {
            for (char ch: inventory)
            {
               if (!isdigit(ch))
               {
                  cout << "Token #" << tokensCount++ << " is " << inventory << ", Inventory is invalid" << endl;
                  fileIsValid = false;
                  continue;
               }//closes if inventory is invalid

            }//closes for loop to check characters of inventory
            if (fileIsValid == true)
               cout << "Token #" << tokensCount++ << " is " << inventory << ", " << "Inventory is valid" << endl;
         }//closes if inventory is valid
         if (extra.length() > 0)
         {

            cout << "Token #" << tokensCount++ << " is " << extra << ", " << "Too many items in record\n" << endl;
            fileIsValid = false;
            continue;
         }//closes if there are too many records in the
         cout << "\n";
      }//closes else loop for inventory check
   }//closes while for reading file line by line and incrementing tokens

   if (fileIsValid)
   {
      cout << "######## " << fileName << " has valid content ########" << endl;
   }//closes if content in file is valid
   else
   {
      cout << "######## " << fileName << " has invalid content ########" << endl;

   }//closes else if file has invalid content
   inFile.close();
   return 0;
}//closes main function

//The fourth item should be a unit price.
// It is valid if and only if it contains only digits and at most one dot.
// If there is a dot, there are at most two digits after the dot
// Returns true if the string is a valid price, false otherwise
bool isValidPrice(string price)
{
   bool ifDecimal = false;// check to find decimal
   int whereDecimal = -1;// find the index of where the decimal
   int charCount = price.length();// counts the number of characters in price

   for (int i = 0; i < charCount; i++)
   {
      if (price[i] == '.')
      {
         if (ifDecimal)
         {
            return false;  // more than one decimal found
         }//if returns false when there are more than 1 decimal
         else
         {
            ifDecimal = true;
            whereDecimal = i;
         }//closes if there is a decimal
      }//closes finding decimal if
      else if (!isdigit(price[i]))
      {
         return false;
      }// closes if non-digit character found
   }//closes for loop fir iterating through length of price

   if (ifDecimal)
   {
      if (whereDecimal == 0 || whereDecimal == charCount - 1)
      {
         return false;
      }//closes if decimal at beginning or end of string
      else if (charCount - whereDecimal > 3)
      {
         return false;
      }//closes else if there are more than two digits after decimal
   }// closes if there is a decimal loop

   return true;
}//closes ifValidPrice function

/* Takes as reference parameter a string to be tokenized and returns the first token found
Returns the empty string if no token is found
The function deletes any leading delimiter and the first token found from the original string
Tokenization is based on a delimiter, where a delimiter is the '\t' (tab) , '  ' (space), ‘\n’ (new line) or ‘\r’ (carriage return)  character
Example: if the string s  is "\t abcd\t\t 345\t ^7$ ", the function returns "abcd" as the first token found, and modifies
the string s to become "\t\t 345\t ^7$ "
*/
string tokenize(string &line)
{
   string token = "";//string goes until delimiter is found
   int i = 0;//index to increment for length of line
   while (i < line.length())
   {
      if (line[i] == '\t' || line[i] == ' ' || line[i] == '\n' || line[i] == '\r')
      {
         i++;
      }//closes the increment if a delimiter is detected
      else
      {
         break;
      }//if no delimiter found, break
   }// while the index is less than the length of i, find all delimiters

   while (i < line.length())
   {
      if (line[i] == '\t' || line[i] == ' ' || line[i] == '\n' || line[i] == '\r')
      {
         break;
      }//closes while loop and breaks out of while if there are delimiters
      else
      {
         token += line[i];
         i++;
      }//closes else if there are no delimiters
   }//closes while loop for iterating through length of line

   line.erase(0, i);
   return token;
}//closes tokenize function
