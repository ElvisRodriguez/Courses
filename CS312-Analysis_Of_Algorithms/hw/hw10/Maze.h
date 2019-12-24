#include <string>

#ifndef MAZE_H
#define MAZE_H

class Maze
{
  public:
    static const char EMPTY = '.';
    static const char BLOCKED = 'X';
    static const char START = 'S';
    static const char END = 'G';
    static const char VISITED = 'V';

    // Creates a Maze with no blocked cells; start = (0, 0); goal = (SIZE, SIZE)
    Maze();

    // Puts obstacle on the cell (row, col)
    void blockCell(int row, int col);

    // is position (row, col) clear?
    bool isClear(int row, int col) const;

    // returns the size of the Maze
    int size() const;

    // clear the maze: erase all obstacles
    void clearAllCells();

    // sets the end cell to (col, row)
    void setEndCell(int row, int col);

    // sets the start cell to (col, row)
    void setStartCell(int row, int col);

    // resets all VISITED positions to EMPTY
    void clearVisited();

    // checks if (row,col) exists in the maze and is empty
    bool isVisitable(int row, int col);

    // find a path from S to G by backtracking
    std::string solveBacktracking();

    // overloaded output operator
    friend std::ostream& operator<< (std::ostream &out, const Maze &m);

  private:
    static const int SIZE = 7;
    char maze[SIZE][SIZE];
    int startCellRow, endCellRow, startCellCol, endCellCol;
};

#endif // MAZE_H
