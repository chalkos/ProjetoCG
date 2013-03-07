#include "Utilities.h"

#define _USE_MATH_DEFINES
#include <math.h>

float toDegree(float radian){
	return radian * 180 / M_PI;
}

float toRadian(float degree){
	return degree * M_PI / 180;
}