#ifndef __ESFERA_H_INCLUDED__
#define __ESFERA_H_INCLUDED__

#include "CG_OBJ.h"

class Esfera : public CG_OBJ {
protected:
	///////////////////// membros
	float raio;
	int fatias;
	int seccoes;
	
	///////////////////// herdado
	void preencherVertices();

public:
	Esfera(float raio, unsigned fatias, unsigned seccoes);
};

#endif // __ESFERA_H_INCLUDED__