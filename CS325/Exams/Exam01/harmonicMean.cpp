#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INPUT_FILE "testNumbers.txt"

vector<double> parseNumbersFromFile(ifstream& in) {
    vector<double> allNumbers;
    if (in.is_open()) {
       string line;
       while(getline(in, line)) {
           double currentNumber;
           string rawNumber = "";
           for (int i = 0; i < line.length(); i++) {
               if (line.at(i) == ' ' || line.at(i) == '\n') {
                   currentNumber = stod(rawNumber);
                   allNumbers.push_back(currentNumber);
                   rawNumber = "";
               } else {
                   rawNumber += line.at(i);
               }
           }
           currentNumber = stod(rawNumber);
           allNumbers.push_back(currentNumber);
       }
   }
   return allNumbers;
}


double HarmonicMean(ifstream& in) {
    /* Takes a stream of real, nonnegative numbers and calculates the
       harmonic mean (n/[(1/x1)+...+(1/xn)]):
       - xi is a real, nonnegative number.
       - n is the count of all real, nonnegative, nonzero numbers.
    */
   if (in.is_open()) {
        int n = 0;
        double mean = 0;
        double denominator = 0;
        vector<double> allNumbers = parseNumbersFromFile(in);
        vector<double> validNumbers;
        for (double number: allNumbers) {
            if (number != 0) {
                n++;
                validNumbers.push_back(number);
            }
        }
        if (n == 0) return 0;
        for (double number: validNumbers) {
            denominator += (1 / number);
        }
        mean = n / denominator;
        return mean;

   }
   return 0;
   
}


int main() {
    ifstream file(INPUT_FILE);
    double mean = HarmonicMean(file);
    cout << "Harmonic mean: " << mean << endl;
    return 0;
}