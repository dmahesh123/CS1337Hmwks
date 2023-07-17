//
// Created by 12102 on 4/23/2023.
//
#include <iostream>
#include<string>

using namespace std;

#include "Date.h"
#include "Account.h"

// Default constructor
Account::Account() {
   accountNumber = 0;
   numOwners = 0;
   ownerPtr = nullptr;
   balance = 0.0;
   numTransactions = 0;
   transacPtr = nullptr;
}

// Sets accountNumber, numOwners, dynamically creates ownerPtr array, and sets balance to zero
void Account::setAccount(int accountNumber_, int numOwners_) {
   accountNumber = accountNumber_;
   numOwners = numOwners_;
   ownerPtr = new Person[numOwners_];
   balance = 0.0;
}

// Assigns Person p to co-owner at index ind of ownerPtr array
void Account::setOwner(int ind, Person p) {
   ownerPtr[ind] = p;
}

// Returns owner at index ind of ownerPtr array
Person Account::getOwner(int ind) const {
   return ownerPtr[ind];
}

// Returns account number
int Account::getAccountNumber() const {
   return accountNumber;
}

// Returns numOwners
int Account::getNumOwners() const {
   return numOwners;
}

// Sets transacPtr to transacPtr_
void Account::setTransacPtr(Transaction * transacPtr_) {
   transacPtr = transacPtr_;
}

// Returns numTransactions
int Account::getNumTransactions() const {
   return numTransactions;
}

// Sets numTransactions to numTransactions_
void Account::setNumTransactions(int numTransactions_) {
   numTransactions = numTransactions_;
}

// Returns Transaction at index ind of transacPtr array
Transaction Account::getTransaction(int ind) const {
   return transacPtr[ind];
}
