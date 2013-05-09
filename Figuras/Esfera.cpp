#include "Esfera.h"

#define _USE_MATH_DEFINES
#include <math.h>

/*********************************

	Esfera

**********************************/
void Esfera::preencherVertices(){
	this->invertTextureCoords = true;

	float alpha = 2 * M_PI / fatias;
	float beta = M_PI / seccoes;

	int vi = 0;
	int ni = 0;
	int ti = 0;
	float posi = 0;
	float posiNext = 0;

	// desenhar a parte de baixo
	float i = -(seccoes/2.0f);
	posi = 1- (i + (seccoes/2.0f))/seccoes;
	posiNext = 1- (i +1 + (seccoes/2.0f))/seccoes;
	for(int j=0; j < fatias; j++){
		this->addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		this->addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		this->addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));

		this->addNormal(&ni,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		this->addNormal(&ni,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		this->addNormal(&ni,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));

		this->addTextureCoord(&ti, posi, j/(float)fatias);
		this->addTextureCoord(&ti, posiNext, (j+1)/(float)fatias);
		this->addTextureCoord(&ti, posiNext, j/(float)fatias);
	}

	// desenhar as secções intermédias
	for(i++; i < (seccoes/2.0f)-1; i+=1){
		posi = 1- (i + (seccoes/2.0f))/seccoes;
		posiNext = 1- (i +1 + (seccoes/2.0f))/seccoes;

		for(int j=0; j < fatias; j++){
			this->addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			this->addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
			this->addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));

			this->addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			this->addVertex(&vi,raio * cos(beta*i) * sin(alpha*(j+1)), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*(j+1)));
			this->addVertex(&vi,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));

			// normais
			this->addNormal(&ni,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			this->addNormal(&ni,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
			this->addNormal(&ni,raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));

			this->addNormal(&ni,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			this->addNormal(&ni,raio * cos(beta*i) * sin(alpha*(j+1)), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*(j+1)));
			this->addNormal(&ni,raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));

			// texturas
			this->addTextureCoord(&ti, posi, j/(float)fatias);
			this->addTextureCoord(&ti, posiNext, (j+1)/(float)fatias);
			this->addTextureCoord(&ti, posiNext, j/(float)fatias);
		
			this->addTextureCoord(&ti, posi, j/(float)fatias);
			this->addTextureCoord(&ti, posi, (j+1)/(float)fatias);
			this->addTextureCoord(&ti, posiNext, (j+1)/(float)fatias);
		}
	}

	// desenhar a secção de cima
	i += 1;
	posi = 1- (i + (seccoes/2.0f))/seccoes;
	posiNext = 1- (i -1 + (seccoes/2.0f))/seccoes;
	for(int j=0; j < fatias; j++){
		this->addVertex(&vi,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		this->addVertex(&vi,raio * cos(beta*(i-1)) * sin(alpha*j), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*j));
		this->addVertex(&vi,raio * cos(beta*(i-1)) * sin(alpha*(j+1)), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*(j+1)));
		
		this->addNormal(&ni,raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		this->addNormal(&ni,raio * cos(beta*(i-1)) * sin(alpha*j), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*j));
		this->addNormal(&ni,raio * cos(beta*(i-1)) * sin(alpha*(j+1)), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*(j+1)));

		this->addTextureCoord(&ti, posi, j/(float)fatias);
		this->addTextureCoord(&ti, posiNext, j/(float)fatias);
		this->addTextureCoord(&ti, posiNext, (j+1)/(float)fatias);
	}
}

Esfera::Esfera(float raio, unsigned fatias, unsigned seccoes){
	this->invertTextureCoords = false;
	this->raio = raio;
	this->fatias = fatias;
	this->seccoes = seccoes;

	this->guardarOBJ( 2 * this->fatias + (this->seccoes-2) * this->fatias * 2);
}