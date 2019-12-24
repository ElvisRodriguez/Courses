//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10-25-17
#ifndef HORIZONTALWINNER_H
#define HORIZONTALWINNER_H

#include "Archive.h"

bool horizontalWinner()
{
	if ( (a == b && b == c && a == c) && ( (a != '-') && (b != '-') && (c != '-') ) ) {
		return true;
	} else if ( (d == e && e == f && d == f) && ( (d != '-') && (e != '-') && (f != '-') ) ) {
		return true;
	} else if ( (g == h && h == i && g == i) && ( (g != '-') && (h != '-') && (i != '-') ) ) {
		return true;
	} else {
		return false;
	}
}

#endif
