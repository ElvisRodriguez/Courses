#include <iostream>
#include "LabeledGraph.h"
using namespace std;

int main() {
  LabeledGraph elvis_labeledgraph;
  elvis_labeledgraph.add_edge("Chris Pratt", "Guardians of the Galaxy");
  elvis_labeledgraph.add_edge("Zoe Saldana", "Guardians of the Galaxy");
  elvis_labeledgraph.add_edge("Vin Diesel", "Guardians of the Galaxy");
  elvis_labeledgraph.add_edge("Zoe Saldana", "Avatar");
  elvis_labeledgraph.add_edge("Sam Worthington", "Avatar");
  elvis_labeledgraph.add_edge("Michelle Rodriguez", "Avatar");
  elvis_labeledgraph.add_edge("Vin Diesel", "The Fate of the Furious");
  elvis_labeledgraph.add_edge("Michelle Rodriguez", "The Fate of the Furious");
  cout << elvis_labeledgraph;
}
