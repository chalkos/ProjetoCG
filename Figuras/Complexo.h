#ifndef __COMPLEXO_H_INCLUDED__
#define __COMPLEXO_H_INCLUDED__

#include "CG_OBJ.h"
#include "../Vec3.h"

enum tipoComplexo {
	complexoParedePedra,
	complexoMadeiraVertical,
	complexoMadeiraHorizontal,
	complexoMesasRedondasBaixo,
};

class Complexo : public CG_OBJ {
private:
	///////////////////// membros
	tipoComplexo tipo;

	int vi;
	int ni;
	int ti;

	///////////////////// os vários modelos
	void vParedePedra();

	void vMadeiraHorizontal();
	void vMadeiraVertical();
	void vAuxMadeiraPlacas(Vec3 posicao, Vec3 tamanho, float angulo, Vec3 texCoordsEnd);
	void vAuxMadeiraPlacas(Vec3 posicao, Vec3 tamanho, float angulo, Vec3 texCoordsBegin, Vec3 texCoordsEnd);

	void vMesasRedondasBaixo();

protected:
	
	///////////////////// herdado
	void preencherVertices();

public:
	Complexo(tipoComplexo t);
};

#endif // __COMPLEXO_H_INCLUDED__