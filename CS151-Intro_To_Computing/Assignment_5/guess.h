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

#ifndef GUESS_H
#define GUESS_H

/*
//Name: GuessNumber()
//Paramter(s): int ( min, max, limit, list(guess_log) )
//Returns: none
//Label   Task                                                              Goto
//01      (start: min,max,limit,guess_log)                                  02
//02      [srand( (unsigned)time(0) )]                                      03
//03      [init randomNum, (rand() % (max + min) --> randomNum]             04
//04      [init guess]                                                      05
//05      [init i, m, n, 0 -- > i, m, n]                                    06
//06      < limit == 0 >                                                    07,10
//07      /print("You don't even want to try?\n")/                          08
//08      /print("Well then, my number was ")/                              09
//09      /print(randomNum, "\n")/                                          50
//10      < limit == 1 >                                                    11,23
//11      /print("Guess my number: ")/                                      12
//12      /input --> guess/                                                 13
//13      [guess --> guesslog[0]]                                           14
//14      < guess == randomNum >                                            15,18
//15      /print("You got it!\n")/                                          16
//16      /print("Your guess was [")/                                       17
//17      /print(guess, "]\n")/                                             50
//18      < guess != randomNum >                                            19,23
//19      /print("You didn't guess my number!\n")/                          20
//20      /print("Your guess was [")/                                       21
//21      /print(guess, "]\n")/                                             22
//22      /print("My number was ", randomNum, "\n")/                        50
//23      < while (i < limit - 1) >                                         24,41
//24      < i == 0 >                                                        25,27
//25      /print("Guess my number: ")/                                      26
//26      /input --> guess/                                                 27
//27      < guess == randomNum >                                            28,36
//28      [guess --> guess_log[i]]                                          29
//29      /print("You got it!\n")/                                          30
//30      /print("Your guesses were [")/                                    31
//31      < while (m < i) >                                                 32,34
//32      /print(guess_log[m], ",")/                                        33
//33      [m++]                                                             31
//34      /print(guess)/                                                    35
//35      /print("]\n")/                                                    41
//36      < guess != randomNum >                                            37,40
//37      [guess --> guess_log[i]]                                          38
//38      /print("Incorrect. Guess Again: ")/                               39
//39      /input --> guess/                                                 40
//40      [i++]                                                             23
//41      < i == limit - 1 >                                                42,50
//42      /print("You didn't guess my number!\n")/                          43
//43      /print("Your guesses were [")/                                    44
//44      < while (n < i) >                                                 45,47
//45      /print(guess_log[n], ",")/                                        46
//46      [n++]                                                             44
//47      /print(guess)/                                                    48
//48      /print("]\n")/                                                    49
//49      /print("My number was ", randomNum, "\n")/                        50
//50      (exit)
*/
void GuessNumber(int min, int max, int limit, int guess_log[]) {
  srand( (unsigned)time(0) );

  int randomNum = (rand() % max + min);
  int guess;
  int i = 0, m = 0, n = 0;

  if (limit == 0) {
    cout << "You don't even want to try?\n";
    cout << "Well then, my number was ";
    cout << randomNum << endl;
    return;
  }

  if (limit == 1) {
    cout << "Guess my number: ";
    cin >> guess;
    guess_log[0] = guess;
    if (guess == randomNum) {
      cout << "You got it!\n";
      cout << "Your guess was [";
      cout << guess << "]\n";
    } else if (guess != randomNum) {
      cout << "You didn't guess my number!\n";
      cout << "Your guess was [";
      cout << guess << "]\n";
      cout << "My number was " << randomNum << endl;
    }
    return;
  }

  while (i < limit - 1)  {
    if (i == 0) {
      cout << "Guess my number: ";
      cin >> guess;
    }

    if (guess == randomNum) {
      guess_log[i] = guess;
      cout << "You got it!\n";
      cout << "Your guesses were [";
        while (m < i) {
          cout << guess_log[m] << ",";
          m++;
        }
      cout << guess;
      cout << "]\n";
      break;
    } else if (guess != randomNum) {
        guess_log[i] = guess;
        cout << "Incorrect. Guess Again: ";
        cin >> guess;
      }
      i++;
    }

    if (i == limit - 1) {
      cout << "You didn't guess my number!\n";
      cout << "Your guesses were [";
        while (n < i) {
          cout << guess_log[n] << ",";
          n++;
        }
      cout << guess;
      cout << "]\n";
      cout << "My number was " << randomNum << endl;
    }
}

#endif //GUESS_H
