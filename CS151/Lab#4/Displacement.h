//Team: <JO-EL>
//Author: <Elvis Rodriguez>
//Creation: <11-13-17>
#ifndef DISPLACEMENT_H
#define DISPLACEMENT_H

#include "Archive.h"

double displacement(double v,double t,double a)
{
	a = toRad(a);
	v = v * cos(a);
	double result = (v * t);
	return result;
}

#endif
