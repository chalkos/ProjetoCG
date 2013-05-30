#include "Plano.h"

/*********************************

	Plano

**********************************/
void Plano::preencherVertices(){
	float x2 = comprimento/camadasx;
	float z2 = largura/camadasz;
	
	comprimento /= 2;
	largura /= 2;

	int vi = 0;
	int ni = 0;
	int ti = 0;
	
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {
			
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, largura - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2 , 0.0f, largura - (j+1)*z2);
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, largura - (j+1)*z2);
		
			this->addVertex(&vi,-comprimento + i*x2, 0.0f, largura - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2, 0.0f, largura - j*z2);
			this->addVertex(&vi,-comprimento + (i+1)*x2, 0.0f, largura - (j+1)*z2);
			
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);

			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			this->addNormal(&ni, 0,1,0);
			
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 1, 1);
			this->addTextureCoord(&ti, 0, 1);
			
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 1, 1);
		}
	}
}

Plano::Plano(float comprimento, int camadasx, int camadasz){
	this->comprimento = comprimento;
	this->largura = comprimento;
	this->camadasx = camadasx;
	this->camadasz = camadasz;

	this->guardarOBJ( this->camadasx * this->camadasz * 2 );
}

Plano::Plano(float compX, float compZ, int camadasx, int camadasz){
	this->comprimento = compX;
	this->largura = compZ;
	this->camadasx = camadasx;
	this->camadasz = camadasz;

	this->guardarOBJ( this->camadasx * this->camadasz * 2 );
}