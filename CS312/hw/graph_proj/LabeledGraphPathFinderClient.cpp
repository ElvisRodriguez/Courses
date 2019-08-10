#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "LabeledGraph.h"

using namespace std;

int main() {
  cout << "One moment...creating graph...\n";

  LabeledGraph imdb("movies.txt");
  map<int, int> parent_map;
  vector<int> path, second_path;
  string source_vertex, target_vertex;
  int index;

  cout << "Enter source vertex: ";
  getline(cin, source_vertex);

  if (imdb.contains(source_vertex)) {
    index = imdb.index(source_vertex);
    parent_map = imdb.breadth_first_search(index);
    cout << "All paths from " << source_vertex << " to other vertices ";
    cout << "have been created\n";
  } else {
    cout << "Source vertex not found...exiting...\n";
    return 0;
  }

  while (true) {
    cout << "\nEnter a target vertex and I will display the path from ";
    cout << source_vertex << " to that vertex (-1 to exit): ";
    getline(cin, target_vertex);
    if (target_vertex == "-1") {
      return 0;
    }
    cout << "\nPath from " << source_vertex << " to " << target_vertex << ":\n";
    index = imdb.index(target_vertex);
    path = imdb.pathTo(parent_map, index);
    cout << "Path Size: " << imdb.distanceTo(source_vertex, target_vertex) << endl;
    cout << source_vertex << " --> ";
    for (int i = 0; i < path.size(); i++) {
      if (i == path.size() - 1) {
        cout << imdb.label(path[i]) << endl;
      } else {
        cout << imdb.label(path[i]) << " --> ";
      }
    }
    cout << "\nSecond Path from " << source_vertex << " to " << target_vertex << ":\n";
    second_path = imdb.secondPathTo(imdb.index(source_vertex), imdb.index(target_vertex));
    cout << "Second Path Size: " << imdb.distanceTo(source_vertex, target_vertex) << endl;
    cout << source_vertex << " --> ";
    for (int i = 0; i < second_path.size(); i++) {
      if (i == second_path.size() - 1) {
        cout << imdb.label(second_path[i]) << endl;
      } else {
        cout << imdb.label(second_path[i]) << " --> ";
      }
    }
  }
  return 0;
}
