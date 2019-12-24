/*
//Name: Elvis Rodriguez
//Date: 3-20-18
//Description: Testing various function using <assert.h> library.
               Practice with documenting functions with pre/post conditions.
*/

//#define NDEBUG
#include <cassert> // assert()
using namespace std;

#define SIZE 7

bool inArray(int num, int numArray[]) {
  /*
  //precondition: num is any integer, numArray is an array of integers
  //postcondition: returns true if num is an element of numArray, false otherwise
  */
  for (int i = 0; i < SIZE; i++) {
    if (numArray[i] == num) {
      return true;
    }
  }
  return false;
}

int dateCheck(int year, int month, int day) {
  /*
  //precondition: year is a positive integer less than or equal to 2018.
                  month is a positive integer greater than or equal to 1 and
                    less than or equal to 12.
                  day is a positive integer greater than or equal to 1 and less
                    than or equal to 28, 29, 30 or 31 (depending on the month input).
  //postcondition: returns 1 if the date is valid (i.e. passes all assertions)
  */
  int array31months[SIZE] = {1,3,5,7,8,10,12};
  assert(year >= 0 && year <= 2018); //year should be a valid A.D. year that has
                                     //already occured or is occuring
  assert(month >= 1 && month <= 12); //month can't be negative, 0, or greater than 12
  assert(day >= 1); //day can't be negative or 0
  if (month == 2 && year % 4 == 0 && year >= 1752) { //fun fact: Modern Leap years
                                                     //started in 1752 with the
                                                     //adoption of the Gregorian
                                                     //calendar by the British
    assert(day <= 29); //day can be 29 if it is a leap year
  } else if (month == 2) {
    assert(day <= 28); //day can't be larger than 28 if month is 2 (February)
  } else if (inArray(month, array31months)) {
    assert(day <= 31); //day can be up to 31 if month is any of the integers
                       //in the array 'array31months'
  } else {
    assert(day <= 30); //day can be up to 30 if month is any integer not in the
                       //array 'array31months'
  }
  return 1;
}

/*
//Reasonable pre/post conditions for <cmath> sqrt() function:
double sqrt(double x) {
  //precondition: x is a double greater than or equal to 0
  //postcondition: returns the square root of x
//Possible assertions for this function:
  assert(x >= 0) //asserting x is a non-negative number, this assertion
                 //make sure the function doesn't return an imaginary number
}
*/

double feetToMeters(double feet) {
  //precondition: feet is a non-negative double
  //postcondition: returns a double that is meters converted from feet
  assert(feet >= 0); //measurements aren't negative
  return feet * 0.3048;
}
