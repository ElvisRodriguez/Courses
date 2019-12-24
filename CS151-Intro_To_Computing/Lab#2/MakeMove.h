//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10-25-17
#ifndef MAKEMOVE_H
#define MAKEMOVE_H

#include "Archive.h"

bool makeMove(int position,char token)
{
	if (position == 1 && a == '-') {
		a = token;
		return true;
	} else if (position == 2 && b == '-') {
		b = token;
		return true;
	} else if (position == 3 && c == '-') {
		c = token;
		return true;
	} else if (position == 4 && d == '-') {
		d = token;
		return true;
	} else if (position == 5 && e == '-') {
		e = token;
		return true;
	} else if (position == 6 && f == '-') {
		f = token;
		return true;
	} else if (position == 7 && g == '-') {
		g = token;
		return true;
	} else if (position == 8 && h == '-') {
		h = token;
		return true;
	} else if (position == 9 && i == '-') {
		i = token;
		return true;
	} else {
		return false;
	}

}

#endif
