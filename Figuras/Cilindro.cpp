#include "Cilindro.h"

#define _USE_MATH_DEFINES
#include <math.h>

/*********************************

	Cilindro

**********************************/
void Cilindro::preencherVertices(){
	float delta = 2 * M_PI / fatias;
	float seccaos = 10;
	float seccao, seccaoSeg;

	float altura2 = altura/2;

	int vi = 0;

	// o topo (desenhado em y=altura/2)
	for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
		this->addVertex(&vi,0,altura2,0);
		this->addVertex(&vi,raio * sin(alpha), altura2, raio * cos(alpha));
		this->addVertex(&vi,raio * sin(alpha+delta), altura2, raio * cos(alpha+delta));
	}

	// as várias secções de altura (para que os triangulos nao fiquem muito esticados)
	for(int i = 0; i<seccoes; i++){
		seccao = (0.5 - (1.0/seccoes)*i) * altura;
		seccaoSeg = (0.5 - (1.0/seccoes)*(i+1)) * altura;

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			this->addVertex(&vi,raio * sin(alpha), seccao, raio * cos(alpha));
			this->addVertex(&vi,raio * sin(alpha), seccaoSeg, raio * cos(alpha));
			this->addVertex(&vi,raio * sin(alpha+delta), seccaoSeg, raio * cos(alpha+delta));
			
			this->addVertex(&vi,raio * sin(alpha+delta), seccao, raio * cos(alpha+delta));
			this->addVertex(&vi,raio * sin(alpha), seccao, raio * cos(alpha));
			this->addVertex(&vi,raio * sin(alpha+delta), seccaoSeg, raio * cos(alpha+delta));
		}
	}

	// a base (desenhado em y= -altura/2)
	for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
		this->addVertex(&vi,0,-altura2,0);
		this->addVertex(&vi,raio * sin(alpha+delta), -altura2, raio * cos(alpha+delta));
		this->addVertex(&vi,raio * sin(alpha), -altura2, raio * cos(alpha));
	}
}

Cilindro::Cilindro(float raio, float altura, unsigned fatias, unsigned seccoes){
	this->raio = raio;
	this->altura = altura;
	this->fatias = fatias;
	this->seccoes = seccoes;

	this->guardarOBJ( 2 * this->fatias + this->fatias * this->seccoes * 2 );
}