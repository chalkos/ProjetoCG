#include "Complexo.h"

#include "../Figuras.h"

/*********************************

	Figuras Complexas

**********************************/
void Complexo::preencherVertices(){
	
	if( tipo == complexoParedePedra ) return vParedePedra();
	if( tipo == complexoMadeiraHorizontal ) return vMadeiraHorizontal();
	if( tipo == complexoMadeiraVertical ) return vMadeiraVertical();

}

Complexo::Complexo( tipoComplexo t ){
	int n = 0;

	this->tipo = t;

	switch( tipo ){
	case complexoParedePedra:
		n = 2*9*2 // parede1
			+ 2*6*2 // parede2
			+ 2*6*2 // parede3
			+ 2*2 // parede4
			+ 2*4 // parede5
			+ 2*6 // parede6
			+ 2*4 // parede7
			+ 2*6 // parede8
			;
		break;
	case complexoMadeiraHorizontal:
		n = 0
			;
		break;
	case complexoMadeiraVertical:
		n = 0
			;
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
#pragma region parede1
	this->addVertex(&vi, -o, 0, o, -o, a, o, -o, a, -u*4);
	this->addVertex(&vi, -o, 0, o, -o, a, -u*4, -o, 0, -u*4);
	this->addVertex(&vi, o, 0, -u*4, o, a, -u*4, o, a, -o);
	this->addVertex(&vi, o, 0, -u*4, o, a, -o, o, 0, -o);
			
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);

	for(int i=8; i<36; i+=4){
		this->addVertex(&vi, -o, 0, -u*i, -o, a, -u*i, -o, a, -u*(i+4));
		this->addVertex(&vi, -o, 0, -u*i, -o, a, -u*(i+4), -o, 0, -u*(i+4));
		this->addVertex(&vi, o, 0, -u*(i+4), o, a, -u*(i+4), o, a, -u*i);
		this->addVertex(&vi, o, 0, -u*(i+4), o, a, -u*i, o, 0, -u*i);
			
		this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
		this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
		this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
		this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
			
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	}
	
	this->addVertex(&vi, -o, 0, -u*36, -o, a, -u*36, -o, a, -u*40-o);
	this->addVertex(&vi, -o, 0, -u*36, -o, a, -u*40-o, -o, 0, -u*40-o);
	this->addVertex(&vi, o, 0, -u*40+o, o, a, -u*40+o, o, a, -u*36);
	this->addVertex(&vi, o, 0, -u*40+o, o, a, -u*36, o, 0, -u*36);
			
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
#pragma endregion parede1

	// 6*2 triangulos para a parede do lado esquerdo da porta, lado de fora
	// mais 6*2 triangulos para a mesma parede, mas do lado de dentro
#pragma region parede2
	this->addVertex(&vi, u*4, 0, o, u*4, a, o, -o, a, o);
	this->addVertex(&vi, u*4, 0, o, -o, a, o, -o, 0, o);
	
	this->addVertex(&vi, o, 0, -o, o, a, -o, u*4, a, -o);
	this->addVertex(&vi, o, 0, -o, u*4, a, -o, u*4, 0, -o);
			
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);

	for(int i=2; i<6; i++){
		this->addVertex(&vi, u*4*i, 0, o, u*4*i, a, o, u*4*(i-1), a, o);
		this->addVertex(&vi, u*4*i, 0, o, u*4*(i-1), a, o, u*4*(i-1), 0, o);
		
		this->addVertex(&vi, u*4*(i-1), 0, -o, u*4*(i-1), a, -o, u*4*i, a, -o);
		this->addVertex(&vi, u*4*(i-1), 0, -o, u*4*i, a, -o, u*4*i, 0, -o);
			
		this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
		this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
		this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
		this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
			
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	}
	
	
	this->addVertex(&vi, u*4*6+o, 0, o, u*4*6+o, a, o, u*4*5, a, o);
	this->addVertex(&vi, u*4*6+o, 0, o, u*4*5, a, o, u*4*5, 0, o);
	
	this->addVertex(&vi, u*4*5, 0, -o, u*4*5, a, -o, u*4*6-o, a, -o);
	this->addVertex(&vi, u*4*5, 0, -o, u*4*6-o, a, -o, u*4*6-o, 0, -o);
			
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
#pragma endregion parede2

	// 6*2 triangulos para a parede do lado esquerdo da porta, lado de fora
	// mais 6*2 triangulos para a mesma parede, mas do lado de dentro
#pragma region parede3
	this->addVertex(&vi, -o, 0, -40*u-o, -o, a, -40*u-o, u*4, a, -40*u-o);
	this->addVertex(&vi, -o, 0, -40*u-o, u*4, a, -40*u-o, u*4, 0, -40*u-o);
	this->addVertex(&vi, u*4, 0, -40*u+o, u*4, a, -40*u+o, o, a, -40*u+o);
	this->addVertex(&vi, u*4, 0, -40*u+o, o, a, -40*u+o, o, 0, -40*u+o);
			
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);

	for(int i=2; i<6; i++){
		this->addVertex(&vi, u*4*(i-1), 0, -40*u-o, u*4*(i-1), a, -40*u-o, u*4*i, a, -40*u-o);
		this->addVertex(&vi, u*4*(i-1), 0, -40*u-o, u*4*i, a, -40*u-o, u*4*i, 0, -40*u-o);
		this->addVertex(&vi, u*4*i, 0, -40*u+o, u*4*i, a, -40*u+o, u*4*(i-1), a, -40*u+o);
		this->addVertex(&vi, u*4*i, 0, -40*u+o, u*4*(i-1), a, -40*u+o, u*4*(i-1), 0, -40*u+o);
			
		this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
		this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
		this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
		this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
			
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
		this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
		this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	}
	
	this->addVertex(&vi, u*4*5, 0, -40*u-o, u*4*5, a, -40*u-o, u*4*6+o, a, -40*u-o);
	this->addVertex(&vi, u*4*5, 0, -40*u-o, u*4*6+o, a, -40*u-o, u*4*6+o, 0, -40*u-o);
	this->addVertex(&vi, u*4*6-o, 0, -40*u+o, u*4*6-o, a, -40*u+o, u*4*5, a, -40*u+o);
	this->addVertex(&vi, u*4*6-o, 0, -40*u+o, u*4*5, a, -40*u+o, u*4*5, 0, -40*u+o);
			
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
#pragma endregion parede3

	// 2 trig para a parede pequena paralela à da porta, lado de fora
	// mais 2 trig para a mesma parede do lado de dentro
#pragma region parede4
	this->addVertex(&vi, u*24+o, 0, -u*40-o, u*24+o, a, -u*40-o, u*24+o, a, -u*36-o);
	this->addVertex(&vi, u*24+o, 0, -u*40-o, u*24+o, a, -u*36-o, u*24+o, 0, -u*36-o);
	this->addVertex(&vi, u*24-o, 0, -u*36+o, u*24-o, a, -u*36+o, u*24-o, a, -u*40+o);
	this->addVertex(&vi, u*24-o, 0, -u*36+o, u*24-o, a, -u*40+o, u*24-o, 0, -u*40+o);
			
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	this->addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	this->addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
			
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
	this->addTextureCoord(&ti, 1, 1.5, 1, 0, 0, 0);
	this->addTextureCoord(&ti, 1, 1.5, 0, 0, 0, 1.5);
#pragma endregion parede4

	// 4 triangulos para a parede comprida da casa de banho feminina
	// mais 4 triangulos para a parte interior dessa parede
#pragma region parede5
	this->addVertex(&vi,
		24*u+o, 0, -36*u-o,
		24*u+o, a, -36*u-o,
		31*u, a, -36*u-o);
	this->addVertex(&vi,
		24*u+o, 0, -36*u-o,
		31*u, a, -36*u-o,
		31*u, 0, -36*u-o);
	
	this->addVertex(&vi,
		31*u, 0, -36*u+o,
		31*u, a, -36*u+o,
		24*u-o, a, -36*u+o);
	this->addVertex(&vi,
		31*u, 0, -36*u+o,
		24*u-o, a, -36*u+o,
		24*u-o, 0, -36*u+o);
	
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	
	this->addTextureCoord(&ti, 16,1.5, 16,0, 14.25,0);
	this->addTextureCoord(&ti, 16,1.5, 14.25,0, 14.25,1.5);
	this->addTextureCoord(&ti, 14.25,1.5, 14.25,0, 16,0);
	this->addTextureCoord(&ti, 14.25,1.5, 16,0, 16,1.5);


	this->addVertex(&vi,
		31*u, 0, -36*u-o,
		31*u, a, -36*u-o,
		38*u+o, a, -36*u-o);
	this->addVertex(&vi,
		31*u, 0, -36*u-o,
		38*u+o, a, -36*u-o,
		38*u+o, 0, -36*u-o);
	
	this->addVertex(&vi,
		38*u-o, 0, -36*u+o,
		38*u-o, a, -36*u+o,
		31*u, a, -36*u+o);
	this->addVertex(&vi,
		38*u-o, 0, -36*u+o,
		31*u, a, -36*u+o,
		31*u, 0, -36*u+o);
	
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	
	this->addTextureCoord(&ti, 14.25,1.5, 14.25,0, 12.5,0);
	this->addTextureCoord(&ti, 14.25,1.5, 12.5,0, 12.5,1.5);
	this->addTextureCoord(&ti, 12.5,1.5, 12.5,0, 14.25,0);
	this->addTextureCoord(&ti, 12.5,1.5, 14.25,0, 14.25,1.5);

#pragma endregion parede5

	// 6 triangulos para a parede do fundo da casa de banho feminina
	// mais 6 triangulos para a parte interior dessa parede
#pragma region parede6
	// parede exterior
	addVertex(&vi, 38*u+o, 0, -36*u-o, 38*u+o, a, -36*u-o, 38*u+o, a, -30*u);
	addVertex(&vi, 38*u+o, 0, -36*u-o, 38*u+o, a, -30*u, 38*u+o, 0, -30*u);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 12.5,1.5, 12.5,0, 11,0);
	addTextureCoord(&ti, 12.5,1.5, 11,0, 11,1.5);
	
	addVertex(&vi, 38*u+o, 0, -30*u, 38*u+o, a, -30*u, 38*u+o, a, -24*u);
	addVertex(&vi, 38*u+o, 0, -30*u, 38*u+o, a, -24*u, 38*u+o, 0, -24*u);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 11,1.5, 11,0, 9.5,0);
	addTextureCoord(&ti, 11,1.5, 9.5,0, 9.5,1.5);
	
	addVertex(&vi, 38*u+o, 0, -24*u, 38*u+o, a, -24*u, 38*u+o, a, -18*u+o);
	addVertex(&vi, 38*u+o, 0, -24*u, 38*u+o, a, -18*u+o, 38*u+o, 0, -18*u+o);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 9.5,1.5, 9.5,0, 8,0);
	addTextureCoord(&ti, 9.5,1.5, 8,0, 8,1.5);

	// parede interior
	addVertex(&vi, 38*u-o, 0, -30*u, 38*u-o, a, -30*u, 38*u-o, a, -36*u+o);
	addVertex(&vi, 38*u-o, 0, -30*u, 38*u-o, a, -36*u+o, 38*u-o, 0, -36*u+o);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 11,1.5, 11,0, 12.5,0);
	addTextureCoord(&ti, 11,1.5, 12.5,0, 12.5,1.5);
	
	addVertex(&vi, 38*u-o, 0, -24*u, 38*u-o, a, -24*u, 38*u-o, a, -30*u);
	addVertex(&vi, 38*u-o, 0, -24*u, 38*u-o, a, -30*u, 38*u-o, 0, -30*u);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 9.5,1.5, 9.5,0, 11,0);
	addTextureCoord(&ti, 9.5,1.5, 11,0, 11,1.5);
	
	addVertex(&vi, 38*u-o, 0, -18*u-o, 38*u-o, a, -18*u-o, 38*u-o, a, -24*u);
	addVertex(&vi, 38*u-o, 0, -18*u-o, 38*u-o, a, -24*u, 38*u-o, 0, -24*u);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 8,1.5, 8,0, 9.5,0);
	addTextureCoord(&ti, 8,1.5, 9.5,0, 9.5,1.5);
#pragma endregion parede6
	
	// 4 triangulos para a parede comprida da casa de banho masculina
	// mais 4 triangulos para a parte interior dessa parede
#pragma region parede7

	// parte de fora
	this->addVertex(&vi,
		38*u+o, 0, -18*u+o,
		38*u+o, a, -18*u+o,
		31*u, a, -18*u+o);
	this->addVertex(&vi,
		38*u+o, 0, -18*u+o,
		31*u, a, -18*u+o,
		31*u, 0, -18*u+o);
	
	this->addVertex(&vi,
		31*u, 0, -18*u+o,
		31*u, a, -18*u+o,
		24*u+o, a, -18*u+o);
	this->addVertex(&vi,
		31*u, 0, -18*u+o,
		24*u+o, a, -18*u+o,
		24*u+o, 0, -18*u+o);
	
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	this->addNormal(&ni, 0,0,1, 0,0,1, 0,0,1);
	
	this->addTextureCoord(&ti, 8,1.5, 8,0, 6.25,0);
	this->addTextureCoord(&ti, 8,1.5, 6.25,0, 6.25,1.5);
	this->addTextureCoord(&ti, 6.25,1.5, 6.25,0, 4.5,0);
	this->addTextureCoord(&ti, 6.25,1.5, 4.5,0, 4.5,1.5);

	// parte interior
	this->addVertex(&vi,
		31*u, 0, -18*u-o,
		31*u, a, -18*u-o,
		38*u-o, a, -18*u-o);
	this->addVertex(&vi,
		31*u, 0, -18*u-o,
		38*u-o, a, -18*u-o,
		38*u-o, 0, -18*u-o);
	
	this->addVertex(&vi,
		24*u-o, 0, -18*u-o,
		24*u-o, a, -18*u-o,
		31*u, a, -18*u-o);
	this->addVertex(&vi,
		24*u-o, 0, -18*u-o,
		31*u, a, -18*u-o,
		31*u, 0, -18*u-o);
	
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	this->addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);
	
	this->addTextureCoord(&ti, 6.25,1.5, 6.25,0, 8,0);
	this->addTextureCoord(&ti, 6.25,1.5, 8,0, 8,1.5);
	this->addTextureCoord(&ti, 4.5,1.5, 4.5,0, 6.25,0);
	this->addTextureCoord(&ti, 4.5,1.5, 6.25,0, 6.25,1.5);
#pragma endregion parede7

	// 6 triangulos para a parede em frente à porta
	// mais 6 triangulos para a parte interior dessa parede
#pragma region parede8
	// parede exterior
	addVertex(&vi, 24*u+o, 0, -18*u+o, 24*u+o, a, -18*u+o, 24*u+o, a, -12*u);
	addVertex(&vi, 24*u+o, 0, -18*u+o, 24*u+o, a, -12*u, 24*u+o, 0, -12*u);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 4.5,1.5, 4.5,0, 3,0);
	addTextureCoord(&ti, 4.5,1.5, 3,0, 3,1.5);
	
	addVertex(&vi, 24*u+o, 0, -12*u, 24*u+o, a, -12*u, 24*u+o, a, -6*u);
	addVertex(&vi, 24*u+o, 0, -12*u, 24*u+o, a, -6*u, 24*u+o, 0, -6*u);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 3,1.5, 3,0, 1.5,0);
	addTextureCoord(&ti, 3,1.5, 1.5,0, 1.5,1.5);
	
	addVertex(&vi, 24*u+o, 0, -6*u, 24*u+o, a, -6*u, 24*u+o, a, o);
	addVertex(&vi, 24*u+o, 0, -6*u, 24*u+o, a, o, 24*u+o, 0, o);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addTextureCoord(&ti, 1.5,1.5, 1.5,0, 0,0);
	addTextureCoord(&ti, 1.5,1.5, 0,0, 0,1.5);

	// parede interior
	addVertex(&vi, 24*u-o, 0, -12*u, 24*u-o, a, -12*u, 24*u-o, a, -18*u-o);
	addVertex(&vi, 24*u-o, 0, -12*u, 24*u-o, a, -18*u-o, 24*u-o, 0, -18*u-o);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 3,1.5, 3,0, 4.5,0);
	addTextureCoord(&ti, 3,1.5, 4.5,0, 4.5,1.5);
	
	addVertex(&vi, 24*u-o, 0, -6*u, 24*u-o, a, -6*u, 24*u-o, a, -12*u);
	addVertex(&vi, 24*u-o, 0, -6*u, 24*u-o, a, -12*u, 24*u-o, 0, -12*u);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 1.5,1.5, 1.5,0, 3,0);
	addTextureCoord(&ti, 1.5,1.5, 3,0, 3,1.5);
	
	addVertex(&vi, 24*u-o, 0, -o, 24*u-o, a, -o, 24*u-o, a, -6*u);
	addVertex(&vi, 24*u-o, 0, -o, 24*u-o, a, -6*u, 24*u-o, 0, -6*u);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addNormal(&ni, -1,0,0, -1,0,0, -1,0,0);
	addTextureCoord(&ti, 0,1.5, 0,0, 1.5,0);
	addTextureCoord(&ti, 0,1.5, 1.5,0, 1.5,1.5);
#pragma endregion parede8

}

void Complexo::vMadeiraHorizontal(){
	int vi = 0;
	int ni = 0;
	int ti = 0;

}

void Complexo::vMadeiraVertical(){
	int vi = 0;
	int ni = 0;
	int ti = 0;

}