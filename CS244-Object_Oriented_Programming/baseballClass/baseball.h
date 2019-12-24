/*
//Name: Elvis Rodriguez
//Date: 04/03/18
//Directive: Create a baseball player class; identifying appropriate atrributes
//           and member functions
*/

#ifndef BASEBALL_H
#define BASEBALL_H

#include <iostream> // cout
#include <iomanip> // setprecision(), fixed
#include <string> // string
#include <sstream> // stringstream
#include <cstdlib> // srand(), rand()
#include <ctime> // time()
//#define NDEBUG
#include <cassert> // assert()
using namespace std;

class BaseballPlayer {
  private:
    string name;
    double hits;
    double atBats;
    double outs;
    int strikes;
  public:
    BaseballPlayer(string);
    string getName();
    double getHits();
    double getAtBats();
    double getOuts();
    string getBattingAverage();
    void swing();
    void playBall(int);
};

#endif //BASEBALL_H
