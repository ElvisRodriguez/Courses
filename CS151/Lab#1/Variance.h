//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10/16/17
#ifndef VARIANCE_H
#define VARIANCE_H

#include "Archive.h"

double variance(double x, double y, double z, double w, double v)
{
	double m, result;
	m = mean(x,y,z,w,v);
	x = ( x - m );
	x = x * x;
	y = ( y - m );
	y = y * y;
	z = ( z - m );
	z = z * z;
	w = ( w - m );
	w = w * w;
	v = ( v - m );
	v = v * v;

	result = mean(x,y,z,w,v);
	return result;
}

#endif
