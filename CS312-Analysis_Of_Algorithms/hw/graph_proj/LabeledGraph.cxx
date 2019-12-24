#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "LabeledGraph.h"

using namespace std;

LabeledGraph::LabeledGraph(string filename) {
  nedges = 0;
  ifstream inputFile;
  inputFile.open(filename);
  string line, actor, movie_title;
  vector<string> tokens;
  if (inputFile.is_open()) {
    while (getline(inputFile, line)) {
      tokens = split_line(line, "/");
      movie_title = tokens[0];
      format_movie_string(movie_title);
      for (int i = 1; i < tokens.size(); i++) {
        actor = tokens[i];
        format_actor_string(actor);
        all_actors.insert(actor);
        add_edge(movie_title, actor);
      }
    }
  }
  inputFile.close();
}

vector<string> LabeledGraph::split_line(string line, string delimeter) {
  vector<string> tokens;
  string token;
  int previous_pos = 0;
  int current_pos = line.find(delimeter);
  while (current_pos != string::npos) {
    token = line.substr(previous_pos, current_pos - previous_pos);
    tokens.push_back(token);
    previous_pos = current_pos + delimeter.length();
    current_pos = line.find(delimeter, previous_pos);
  }
  return tokens;
}

void LabeledGraph::format_actor_string(string& name) {
  string delimiter = ", ";
  if (name.find(delimiter) != string::npos) {
    string first_name = name.substr(name.find(delimiter) + delimiter.length(),
                                    name.length());
    string last_name = name.substr(0, name.find(delimiter));
    name = first_name + " " + last_name;
  }
}

void LabeledGraph::format_movie_string(string& title) {
  string comma = ", ";
  string space = " ";
  if (title.find(comma) != string::npos) {
    string title_end = title.substr(0, title.find(comma));
    string title_begin = title.substr(title.find(comma) + comma.length(),
                         title.length());
    string title_year = title_begin.substr(title_begin.find(space) + space.length(),
                                           title_begin.length());
    title_begin = title_begin.substr(0, title_begin.find(space));
    title = title_begin + " " + title_end + " " + title_year;
  }
}

void LabeledGraph::addDistance(int vertex, int distance) {
  if (vertexDistances.find(vertex) == vertexDistances.end()) {
    vertexDistances.insert(pair<int, int>(vertex, distance));
  } else {
    vertexDistances[vertex] += distance;
  }
}

void LabeledGraph::add_vertex(string vlabel){
  labels.push_back(vlabel);
  indexedLabels.insert(pair<string, int>(vlabel, V()));
  set<int> s;
  vertices.push_back(s);
}

void LabeledGraph::add_edge(string source, string target){
    if (!contains(source))
      add_vertex(source);
    if (!contains(target))
      add_vertex(target);
    vertices[indexedLabels[source]].insert(indexedLabels[target]);
    vertices[indexedLabels[target]].insert(indexedLabels[source]);
    nedges++;
}

bool LabeledGraph::contains(string vlabel) const {
  return indexedLabels.find(vlabel) != indexedLabels.end();
}

set<int> LabeledGraph::neighbors(int v) const{
    return vertices[v];
}

string LabeledGraph::label(int v) const {
    return labels[v];
}

int LabeledGraph::index(string vlabel) {
    return indexedLabels[vlabel];
}

vector<string> LabeledGraph::get_neighbors(string query_string) {
  vector<string> all_neighbors;
  set<int> query_neighbors = neighbors(index(query_string));
  set<int>::iterator it;
  for (it = query_neighbors.begin(); it != query_neighbors.end(); it++) {
    all_neighbors.push_back(labels[*it]);
  }
  return all_neighbors;
}

map<int, int> LabeledGraph::breadth_first_search(int v) {
  map<int, int> parent_map;
  queue<int> nodes;
  set<int> node_neighbors;
  unordered_set<int> visited;
  int node;
  parent_map.insert(pair<int, int>(v, -1));
  nodes.push(v);
  addDistance(v, 0);
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();
    visited.insert(node);
    node_neighbors = neighbors(node);
    set<int>::iterator it;
    for (it = node_neighbors.begin(); it != node_neighbors.end(); it++) {
      if (visited.find(*it) == visited.end()) {
        visited.insert(*it);
        nodes.push(*it);
        parent_map.insert(pair<int, int>(*it, node));
        addDistance(*it, vertexDistances[node] + 1);
      }
    }
  }
  return parent_map;
}

vector<int> LabeledGraph::pathTo(map<int, int>& parent_map, int target) {
  vector<int> path;
  stack<int> temp_path;
  if (parent_map.find(target) != parent_map.end()) {
    int current_node = target;
    while (parent_map[current_node] != -1) {
      temp_path.push(current_node);
      current_node = parent_map[current_node];
    }
    while (!temp_path.empty()) {
      path.push_back(temp_path.top());
      temp_path.pop();
    }
  }
  return path;
}

vector<int> LabeledGraph::secondPathTo(int source, int target) {
  map<int, int> parent_map;
  queue<int> nodes;
  set<int> node_neighbors;
  unordered_set<int> visited;
  int node;
  parent_map.insert(pair<int, int>(source, -1));
  nodes.push(source);
  while (!nodes.empty()) {
    node = nodes.front();
    nodes.pop();
    visited.insert(node);
    node_neighbors = neighbors(node);
    set<int>::iterator it;
    stack<int> reverse_neighbors;
    for (it = node_neighbors.begin(); it != node_neighbors.end(); it++) {
      reverse_neighbors.push(*it);
    }
    while (!reverse_neighbors.empty()) {
      if (visited.find(reverse_neighbors.top()) == visited.end()) {
        if (reverse_neighbors.top() == target) {
          parent_map.insert(pair<int, int>(target, node));
          return pathTo(parent_map, target);
        }
        visited.insert(reverse_neighbors.top());
        nodes.push(reverse_neighbors.top());
        parent_map.insert(pair<int, int>(reverse_neighbors.top(), node));
      }
      reverse_neighbors.pop();
    }
  }
}

int LabeledGraph::distanceTo(string source, string target) {
  return vertexDistances[index(target)] - vertexDistances[index(source)];
}

ostream& operator<< (ostream &out, const LabeledGraph &g) {
  out << "======================================\n";
  out << "Graph Summary: " << g.V() << " vertices, ";
  out << g.E() << " edges\n";
  out << "======================================\n";
  for (int i = 0; i < g.labels.size(); i++) {
    out << g.labels[i] << endl;
    set<int>::iterator it;
    for (it = g.neighbors(i).begin(); it != g.neighbors(i).end(); it++) {
      out << '\t' << g.labels[*it] << endl;
    }
  }
  return out;
}
