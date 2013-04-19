#ifndef __FIGURAS_H_INCLUDED__
#define __FIGURAS_H_INCLUDED__

#include "Figuras\CG_OBJ.h"

class Figuras{
private:
	static CG_OBJ objetos[];

public:
	static void init();
	static void desenharFigura(int indice);

	static void desenharParedes();//
	static void desenharCopoChampanhe();//
	static void desenharCopoSimples();
	static void desenharCopoVinho();//
	static void desenharGarrafaVinho();//
	static void desenharMesaRectangular();//
	static void desenharMesaEsplanada();
	static void desenharMesaRedonda();//
	static void desenharCadeiraSimples();//
	static void desenharCadeiraBalcao();//
	static void desenharCandeeiroSuspenso();//
	static void desenharCandeeiroPe();//
};



#endif // __FIGURAS_H_INCLUDED__