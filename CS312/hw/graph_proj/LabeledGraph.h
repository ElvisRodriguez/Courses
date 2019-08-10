#ifndef LABELED_GRAPH_H
#define LABELED_GRAPH_H

#include <set>
#include <map>
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>

class LabeledGraph {
public:

    // CONSTRUCTOR
    LabeledGraph()  {nedges = 0; }

    // 2nd CONSTRUCTOR
    LabeledGraph(std::string filename);

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex with a specifc label
    void add_vertex(std::string vlabel);

    //adds an edge from vertex with source label to vertex with target label
    void add_edge(std::string source, std::string target);

    //Returns a list of string vertices adjacent to the vertex query_string
    std::vector<std::string> get_neighbors(std::string query_string);

    //Performs a breadth first search with root node v returning the parent map
    std::map<int, int> breadth_first_search(int v);

    //Returns the path (as a vector) from source int to target int
    std::vector<int> pathTo(std::map<int, int>& parent_map, int target);

    //Finds secondary shortest path from source to vector
    std::vector<int> secondPathTo(int source, int target);

    //Returns the number of edges between a source and target vertex
    int distanceTo(std::string source, std::string target);

    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return vertices.size(); } //number of vertices
    unsigned long long int E( ) const { return nedges; }       //number of edges
    bool contains(std::string vlabel) const;     //does graph contain vertex with label vlabel?
    std::set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    std::string label(int v) const;     //returns the label of vertex v
    int index(std::string vlabel);           //returns the index of the vertex with label vlabel

    // Public Data Members

    // All vertices in movies.txt that are actors
    std::set<std::string> all_actors;

    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const LabeledGraph &g);

private:
  // changed nedges to larger int value to handle overflows
  unsigned long long int nedges;
  std::vector<std::set<int> > vertices;
  std::vector<std::string> labels;
  std::map<std::string, int> indexedLabels;
  std::unordered_map<int, int> vertexDistances;

  //Adds distance between source/target vertex
  void addDistance(int source, int distance);

  //Returns a vector of delimater separated tokens from line string
  std::vector<std::string> split_line(std::string line, std::string delimeter);

  //Reformat actor strings to be in 'firstname lastname' format
  void format_actor_string(std::string& name);

  //Reformat movie strings to be in 'title (year)' format
  void format_movie_string(std::string& title);
};

#endif
