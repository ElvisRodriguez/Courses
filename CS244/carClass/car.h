/*
//Name: Elvis Rodriguez
//Date: 3-8-18
*/

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
//#define NDEBUG
#include <cassert>
using namespace std;

#define SIZE 4

class Car {
  private:
    double speed;
    int index;
    //Used to 'point' at the directions array
    string directions = "NESW";
    //N = North, E = East, S = South, W = West
    char direction;
    //Will be an index of the directions array
  public:
    Car();
    Car(double, char);
    double getSpeed() const;
    char getDirection() const;
    void changeDirection(char);
    void changeSpeed(double);
    bool isGoingForward();
};

#endif //CAR_H
