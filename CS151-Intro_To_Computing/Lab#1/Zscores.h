//Team: JO-EL
//Author: Jonathan James
//Creation: 10/16/17
#ifndef ZSCORES_H
#define ZSCORES_H

#include "Archive.h"

void zscores(double& x, double& y, double& z, double& w, double& v)
{
	double mu = mean(x,y,z,w,v);
	double sig = sqrt(variance(x, y, z, w, v));

	x = (x - mu) / sig;
	y = (y - mu) / sig;
	z = (z - mu) / sig;
	w = (w - mu) / sig;
	v = (v - mu) / sig;
}

#endif
