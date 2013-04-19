#ifndef __SOLIDOREVOLUCAO_H_INCLUDED__
#define __SOLIDOREVOLUCAO_H_INCLUDED__

#include "CG_OBJ.h"

enum TipoSolidoRevolucao { mesa, garrafa, candeeiro, abajour };

class SolidoRevolucao : public CG_OBJ {
private:
	int fatias;
	bool fechado;

	float x[100];
	float y[100];
	int pontos;

	///////////////////// herdado
	void preencherVertices();

public:
	SolidoRevolucao(TipoSolidoRevolucao tipo, int detalhe);
};

#endif // __SOLIDOREVOLUCAO_H_INCLUDED__