/*
//Name: Elvis Rodriguez
//Date: 3-22-18
//Directive: Create a simple set class with included member functions: union,
             intersection, difference, cartesian product
*/
#ifndef SETS_H
#define SETS_H

#include <iostream> // cout
#include <sstream> //stringstream
#include <string> // string
#include <ctime> // time()
#include <cstdlib> // srand() rand()
#define NDEBUG
#include <cassert> // assert()
using namespace std;

class Set {
  private:
    int *dataSet;
    int size;
  public:
    Set(); //initializes dataSet to an array of size 5
           //sets all elements of dataSet to 0
    Set(int); //initializes dataSet to an array of size input
              //converts input below 0 to a positive integer
              //sets all elements of dataSet to 0
    bool isDataASet() const; //returns true if each element of dataSet is
                             //uniquw, false otherwise
    int getSize() const; //returns size
    void insertRandomData(); //sets the elements of dataSet to to random
                             //values
    bool insertData(int*); //sets dataSet to input array if and only if the
                           //the array is a set and returns true if it is
                           //if not, it calls the insertRandomData() method
                           //and returns false
    int getDataByIndex(int) const; //returns the element of dataSet at
                                   //index input
    string getData() const; //returns a formatted string containing the current
                            //elements in dataSet
    bool isInSet(int) const; //checks if input is also an element in dataSet
                             //returns false if it's not
    string dataUnion(Set) const; //returns a formatted string containing the
                                 //the elements of two Set object's dataSets
                                 //that are in their union set
    string dataIntersection(Set) const; //returns a formatted string containing
                                        //the elements of two Set object's
                                        //dataSets that are in the intersection
                                        //set
    string dataDifference(Set) const; //returns a formatted string containing
                                      //the elements of two Set object's
                                      //dataSets that are in the difference set
    string dataCartesianProduct(Set) const; //returns a formatted string
                                            //containing the cartesian product
                                            //of two Set object's dataSets
    void garbageCollection(); //deallocates dataSet
};

#endif //SETS_H
