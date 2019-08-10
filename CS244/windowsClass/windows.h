/*
//Name: Elvis Rodriguez
//Date: 04/04/18
//Directive: Design a "Windows" class. Using Microsoft Windows, MAC windows or
             Linux windows. Look at the different types of windows that are
             displayed, e.g. main, menu, etc. Create a class (in C++) with the
             common attributes and functions of the windows that are displayed
             (.e.g. they can be moved, open or minimized, etc.).
*/

#ifndef WINDOWS_H
#define WINDOWS_H

#include <iostream> // cout
#include <string> // string
#include <sstream> // stringstream
using namespace std;

#define DEFAULT 15

class Windows {
  private:
    int currentSize;
    string drawHorizontal(int, int);
    string drawVertical(int, int);
  public:
    Windows();
    void open(int);
    void minimize();
    void maximize();
    void restore();
    void move(unsigned int);
};

#endif //WINDOWS_H
