/*
//Name: Elvis Rodriguez
//Creation: 11/28/2017
//Version: 8.R
//Description: Displays all possible three letter arrangements of the letters of
               the alphabet such that order does not matter and arrangements
               cannot have repeating letters with ten (10) arrangements on each
               line separated by spaces.
*/

#ifndef COMBINATION_H
#define COMBINATION_H

/*
//Name: ComboWithout()
//Parameter(s): None
//Returns: None
//Label   Task                                                            Goto
//01      (start)                                                         02
//02      [init count as int, 0 --> count]                                03
//03      ["ABCDEFGHIJKLMNOPQRSTUVWXYZ" --> char(list(alpha))]            04
//04      [init i as int, 0 --> i]                                        05
//05      < i < 24 >                                                      06,15
//06      [init j as int, i+1 --> j]                                      07
//07      < j < 25 >                                                      08,14
//08      [init h as int, j+1 --> h]                                      09
//09      < h < 26 >                                                      10,07
//10      < count%10 == 0 and count != 0 >                                11,12
//11      /print("\n")/                                                   12
//12      /print(alpha[i],alpha[j],alpha[h], " ")/                        13
//13      [count++]                                                       09
//14      [i++]                                                           06
//15      (exit)
*/
void ComboWithout() {
  int count = 0;
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int i = 0;
  while (i < 24) {
    for (int j = i + 1; j < 25; j++) {
      for (int h = j + 1; h < 26; h++) {
        if (count % 10 == 0 && count != 0) {
          cout << endl;
        }
        cout << alpha[i] << alpha[j] << alpha[h] << " ";
        count++;
      }
    }
    i++;
  }
//Professor Reid, you may uncomment the line below to see that there are 2600 permutations.
  //cout << endl << count << "\n";
}

#endif "combination.h"
