/*
//Name: Elvis Rodriguez
//Date: 3-13-18
*/

#include "bankAccount.h"

BankAccount::BankAccount() {
  string newAccountNum;
  string newPin;
  cout << "Set Up Account:\n";
  cout << "Account Number: ";
  getline(cin, newAccountNum);
  cout << "Pin: ";
  getline(cin, newPin);
  accountNumber = newAccountNum;
  pin = newPin;
  balance = 0;
  isLoggedIn = false;
}

BankAccount::BankAccount(string newAccountNum, string newPin) {
  accountNumber = newAccountNum;
  pin = newPin;
  balance = 0;
  isLoggedIn = false;
}

void BankAccount::login(string pinAttempt) {
  if (pinAttempt == pin) {
    isLoggedIn = true;
  } else {
    cout << "Incorrect Pin\n";
  }
}

void BankAccount::deposit(float amount) {
  if (isLoggedIn) {
    balance += amount;
  } else {
    cout << "You must login to make a deposit\n";
  }
}

void BankAccount::withdraw(float amount) {
  if (isLoggedIn) {
    if (amount < balance) {
      balance -= amount;
    } else {
      cout << "Withdrawal exceeds balance.\n";
    }
  } else {
    cout << "You must login to make a withdrawal\n";
  }
}

string BankAccount::getAccountNumber() const {
  return accountNumber;
}

float BankAccount::getBalance() const {
  if (isLoggedIn) {
    return balance;
  } else {
    cout << "You must login to see your balance\n";
  }
}
