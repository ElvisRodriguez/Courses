#ifndef YGOWAR_H
#define YGOWAR_H

struct monster {
  string name;
  int atk, def;
  char mode = 'A';
};

/*
//Name: initialize()
//Parameter(s): monster monsters[]
//Returns: none
//Label   Task                                                              Goto
//01      (start: monsters)                                                 01
//02      [init dataFile as ifstream]                                       03
//03      [init line as string]                                             04
//04      [init i, count as int 0 --> i, count]                             05
//05      [dataFile.open("ygoMonsters.txt")]                                06
//06      < dataFile.is_open() >                                            07,17
//07      < getline(dataFile, line) >                                       08,17
//08      < count % 3 == 0 >                                                09,10
//09      /line --> monsters[i].name/                                       10
//10      < count % 3 == 1 >                                                11,12
//11      /line --> monsters[i].name/                                       12
//12      < count % 3 == 2 >                                                13,14
//13      /line --> monsters[i].def/                                        14
//14      [count++]                                                         15
//15      < count % 3 == 0 >                                                16,07
//16      [i++]                                                             07
//17      [dataFile.close()]                                                18
//18      (exit)
*/
void initialize(monster monsters[]) {
  ifstream dataFile;
  string line;
  int i = 0, count = 0;
  dataFile.open("ygoMonsters.txt");
  if (dataFile.is_open()) {
    while (getline(dataFile, line)) {
      if (count % 3 == 0) {
        stringstream(line) >> monsters[i].name;
      } else if (count % 3 == 1) {
        stringstream(line) >> monsters[i].atk;
      } else if (count % 3 == 2) {
        stringstream(line) >> monsters[i].def;
      }
      count++;
      if (count % 3 == 0) {
        i++;
      }
    }
  }
  dataFile.close();
}

/*
//Name: shuffle()
//Parameter(s): monster deck[]
//Returns: None
//Label   Task                                                              Goto
//01      (start: deck)                                                     02
//02      [srand((unsigned)time(0))]                                        03
//03      [init temp as monster]                                            04
//04      [init j as int]                                                   05
//05      [init i as int, 0 --> i]                                          06
//06      < i < 52 >                                                        07,12
//07      [j = (rand() % 52)]                                               08
//08      [temp = deck[i]]                                                  09
//09      [deck[i] = deck[j]]                                               10
//10      [deck[j] = temp]                                                  11
//11      [i++]                                                             06
//12      (exit)
*/
void shuffle(monster deck[]) {
  srand((unsigned)time(0));
  monster temp;
  int j;
  for (int i = 0; i < 52; i++) {
    j = (rand() % 52);
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

/*
//Name: emptyCard()
//Parameters: None
//Returns: monster
//Label   Task                                                              Goto
//01      (start)                                                           02
//02      [init result as monster]                                          03
//03      ["Placeholder" --> result.name]                                   04
//04      [0 --> result.atk]                                                05
//05      [0 --> result.def]                                                06
//06      (exit: result)
*/
monster emptyCard() {
  monster result;
  result.name = "Placeholder";
  result.atk = 0;
  result.def = 0;
  return result;
}

/*
//Name: createDecks()
//Parameters: monster(userPile[], botPile[], sourceDeck[])
//Returns: none
//Label   Task                                                              Goto
//01      [init nullCard as monster, emptyCard() --> nullCard]              02
//02      [init i, j, k as int, 0 --> i, j, k]                              03
//03      < i < 52 >                                                        04,10
//04      < i % 2 == 0 >                                                    05,07
//05      [userPile[j] = sourceDeck[i]]                                     06
//06      [j++]                                                             09
//07      [botPile[k] = sourceDeck[i]]                                      08
//08      [k++]                                                             09
//09      [i++]                                                             03
//10      [init m as int, 26 --> m]                                         11
//11      < m < 52 >                                                        12,15
//12      [userPile[m] = nullCard]                                          13
//13      [botPile[m] = nullCard]                                           14
//14      [m++]                                                             11
//15      (exit)
*/
void createDecks(monster userPile[], monster botPile[], monster sourceDeck[]) {
  monster nullCard = emptyCard();
  for (int i = 0, j = 0, k = 0; i < 52; i++) {
    if (i % 2 == 0) {
      userPile[j] = sourceDeck[i];
      j++;
    } else {
      botPile[k] = sourceDeck[i];
      k++;
    }
  }
  for (int m = 26; m < 52; m++) {
    userPile[m] = nullCard;
    botPile[m] = nullCard;
  }
}

/*
//Name: isEmpty()
//Parameters: monster deck[]
//Returns: bool
//Label   Task                                                              Goto
//01      (start: deck)                                                     02
//02      [init i as int, 0 --> i]                                          03
//03      < i < 52 >                                                        04,06
//04      < deck[i].name != "Placeholder" >                                 05,06
//05      (exit: false)
//06      [i++]                                                             03
//07      (exit: true)
*/
bool isEmpty(monster deck[]) {
  for (int i = 0; i < 52; i++) {
    if (deck[i].name != "Placeholder") {
      return false;
    }
  }
  return true;
}

/*
//Name: findTop()
//Parameters: monster deck[]
//Returns: int
//Label   Task                                                              Goto
//01      (start: deck)                                                     02
//02      [init i as int, 51 --> i]                                         03
//03      < i > 0 >                                                         04,06
//04      < deck[i].name != "Placeholder" >                                 05,06
//05      (exit: i)
//06      [i++]                                                             03
//07      (exit: 0)
*/
int findTop(monster deck[]) {
  for (int i = 51; i > 0; i--) {
    if (deck[i].name != "Placeholder") {
      return i;
    }
  }
  return 0;
}

/*
//Name: pop()
//Parameters: monster deck[]
//Returns: None
//Label   Task                                                              Goto
//01      (start: deck)                                                     02
//02      < !(isEmpty(deck)) >                                              03,06
//03      [init x as in, findTop(deck) --> x]                               04
//04      [init replacement as monster, emptyCard() --> replacement]        05
//05      [deck[x] = replacement]                                           06
//06      (exit)
*/
void pop(monster deck[]) {
  if (!(isEmpty(deck))) {
    int x = findTop(deck);
    monster replacement = emptyCard();
    deck[x] = replacement;
  }
}

/*
//Name: push()
//Parameters: monster(deck[], newCard)
//Returns: None
//Label   Task                                                              Goto
//01      (start: deck, newCard)                                            02
//02      [init x as int, findTop(deck) --> x]                              03
//03      [init i as int, (x+1) --> i]                                      04
//04      < i > 0 >                                                         05,07
//05      [deck[i] = deck[i - 1]]                                           06
//06      [i++]                                                             04
//07      [deck[0] = newCard]                                               08
//08      (exit)
*/
void push(monster deck[], monster newCard) {
  int x = findTop(deck);
  for (int i = x + 1; i > 0; i--) {
    deck[i] = deck[i - 1];
  }
  deck[0] = newCard;
}

//Declared globally due to counting issue. Used in toRecords() function
//To keep track of the number of rounds.
int count = 0;

/*
//Name: toRecords()
//Parameters: monster(userDeck[], botDeck[]), int(x, y, userLP, botLP,), bool hasWon, int& count, bool& status
//Returns: none
//Label   Task                                                                                            Goto
//01      (start: userDeck, botDeck, x, y, userLP, botLP, hasWon, count, status)                          02
//02      [init record as ofstream]                                                                       03
//03      [init out as stringstream]                                                                      04
//04      [count++]                                                                                       05
//05      /write_to_out('\n', left)/                                                                      06
//06      /write_to_out("ROUND", count, '\n')/                                                            07
//07      /write_to_out("Player's card:\n")/                                                              08
//08      /write_to_out('\t', userDeck[x].name, '\n')/                                                    09
//09      /write_to_out('\t', "Attack: ", userDeck[x].atk, '\n')/                                         10
//10      /write_to_out('\t', "Defense: ", userDeck[x].atk, '\n')/                                        11
//11      < userDeck[x].mode == 'A' >                                                                     12,13
//12      /write_to_out('\t', "Mode: Attack\n")/                                                          14
//13      /write_to_out('\t', "Mode: Defense\n")/                                                         14
//14      /write_to_out("Computer's card:\n")/                                                            15
//15      /write_to_out('\t', botDeck[y].name, '\n')/                                                     16
//16      /write_to_out('\t', "Attack: ", botDeck[y].atk, '\n')/                                          17
//17      /write_to_out('\t', "Defense: ", botDeck[y].atk, '\n')/                                         18
//18      < botDeck[y].mode == 'A' >                                                                      19,20
//19      /write_to_out('\t', "Mode: Attack\n")/                                                          21
//20      /write_to_out('\t', "Mode: Defense\n")/                                                         21
//21      /write_to_out("Player's life:\n")/                                                              22
//22      < userLP < 0 >                                                                                  23,24
//23      [userLP == 0]                                                                                   24
//24      /write_to_out('\t', userLP, '\n')/                                                              25
//25      /write_to_out("Player's life:\n")/                                                              26
//26      < userLP < 0 >                                                                                  27,28
//27      [userLP == 0]                                                                                   28
//28      /write_to_out('\t', userLP, '\n')/                                                              29
//29      < hasWon == true >                                                                              30,31
//30      /write_to_out("Player has won this round\n")/                                                   32
//31      /write_to_out("Computer has won this round\n")/                                                 32
//32      /print(setfill('_'), setw(50), '_', '\n')/                                                      33
//33      /print(out.str())/                                                                              34
//34      [record.open("ygoWarRoundRecords.txt", ios::out | ios::app)]                                    35
//35      < record.is_open >                                                                              36,44
//36      /write_to_record(out.str())/                                                                    37
//37      < status == true >                                                                              38,39
//38      /write_to_record("Status: At war\n")/                                                           40
//39      /write_to_record("Status: Not at war\n")/                                                       40
//40      /write_to_record(setfill('_'), setw(50), '_', '\n')/                                            41
//41      < userLP == 0 or isEmpty(userDeck) >                                                            42,43
//42      /write_to_record("Computer has won this game\n")/                                               44
//43      /write_to_record("Player has won this game\n")/                                                 44
//44      [record.close()]                                                                                45
//45      (exit)
*/
void toRecords(monster userDeck[], monster botDeck[], int x, int y, int userLP, int botLP, bool hasWon, int& count, bool& status) {
  ofstream record;
  stringstream out;
  count++;
  out << endl << left;
  out << "ROUND " << count << endl;
  out << "Player's card:\n";
  out << "\t" << userDeck[x].name << endl;
  out << "\t" << "Attack: " << userDeck[x].atk << endl;
  out << "\t" << "Defense: " << userDeck[x].def << endl;
  if (userDeck[x].mode == 'A') {
    out << "\t" << "Mode: Attack\n";
  } else {
    out << "\t" << "Mode: Defense\n";
  }
  out << "Computer's card:\n";
  out << "\t" << botDeck[y].name << endl;
  out << "\t" << "Attack: " << botDeck[y].atk << endl;
  out << "\t" << "Defense: " << botDeck[y].def << endl;
  if (botDeck[y].mode == 'A') {
    out << "\t" << "Mode: Attack\n";
  } else {
    out << "\t" << "Mode: Defense\n";
  }
  out << "Player's life:\n";
  if (userLP < 0) {
    userLP = 0;
  }
  out << "\t" << userLP << endl;
  out << "Computer's life:\n";
  if (botLP < 0) {
    botLP = 0;
  }
  out << "\t" << botLP << endl;
  if (hasWon == true) {
    out << "Player won this round\n";
  } else {
    out << "Computer won this round\n";
  }
  cout << out.str();
  cout << setfill('_') << setw(50) << '_' << endl;
  record.open("ygoWarRoundRecords.txt", ios::out | ios::app);
    if (record.is_open()) {
      record << out.str();
      if (status == true) {
        record << "Status: At war\n";
      } else {
        record << "Status: Not at war\n";
      }
      record << setfill('_') << setw(50) << '_' << endl;
      if (userLP == 0 || isEmpty(userDeck)) {
        record << "Computer has won this game\n";
      } else if (botLP == 0 || isEmpty(botDeck)) {
        record << "Player has won this game\n";
      }
    }
    record.close();
}

/*
//Name: endOfWar()
//Parameter(s): monster(temp[], winner[]), bool& war
//Returns: None
//Label   Task                                                              Goto
//01      (start: temp, winner, war)                                        02
//02      [init z as int]                                                   03
//03      < not (isEmpty(temp)) >                                           04,07
//04      [findTop(temp) --> z]                                             05
//05      [push(winner, temp[z])]                                           06
//06      [pop(temp)]                                                       07
//07      [war = false]                                                     08
//08      /print("War ended!\n")/                                           09
//09      (exit)
*/
void endOfWar(monster temp[], monster winner[], bool& war) {
  int z;
  while (!(isEmpty(temp))) {
    z = findTop(temp);
    push(winner, temp[z]);
    pop(temp);
  }
  war = false;
  cout << "War ended!\n";
}

/*
//Name: declareWar()
//Parameter(s): monster(userDeck[], botDeck[], temp), bool& war, int&(userLP, botLP, x, y)
//Returns: None
//Label   Task                                                                                              Goto
//01      (start: userDeck, botDeck, temp, war, userLP, botLP, x, y)                                        02
//02      [srand((unsigned)time(0))]                                                                        03
//03      [init hasWon as bool]                                                                             04
//04      < (war and (not(isEmpty(userDeck)) and userLP > 0)) and (not(isEmpty(botDeck)) and botLP > 0) >   05,89
//05      /print("WAR!!!\n")/                                                                               06
//06      [push(temp, userDeck[x])]                                                                         07
//07      [push(temp, botDeck[y])]                                                                          08
//08      [pop(userDeck)]                                                                                   09
//09      [pop(botDeck)]                                                                                    10
//10      [x = findTop(userDeck)]                                                                           11
//11      [y = findTop(botDeck)]                                                                            12
//12      /print(setfill('_'), setw(50), '_', '\n')/                                                        13
//13      /print("Your life points are: ", userLP, '\n')/                                                   14
//14      /print("Your opponent's life points are: ", botLP, '\n')                                          15
//15      /print("Will you bring out your card in attack or defense mode?(A/D)\n")/                         16
//16      /input --> userDeck[x].mode/                                                                      17
//17      /print(setfill('_'), setw(50), '_', '\n')/                                                        18
//18      [userDeck[x].mode == toupper(userDeck[x].mode)]                                                   19
//19      [init randomPick as int, (rand() % 2) --> randomPick]                                             20
//20      < randomPick == 1 >                                                                               21,22
//21      [botDeck[y].mode = 'D']                                                                           22
//22      /print("Battle!\n")/                                                                              23
//23      < userDeck[x].mode == 'A' and botDeck[y].mode == 'A' >                                            24,40
//24      < userDeck[x].atk > botDeck[y].atk >                                                              25,32
//25      [hasWon = true]                                                                                   26
//26      [botLP -= (userDeck[x].atk - botDeck[y].atk)]                                                     27
//27      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           28
//28      [pop(botDeck)]                                                                                    29
//29      [push(userDeck, userDeck[x])]                                                                     30
//30      [pop(userDeck)]                                                                                   31
//31      [endOfWar(temp, userDeck, war)]                                                                   05
//32      < userDeck[x].atk < botDeck[y].atk >                                                              33,05
//33      [hasWon = false]                                                                                  34
//34      [userLP -= (botDeck[y].atk - userDeck[x].atk)]                                                    35
//35      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           36
//36      [pop(userDeck)]                                                                                   37
//37      [push(botDeck, botDeck[y])]                                                                       38
//38      [pop(botDeck)]                                                                                    39
//39      [endOfWar(temp, botDeck, war)]                                                                    05
//40      < userDeck[x].mode == 'A' and botDeck[y].mode == 'D' >                                            41,56
//41      < userDeck[x].atk > botDeck[y].def >                                                              42,48
//42      [hasWon = true]                                                                                   43
//43      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           44
//44      [pop(botDeck)]                                                                                    45
//45      [push(userDeck, userDeck[x])]                                                                     46
//46      [pop(userDeck)]                                                                                   47
//47      [endOfWar(temp, userDeck, war)]                                                                   05
//48      < userDeck[x].atk < botDeck[y].def >                                                              49,05
//49      [hasWon = false]                                                                                  50
//50      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           51
//51      [push(botDeck, botDeck[y])]                                                                       52
//52      [pop(botDeck)]                                                                                    53
//53      [push(botDeck, userDeck[x])]                                                                      54
//54      [pop(userDeck)]                                                                                   55
//55      [endOfWar(temp, botDeck, war)]                                                                    05
//56      < userDeck[x].mode == 'D' and botDeck[y].mode == 'A' >                                            57,72
//57      < userDeck[x].def > botDeck[y].atk >                                                              58,65
//58      [hasWon = true]                                                                                   59
//59      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           60
//60      [push(userDeck, userDeck[x])]                                                                     61
//61      [pop(userDeck)]                                                                                   62
//62      [push(userDeck, botDeck[y])]                                                                      63
//63      [pop(botDeck)]                                                                                    64
//64      [endOfWar(temp, userDeck, war)]                                                                   05
//65      < userDeck[x].def < botDeck[y].atk >                                                              66,05
//66      [hasWon = false]                                                                                  67
//67      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           68
//68      [pop(userDeck)]                                                                                   69
//69      [push(botDeck, botDeck[y])]                                                                       70
//70      [pop(botDeck)]                                                                                    71
//71      [endOfWar(temp, botDeck, war)]                                                                    05
//72      < userDeck[x].mode == 'D' and botDeck[y].mode == 'D' >                                            73,05
//73      < userDeck[x].def > botDeck[y].def >                                                              74,81
//74      [hasWon = true]                                                                                   75
//75      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                           76
//76      [push(userDeck, userDeck[x])]                                                                     77
//77      [pop(userDeck)]                                                                                   78
//78      push(userDeck, botDeck[y])                                                                        79
//79      [pop(botDeck)]                                                                                    80
//80      [endOfWar(temp, userDeck, war)]                                                                   05
//81      < userDeck[x].def < botDeck[y].def >                                                              05
//82      [hasWon == false]                                                                                 83
//83      [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war]                            84
//84      [push(botDeck, botDeck[y])]                                                                       85
//85      [pop(botDeck)]                                                                                    86
//86      [push(botDeck, userDeck[x])]                                                                      87
//87      [pop(userDeck)]                                                                                   88
//88      [endOfWar(temp, botDeck, war)]                                                                    05
//89      (exit)
*/
void declareWar(monster userDeck[], monster botDeck[], monster temp[], bool& war, int& userLP, int& botLP, int& x, int& y) {
  srand((unsigned)time(0));
  bool hasWon;
  while (war && (!(isEmpty(userDeck)) && userLP > 0) && (!(isEmpty(botDeck)) && botLP > 0) ) {
    cout << "WAR!!!\n";
    push(temp, userDeck[x]);
    push(temp, botDeck[y]);
    pop(userDeck);
    pop(botDeck);
    x = findTop(userDeck);
    y = findTop(botDeck);
    cout << setfill('_') << setw(50) << '_' << endl;
    cout << "Your life points are: " << userLP << endl;
    cout << "Your opponent's life points are: " << botLP << endl;
    cout << "Will you bring out your card in attack or defense mode?(A/D)\n";
    cin >> userDeck[x].mode;
    cout << setfill('_') << setw(50) << '_' << endl;
    userDeck[x].mode = toupper(userDeck[x].mode);
    int randomPick = rand() % 2;
    if (randomPick == 1) {
      botDeck[y].mode = 'D';
    }
    cout << "Battle!\n";
    if (userDeck[x].mode == 'A' && botDeck[y].mode == 'A') {
      if (userDeck[x].atk > botDeck[y].atk) {
        hasWon = true;
        botLP -= (userDeck[x].atk - botDeck[y].atk);
        toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
        pop(botDeck);
        push(userDeck, userDeck[x]);
        pop(userDeck);
        endOfWar(temp, userDeck, war);
      } else if (userDeck[x].atk < botDeck[y].atk) {
          hasWon = false;
          userLP -= (botDeck[y].atk - userDeck[x].atk);
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          pop(userDeck);
          push(botDeck, botDeck[y]);
          pop(botDeck);
          endOfWar(temp, botDeck, war);
      }
    } else if (userDeck[x].mode == 'A' && botDeck[y].mode == 'D') {
        if (userDeck[x].atk > botDeck[y].def) {
          hasWon = true;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          pop(botDeck);
          push(userDeck, userDeck[x]);
          pop(userDeck);
          endOfWar(temp, userDeck, war);
    } else if (userDeck[x].atk < botDeck[y].def) {
        hasWon = false;
        toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
        push(botDeck, botDeck[y]);
        pop(botDeck);
        push(botDeck, userDeck[x]);
        pop(userDeck);
        endOfWar(temp, botDeck, war);
      }
    } else if (userDeck[x].mode == 'D' && botDeck[y].mode == 'A') {
        if (userDeck[x].def > botDeck[y].atk) {
          hasWon = true;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          push(userDeck, userDeck[x]);
          pop(userDeck);
          push(userDeck, botDeck[y]);
          pop(botDeck);
          endOfWar(temp, userDeck, war);
        } else if (userDeck[x].def < botDeck[y].atk) {
            hasWon = false;
            toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
            pop(userDeck);
            push(botDeck, botDeck[y]);
            pop(botDeck);
            endOfWar(temp, botDeck, war);
          }
    } else if (userDeck[x].mode == 'D' && botDeck[y].mode == 'D') {
        if (userDeck[x].def > botDeck[y].def) {
          hasWon = true;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          push(userDeck, userDeck[x]);
          pop(userDeck);
          push(userDeck, botDeck[y]);
          pop(botDeck);
          endOfWar(temp, userDeck, war);
      } else if (userDeck[x].def < botDeck[y].def) {
          hasWon = false;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
            push(botDeck, botDeck[y]);
            pop(botDeck);
            push(botDeck, userDeck[x]);
            pop(userDeck);
            endOfWar(temp, botDeck, war);
          }
        }
      }
}

/*
//Name: warYGO()
//Parameter(s): monster(userDeck[], botDeck[])
//Returns: None
//Label   Task                                                                                      Goto
//001     (start: userDeck, botDeck)                                                                002
//002     [srand((unsigned)time(0))]                                                                003
//003     [init temp as monster[52]]                                                                004
//004     [init i as int, 0 --> i]                                                                  005
//005     < i < 52 >                                                                                006,007
//006     [temp[i] = emptyCard()]                                                                   005
//007     [init war, hasWon as bool, false --> war]                                                 008
//008     [init x, y, userLP, botLP, randomPick as int, 4000 --> userLP, botLP]                     009
//009     /print("YuGiOh War\n")/                                                                   010
//010     /print(setfill('_'), setw(50), '_', '\n')/                                                011
//011     < ( (!(isEmpty(userDeck)) and userLP > 0) and (!(isEmpty(botDeck)) and botLP > 0) ) >     012,106
//012     [x = findTop(userDeck)]                                                                   013
//013     [y = findTop(botDeck)]                                                                    014
//014     /print("Your life points are: ", userLP, '\n')/                                           015
//015     /print("Your opponent's life points are: ", botLP, '\n')/                                 016
//016     /print("Will you bring out your card in attack or defense mode?(A/D)\n")/                 017
//017     /input --> userDeck[x].mode/                                                              018
//018     /print(setfill('_'), setw(50), '_', '\n')/                                                019
//019     [userDeck[x].mode = toupper(userDeck[x].mode)]                                            020
//020     [randomPick = rand() % 2]                                                                 021
//021     < randomPick == 1 >                                                                       022,023
//022     [botDeck[y].mode = 'D']                                                                   023
//023     /print("Battle!\n")/                                                                      024
//024     < userDeck[x].mode == 'A' and botDeck[y].mode == 'A' >                                    025,045
//025     < userDeck[x].atk > botDeck[y].atk >                                                      026,032
//026     [hasWon = true]                                                                           027
//027     [botLP -= (userDeck[x].atk - botDeck[y].atk)]                                             028
//028     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   029
//029     [pop(botDeck)]                                                                            030
//030     [push(userDeck, userDeck[x])]                                                             031
//031     [pop(userDeck)]                                                                           011
//032     < userDeck[x].atk < botDeck[y].atk >                                                      033,039
//033     [hasWon = false]                                                                          034
//034     [userLP -= (botDeck[y].atk - userDeck[x].atk)]                                            035
//035     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   036
//036     [pop(userDeck)]                                                                           037
//037     [push(botDeck, botDeck[y])]                                                               038
//038     [pop(botDeck)]                                                                            011
//039     [war = true]                                                                              040
//040     [push(temp, userDeck[x])]                                                                 041
//041     [push(temp, botDeck[y])]                                                                  042
//042     [pop(userDeck)]                                                                           043
//043     [pop(botDeck)]                                                                            044
//044     [declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y)]                           011
//045     < userDeck[x].mode == 'A' and botDeck[y].mode == 'D' >                                    046,065
//046     < userDeck[x].atk > botDeck[y].def >                                                      047,052
//047     [hasWon = true]                                                                           048
//048     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   049
//049     [pop(botDeck)]                                                                            050
//050     [push(userDeck, userDeck[x])]                                                             051
//051     [pop(userDeck)]                                                                           011
//052     < userDeck[x].atk < botDeck[y].def >                                                      053,059
//053     [hasWon = false]                                                                          054
//054     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   055
//055     [push(botDeck, botDeck[y])]                                                               056
//056     [pop(botDeck)]                                                                            057
//057     [push(botDeck, userDeck[x])]                                                              058
//058     [pop(userDeck)]                                                                           011
//059     war = true                                                                                060
//060     push(temp, userDeck[x])                                                                   061
//061     push(temp, botDeck[y])                                                                    062
//062     pop(userDeck)                                                                             063
//063     pop(botDeck)                                                                              064
//064     [declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y)]                           011
//065     < userDeck[x].mode == 'D' and botDeck[y].mode == 'A' >                                    066,085
//066     < userDeck[x].def > botDeck[y].atk >                                                      067,073
//067     [hasWon = true]                                                                           068
//068     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   069
//069     [push(userDeck, userDeck[x])]                                                             070
//070     [pop(userDeck)]                                                                           071
//071     [push(userDeck, botDeck[y])]                                                              072
//072     [pop(botDeck)]                                                                            011
//073     < userDeck[x].def < botDeck[y].atk >                                                      074,079
//074     [hasWon = false]                                                                          075
//075     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   076
//076     [pop(userDeck)]                                                                           077
//077     [push(botDeck, botDeck[y])]                                                               078
//078     [pop(botDeck)]                                                                            011
//079     [war = true]                                                                              080
//080     [push(temp, userDeck[x])]                                                                 081
//081     [push(temp, botDeck[y])]                                                                  082
//082     [pop(userDeck)]                                                                           083
//083     [pop(botDeck)]                                                                            084
//084     [declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y)]                           011
//085     < userDeck[x].mode == 'D' and botDeck[y].mode == 'D' >                                    086,011
//086     < userDeck[x].def > botDeck[y].def >                                                      087,093
//087     [hasWon = true]                                                                           088
//088     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   089
//089     [push(userDeck, userDeck[x])]                                                             090
//090     [pop(userDeck)]                                                                           091
//091     [push(userDeck, botDeck[y])]                                                              092
//092     [pop(botDeck)]                                                                            011
//093     < userDeck[x].def < botDeck[y].def >                                                      094,100
//094     [hasWon = false]                                                                          095
//095     [toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war)]                   096
//096     [push(botDeck, botDeck[y])]                                                               097
//097     [pop(botDeck)]                                                                            098
//098     [push(botDeck, userDeck[x])]                                                              099
//099     [pop(userDeck)]                                                                           011
//100     [war = true]                                                                              101
//101     [push(temp, userDeck[x])]                                                                 102
//102     [push(temp, botDeck[y])]                                                                  103
//103     [pop(userDeck)]                                                                           104
//104     [pop(botDeck)]                                                                            105
//105     [declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y)]                           011
//106     < userLP > 0 and (!(isEmpty(userDeck))) >                                                 107,108
//107     /print("You win!\n")/                                                                     112
//108     < userLP <= 0 >                                                                           109,110
//109     /print("Your life points have reached 0! You lose!\n")/                                   112
//110     < isEmpty(userDeck) >                                                                     111,112
//111     /print("You lose by way of deck out!\n")/                                                 112
//112     (exit)
*/
void warYGO(monster userDeck[], monster botDeck[]) {
  srand((unsigned)time(0));
  monster temp[52];
  for (int i = 0; i < 52; i++) {
    temp[i] = emptyCard();
  }
  bool war = false, hasWon;
  int x, y, userLP = 4000, botLP = 4000, randomPick;
  cout << "YuGiOh War\n";
  cout << setfill('_') << setw(50) << '_' << endl;
  while ( (!(isEmpty(userDeck)) && userLP > 0) && (!(isEmpty(botDeck)) && botLP > 0) ) {
    x = findTop(userDeck);
    y = findTop(botDeck);
    cout << "Your life points are: " << userLP << endl;
    cout << "Your opponent's life points are: " << botLP << endl;
    cout << "Will you bring out your card in attack or defense mode?(A/D)\n";
    cin >> userDeck[x].mode;
    cout << setfill('_') << setw(50) << '_' << endl;
    userDeck[x].mode = toupper(userDeck[x].mode);
    randomPick = rand() % 2;
    if (randomPick == 1) {
      botDeck[y].mode = 'D';
    }
    cout << "Battle!\n";
    if (userDeck[x].mode == 'A' && botDeck[y].mode == 'A') {
      if (userDeck[x].atk > botDeck[y].atk) {
        hasWon = true;
        botLP -= (userDeck[x].atk - botDeck[y].atk);
        toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
        pop(botDeck);
        push(userDeck, userDeck[x]);
        pop(userDeck);
      } else if (userDeck[x].atk < botDeck[y].atk) {
          hasWon = false;
          userLP -= (botDeck[y].atk - userDeck[x].atk);
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          pop(userDeck);
          push(botDeck, botDeck[y]);
          pop(botDeck);
      } else {
          war = true;
          push(temp, userDeck[x]);
          push(temp, botDeck[y]);
          pop(userDeck);
          pop(botDeck);
          declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y);
        }
      } else if (userDeck[x].mode == 'A' && botDeck[y].mode == 'D') {
        if (userDeck[x].atk > botDeck[y].def) {
          hasWon = true;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          pop(botDeck);
          push(userDeck, userDeck[x]);
          pop(userDeck);
      } else if (userDeck[x].atk < botDeck[y].def) {
          hasWon = false;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          push(botDeck, botDeck[y]);
          pop(botDeck);
          push(botDeck, userDeck[x]);
          pop(userDeck);
        } else {
            war = true;
            push(temp, userDeck[x]);
            push(temp, botDeck[y]);
            pop(userDeck);
            pop(botDeck);
            declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y);
          }
      } else if (userDeck[x].mode == 'D' && botDeck[y].mode == 'A') {
          if (userDeck[x].def > botDeck[y].atk) {
            hasWon = true;
            toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
            push(userDeck, userDeck[x]);
            pop(userDeck);
            push(userDeck, botDeck[y]);
            pop(botDeck);
          } else if (userDeck[x].def < botDeck[y].atk) {
            hasWon = false;
            toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
              pop(userDeck);
              push(botDeck, botDeck[y]);
              pop(botDeck);
          } else {
              war = true;
              push(temp, userDeck[x]);
              push(temp, botDeck[y]);
              pop(userDeck);
              pop(botDeck);
              declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y);
            }
      } else if (userDeck[x].mode == 'D' && botDeck[y].mode == 'D') {
        if (userDeck[x].def > botDeck[y].def) {
          hasWon = true;
          toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
          push(userDeck, userDeck[x]);
          pop(userDeck);
          push(userDeck, botDeck[y]);
          pop(botDeck);
        } else if (userDeck[x].def < botDeck[y].def) {
            hasWon = false;
            toRecords(userDeck, botDeck, x, y, userLP, botLP, hasWon, count, war);
            push(botDeck, botDeck[y]);
            pop(botDeck);
            push(botDeck, userDeck[x]);
            pop(userDeck);
          } else {
              war = true;
              push(temp, userDeck[x]);
              push(temp, botDeck[y]);
              pop(userDeck);
              pop(botDeck);
              declareWar(userDeck, botDeck, temp, war, userLP, botLP, x, y);
            }
      }
    }
    if ( userLP > 0 && (!(isEmpty(userDeck))) ) {
      cout << "You win!\n";
    } else if (userLP <= 0) {
      cout << "Your life points have reached 0! You lose!\n";
    } else if (isEmpty(userDeck)) {
      cout << "You lose by way of deck out!\n";
    }
}


#endif //YGOWAR_H
