#include "MazePath.h"
#include <iostream>
#include <cassert>
using namespace std;

int main ()
{
  //Testing isValid function with valid strings
  cout << "\nRunning tests ... \n";
  MazePath m("NEEESW");
  assert(m.directionsOut() == "ENWWWS" && "NEEESW should give result ENWWWS");
  m = "W";
  assert(m.directionsOut() == "E");

  m = "S";
  assert(m.directionsOut() == "N");

  m = "N";
  assert(m.directionsOut() == "S");

  m = "E";
  assert(m.directionsOut() == "W");

  m = "EEEEEEEE";
  assert(m.directionsOut() == "WWWWWWWW");

  m = "WWWWWWWW";
  assert(m.directionsOut() == "EEEEEEEE");

  m = "NESWNESWNESWNESW";
  assert(m.directionsOut() == "ENWSENWSENWSENWS");

  cout << "\nPassed.\n\n";

}
