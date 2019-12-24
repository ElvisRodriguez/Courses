#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "ygoWar.h"

/*
//Name: main()
//Paramter(s): None
//Returns: int
//Label   Task                                                                      Goto
//01      (start)                                                                   02
//02      [init monsters[], userDeck[], botDeck[] to monster type array of size 52] 03
//03      [initialize(monsters)]                                                    04
//04      [shuffle(monsters)]                                                       05
//05      [createDecks(userDeck, botDeck, monsters)]                                06
//06      [warYGO(userDeck, botDeck)]                                               07
//07      (exit: 0)
*/
int main() {
  monster monsters[52], userDeck[52], botDeck[52];

  initialize(monsters);
  shuffle(monsters);
  createDecks(userDeck, botDeck, monsters);

  warYGO(userDeck, botDeck);

  return 0;
}
