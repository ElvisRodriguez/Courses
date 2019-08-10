#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <vector>
#include <string>
#include <iostream>

class Graph {
public:

    // CONSTRUCTOR
    Graph()  {nedges = 0; }

    // MODIFICATION MEMBER FUNCTIONS
    //adds a vertex to the graph. The index is automatically assigned.
    void add_vertex();

    //adds an edge connecting source to target
    void add_edge(int source, int target);

    // CONSTANT MEMBER FUNCTIONS
    int V( ) const { return edges.size(); }  //returns number of vertices
    int E( ) const { return nedges; }        //returns number of edges
    std::set<int> neighbors(int v) const;  //returns the vertices adjacent to vertex v
    bool contains(int v) const;   //checks if the vertex v is in the graph

    // OVERLOADED OUTPUT OPERATOR
    friend std::ostream& operator<< (std::ostream &out, const Graph &g);

private:
  int nedges;
  std::vector<std::set<int> > edges;
};

#endif
