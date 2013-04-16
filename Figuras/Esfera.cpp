#include "Esfera.h"

#define _USE_MATH_DEFINES
#include <math.h>

/*********************************

	Esfera

**********************************/
void Esfera::preencherVertices(){
	float alpha = 2 * M_PI / fatias;
	float beta = M_PI / seccoes;

	int vi = 0;

	// desenhar a parte de baixo
	float i = -(seccoes/2.0f);
	for(int j=0; j < fatias; j++){
		CG_OBJ::addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		CG_OBJ::addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		CG_OBJ::addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));
	}

	// desenhar as secções intermédias
	for(i++; i < (seccoes/2.0f)-1; i+=1){
		for(int j=0; j < fatias; j++){
			CG_OBJ::addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			CG_OBJ::addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
			CG_OBJ::addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));
			//continue;
			CG_OBJ::addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			CG_OBJ::addVertex(&vi,raio * cos(beta*i) * sin(alpha*(j+1)), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*(j+1)));
			CG_OBJ::addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		}
	}

	// desenhar a secção de cima
	i += 1;
	for(int j=0; j < fatias; j++){
		CG_OBJ::addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		CG_OBJ::addVertex(&vi,raio * cos(beta*(i-1)) * sin(alpha*j), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*j));
		CG_OBJ::addVertex(&vi,raio * cos(beta*(i-1)) * sin(alpha*(j+1)), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*(j+1)));
	}
}

Esfera::Esfera(float raio, unsigned fatias, unsigned seccoes){
	this->raio = raio;
	this->fatias = fatias;
	this->seccoes = seccoes;

	this->guardarOBJ( 2 * this->fatias + (this->seccoes-2) * this->fatias * 2);
}