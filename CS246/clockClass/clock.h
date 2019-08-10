/*
//Name: Elvis Rodriguez
//Date: 3-21-18
//Description: A clock class that can show inputted hour and minute, as well as
               real time using the <ctime> library
*/

#include <iostream> //cout
#include <ctime> //time()
#define NDEBUG //turned on as debugging tests were successful
#include <cassert> //assert()
using namespace std;

class Clock {
  private:
    int hour;
    int minute;
  public:
    Clock(); //sets hour to 12 and minute to 0 (noon)
    Clock(int); //sets hour to input and minute to 0 if input >= 0
    Clock(int, int); //sets hour to first input and minute to second input
                     //so long as both inputs >= 0
    void setHour(int); //sets hour to input if input >= 0
    void setMinute(int); //sets minute to input if input >= 0
    int getHour() const; //returns hour
    int getMinute() const; //returns minute
    void currentTime(); //displays current time in HH:MM format
};
