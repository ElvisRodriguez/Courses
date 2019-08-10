//Team: JO - EL
//Author: Jonathan James
//Creation: 10.25.17
#ifndef DIAGONALWINNER_H
#define DIAGONALWINNER_H

#include "Archive.h"

bool diagonalWinner()
{
	if (( e == c && e == g && g == c) && (c != '-') && (e != '-') && (g != '-')){
		return true;
	}
	else if (( e == a && e == i && a == i) && (a != '-') && (e != '-') && (i != '-')){
		return true;
	}

	return false;
}

#endif
