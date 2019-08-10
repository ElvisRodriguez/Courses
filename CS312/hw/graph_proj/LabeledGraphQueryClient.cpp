#include <iostream>
#include <vector>
#include <string>
#include "LabeledGraph.h"

using namespace std;

int main() {
  cout << "Creating Graph...\n";
  LabeledGraph imdb("movies.txt");
  string query_string = "";
  while (query_string != "q") {
    cout << "Enter an actor or movie (Enter q to quit):\n";
    getline(cin, query_string);
    if (query_string == "q") {
      break;
    }
    if (!imdb.contains(query_string)) {
      cout << query_string << " is not in our database, try again\n";
    } else {
      vector<string> neighbors = imdb.get_neighbors(query_string);
      for (int i = 0; i < neighbors.size(); i++) {
        cout << '\t' << neighbors[i] << endl;
      }
    }
  }
  return 0;
}
