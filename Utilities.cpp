#include "Utilities.h"

#define _USE_MATH_DEFINES
#include <math.h>

void normalize(float *vec3){
	float norm = sqrt( vec3[0] * vec3[0] + vec3[1] * vec3[1] + vec3[2] * vec3[2] );
	
	vec3[0] /= norm;
	vec3[1] /= norm;
	vec3[2] /= norm;
}

void crossProduct(float *a, float *b, float *c){
	a[0] = b[1] * c[2] - c[1] * b[2];
	a[1] = b[2] * c[0] - c[2] * b[0];
	a[2] = b[0] * c[1] - c[0] * b[1];
}

float innerProduct(float *v, float *q){
	return v[0] * q[0] + v[1] * q[1] + v[2] * q[2];
}