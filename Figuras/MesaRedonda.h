#ifndef __MESAREDONDA_H_INCLUDED__
#define __MESAREDONDA_H_INCLUDED__

#include "CG_OBJ.h"

class MesaRedonda : public CG_OBJ {
private:
	int fatias;

	float x[100];
	float y[100];
	int pontos;

	///////////////////// herdado
	void preencherVertices();

public:
	MesaRedonda(int detalhe);
};

#endif // __MESAREDONDA_H_INCLUDED__