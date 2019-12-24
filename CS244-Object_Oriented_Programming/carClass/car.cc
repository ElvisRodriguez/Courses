/*
//Name: Elvis Rodriguez
//Date: 3-8-18
*/

#include "car.h"

Car::Car() {
  //default member values
  speed = 0;
  index = 0;
  direction = directions[index];
}

Car::Car(double newSpeed, char newDirection) {
  speed = newSpeed;
  for (int i = 0; i < SIZE; i++) {
    if (newDirection == directions[i]) {
      direction = newDirection;
      index = i;
    }
  }
}

double Car::getSpeed() const {
  return speed;
}

char Car::getDirection() const {
  return direction;
}

void Car::changeDirection(char newDirection) {
  //for loop changes direction to newDirection if char argument is in
  //directions array
  for (int i = 0; i < SIZE; i++) {
    if (newDirection == directions[i]) {
      direction = newDirection;
      index = i;
    }
  }
  //if-else chain changes direction to another element of directions array
  //according to 3 arguments; L (turn left), R (turn right), U (make a u-turn)
  //if and only if char argument was not in directions array
  if (newDirection == 'L') {
    if (index - 1 < 0) {
      index += (SIZE - 1);
    } else {
      index -= 1;
    }
  } else if (newDirection == 'R') {
    if (index + 1 == SIZE) {
      index -= SIZE - 1;
    } else {
      index += 1;
    }
  } else if (newDirection == 'U') {
    if (index + 2 > SIZE - 1) {
      index -= 2;
    } else {
      index += 2;
    }
  }
  direction = directions[index];
}

void Car::changeSpeed(double newSpeed) {
  speed = newSpeed;
}

bool Car::isGoingForward() {
  if (speed > 0) {
    return true;
  }
  return false;
}
