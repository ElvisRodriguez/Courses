//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10/30/17
#ifndef MAKEMOVE_H
#define MAKEMOVE_H

#include "Archive.h"

bool makeMove(int position,char token)
{
	if (position == 1 && grid[0] == '-') {
		grid[0] = token;
		return true;
	} else if (position == 2 && grid[1] == '-') {
		grid[1] = token;
		return true;
	} else if (position == 3 && grid[2] == '-') {
		grid[2] = token;
		return true;
	} else if (position == 4 && grid[3] == '-') {
		grid[3] = token;
		return true;
	} else if (position == 5 && grid[4] == '-') {
		grid[4] = token;
		return true;
	} else if (position == 6 && grid[5] == '-') {
		grid[5] = token;
		return true;
	} else if (position == 7 && grid[6] == '-') {
		grid[6] = token;
		return true;
	} else if (position == 8 && grid[7] == '-') {
		grid[7] = token;
		return true;
	} else if (position == 9 && grid[8] == '-') {
		grid[8] = token;
		return true;
	} else {
		return false;
	}
}

#endif
