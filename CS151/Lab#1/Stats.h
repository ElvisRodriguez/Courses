//Team: JO-EL
//Author: Elvis Rodriguez
//Creation: 10/16/17
#ifndef STATS_H
#define STATS_H

#include "Archive.h"

std::string stats(double x, double y, double z, double w, double v)
{
	std::stringstream sout;
	sout.precision(2);
	sout << std::fixed;
	sout << "For values\n";
	sout << "[" << x << "," << y << "," << z << "," << w << "," << v << "]\n";
	sout << "Mean\n";
	sout << mean(x,y,z,w,v) << "\n";
	sout << "Standard Deviation\n";
	sout << sqrt(variance(x, y , z, w, v) ) << "\n";
	sout << "Z-scores\n";
	zscores(x,y,z,w,v);
	sout << "[" << x << "," << y << "," << z << "," << w << "," << v << "]";

	return sout.str();
}

#endif
