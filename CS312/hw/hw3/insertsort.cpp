#include <iostream>
#include <cassert>

using namespace std;
void insert(int A[], int i, int key) {
    while (i >= 0 && A[i] > key){
        A[i + 1] = A[i];
        i = i - 1;
    }
    A[i + 1] = key;
}

void insertionSort(int A[], size_t N) {
  int key, i;
  for(int j = 1; j < N; j++) {
    key = A[j];
    i = j - 1;
    insert(A, i, key);
  }
}

bool isSorted(int A[], size_t N){
  for (int i = 0; i < N - 1; i++) {
    if (!(A[i] <= A[i+1])) {
      return false;
    }
  }
  return true;
 }

void printArray(int A[], size_t N){
  cout << '{';
  for (int i = 0; i < N; i++) {
    cout << A[i] << ' ';
  }
  cout << '}' << endl;
}

int main () {
  int A[] = {22, 11, 99, 88, 9, 7, 42};
  printArray(A, 7);

  assert(!isSorted(A, 7));

  //Calls to insert function go here (to sort the array manually)
  insert(A, 0, 11);
  insert(A, 1, 99);
  insert(A, 2, 88);
  insert(A, 3, 9);
  insert(A, 4, 7);
  insert(A, 5, 42);

  assert(isSorted(A, 7));
  cout << "Array after sorting:  " << endl;
  printArray(A, 7);

  int B[] = {222, 111, 999, 888, 99, 77, 422};
  insertionSort(B, 7);
  assert(isSorted(B, 7));
  cout << "Array after sorting:  " << endl;
  printArray(B, 7);

  int arrayRodriguez[] = {25, 3, 74, 100, 21, 212, 50, 34, 24, 1};
  insertionSort(arrayRodriguez, 10);
  assert(isSorted(arrayRodriguez, 10));
  cout << "Array after sorting:  " << endl;
  printArray(arrayRodriguez, 10);
}
