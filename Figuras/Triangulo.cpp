#include "Triangulo.h"

/*********************************

	Triangulo

**********************************/
void Triangulo::preencherVertices(){
	comprimento /= 2;
	largura /= 2;

	int vi = 0;
	int ni = 0;
	int ti = 0;

	this->addVertex(&vi,
		-comprimento, 0, largura,
		comprimento, 0, largura,
		-comprimento, 0, -largura);
	this->addNormal(&ni, 0,1,0, 0,1,0, 0,1,0); 
	this->addTextureCoord(&ti, 0,1, 1,1, 0,0);
}

Triangulo::Triangulo(float compX, float compZ){
	this->comprimento = compX;
	this->largura = compZ;

	this->guardarOBJ( 1 );
}