#ifndef __GARRAFA_H_INCLUDED__
#define __GARRAFA_H_INCLUDED__

#include "CG_OBJ.h"

class Garrafa : public CG_OBJ {
private:
	int fatias;

	float x[100];
	float y[100];
	int pontos;

	///////////////////// herdado
	void preencherVertices();

public:
	Garrafa(int tipo, int detalhe);
};

#endif // __GARRAFA_H_INCLUDED__