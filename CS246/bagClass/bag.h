/*
//Name: Elvis Rodriguez
//Date: 3-15-18
*/

#ifndef BAG_H
#define BAG_H

#include <cstdlib> // srand() rand()
#include <ctime> // time()
#include <iostream> // cout
#define NDEBUG
#include <cassert> // assert()
using namespace std;

class Bag {
  private:
    int* data;
    size_t count;
    void shift(size_t);
  public:
    Bag();
    Bag(int);
    size_t size() const;
    void insert(int);
    void removeAtEnd();
    void removeItem(int);
    int occurences(int) const;
    void destroy();
};

#endif //BAG_H
