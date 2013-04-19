#ifndef __CUBO_H_INCLUDED__
#define __CUBO_H_INCLUDED__

#include "CG_OBJ.h"

class Cubo : public CG_OBJ {
protected:
	///////////////////// membros
	int camadasx;
	int camadasy;
	int camadasz;
	float lado;
	
	///////////////////// herdado
	void preencherVertices();

public:
	Cubo(float lado, int camadasx, int camadasy, int camadasz);
};

#endif // __CUBO_H_INCLUDED__