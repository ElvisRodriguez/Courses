/*
//Name: Elvis Rodriguez
//Creation: 10/17/2017
//Version: 4.R
//Description: Takes an input of 3 bases from the user, then prints out
               a random in each base n notation where n is each user-
               -inputted base.
*/
#ifndef BASENNOTATION_H
#define BASENNOTATION_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
//Name: NumberGenerator()
//Parameter(s): int base, value
//Return: none
//Label   Task                                      Goto
//01      (start: base, value)                      02
//02      < value > 0 >                             03,05
//03      [(value / base) --> value]                04
//04      (exit: self(base, value))                 05
//05      /print(value % base)/                     06
//06      (exit)
*/
void NumberGenerator(int base, int value) {
  if (value > 0)  {
    value = value / base;
    NumberGenerator(base, value);
  }
  cout << (value % base);
}

/*
//Name: BaseConvert()
//Parameter(s): int base, value
//Return: none
//Label       Task                              Goto
//01          (start: base, value)              02
//02          < (base >= 2) and (base <=9)      03,04
//03          [NumberGenerator(base, value)]    04
//04          < base > 9 or base < 2 >          05
//05          /print(" ")/                      06
//06          (exit)
*/
void BaseConvert(int base, int value) {
  if ( (base >= 2) && (base <= 9) ) {
    NumberGenerator(base, value);
  } else {
    cout << "";
  }
}

#endif //BASENNOTATION_H
