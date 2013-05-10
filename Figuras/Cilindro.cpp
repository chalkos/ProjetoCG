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
	int ni = 0;
	int ti = 0;

	float alpha;
	float alphaDelta;

	// o topo (desenhado em y=altura/2)
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,0,altura2,0);
		this->addVertex(&vi,raio * sin(alpha), altura2, raio * cos(alpha));
		this->addVertex(&vi,raio * sin(alphaDelta), altura2, raio * cos(alphaDelta));
		
		this->addNormal(&ni, 0, 1, 0);
		this->addNormal(&ni, 0, 1, 0);
		this->addNormal(&ni, 0, 1, 0);
		
		this->addTextureCoord(&ti, 0.5, 0.5);
		this->addTextureCoord(&ti, 0.5 + 0.5*cos(alpha), 0.5 + 0.5*sin(alpha));
		this->addTextureCoord(&ti, 0.5 + 0.5*cos(alphaDelta), 0.5 + 0.5*sin(alphaDelta));

		/*this->addTextureCoord(&ti, fatia/(float)fatias, 0);
		this->addTextureCoord(&ti, fatia/(float)fatias, 1);
		this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1);*/
	}

	// as várias secções de altura (para que os triangulos nao fiquem muito esticados)
	for(int i = 0; i<seccoes; i++){
		seccao = (0.5 - (1.0/seccoes)*i) * altura;
		seccaoSeg = (0.5 - (1.0/seccoes)*(i+1)) * altura;

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,raio * sin(alpha), seccao, raio * cos(alpha));
			this->addNormal(&ni, sin(alpha), 0, cos(alpha));

			this->addVertex(&vi,raio * sin(alpha), seccaoSeg, raio * cos(alpha));
			this->addNormal(&ni, sin(alpha), 0, cos(alpha));

			this->addVertex(&vi,raio * sin(alphaDelta), seccaoSeg, raio * cos(alphaDelta));
			this->addNormal(&ni, sin(alphaDelta), 0, cos(alphaDelta));
			
			this->addTextureCoord(&ti, fatia/(float)fatias, i/(float)seccoes);
			this->addTextureCoord(&ti, fatia/(float)fatias, (i+1)/(float)seccoes);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, (i+1)/(float)seccoes);



			this->addVertex(&vi,raio * sin(alphaDelta), seccao, raio * cos(alphaDelta));
			this->addNormal(&ni, sin(alphaDelta), 0, cos(alphaDelta));

			this->addVertex(&vi,raio * sin(alpha), seccao, raio * cos(alpha));
			this->addNormal(&ni, sin(alpha), 0, cos(alpha));

			this->addVertex(&vi,raio * sin(alphaDelta), seccaoSeg, raio * cos(alphaDelta));
			this->addNormal(&ni, sin(alphaDelta), 0, cos(alphaDelta));
			
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, i/(float)seccoes);
			this->addTextureCoord(&ti, fatia/(float)fatias, i/(float)seccoes);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, (i+1)/(float)seccoes);
		}
	}

	// a base (desenhado em y= -altura/2)
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,0,-altura2,0);
		this->addVertex(&vi,raio * sin(alphaDelta), -altura2, raio * cos(alphaDelta));
		this->addVertex(&vi,raio * sin(alpha), -altura2, raio * cos(alpha));

		this->addNormal(&ni, 0, -1, 0);
		this->addNormal(&ni, 0, -1, 0);
		this->addNormal(&ni, 0, -1, 0);
		
		this->addTextureCoord(&ti, 0.5, 0.5);
		this->addTextureCoord(&ti, 0.5 + 0.5*cos(alphaDelta), 0.5 + 0.5*sin(alphaDelta));
		this->addTextureCoord(&ti, 0.5 + 0.5*cos(alpha), 0.5 + 0.5*sin(alpha));
	}
}

Cilindro::Cilindro(float raio, float altura, int fatias, int seccoes){
	this->raio = raio;
	this->altura = altura;
	this->fatias = fatias;
	this->seccoes = seccoes;

	this->guardarOBJ( 2 * this->fatias + this->fatias * this->seccoes * 2 );
}