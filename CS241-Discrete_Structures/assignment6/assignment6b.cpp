//Name: Elvis Rodriguez
//Date: 5-15-18
//Assignment 6 programming portion

#include <iostream>
#include <string>
using namespace std;

void Mult2(int* A,int* B,int* R) {
  R[0] = (A[0] * B[0]) + (A[1] * B[2]);
  R[1] = (A[0] * B[1]) + (A[1] * B[3]);
  R[2] = (A[2] * B[0]) + (A[3] * B[2]);
  R[3] = (A[2] * B[1]) + (A[3] * B[3]);
}

void Print(int* A) {
  for (int i = 0; i < 4; i++) {
    if (i == 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << " ";
    }
  }
  cout << endl;
}

int main() {
  int A[4], B[4], C[4];

  cout << "Enter the elements of matrix A\n";
  for (int i = 0; i < 4; i++) {
    cin >> A[i];
  }

  cout << "Enter the elements of matrix B\n";
  for (int i = 0; i < 4; i++) {
    cin >> B[i];
  }

  cout << "The product of\n";
  Print(A);
  cout << "and\n";
  Print(B);
  cout << "is\n";
  Mult2(A,B,C);
  Print(C);

  return 0;
}
