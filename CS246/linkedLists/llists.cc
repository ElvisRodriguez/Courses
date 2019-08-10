#include "llists.h"

List::List() {
  head = NULL;
  tail = NULL;
  count = 0;
}

bool List::isEmpty() const {
  if (head == NULL) {
    return true;
  }
  return false;
}

void List::createNode(int value) {
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  if (isEmpty()) {
    head = temp;
    tail = temp;
    temp = NULL;
  } else {
    tail->next = temp;
    tail = temp;
  }
  count++;
}

int List::size() const {
  return count;
}

void List::insertNode(int position, int value) {
  if (position == 0) {
    node *temp = new node;
    temp->data = value;
    temp->next = head;
    head = temp;
  } else if (position == size()) {
    createNode(value);
  } else {
    node *previous;
    node *current = head;
    node *temp = new node;
    for (int i = 1; i < position; i++) {
      previous = current;
      current = current->next;
    }
    temp->data = value;
    previous->next = temp;
    temp->next = current;
  }
  count++;
}

void List::deleteNode(int position) {
  if (position == 0) {
    node *temp = head;
    head = head->next;
    delete temp;
  } else if (position == size() - 1) {
    node *current = head;
    node *previous;
    while (current->next != NULL) {
      previous = current;
      current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
  } else {
    node *current = head;
    node *previous;
    for (int i = 1; i < position; i++) {
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
  }
  count--;
}

void List::displayList() const {
  node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " --> ";
    temp = temp->next;
  }
  cout << endl;
}

//------------------Question 1 begin------------------//
//Write a function to reverse a linked list in place

void List::reverseList() {
  node *current = head;
  node *previous = NULL;
  node *Next = NULL;
  while (current != NULL) {
    Next = current->next;
    current->next = previous;
    previous = current;
    current = Next;
  }
  head = previous;
}

//------------------Question 1 end--------------------//

//------------------Question 2 begin------------------//
//Consider two linked lists of integers. The lists are not sorted.
//Write a function(s) to output all elements that the two lists have in common

bool contains(List& A, int element) {
  node *temp = A.head;
  while (temp != NULL) {
    if (element == temp->data) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void printSameNumbers(List& A, List& B) {
  node *tempA = A.head;
  List output;
  while (tempA != NULL) {
    if (contains(B, tempA->data)) {
      if (!(contains(output, tempA->data))) {
        output.createNode(tempA->data);
      }
    }
    tempA = tempA->next;
  }
  output.displayList();
}

//------------------Question 2 end--------------------//

//------------------Bonus Question begin--------------//
//Write a function that detects if a list has a loop

bool List::hasLoop() {
  if (head == NULL) {
    return false;
  }
  node *slow = head;
  node *fast = head->next;
  while (true) {
    slow = slow->next;
    fast = fast->next;
    fast = fast->next;
    if (fast->next == NULL) {
      return false;
    } else if (slow == fast) {
      return true;
    }
  }
}

//------------------Bonus Question end----------------//

List::~List() {
  while (count != 0) {
    deleteNode(count);
  }
}
