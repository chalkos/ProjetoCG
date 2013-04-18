#include "Copo.h"

/*********************************

	Copo

**********************************/

void Copo::preencherVertices(){
	this->revolutionSolid(x, y, this->pontos, this->fatias);
}

Copo::Copo(int tipo, int detalhe){
	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;
	if( this->fatias > 100 ) this->fatias = 100;

	int i=0;
	
	if( tipo == 1 ){ // copo simples
		this->pontos = 6;

		x[i++] = 0;
		x[i++] = 2;
		x[i++] = 2.5;
		x[i++] = 2.4;
		x[i++] = 1.9;
		x[i++] = 0;

		i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 5;
		y[i++] = 5;
		y[i++] = 0.1;
		y[i++] = 0.1;
	} else if( tipo == 2 ){ // champagne flute
		this->pontos = 41;
		
		x[i++] = 0;
		x[i++] = 37;
		x[i++] = 37;
		x[i++] = 28;
		x[i++] = 19;
		x[i++] = 11;
		x[i++] = 7;
		x[i++] = 5;
		x[i++] = 4;
		x[i++] = 4;
		x[i++] = 5;
		x[i++] = 8;
		x[i++] = 11;
		x[i++] = 14;
		x[i++] = 18;
		x[i++] = 21;
		x[i++] = 24;
		x[i++] = 26;
		x[i++] = 27;
		x[i++] = 27;
		x[i++] = 27;
		x[i++] = 27;
		x[i++] = 26;
		x[i++] = 25;
		x[i++] = 23;
		x[i++] = 22;
		//dentro
		x[i++] = 22;
		x[i++] = 24;
		x[i++] = 25;
		x[i++] = 26;
		x[i++] = 26;
		x[i++] = 26;
		x[i++] = 24;
		x[i++] = 22;
		x[i++] = 20;
		x[i++] = 17;
		x[i++] = 14;
		x[i++] = 10;
		x[i++] = 7;
		x[i++] = 5;
		x[i++] = 0;

		i=0;
		y[i++] = 0;
		y[i++] = 0;
		y[i++] = 3;
		y[i++] = 4;
		y[i++] = 8;
		y[i++] = 13;
		y[i++] = 21;
		y[i++] = 32;
		y[i++] = 57;
		y[i++] = 94;
		y[i++] = 103;
		y[i++] = 112;
		y[i++] = 115;
		y[i++] = 119;
		y[i++] = 125;
		y[i++] = 131;
		y[i++] = 139;
		y[i++] = 148;
		y[i++] = 158;
		y[i++] = 175;
		y[i++] = 187;
		y[i++] = 199;
		y[i++] = 207;
		y[i++] = 217;
		y[i++] = 230;
		y[i++] = 234;
		// dentro
		y[i++] = 230;
		y[i++] = 217;
		y[i++] = 207;
		y[i++] = 199;
		y[i++] = 175;
		y[i++] = 168;
		y[i++] = 162;
		y[i++] = 155;
		y[i++] = 149;
		y[i++] = 143;
		y[i++] = 137;
		y[i++] = 132;
		y[i++] = 130;
		y[i++] = 129;
		y[i++] = 129;
	}

	//este cálculo está mal. com o cálice deu 1170, mas ao fazer o cálice só preencheu 1156 triangulos
	//lógica:
	//existe uma junção no topo e no fundo, nessa junção só existe 1 triangulo por fatia
	// como é topo e base = 2, logo fatias * 2
	// para cada fatia, imaginando este objecto:
	//  _
	//   \
	//   <
	//  _/
	//  temos 7 coordenadas, não contando com os triangulos do topo e da base dá: fatias * (7-3) * 2, porque ele vai estar a meter pares de triangulos
	this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
}