/*
//Name: Elvis Rodriguez
//Assignment: 1
//Description: The functions conjunction(), disjunction(), negation(), implication(), and equivalence() should
return the truth value of the conjunction, disjunction, negation, implication and equivalence
connectives respectively. The functions truthTable() return a formatted string of a truth table
that consists of all the connectives like the one on the formula sheet. Use the symbols &, |, !, >
and = to represent conjunction, disjunction, negation, implication and equivalence in the tables
respectively...
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

bool conjunction(bool A, bool B) {
  return (A && B);
}

bool disjunction(bool A, bool B) {
  return (A || B);
}

bool negation(bool A) {
  return (!A);
}

bool implication(bool P, bool Q) {
  if (P == true && Q == false) {
    return Q;
  }
  return true;
}

bool equivalence(bool A, bool B) {
  return (A == B);
}

char btoc(bool value) {
  return (value)?('T'):('F');
}

string truthTable() {
  stringstream result;
  bool A = true, B = true;
  //These values determine the position of the truth values in the chart
  //2 = A,6 = B,11 = !A,16 = A&B,22 = A|B,28 = A>B,34 = A=B
  string topOfChart = "  A : B : !A : A&B : A|B : A>B : A=B\n";
  string separator = "";
  for (int i = 0; i < topOfChart.length(); i++) {
    separator += "-";
  }
  separator += "\n";
  string firstLine = "", secondLine = "", thirdLine = "", fourthLine = "";
  result << topOfChart << separator;
  for (int i = 0; i < topOfChart.length(); i++) {
    if (i == 2) {
      firstLine += btoc(A);
      secondLine += btoc(A);
      thirdLine += btoc(negation(A));
      fourthLine += btoc(negation(A));
    } else if (i == 6) {
        firstLine += btoc(B);
        secondLine += btoc(negation(B));
        thirdLine += btoc(B);
        fourthLine += btoc(negation(B));
      } else if (i == 11) {
          firstLine += btoc(negation(A));
          secondLine += " ";
          thirdLine += btoc(A);
          fourthLine += " ";
        } else if (i == 16) {
            firstLine += btoc(conjunction(A, B));
            secondLine += btoc(conjunction(A, negation(B)));
            thirdLine += btoc(conjunction(negation(A), B));
            fourthLine += btoc(conjunction(negation(A), negation(B)));
          } else if (i == 22) {
              firstLine += btoc(disjunction(A, B));
              secondLine += btoc(disjunction(A, negation(B)));
              thirdLine += btoc(disjunction(negation(A), B));
              fourthLine += btoc(disjunction(negation(A), negation(B)));
            } else if (i == 28) {
                firstLine += btoc(implication(A, B));
                secondLine += btoc(implication(A, negation(B)));
                thirdLine += btoc(implication(negation(A), B));
                fourthLine += btoc(implication(negation(A), negation(B)));
              } else if (i == 34) {
                  firstLine += btoc(equivalence(A, B));
                  secondLine += btoc(equivalence(A, negation(B)));
                  thirdLine += btoc(equivalence(negation(A), B));
                  fourthLine += btoc(equivalence(negation(A), negation(B)));
                } else if (i == 4 || i == 8 || i == 13 || i == 19 || i == 25 || i == 31) {
                    firstLine += ":";
                    secondLine += ":";
                    thirdLine += ":";
                    fourthLine += ":";
                  } else if (i == topOfChart.length() - 1){
                      firstLine += "\n";
                      secondLine += "\n";
                      thirdLine += "\n";
                      fourthLine += "\n";
                    } else {
                        firstLine += " ";
                        secondLine += " ";
                        thirdLine += " ";
                        fourthLine += " ";
                      }
    }
  result << firstLine << separator << secondLine << separator;
  result << thirdLine << separator << fourthLine << separator;
  return result.str();
}

int main() {
  cout << truthTable() << endl;
  return 0;
}
