/*
//Name: Elvis Rodriguez
//Date: 3-13-18
*/
#ifndef HUMANS_H
#define HUMANS_H

/*
//It's good practice when including libraries to add a comment next to
//those inclusions stating what functions you'll be utilizing from them
*/

#include <iostream> //cout
#include <string>

#define NDEBUG //This preprocessor directive tells the compiler to ignore
               //all of our calls to the assert() function

#include <cassert> //assert()
using namespace std;

class Human {
  private:
    int age;
    string name;
  public:
    Human();
    Human(int);
    Human(int, string);
    void setAge(int);
    void setName(string);
    int getAge() const;
    string getName() const;
    void birthday();
    void speak();
    void jump(int);
};

#endif //HUMANS_H
