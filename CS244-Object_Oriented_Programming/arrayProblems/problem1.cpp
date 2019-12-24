/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Directive: Write a program that calculates the GPA from a list of grades.
             A=4, B=3, C=2, D=1, F=0. Assume that the numeric grades are stored
             in an array of size 10 – representing two semesters and print out the GPA.
*/

#include "problem1.h"

int main() {
  cout << "Problem 1:\n";
  int grades[SIZE];
  generateRandomGrades(grades);
  printAllGrades(grades);
  GPA(grades);

  return 0;
}
