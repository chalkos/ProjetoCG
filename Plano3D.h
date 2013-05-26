#ifndef __PLANO3D_H_INCLUDED__
#define __PLANO3D_H_INCLUDED__

#include "Vec3.h"

class Plano3D{
private:
	Vec3 normal;
	float D;
	
	Vec3 ponto;

public:
	Plano3D();
	Plano3D( Vec3 *normal, Vec3 *ponto );

	Vec3 getPonto();
	Vec3 getNormal();

	float distancia( Vec3 *ponto );
};

#endif // __PLANO3D_H_INCLUDED__