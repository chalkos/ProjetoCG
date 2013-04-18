#ifndef __FIGURAS_H_INCLUDED__
#define __FIGURAS_H_INCLUDED__

#include "Figuras\CG_OBJ.h"

class Figuras{
private:
	static CG_OBJ objetos[];

public:
	static void init();
	static void desenharParedes();
	static void desenharFigura(int indice);
	static void desenharCopoChampanhe();
	static void desenharGarrafa();
	static void desenharCadeira();
};



#endif // __FIGURAS_H_INCLUDED__