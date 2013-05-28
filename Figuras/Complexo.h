#ifndef __COMPLEXO_H_INCLUDED__
#define __COMPLEXO_H_INCLUDED__

#include "CG_OBJ.h"

enum tipoComplexo {
	complexoParedePedra,
	complexoMadeiraVertical,
	complexoMadeiraHorizontal,
};

class Complexo : public CG_OBJ {
protected:
	///////////////////// membros
	tipoComplexo tipo;
	
	///////////////////// herdado
	void preencherVertices();

	///////////////////// os vários modelos
	void vParedePedra();
	void vMadeiraHorizontal();
	void vMadeiraVertical();

public:
	Complexo(tipoComplexo t);
};

#endif // __COMPLEXO_H_INCLUDED__