#ifndef __FIGURAS_H_INCLUDED__
#define __FIGURAS_H_INCLUDED__

#include "Figuras\CG_OBJ.h"

enum indiceFiguras {
	// paredes
	figParedes,
	figParedeChao,
	figParedeLado,
	figParedeFrente,

	// objetos simples (formados por apenas uma figura)
	figMesaRedonda,
	figGarrafaVinho,
	figCandeeiroSuspenso,
	figCopoChampanhe,
	figCopoSimples,
	figCopoVinho,

	// mesa e cadeiras
	figCubo_10_5camadas,
	figCilindro_r2_10camadas,

	// testes luz e amostras
	figTesteLuz,
	figFormaCilindricaTesteLuz,
	figPlano,
	figEmissorLuz,

	// necess�rias para o candeeiro de pe
	figAbajourParaCandeeiroDePe,
	figCilindro_BaseDeCandeeiroDePe,
	figCilindro_TroncoDeCandeeiroDePe,
	figCilindro_SuporteDeAbajourDeCandeeiroDePe,


	// n�o acrescentar nada depois deste elemento
	figCOUNT_ENUM
};

class Figuras{
private:
	static CG_OBJ *objetos;

public:
	static void init();
	static void desenharFigura(int indice, float scaleX, float scaleY, float scaleZ);

	static void desenharParedes();
	static void desenharCopoChampanhe();
	static void desenharCopoSimples();
	static void desenharCopoVinho();
	static void desenharGarrafaVinho();
	static void desenharMesaRectangular();
	static void desenharMesaEsplanada();
	static void desenharMesaRedonda();
	static void desenharCadeiraSimples();
	static void desenharCadeiraBalcao();
	static void desenharCandeeiroSuspenso();
	static void desenharCandeeiroPe();
	static void desenharEmissorLuz();
};



#endif // __FIGURAS_H_INCLUDED__