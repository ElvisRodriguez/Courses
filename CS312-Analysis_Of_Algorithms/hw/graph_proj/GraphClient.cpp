#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
  Graph elvisGraph;
  for (int i = 0; i < 5; i++) {
    elvisGraph.add_vertex();
  }
  elvisGraph.add_edge(0,4);
  elvisGraph.add_edge(0,2);
  elvisGraph.add_edge(4,2);
  elvisGraph.add_edge(4,1);
  elvisGraph.add_edge(2,3);

  cout << elvisGraph << endl;
}
