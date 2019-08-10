#include <iostream>
#include "Maze.h"
#include "MazePath.h"

using namespace std;

int main() {
  Maze maze;
  MazePath path;
  maze.blockCell(1,3);
  maze.blockCell(2,3);
  cout << maze << endl;
  path = maze.solveBacktracking();
  cout << "Solution to maze: " << path.directionsOut() << endl;
}
