#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "LabeledGraph.h"

using namespace std;

int main() {
  cout << "Creating Graph...\n";
  LabeledGraph imdb("movies.txt");
  string actor = "Jim Carrey";
  int index = imdb.index(actor);
  map<int, int> parent_map = imdb.breadth_first_search(index);

  // Assert index of actor is the parent map's root node
  assert(parent_map[index] == -1);

  // Find all nodes adjacent to actor
  vector<string> neighbors = imdb.get_neighbors(actor);

  for (int i = 0; i < neighbors.size(); i++) {

    // Assert each neighbor is in the labeled graph
    assert(imdb.contains(neighbors[i]));

    index = imdb.index(neighbors[i]);

    // Assert these neighbors are child nodes of actor
    assert(parent_map.find(index) != parent_map.end());
  }

  cout << "\nTests Passed\n";
}
