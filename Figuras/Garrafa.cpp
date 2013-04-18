#include "Garrafa.h"

/*********************************

	Garrafa

**********************************/

void Garrafa::preencherVertices(){
	this->revolutionSolid(x, y, this->pontos, this->fatias);
}

Garrafa::Garrafa(int tipo, int detalhe){
	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;
	if( this->fatias > 100 ) this->fatias = 100;

	int i=0;
	
	if( tipo == 1 ){ // garrafa de vinho
		this->pontos = 31;

		x[i++] = 0; x[i++] = 33; x[i++] = 35; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36; x[i++] = 36;
		x[i++] = 36; x[i++] = 36; x[i++] = 34; x[i++] = 31; x[i++] = 27;
		x[i++] = 22; x[i++] = 18; x[i++] = 14; x[i++] = 13; x[i++] = 13;
		x[i++] = 13; x[i++] = 13; x[i++] = 13; x[i++] = 15; x[i++] = 15;
		x[i++] = 0;

		i=0;
		y[i++] = 0; y[i++] = 0; y[i++] = 3; y[i++] = 7; y[i++] = 15;
		y[i++] = 26; y[i++] = 38; y[i++] = 52; y[i++] = 65; y[i++] = 78;
		y[i++] = 91; y[i++] = 103; y[i++] = 115; y[i++] = 130; y[i++] = 145;
		y[i++] = 161; y[i++] = 172; y[i++] = 181; y[i++] = 188; y[i++] = 194;
		y[i++] = 200; y[i++] = 205; y[i++] = 211; y[i++] = 217; y[i++] = 230;
		y[i++] = 244; y[i++] = 255; y[i++] = 266; y[i++] = 266; y[i++] = 274;
		y[i++] = 274;
	} 

	this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
}