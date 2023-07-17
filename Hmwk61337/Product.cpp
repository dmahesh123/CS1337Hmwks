#include <iostream>
#include "Product.h"
// contains the function description of all the member functions
// includes public member functions

using namespace std;
// setProductAttributes: mutator to set the PLU, name, type, price and inventory of a Product. The arguments should be in that order
void Product::setProductAttributes(string PLU2, string Name2, int Type2, double Price2, int Inventory2)
{
   //use as temporary/copy variables
   PLU = PLU2;
   name = Name2;
   type = Type2;
   price = Price2;
   inventory = Inventory2;
}//closes setProductAttributes
// getPLU: accessor to get the PLU
string Product::getPLU() const
{
   return PLU;
}//closes getPLU
// getName: accessor to get the name
string Product::getName() const
{
   return name;
}//closes getName
// getType: accessor to get the type

int Product::getType() const
{
   return type;
}//closes getType
//• getPrice: accessor to get the price
double Product::getPrice() const
{
   return price;
}//closes getPrice
//getInventory: accessor to get the inventory
int Product::getInventory() const
{
   return inventory;
}//closes getInventory
//setInventory: mutator to set the inventory
void Product::setInventory(int tempInventory)
{
   inventory = tempInventory;
}//closes setInventory
