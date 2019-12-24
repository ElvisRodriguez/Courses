//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10/30/17
#ifndef WINNER_H
#define WINNER_H

#include "Archive.h"

bool winner()
{
  if (horizontalWinner() == 1) {
		 return true;
	 }

	//diagonalWinner()
	if ( (grid[0] == grid[4] && grid[4] == grid[8] && grid[0] == grid[8]) && ( (grid[0] != '-') && (grid[4] != '-') && (grid[8] != '-') ) ) {
		return true;
	} else if ( (grid[2] == grid[4] && grid[4] == grid[6] && grid[2] == grid[6]) && ( (grid[2] != '-') && (grid[4] != '-') && (grid[6] != '-') ) ) {
		return true;
	}

	//verticalWinner()
	if ( (grid[0] == grid[3] && grid[3] == grid[6] && grid[0] == grid[6]) && ( (grid[0] != '-') && (grid[3] != '-') && (grid[6] != '-') ) ) {
		return true;
	} else if ( (grid[1] == grid[4] && grid[4] == grid[7] && grid[1] == grid[7]) && ( (grid[1] != '-') && (grid[4] != '-') && (grid[7] != '-') ) ) {
		return true;
	} else if ( (grid[2] == grid[5] && grid[5] == grid[8] && grid[2] == grid[8]) && ( (grid[2] != '-') && (grid[5] != '-') && (grid[8] != '-') ) ) {
		return true;
	} else {
		return false;
	}
}

#endif
