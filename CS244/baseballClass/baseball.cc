#include "baseball.h"

BaseballPlayer::BaseballPlayer(string setName = "Roberto Clemente") {
  name = setName;
  hits = 0;
  atBats = 0;
  outs = 0;
  strikes = 0;
}

string BaseballPlayer::getName() {
  return name;
}

double BaseballPlayer::getHits() {
  return hits;
}

double BaseballPlayer::getAtBats() {
  return atBats;
}

double BaseballPlayer::getOuts() {
  return outs;
}

string BaseballPlayer::getBattingAverage() {
  if (atBats > 0) {
    stringstream result;
    result << fixed << setprecision(3);
    result << "Batting Average: ";
    result << (hits / atBats) << endl;
    return result.str();
  } else {
    return "This player does not yet have a batting average\n";
  }
}

void BaseballPlayer::swing() {
  bool hasHit = false;
  cout << "It's " << name << "'s turn at bat!\n";
  atBats++;
  while (!hasHit && strikes < 3) {
    int value = rand() % 100;
    cout << "\n\t\t" << value << "\n\n" ;
    if (strikes == 0) {
      cout << "First Pitch:\n\t...\n";
    } else if (strikes == 1) {
      cout << "Second Pitch:\n\t...\n";
    } else {
      cout << "Final Pitch:\n\t...\n";
    }
    cout << name << " swings and ...!\n";
    if (value > 80) {
      hasHit = true;
      hits++;
      cout << "IT'S A HOME RUN!\n";
    } else if (value > 60) {
      hasHit = true;
      hits++;
      cout << name << " gets a hit waaaaaaay into outfield!\n";
    } else if (value > 40) {
      hasHit = true;
      hits++;
      cout << name << " gets a hit into infield!\n";
    } else {
      strikes++;
      if (strikes == 3) {
        cout << "STRIKE " << strikes << " YOOOOOOOOOOOOUUUUUURRRR OUT!\n";
        outs++;
      } else {
        cout << "STRIKE " << strikes << "!\n";
      }
    }
  }
  cout << getBattingAverage();
  strikes = 0;
}

void BaseballPlayer::playBall(int battingRounds) {
  for (int i = 0; i < battingRounds; i++) {
    swing();
  }
}
