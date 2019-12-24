#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.1415926
#define G -9.8
#define toRad(X) ((X) * PI / 180.0)

double height(double,double,double);
double displacement(double,double,double);
double velocity(double,double,double);
std::string stats(double,double,double);

#endif
