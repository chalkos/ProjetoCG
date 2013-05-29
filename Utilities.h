#ifndef __UTILITIES_H_INCLUDED__
#define __UTILITIES_H_INCLUDED__

#define toDegree(rad) ( (rad) * 57.2957795131 )

#define toRadian(deg) ( (deg) * 0.01745329251 )

void normalize(float *vec3);
void crossProduct(float *A, float *B, float *C);
float innerProduct(float *P, float *Q);


#endif // __UTILITIES_H_INCLUDED__