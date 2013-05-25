#ifndef __UTILITIES_H_INCLUDED__
#define __UTILITIES_H_INCLUDED__

#include <math.h>

#define toDegree(rad) \
	( (rad) * 180 / M_PI )

#define toRadian(deg) \
	( (deg) * M_PI / 180 )

void normalize(float *vec3);
void crossProduct(float *a, float *b, float *c);
float innerProduct(float *v, float *q);


#endif // __UTILITIES_H_INCLUDED__