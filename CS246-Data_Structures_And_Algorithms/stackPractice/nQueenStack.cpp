//Name: Elvis Rodriguez
//Question 3: Implement the N-Queens Problem using a stack

#include <iostream>
#include <stack>
using namespace std;

#define N 8

bool isSafe(int board[N][N], int, int);
bool solveNQueens(int board[N][N]);
void printResult(int board[N][N]);

int main() {
  int board[N][N] = {0};
  if (solveNQueens(board)) {
    printResult(board);
  } else {
    printResult(board);
    cout << "Incomplete board\n";
  }
  return 0;
}

bool isSafe(int board[N][N], int row, int col) {
  for (int i = 0; i < N; i++) {
    if (board[row][i] || board[i][col]) {
      return false;
    }
  }
  for (int i = 0; (row - i) >= 0 && (col-i) >= 0; i++) {
    if (board[row-i][col-i]) {
      return false;
    }
  }
  for (int i = 0; (row + i) < N && (col+i) < N; i++) {
    if (board[row+i][col+i]) {
      return false;
    }
  }
  for (int i = 0; (row - i) >= 0 && (col+i) < N; i++) {
    if (board[row-i][col+i]) {
      return false;
    }
  }
  for (int i = 0; (row + i) < N && (col-i) >= 0; i++) {
    if (board[row+i][col-i]) {
      return false;
    }
  }
  return true;
}

bool solveNQueens(int board[N][N]) {
  int filled = 0;
  stack<int> row;
  stack<int> col;
  row.push(0);
  col.push(0);
  while (filled < N) {
    if (isSafe(board, row.top(), col.top())) {
      board[row.top()][col.top()] = 1;
      filled++;
      row.push(row.top() + 1);
      col.push(0);
    } else {
      col.top()++;
    }
    if (col.top() > N - 1) {
      row.pop();
      col.pop();
      board[row.top()][col.top()] = 0;
      col.top()++;
      filled--;
      if (row.empty() || col.empty()) {
        return false;
      }
    }
  }
  return true;
}

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
