#include <iostream>
#include <stack>

#ifndef MAZEPATH_H
#define MAZEPATH_H

class MazePath {

    public:
       const static std::string DIRECTIONS;
       const static std::string COMPLEMENTS;

      //CONSTRUCTORS
      MazePath();
      MazePath(std::string steps);

      //takes a step further into the maze
      void takeStep(char step);

      //returns the sequence of steps to get back to the starting point
      std::string directionsOut();

      //overloaded output operator
      friend std::ostream& operator<< (std::ostream &out, const MazePath &mazepath);

      // overloaded assignment operator
      MazePath& operator= (const std::string &m);

  private:
     std::stack<char> path;
     std::string strPath;

};

#endif
