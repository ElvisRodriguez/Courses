#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#define SIZE 25

void printArray(char arr[]) {
  cout << "[";
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      cout << arr[i] << "]\n";
    } else {
        cout << arr[i] << ", ";
    }
  }
}

void printIndices() {
  cout << "[";
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      cout << i << "]\n";
    } else if (i >= 9) {
      cout << i << ",";
    } else {
      cout << i << ", ";
    }
  }
}

void candyCrush()
  {
    srand((unsigned)time(0));
    char characters[3] = {'O', 'R', 'Y'};
    char charArray[SIZE];
    int counter = 0, x;
    //Random initialization of character array
    for (int i = 0; i < SIZE; i++)
      {
        x = rand() % 3;
        charArray[i] = characters[x];
      }
    //showing original Array
    printArray(charArray);
    printIndices();
    //reusing x as iterator
    x = 0;
    while (x < SIZE)
      {
        if (charArray[x] == 'O')
          {
            while (charArray[x] == 'O' && x < SIZE)
              {
                counter++;
                x++;
              }
        if (counter >= 3)
          {
            while (counter > 0)
              {
                charArray[x - 1] = 'x';
                counter--;
                x--;
              }
            cout << "Index: = " << x << '\n';
          }
        else
          {
            while (counter > 0)
              {
                counter--;
                x--;
              }
          }
        }
        else if (charArray[x] == 'R')
          {
            while (charArray[x] == 'R' && x < SIZE)
              {
                counter++;
                x++;
              }
            if (counter >= 3)
              {
                while (counter > 0)
                  {
                    charArray[x - 1] = 'x';
                    counter--;
                    x--;
                  }
                cout << "Index: = " << x << '\n';
              }
            else
              {
                while (counter > 0)
                  {
                    counter--;
                    x--;
                  }
              }
          }
          else if (charArray[x] == 'Y')
            {
              while (charArray[x] == 'Y' && x < SIZE)
                {
                  counter++;
                  x++;
                }
              if (counter >= 3)
                {
                  while (counter > 0)
                    {
                      charArray[x - 1] = 'x';
                      counter--;
                      x--;
                    }
                  cout << "Index: = " << x << '\n';
                }
                else
                  {
                    while (counter > 0)
                      {
                        counter--;
                        x--;
                      }
                  }
            }
        x++;
      }
      //printing out newly changed Array
      printArray(charArray);
      printIndices();
    }

int main() {
  candyCrush();
  return 0;
}
