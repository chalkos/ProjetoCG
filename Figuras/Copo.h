#ifndef __COPO_H_INCLUDED__
#define __COPO_H_INCLUDED__

#include "CG_OBJ.h"

class Copo : public CG_OBJ {
private:
	int fatias;

	float x[100];
	float y[100];
	int pontos;

	///////////////////// herdado
	void preencherVertices();

public:
	Copo(int tipo, int detalhe);
};

#endif // __COPO_H_INCLUDED__