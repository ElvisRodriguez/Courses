#include "clock.h"

Clock::Clock() {
  hour = 12;
  minute = 0;
}

Clock::Clock(int inputHour) {
  assert(inputHour >= 0);
  inputHour %= 24;
  hour = inputHour;
}

Clock::Clock(int inputHour, int inputMinute) {
  assert(inputHour >= 0 && inputMinute >= 0);
  inputHour %= 24;
  inputMinute %= 60;
  hour = inputHour;
  minute = inputMinute;
}

void Clock::setHour(int inputHour) {
  assert(inputHour >= 0);
  inputHour %= 24;
  hour = inputHour;
}

void Clock::setMinute(int inputMinute) {
  assert(inputMinute >= 0);
  inputMinute %= 60;
  minute = inputMinute;
}

int Clock::getHour() const {
  return hour;
}

int Clock::getMinute() const {
  return minute;
}

void Clock::currentTime() {
  int currentMinute;
  int currentHour;
  int secondsInADay = 60 * 60 * 24;
  int secondsInAnHour = 60 * 60;
  int totalSeconds = time(0); //total seconds since Jan 1, 1970
  while (totalSeconds > secondsInADay) {
    totalSeconds -= secondsInADay;
  }
  currentHour = totalSeconds / secondsInAnHour;
  while (totalSeconds > secondsInAnHour) {
    totalSeconds -= secondsInAnHour;
  }
  currentHour -= 4; //sets hour to EST time
  currentMinute = totalSeconds / 60;
  cout << "Current Time: " << currentHour;
  cout << ":" << currentMinute << endl;
}
