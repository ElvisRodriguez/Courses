#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>

char grid[9];

void initialize();
bool verticalWinner();
bool horizontalWinner();
bool diagonalWinner();
bool winner();
bool hasMove();
bool makeMove(int position,char token);
std::string board();

#endif
