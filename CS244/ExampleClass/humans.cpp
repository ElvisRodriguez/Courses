/*
//Now that we've created our Human class and defined it's member functions
//It's time to test our code and make sure our functions perform as intended
*/

#include "humans.h"

int main() {
  Human person;
  int testValue; //we'll use this to test our birthday() function
  string creator;

  creator = "Bjarne Stroustrup";

  person.setName(creator);
  person.setAge(66);

  //These asserts make sure our getter functions work correctly
  assert(person.getName() == creator);
  assert(person.getAge() == 66);

  testValue = person.getAge();
  person.birthday();
  assert(person.getAge() == ++testValue); //Remember the prefix operator?
                                          //it increments/decrements a
                                          //value before an operation such as
                                          //comparison (==) is performed

  person.speak(); //If these two member functions are executed,
  person.jump(5); //it means all of our assertion tests passed!

  return 0;
}
