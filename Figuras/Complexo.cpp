#include "Complexo.h"

#include "../Figuras.h"

/*********************************

	Figuras Complexas

**********************************/
void Complexo::preencherVertices(){
	
	if( tipo == complexoParedePedra ) vParedePedra();

}

Complexo::Complexo( tipoComplexo t ){
	int n = 0;

	this->tipo = t;

	switch( tipo ){
	case complexoParedePedra:
		n = 2*9*2 + 2*6*2;
		break;
	}

	this->guardarOBJ( n );
}

void Complexo::vParedePedra(){
	int vi = 0;
	int ni = 0;
	int ti = 0;
	
	// 2*9 trig para a parede da porta do lado de fora
	// mais 2*9 trig para a parede da porta do lado de dentro
	this->addVertex(&vi, -o, 0, o);
	this->addVertex(&vi, -o, u*6, o);
	this->addVertex(&vi, -o, u*6, -u*4);
	this->addVertex(&vi, -o, 0, o);
	this->addVertex(&vi, -o, u*6, -u*4);
	this->addVertex(&vi, -o, 0, -u*4);
	
	this->addVertex(&vi, o, 0, -u*4);
	this->addVertex(&vi, o, u*6, -u*4);
	this->addVertex(&vi, o, u*6, -o);
	this->addVertex(&vi, o, 0, -u*4);
	this->addVertex(&vi, o, u*6, -o);
	this->addVertex(&vi, o, 0, -o);
			
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
			
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);

	for(int i=8; i<36; i+=4){
		this->addVertex(&vi, -o, 0, -u*i);
		this->addVertex(&vi, -o, u*6, -u*i);
		this->addVertex(&vi, -o, u*6, -u*(i+4));
		this->addVertex(&vi, -o, 0, -u*i);
		this->addVertex(&vi, -o, u*6, -u*(i+4));
		this->addVertex(&vi, -o, 0, -u*(i+4));
		
		this->addVertex(&vi, o, 0, -u*(i+4));
		this->addVertex(&vi, o, u*6, -u*(i+4));
		this->addVertex(&vi, o, u*6, -u*i);
		this->addVertex(&vi, o, 0, -u*(i+4));
		this->addVertex(&vi, o, u*6, -u*i);
		this->addVertex(&vi, o, 0, -u*i);
			
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, -1,0,0);
		this->addNormal(&ni, 1,0,0);
		this->addNormal(&ni, 1,0,0);
		this->addNormal(&ni, 1,0,0);
		this->addNormal(&ni, 1,0,0);
		this->addNormal(&ni, 1,0,0);
		this->addNormal(&ni, 1,0,0);
			
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 1, 0);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 0, 1.5);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 1, 0);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 0, 1.5);
	}
	
	this->addVertex(&vi, -o, 0, -u*36);
	this->addVertex(&vi, -o, u*6, -u*36);
	this->addVertex(&vi, -o, u*6, -u*40-o);
	this->addVertex(&vi, -o, 0, -u*36);
	this->addVertex(&vi, -o, u*6, -u*40-o);
	this->addVertex(&vi, -o, 0, -u*40-o);
		
	this->addVertex(&vi, o, 0, -u*40-o);
	this->addVertex(&vi, o, u*6, -u*40-o);
	this->addVertex(&vi, o, u*6, -u*36);
	this->addVertex(&vi, o, 0, -u*40-o);
	this->addVertex(&vi, o, u*6, -u*36);
	this->addVertex(&vi, o, 0, -u*36);
			
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, -1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
	this->addNormal(&ni, 1,0,0);
			
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);


	// 6*2 triangulos para a parede do lado esquerdo da porta, lado de fora
	// mais 6*2 triangulos para a mesma parede, mas do lado de dentro
	this->addVertex(&vi, u*4, 0, o);
	this->addVertex(&vi, u*4, u*6, o);
	this->addVertex(&vi, -o, u*6, o);
	this->addVertex(&vi, u*4, 0, o);
	this->addVertex(&vi, -o, u*6, o);
	this->addVertex(&vi, -o, 0, o);
	
	this->addVertex(&vi, o, 0, -o);
	this->addVertex(&vi, o, u*6, -o);
	this->addVertex(&vi, u*4, u*6, -o);
	this->addVertex(&vi, o, 0, -o);
	this->addVertex(&vi, u*4, u*6, -o);
	this->addVertex(&vi, u*4, 0, -o);
			
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
			
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);

	for(int i=2; i<6; i++){
		this->addVertex(&vi, u*4*i, 0, o);
		this->addVertex(&vi, u*4*i, u*6, o);
		this->addVertex(&vi, u*4*(i-1), u*6, o);
		this->addVertex(&vi, u*4*i, 0, o);
		this->addVertex(&vi, u*4*(i-1), u*6, o);
		this->addVertex(&vi, u*4*(i-1), 0, o);
		
		this->addVertex(&vi, u*4*(i-1), 0, -o);
		this->addVertex(&vi, u*4*(i-1), u*6, -o);
		this->addVertex(&vi, u*4*i, u*6, -o);
		this->addVertex(&vi, u*4*(i-1), 0, -o);
		this->addVertex(&vi, u*4*i, u*6, -o);
		this->addVertex(&vi, u*4*i, 0, -o);
			
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,1);
		this->addNormal(&ni, 0,0,-1);
		this->addNormal(&ni, 0,0,-1);
		this->addNormal(&ni, 0,0,-1);
		this->addNormal(&ni, 0,0,-1);
		this->addNormal(&ni, 0,0,-1);
		this->addNormal(&ni, 0,0,-1);
			
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 1, 0);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 0, 1.5);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 1, 0);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5);
		this->addTextureCoord(&ti, 0, 0);
		this->addTextureCoord(&ti, 0, 1.5);
	}
	
	
	this->addVertex(&vi, u*4*6+o, 0, o);
	this->addVertex(&vi, u*4*6+o, u*6, o);
	this->addVertex(&vi, u*4*5, u*6, o);
	this->addVertex(&vi, u*4*6+o, 0, o);
	this->addVertex(&vi, u*4*5, u*6, o);
	this->addVertex(&vi, u*4*5, 0, o);
	
	this->addVertex(&vi, u*4*5, 0, -o);
	this->addVertex(&vi, u*4*5, u*6, -o);
	this->addVertex(&vi, u*4*6-o, u*6, -o);
	this->addVertex(&vi, u*4*5, 0, -o);
	this->addVertex(&vi, u*4*6-o, u*6, -o);
	this->addVertex(&vi, u*4*6-o, 0, -o);
			
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
	this->addNormal(&ni, 0,0,-1);
			
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 1, 0);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5);
	this->addTextureCoord(&ti, 0, 0);
	this->addTextureCoord(&ti, 0, 1.5);
	
}