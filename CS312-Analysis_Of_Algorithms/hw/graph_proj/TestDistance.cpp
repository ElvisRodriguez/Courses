#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "LabeledGraph.h"

using namespace std;

int main() {
  cout << "Creating Graph...\n";
  LabeledGraph imdb("movies.txt");
  cout << "Running tests...\n";
  string actor = "Kevin Bacon";
    int index = imdb.index(actor);
    map<int, int> parent_map = imdb.breadth_first_search(index);

    // Assert distance from a node to itself is 0
    assert(imdb.distanceTo(actor, actor) == 0);

    // Path sizes assertions
    set<string> actors = imdb.all_actors;
    set<string>::iterator it;
    for (it = actors.begin(); it != actors.end(); it++) {
      if (parent_map.find(imdb.index(*it)) != parent_map.end()) {
        vector<int> path = imdb.pathTo(parent_map, imdb.index(*it));
           assert(imdb.distanceTo(actor, *it) == path.size());
      }
    }
  cout << "Tests Passed\n";
  return 0;
}
