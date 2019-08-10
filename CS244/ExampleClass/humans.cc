/*
//It's good practice to have the order of your function definitions
//match the order of the function prototypes you created in your header
//(humans.h) file.
*/

#include "humans.h"

/*
//Remember to include the scope resolution operator (::) so that the compiler
//knows that these functions belong to your Human class instead of simply
//being 'loose' functions
*/

Human::Human() {
  age = 70;
  name = "Dennis Ritchie"; //Fun fact, this guy's the creator of C.
}

Human::Human(int newAge) {
  age = newAge;
  name = "default";
}

Human::Human(int newAge, string newName) {
  age = newAge;
  name = newName;
}

void Human::setAge(int newAge) {
  age = newAge;
}

void Human::setName(string newName) {
  name = newName;
}

int Human::getAge() const {
  return age;
}

string Human::getName() const {
  return name;
}

void Human::birthday() {
  cout << "It's " << name << "'s ";
  cout << "birthday!\n";
  age++;
}

void Human::speak() {
  cout << "Hi my name is ";
  cout << name << endl;
  if (name == "Bjarne Stroustrup") {
    cout << "I created C++ back in 1979\n";
  }
}

void Human::jump(int meters) {
  cout << name << " jumped ";
  cout << meters << " meters!\n";
}
