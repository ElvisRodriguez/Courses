#include "llists.h"

int main() {
  srand(time(0));
  cout << "1. Reverse a Linked List in place:\n";
  List temp;
  for (int i = 0, j = 0; i < 10; i++) {
    j = i;
    j = rand() % 10;
    temp.createNode(j);
  }
  cout << "Original List\n";
  temp.displayList();
  temp.reverseList();
  cout << "Reversed List\n";
  temp.displayList();

  cout << "2. Output all the elements ";
  cout << "that two unsorted linked lists ";
  cout << "have in common\n";

  List temp2;
  for (int i = 0, j = 0; i < 10; i++) {
    j = i;
    j = rand() % 10;
    temp2.createNode(j);
  }
  cout << "First Linked list:\n";
  temp.displayList();
  cout << "Second Linked List:\n";
  temp2.displayList();
  cout << "The elements they have in common:\n";
  printSameNumbers(temp, temp2);
  if (!temp.hasLoop()) {
    cout << "Loop function works\n";
  }

  return 0;
}
