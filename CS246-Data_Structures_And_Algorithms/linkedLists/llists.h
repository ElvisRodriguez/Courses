/*
//Name: Elvis Rodriguez
//Date: 3-20-18
//Description: Practice with linked lists
*/

#include <cstdlib> // NULL
#include <iostream> // cout
#include <cstdlib> // srand() rand()
#include <ctime> // time()
using namespace std;

struct node {
  int data;
  node *next;
};

class List {
  private:
    node *head, *tail;
    int count;
  public:
    List();
    bool isEmpty() const;
    void createNode(int);
    int size() const;
    void insertNode(int, int);
    void deleteNode(int);
    void displayList() const;
    void reverseList();
    friend bool contains(List&, int);
    friend void printSameNumbers(List&, List&);
    bool hasLoop();
    ~List();
};
