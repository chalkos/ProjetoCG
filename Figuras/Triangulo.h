#ifndef __TRIANGULO_H_INCLUDED__
#define __TRIANGULO_H_INCLUDED__

#include "CG_OBJ.h"

class Triangulo : public CG_OBJ {
protected:
	///////////////////// membros
	float comprimento; //x
	float largura; //z
	
	///////////////////// herdado
	void preencherVertices();

public:
	Triangulo(float compX, float compZ);
};

#endif // __TRIANGULO_H_INCLUDED__