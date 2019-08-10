#ifndef CRUSH_H
#define CRUSH_H

#include <iostream> // cout cin
#include <cstdlib> // srand() rand()
#include <ctime> // time()
using namespace std;

#define SIZE 9

class crushGame {
  private:
    char * values;
    int vSize;
    char board[SIZE][SIZE];
  public:
    crushGame();
    void printBoard();
    ~crushGame();
};

crushGame::crushGame() {
  vSize = 6;
  values = new char[vSize];
  for (int i = 0, j = 'A'; i < vSize; i++, j++) {
    values[i] = j;
  }
  int x;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      x = rand() % vSize;
      board[i][j] = values[x];
    }
  }
}

void crushGame::printBoard() {
  for (int i = 0; i < SIZE; i++) {
    if (i > 0) {
      cout << endl;
    }
    for (int j = 0; j < SIZE; j++) {
      cout << board[i][j] << " ";
    }
  }
  cout << endl;
}

crushGame::~crushGame() {
  delete[] values;
}

#endif //CRUSH_H
