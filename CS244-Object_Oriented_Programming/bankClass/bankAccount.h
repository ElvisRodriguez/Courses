/*
//Name: Elvis Rodriguez
//Date: 3-13-18
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#define NDEBUG
#include <cassert>
using namespace std;

class BankAccount {
  private:
    string accountNumber;
    string pin;
    float balance;
    bool isLoggedIn;
  public:
    BankAccount();
    BankAccount(string, string);
    void login(string);
    void deposit(float);
    void withdraw(float);
    string getAccountNumber() const;
    float getBalance() const;
};

#endif //BANKACCOUNT_H
