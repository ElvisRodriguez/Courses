/*
//Name: Elvis Rodriguez
//Date: 3-13-18
*/

#include "bankAccount.h"

int main() {
  string falseAccountNum = "0660244578914423";
  string falsePin = "0123";

  BankAccount test(falseAccountNum, falsePin);
  assert(falseAccountNum == test.getAccountNumber());

  test.login(falsePin);
  assert(test.getBalance() == 0);

  test.deposit(100);
  assert(test.getBalance() == 100);

  test.withdraw(55.50);
  assert(test.getBalance() == 44.50);

  return 0;
}
