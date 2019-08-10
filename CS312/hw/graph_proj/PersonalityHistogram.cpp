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
  string source_vertex, item;
  int personality_num, no_num;
  vector<int> personality_nums;

  do {
    cout << "Enter source vertex: ";
    getline(cin, source_vertex);
    if (!imdb.contains(source_vertex)) {
      cout << source_vertex << " not in database, try again\n";
    }
  } while (!imdb.contains(source_vertex));

  map<int, int> parent_map = imdb.breadth_first_search(imdb.index(source_vertex));
  set<string> actors = imdb.all_actors;
  set<string>::iterator it;
  for (it = actors.begin(); it != actors.end(); it++) {
    if (parent_map.find(imdb.index(*it)) != parent_map.end()) {
      personality_num = imdb.distanceTo(source_vertex, *it) / 2;
      if (personality_num + 1 > personality_nums.size()) {
        for (int i = personality_nums.size(); i < personality_num + 1; i++) {
          personality_nums.push_back(0);
        }
      }
      personality_nums[personality_num]++;
    } else no_num++;
  }

  cout << "Personality Histogram:\n";
  cout << "-----------------------------------\n";
  cout << "Personality Number|Number Of Actors\n";
  cout << "-----------------------------------\n";
  for (int i = 0; i < personality_nums.size(); i++) {
    cout << '\t' << i << "\t  |\t" << personality_nums[i] << endl;
  }
  cout << "\t∞\t  |\t" << no_num << endl;
  cout << "-----------------------------------\n";
  return 0;
}
