/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that calculates the GPA from a list of grades.
             A=4, B=3, C=2, D=1, F=0. Assume that the numeric grades are stored
             in an array of size 10 – representing two semesters and print out the GPA.
*/

#include <iostream> //cout
#include <iomanip> //setprecision(), fixed
#include <cstdlib> //srand(), rand()
#include <ctime> //time()
using namespace std;

#define SIZE 10

void generateRandomGrades(int gradeArray[]) {
  srand(time(0));
  int randomNum;
  for (int i = 0; i < SIZE; i++) {
    randomNum = rand() % 5;
    gradeArray[i] = randomNum;
  }
}

void printAllGrades(int gradeArray[]) {
  cout << "[";
  for (int i = 0; i < SIZE; i++) {
    if (i == SIZE - 1) {
      cout << gradeArray[i] << "]\n";
    } else {
        cout << gradeArray[i] << ", ";
    }
  }
}

void GPA(int gradeArray[]) {
  double result = 0;
  for (int i = 0; i < SIZE; i++) {
    result += gradeArray[i];
  }
  result /= SIZE;
  cout << fixed << setprecision(2);
  cout << "GPA: " << result << endl;
}
