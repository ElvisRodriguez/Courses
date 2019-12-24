#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>

char a, b, c, d, e, f, g, h, i;

void initialize();
bool verticalWinner();
bool horizontalWinner();
bool diagonalWinner();
bool winner();
bool hasMove();
bool makeMove(int position,char token);
std::string board();

#endif
