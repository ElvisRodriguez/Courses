/*
//Name: Elvis Rodriguez
//Creation: 10/17/2017
//Version: 4.R
//Description: Takes an input of 3 bases from the user, then prints out
               a random in each base n notation where n is each user-
               -inputted base.
*/
#include "baseNNotation.h"

/*
//Name: main()
//Parameter(s): none
//Return: int
//Label     Task                                                            Goto
//01        (start)                                                         02
//02        [int base1, base2, base3]                                       03
//03        [srand( (unsigned)time(0) )]                                    04
//04        [(rand() % 99 + 1) --> int randomNum1]                          05
//05        [(rand() % 99 + 1) --> int randomNum2]                          06
//06        /print("Enter three bases: ")/                                  07
//07        /input --> base1, base2, base3/                                 08
//08        /print("\n")/                                                   09
//09        /print(randomNum1, " in base ", base1, " is ")/                 10
//10        [NumberGenerator(base1, randomNum1)]                            11
//11        /print("\n")/                                                   12
//12        /print(randomNum1, " in base ", base2, " is ")/                 13
//13        [NumberGenerator(base2, randomNum1)]                            14
//14        /print("\n")/                                                   15
//15        /print(randomNum1, " in base ", base3, " is ")/                 16
//16        [NumberGenerator(base3, randomNum1)]                            17
//17        /print("\n\n")/                                                 18
//18        /print(randomNum2, " in base ", base1, " is ")/                 19
//19        [BaseConvert(base1, randomNum2)]                                20
//20        /print("\n")/                                                   21
//21        /print(randomNum2, " in base ", base2, " is ")/                 22
//22        [BaseConvert(base2, randomNum2)]                                23
//23        /print("\n")/                                                   24
//24        /print(randomNum2, " in base ", base3, " is ")/                 25
//25        [BaseConvert(base3, randomNum2)]                                26
//26        /print("\n")/                                                   27
//27        (exit)
*/
int main() {
  int base1, base2, base3;

  srand( (unsigned)time(0) );

  nint randomNum1 = (rand() % 99 + 1);
  int randomNum2 = (rand() % 99 + 1);

  cout << "Enter three bases: ";
  cin >> base1 >> base2 >> base3;
  cout << endl;

  cout << randomNum1 << " in base " << base1 << " is ";
  NumberGenerator(base1, randomNum1);
  cout << endl;
  cout << randomNum1 << " in base " << base2 << " is ";
  NumberGenerator(base2, randomNum1);
  cout << endl;
  cout << randomNum1 << " in base " << base3 << " is ";
  NumberGenerator(base3, randomNum1);
  cout << endl << endl;

  cout << randomNum2 << " in base " << base1 << " is ";
  BaseConvert(base1, randomNum2);
  cout << endl;
  cout << randomNum2 << " in base " << base2 << " is ";
  BaseConvert(base2, randomNum2);
  cout << endl;
  cout << randomNum2 << " in base " << base3 << " is ";
  BaseConvert(base3, randomNum2);
  cout << endl;

  return 0;
}
