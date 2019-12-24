#include <iostream>
#include <cassert>

using namespace std;
/*
  Merge Procedure
  Assumes that the subarrays A[p..q] and A[q+1..r] are sorted
  It merges them to form a single sorted subarray
  that replaces the current subarray A[p..r]
*/
int merge(int A[], size_t p, size_t q, size_t r) {
  int ordered_pairs=0;
  int n1 = q - p + 1;
  int n2 =  r - q;
  int Left[n1];
  int Right[n2];
  for (int i =0; i<n1; i++){
      Left[i] = A[p + i];
  }
  for (int j=0; j<n2; j++){
      Right[j] = A[q+j+1];
  }
  int i = 0;
  int j = 0;
  int k = p;
  while (i < n1 && j < n2)
  {
    if (Left[i] <= Right[j])
    {
        A[k] = Left[i];
        i++;
        ordered_pairs += n2 - j;
    }
    else
    {
        A[k] = Right[j];
        j++;
    }
    k++;
  }
  while (i < n1)
  {
      A[k] = Left[i];
      i++;
      k++;
  }
  while (j < n2)
  {
      A[k] = Right[j];
      j++;
      k++;
  }
  return ordered_pairs;
}

/*
  Merge Sort Implementation Algorithm
  Sorts the elements in the subarray A[p..r]
*/
int mergeSort(int A[], size_t p, size_t r) {
  if (p<r){
    int ordered_pairs=0;
    int q=(p+r)/2;
    ordered_pairs+= mergeSort(A, p, q);
    ordered_pairs+= mergeSort(A, q+1, r);
    ordered_pairs+= merge(A, p, q, r);
    return ordered_pairs;
  }
  else return 0;
}


int main () {

  int A[] = {22, 11, 99, 88, 9, 7};
  assert(mergeSort(A,0,5)==4);

  int B[] = {14, 15, 20, 16, 10};
  assert(mergeSort(B, 0, 4)==5);

  int C[] = {4, 5, 6, 7, 8};
  assert(mergeSort(C, 0, 4)==10);

  int D[] = {60, 50, 40, 30, 20};
  assert(mergeSort(D, 0, 4)==0);

  int F[] = {20, 60, 50, 40, 30};
  assert(mergeSort(F, 0, 4)==4);

}
