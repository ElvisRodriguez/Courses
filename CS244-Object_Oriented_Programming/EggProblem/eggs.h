/*
Follow the instructions below carefully and DO NOT change any code that you
are not asked to change.
*/

#ifndef EGGS_H
#define EGGS_H

#define HEIGHT 100

class Egg {
  private:
    bool broken;
  public:
    Egg();
    bool isBroken(int);
    int break_point;
};

/*
In the body of this function, set the variable 'broken' to false.
*/
Egg::Egg() {
  //Write code here
}

/*
In the body of this function, set the variable 'broken' to true if the variable
'floor_level' is greater than or equal to the variable break_point and return
true. Otherwise, return false.
*/
bool Egg::isBroken(int floor_level) {
  //write code here
}

#endif
