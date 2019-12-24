//Team: JO - EL
//Author: Jonathan James
//Creation: 10.25.17
#ifndef VERTICALWINNER_H
#define VERTICALWINNER_H

#include "Archive.h"

bool verticalWinner()
{
	if (( d == a && d == g && a == g) && (a != '-') && (d != '-') && (g != '-')){
		return true;
	}
	else if (( e == b && e == h && b == h) && (b != '-') && (e != '-') && (h != '-')){
		return true;
	}
	else if (( f == c && f == i && c == i) && (c != '-') && (f != '-') && (i != '-')){
			return true;
		}
	return false;
}

#endif
