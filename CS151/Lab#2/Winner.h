//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10-25-17
#ifndef WINNER_H
#define WINNER_H

#include "Archive.h"

bool winner()
{
	 if (horizontalWinner() == 1) {
		 return true;
	 }

	//diagonalWinner()
	if ( (a == e && e == i && a == i) && ( (a != '-') && (e != '-') && (i != '-') ) ) {
		return true;
	} else if ( (c == e && e == g && c == g) && ( (c != '-') && (e != '-') && (g != '-') ) ) {
		return true;
	}

	//verticalWinner()
	if ( (a == d && d == g && a == g) && ( (a != '-') && (d != '-') && (g != '-') ) ) {
		return true;
	} else if ( (b == e && e == h && b == h) && ( (b != '-') && (e != '-') && (h != '-') ) ) {
		return true;
	} else if ( (c == f && f == i && c == i) && ( (c != '-') && (f != '-') && (i != '-') ) ) {
		return true;
	} else {
		return false;
	}
}

#endif
