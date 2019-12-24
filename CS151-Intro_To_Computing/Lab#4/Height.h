//Team: <JO-EL>
//Author: <Johnathan James>
//Creation: <11-13-17>
#ifndef HEIGHT_H
#define HEIGHT_H

#include "Archive.h"

double height(double v,double t,double a)
{
	a = toRad(a);
	v = v * sin(a);
	double result = (v * t) + (0.5 * G * (t * t));
	return result;
}

#endif
