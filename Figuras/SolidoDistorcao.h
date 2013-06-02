#ifndef __SOLIDODISTORCAO_H_INCLUDED__
#define __SOLIDODISTORCAO_H_INCLUDED__

#include "CG_OBJ.h"
#include "../Vec3.h"

enum TipoSolidoDistorcao { pernaDeMesa };

class SolidoDistorcao : public CG_OBJ {
private:
	int fatias;

	Vec3 centros[100];
	int pontos;
	int indice;
	float raio;

	///////////////////// herdado
	void preencherVertices();

public:
	SolidoDistorcao(TipoSolidoDistorcao tipo, float raio, int detalhe);
};

#endif // __SOLIDODISTORCAO_H_INCLUDED__