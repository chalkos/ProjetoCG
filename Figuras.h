#ifndef __FIGURAS_H_INCLUDED__
#define __FIGURAS_H_INCLUDED__

#include "Figuras\CG_OBJ.h"

#define u 10 // undidade
#define m 5 // metade
#define q 2.5 // um quarto
#define o 1.25 // um oitavo
#define p 0.01 // distancia pequena

enum indiceFiguras {
	figParedePedra,
	figRelva,
	
	figEmissorLuz,

	// não acrescentar nada depois deste elemento
	figCOUNT_ENUM
};

class Figuras{
private:
	static CG_OBJ *objetos;

public:
	static void init();
	static void desenharFigura(int indice, float scaleX, float scaleY, float scaleZ);
	
	static void desenharEmissorLuz();
	//static void desenhar
	static void desenharParedePedra();
};



#endif // __FIGURAS_H_INCLUDED__