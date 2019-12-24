//Team: <JO-EL>
//Author: <Elvis Rodriguez>
//Creation: <11-13-17>
#ifndef VELOCITY_H
#define VELOCITY_H

#include "Archive.h"

double velocity(double v,double t,double a)
{
	a = toRad(a);
	v = v * sin(a);
	double result = v + (G * t);
	return result;
}

#endif
