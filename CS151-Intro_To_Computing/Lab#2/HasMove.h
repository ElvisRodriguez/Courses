//Team: JO - EL
//Author: Jonathan James
//Creation: 10.25.17
#ifndef HASMOVE_H
#define HASMOVE_H

#include "Archive.h"

bool hasMove()
{
	if (a == '-' || b == '-' || c == '-' || d == '-' || e == '-' || f == '-' || g == '-' || h == '=' || i == '-'){
		return true;
	}
	return false;
}

#endif
