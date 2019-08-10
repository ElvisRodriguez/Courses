#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isDistinct(char A, char B, char C) {
  if (A == B || A == C || B == C) {
    return false;
  }
  return true;
}

int Perm3() {
  int count = 0;
  ofstream out;
  char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  out.open("output.txt");
  if (out.is_open()) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        for (int h = 0; h < 26; h++) {
          if ((isDistinct(alpha[i], alpha[j], alpha[h]))) {
            out << alpha[i] << alpha[j] << alpha[h] << " ";
            count++;
            if (count == 10) {
              out << endl;
              count = 0;
            }
          }
        }
      }
    }
  }
  out.close();
}
int main() {

  Perm3();

  return 0;
}
