#ifndef __PLANO_H_INCLUDED__
#define __PLANO_H_INCLUDED__

#include "CG_OBJ.h"

class Plano : public CG_OBJ {
protected:
	///////////////////// membros
	int camadasx;
	int camadasz;
	float comprimento; //x
	float largura; //z
	
	///////////////////// herdado
	void preencherVertices();

public:
	Plano(float comprimento, int camadasx, int camadasz);
	Plano(float compX, float compZ, int camadasx, int camadasz);
};

#endif // __PLANO_H_INCLUDED__