#include <iostream>
using namespace std;

#define N 8 //While the N is still 8 here, the value can be changed to any size
            //without causing undesired output

void printResult(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
      if (j % (N - 1) == 0 && j != 0) {
        cout << endl;
      }
    }
  }
}

bool isSafe(int board[N][N], int row, int col) {
  int i, j;
  for (i = 0; i < col; i++) {
    if (board[row][i]) {
      return false;
    }
  }
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  for (i = row, j = col; j >= 0 && i < N; i++, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  return true;
}

bool solveNQueenTile(int board[N][N], int col) {
  if (col >= N) {
    return true;
  }
  for (int i = 0; i < N; i++) {
    if ( isSafe(board, i, col) ) {
      board[i][col] = 1;
        if (solveNQueenTile(board, col + 1) == true) {
          return true;
        }
      board[i][col] = 0;
    }
  }
  return false;
}

bool solveNQueensProblem() {
  int board[N][N] = {0};
  if (solveNQueenTile(board, 0) == false) {
    cout << "Such a solution does not exist" << endl;
    return false;
  }
  printResult(board);
  return true;
}

int main() {
  solveNQueensProblem();

  return 0;
}
