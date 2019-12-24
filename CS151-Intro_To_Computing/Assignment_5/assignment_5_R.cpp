/*
//Name: Elvis Rodriguez
//Creation: 11/06/2017
//Version: 5.R
//Description: Takes three inputs from the user (minimum value, maximum value,
               and amount of tries), then picks a random number from within the
               range of minimum to maximum, and has the user guess; with the
               user getting x amount of tries where x is the user_inputted
               amount of tries. The users attempts are then shown to the user
               regardless of whether they passed or failed.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "guess.h"

/*
//Name: main()
//Parameter(s): none
//Returns: int
//Label   Task                                                Goto
//01      (start)                                             02
//02      [init int list(guesses[100]), max, min, limit]      03
//03      /print("Enter two numbers: ")/                      04
//04      /input --> min, max/                                05
//05      /print("Enter a limit: ")/                          06
//06      /inout --> limit/                                   07
//07      /print("\n")/                                       08
//08      [GuessNumber(min,max,limit,guesses)]                09
//09      (exit: 0)
*/
int main() {
  int guesses[100], max, min, limit;

  cout << "Enter two numbers: ";
  cin >> min >> max;

  cout << "Enter a limit: ";
  cin >> limit;

  cout << endl;

  GuessNumber(min, max, limit, guesses);

  return 0;
}
