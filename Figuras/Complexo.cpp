#include <math.h>
#include "Complexo.h"

#include "../Figuras.h"
#include "../Utilities.h"

/*********************************

	Figuras Complexas

**********************************/
void Complexo::preencherVertices(){
	
	if( tipo == complexoParedePedra ) return vParedePedra();
	if( tipo == complexoMadeiraHorizontal ) return vMadeiraHorizontal();
	if( tipo == complexoMadeiraVertical ) return vMadeiraVertical();
	if( tipo == complexoMesasRedondasBaixo ) return vMesasRedondasBaixo();

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
			+ 2   // parede9
			+ 1   // parede10
			;
		break;
	case complexoMadeiraHorizontal:
		n = 2 // lado direito da porta
			+ 2 // lado esqurdo da porta
			+ 2 //intervalo entre a primeira e segunda seccções largas
			+ 2 //ultima da parede de dentro do lado da porta
			;
		break;
	case complexoMadeiraVertical:
		n = //lado da porta
			1*2 //esquina
			+ 2*2 //lado da porta
			+ 1*2 //acima da porta
			+ 3*2 //primeira secção larga à esquerda da porta
			+ 3*2 //segunda secção larga à esquerda da porta
			//parede do lado esquerdo da porta, parte de fora
			;
		break;
	case complexoMesasRedondasBaixo:
		n = 0; //tenho que ver depois

	}

	vi = 0;
	ni = 0;
	ti = 0;

	this->guardarOBJ( 5000 ); //modificar para n
}

void Complexo::vMesasRedondasBaixo(){

	float x[20];
	float y[20];
	int j, i=0;
	
	x[i++] = 0; x[i++] = 2.5; x[i++] = 2.5; x[i++] = 2.5; x[i++] = 2.5; x[i++] = 2.5; x[i++] = 2.5; x[i++] = 0.5; x[i++] = 0.5;
	x[i++] = 0.5; x[i++] = 0.5; x[i++] = 0.5; x[i++] = 0.5; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 4; x[i++] = 0;

	j=i;  i=0;
	y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 0; y[i++] = 0.1; y[i++] = 0.1; y[i++] = 0.1; y[i++] = 0.1; y[i++] = 0.1;
	y[i++] = 0.1; y[i++] = 3.9; y[i++] = 3.9; y[i++] = 3.9; y[i++] = 3.9; y[i++] = 3.9; y[i++] = 3.9; y[i++] = 4; y[i++] = 4; y[i++] = 4; y[i++] = 4;   

	this->revolutionSolidClose(x, y, i, 30, Vec3(10,0,10), true);
}

void Complexo::vParedePedra(){
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
	
	// 2 triangulos para a parede junto à escada
#pragma region parede9
	addVertex(&vi,
		14*u+o, 0, -4*u-o,
		14*u+o, a, -4*u-o,
		14*u+o, a, -o);
	addVertex(&vi,
		14*u+o, 0, -4*u-o,
		14*u+o, a, -o,
		14*u+o, 0, -o);
	
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);
	addNormal(&ni, 1,0,0, 1,0,0, 1,0,0);

	addTextureCoord(&ti, 1.46875,1.5, 1.46875,0, 0.46875,0);
	addTextureCoord(&ti, 1.46875,1.5, 0.46875,0, 0.46875,1.5);

#pragma endregion parede 9

	// 1 triangulo para a parede por baixo da escada
#pragma region parede10
	addVertex(&vi,
		6*u, 0, -4*u-o,
		14*u+o, a, -4*u-o,
		14*u+o, 0, -4*u-o);
	
	addNormal(&ni, 0,0,-1, 0,0,-1, 0,0,-1);

	addTextureCoord(&ti, 3.46875,1.5, 1.46875,0, 1.46875,1.5);
#pragma endregion parede 10
}

void Complexo::vMadeiraHorizontal(){
	/********* parede do lado de fora da porta ******/
	//lado direito da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-q,-4*u),
		Vec3(4*u+o+p,q,0),
		-90, Vec3(0,0.5,0), Vec3(4,1,0));

	//lado esquerdo da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-q,-10*u-m),
		Vec3(2*u+m,q,0),
		-90, Vec3(0,0.5,0), Vec3(4,1,0));

	//intervalo entre a primeira e segunda seccções largas
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-q,-26*u-m),
		Vec3(7*u,q,0),
		-90, Vec3(0,0.5,0), Vec3(6,1,0));

	//ultima da parede de dentro do lado da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-q,-40*u-o-p),
		Vec3(4*u+o+m+p,q,0),
		-90, Vec3(0,0.5,0), Vec3(6,1,0));

	/********* parede do lado esquerdo da porta, parte de fora ******/
	//primeira da direita para a esquerda
	vAuxMadeiraPlacas(
		Vec3(8*u,a-q,-40*u-o-p),
		Vec3(8*u+o+p,q,0),
		180, Vec3(0,0.5,0), Vec3(16,1,0));

	//segunda da direita para a esquerda
	vAuxMadeiraPlacas(
		Vec3(16*u,a-q,-40*u-o-p),
		Vec3(8*u,q,0),
		180, Vec3(0,0.5,0), Vec3(16,1,0));
	
	//terceira da direita para a esquerda
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,-40*u-o-p),
		Vec3(8*u+o+p,q,0),
		180, Vec3(0,0.5,0), Vec3(16,1,0));
	
	//continuando para a parede de 4u
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,-36*u-o-p),
		Vec3(4*u,q,0),
		90, Vec3(0,0.5,0), Vec3(8,1,0));

	//continuando para a parede de 14u, dividida em 2
	vAuxMadeiraPlacas(
		Vec3(31*u,a-q,-36*u-o-p),
		Vec3(7*u-o-p,q,0),
		180, Vec3(0,0.5,0), Vec3(14,1,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,a-q,-36*u-o-p),
		Vec3(7*u+o+p,q,0),
		180, Vec3(0,0.5,0), Vec3(14,1,0));

	//continuando para a parede de 18u, dividida em 3
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,a-q,-30*u),
		Vec3(6*u+o+p,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,a-q,-24*u),
		Vec3(6*u,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,a-q,-18*u+o+p),
		Vec3(6*u+o+p,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));

	//continuando para a parede de 14u, dividida em 2
	vAuxMadeiraPlacas(
		Vec3(31*u,a-q,-18*u+o+p),
		Vec3(7*u+o+p,q,0),
		0, Vec3(0,0.5,0), Vec3(14,1,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,-18*u+o+p),
		Vec3(7*u-o-p,q,0),
		0, Vec3(0,0.5,0), Vec3(14,1,0));

	//continuando para a parede de 18u, dividida em 3
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,-12*u),
		Vec3(6*u-o-p,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,-6*u),
		Vec3(6*u,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,a-q,+o+p),
		Vec3(6*u+o+p,q,0),
		90, Vec3(0,0.5,0), Vec3(12,1,0));

	//continuando para a parede de 24u, dividida em 3
	vAuxMadeiraPlacas(
		Vec3(16*u,a-q,+o+p),
		Vec3(8*u+o+p,q,0),
		0, Vec3(0,0.5,0), Vec3(16,1,0));
	vAuxMadeiraPlacas(
		Vec3(8*u,a-q,+o+p),
		Vec3(8*u,q,0),
		0, Vec3(0,0.5,0), Vec3(16,1,0));
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-q,+o+p),
		Vec3(8*u+o+p,q,0),
		0, Vec3(0,0.5,0), Vec3(16,1,0));

}

void Complexo::vMadeiraVertical(){
	/********* parede do lado de fora da porta ******/
	//esquina
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,o-m),
		Vec3(m+p,a-q,0),
		-90, Vec3(1,a/(float)u,0));

	// junto à porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*4),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*8-m),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));

	//acima da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,a-u,-u*8),
		Vec3(u*4,u,0),
		-90, Vec3(8,1,0));

	//primeira secção larga à esquerda da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*10-m),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));
	
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*19-m),
		Vec3(9*u,a,0),
		-90, Vec3(18,a/(float)u,0));
	
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*20),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));

	//segunda secção larga à esquerda da porta
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*26-m),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));
	
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*36+m),
		Vec3(9*u,a,0),
		-90, Vec3(18,a/(float)u,0));
	
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-u*36),
		Vec3(m,a-q,0),
		-90, Vec3(1,a/(float)u-q,0));

	//ultima esquina do lado esquerdo
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,-40*u-o-p),
		Vec3(m+p,a-q,0),
		-90, Vec3(1,a/(float)u,0));
	
	/********* parede do lado esquerdo da porta, parte de fora ******/
	vAuxMadeiraPlacas(
		Vec3(m-o,0,-40*u-o-p),
		Vec3(m+p,a-q,0),
		180, Vec3(1,a/(float)u,0));

	// outros pilares nessa parede
	vAuxMadeiraPlacas(
		Vec3(8*u-q,0,-40*u-o-p),
		Vec3(m,a-q,0),
		180, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(16*u-q,0,-40*u-o-p),
		Vec3(m,a-q,0),
		180, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-40*u-o-p),
		Vec3(m+p,a-q,0),
		180, Vec3(1,a/(float)u,0));

	// parede seguinte, é a de 4u com apenas 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-40*u-o-p+m),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-36*u-o-p),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));

	//parede seguinte, é a de 14u com 2 divisões e 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p+m,0,-36*u-o-p),
		Vec3(m,a-q,0),
		180, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(31*u+q,0,-36*u-o-p),
		Vec3(m,a-q,0),
		180, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,0,-36*u-o-p),
		Vec3(m,a-q,0),
		180, Vec3(1,a/(float)u,0));

	//parede seguinte, é a de 18u com 3 divisoes e 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,0,-36*u-o-p+m),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,0,-30*u+q),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,0,-24*u+q),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p,0,-18*u+o+p),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));

	//parede seguinte, é a de 14u com 2 divisoes e 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(38*u+o+p-m,0,-18*u+o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(31*u-q,0,-18*u+o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-18*u+o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));

	//parede seguinte, é a de 18u com 3 divisões e 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-18*u+o+p+m),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-12*u+q),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,-6*u+q),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p,0,o+p),
		Vec3(m,a-q,0),
		90, Vec3(1,a/(float)u,0));

	//parede seguinte, é a 24u com 3 divisoes e 2 esquinas
	vAuxMadeiraPlacas(
		Vec3(24*u+o+p-m,0,o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(18*u-q,0,o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(12*u-q,0,o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(6*u-q,0,o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));
	vAuxMadeiraPlacas(
		Vec3(-o-p,0,o+p),
		Vec3(m,a-q,0),
		0, Vec3(1,a/(float)u,0));





}

void Complexo::vAuxMadeiraPlacas(Vec3 posicao, Vec3 tamanho, float angulo, Vec3 texCoordsBegin, Vec3 texCoordsEnd){
	Vec3 normal = Vec3(sin(angulo), 0, cos(angulo));
	
	angulo += 90;
	float px = sin( toRadian(angulo));
	float pz = cos( toRadian(angulo));

	//tamanho = tamanho.multiplicar(u);
	//posicao = posicao.multiplicar(u);
	
	addVertex(&vi,
		posicao.X() + tamanho.X() * px, posicao.Y(), posicao.Z() + tamanho.X() * pz,
		posicao.X() + tamanho.X() * px, posicao.Y() + tamanho.Y(), posicao.Z() + tamanho.X() * pz,
		posicao.X(), posicao.Y() + tamanho.Y(), posicao.Z());
	addVertex(&vi,
		posicao.X() + tamanho.X() * px, posicao.Y(), posicao.Z() + tamanho.X() * pz,
		posicao.X(), posicao.Y() + tamanho.Y(), posicao.Z(),
		posicao.X(), posicao.Y(), posicao.Z());

	
	addNormal(&ni, normal.X(),normal.Y(),normal.Z(), normal.X(),normal.Y(),normal.Z(), normal.X(),normal.Y(),normal.Z());
	addNormal(&ni, normal.X(),normal.Y(),normal.Z(), normal.X(),normal.Y(),normal.Z(), normal.X(),normal.Y(),normal.Z());

	addTextureCoord(&ti, texCoordsEnd.X(),texCoordsEnd.Y(), texCoordsEnd.X(),texCoordsBegin.Y(), texCoordsBegin.X(),texCoordsBegin.Y());
	addTextureCoord(&ti, texCoordsEnd.X(),texCoordsEnd.Y(), texCoordsBegin.X(),texCoordsBegin.Y(), texCoordsBegin.X(),texCoordsEnd.Y());
}

void Complexo::vAuxMadeiraPlacas(Vec3 posicao, Vec3 tamanho, float angulo, Vec3 texCoordsEnd){
	vAuxMadeiraPlacas(posicao, tamanho, angulo, Vec3(0,0,0), texCoordsEnd);
}