#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

double mean(double x, double y, double z, double w, double v);
double variance(double x, double y, double z, double w, double v);
void zscores(double& x, double& y, double& z, double& w, double& v);
std::string stats(double x, double y, double z, double w, double v);

#endif
