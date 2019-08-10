/*
//Name: Elvis Rodriguez
//Creation: 11/27/2017
//Version: 7.R
//Description: Builds an array of random number between two user-given parameters,
               displays that array, then sorts the same array and displays that.
*/

#ifndef RANDOM_H
#define RANDOM_H

/*
//Name: RandomNumbers()
//Parameter(s): int(data[], size, min, max)
//Returns: bool
//Label   Task                                                      Goto
//01      (start: data[], size, min, max)                           02
//02      [srand((unsigned)time(0))]                                03
//03      [init randNum as int]                                     04
//04      [init i, 0 --> i]                                         05
//05      < i < size >                                              06,09
//06      [rand()%(max-min+1)+min --> randNum]                      07
//07      [randNum --> data[i]]                                     08
//08      [i++]                                                     05
//09      (exit: true)
*/
bool RandomNumbers(int data[], int size, int min, int max){
  srand( (unsigned)time(0) );
  int randNum;
  for (int i = 0; i < size; i++) {
    randNum = rand() % (max - min + 1) + min;
    data[i] = randNum;
  }
  return true;
}

/*
//Name: PrintArray()
//Parameter(s): int(data[], size)
//Returns: None
//Label   Task                                            Goto
//01      (start: data[], size)                           02
//02      /print("[")/                                    03
//03      [init i as int, 0 --> i]                        04
//04      < i < size >                                    05,09
//05      < i == size - 1 >                               06,07
//06      /print(data[i])/                                07
//07      /print(data[i], ", ")/                          08
//08      [i++]                                           04
//09      /print("]")/                                    10
//10      (exit)
*/
void PrintArray(int data[], int size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      cout << data[i];
    } else {
      cout << data[i] << ", ";
    }
  }
  cout << "]";
}

/*
//Name: Sort()
//Parameter(s): int(data[], size)
//Returns: None
//Label   Task                                        Goto
//01      (start: data[], size)                       02
//02      [init temp as int]                          03
//03      [init i as int, 0 --> i]                    04
//04      < i <= size >                               05,13
//05      [init j as int, i+1 --> j]                  06
//06      < j <= size >                               07,12
//07      < data[i] < data[j] >                       08,11
//08      [data[j] --> temp]                          09
//09      [data[i] --> data[j]]                       10
//10      [temp --> data[i]]                          11
//11      [j++]                                       06
//12      [i++]                                       04
//13      (exit)
*/
void Sort(int data[], int size) {
  int temp;
  for(int i = 0; i <= size; i++) {
    for(int j = i + 1; j <= size; j++) {
      if(data[i] < data[j]) {
        temp = data[j];
        data[j] = data[i];
        data[i] = temp;
      }
    }
  }
}


#endif //RANDOM_H
