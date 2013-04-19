#ifndef __CILINDRO_H_INCLUDED__
#define __CILINDRO_H_INCLUDED__

#include "CG_OBJ.h"

class Cilindro : public CG_OBJ {
protected:
	///////////////////// membros
	float raio;
	float altura;
	unsigned fatias;
	unsigned seccoes;
	
	///////////////////// herdado
	void preencherVertices();

public:
	Cilindro(float raio, float altura, int fatias, int seccoes);
};

#endif // __CILINDRO_H_INCLUDED__