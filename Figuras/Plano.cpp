#include "Plano.h"

/*********************************

	Plano

**********************************/
void Plano::preencherVertices(){
	float x2 = comprimento/camadasx;
	float z2 = comprimento/camadasz;

	comprimento /= 2;

	int vi = 0;
	int ni = 0;
	int ti = 0;
	
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {
			
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, comprimento - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2 , 0.0f, comprimento - (j+1)*z2);
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, comprimento - (j+1)*z2);
		
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, comprimento - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2, 0.0f, comprimento - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2, 0.0f, comprimento - (j+1)*z2);
			
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);

			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasz);
			
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
		}
	}
}

Plano::Plano(float comprimento, int camadasx, int camadasz){
	this->comprimento = comprimento;
	this->camadasx = camadasx;
	this->camadasz = camadasz;

	this->guardarOBJ( this->camadasx * this->camadasz * 2 );
}