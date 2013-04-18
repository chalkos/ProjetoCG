#include "MesaRedonda.h"

/*********************************

	MesaRedonda

**********************************/

void MesaRedonda::preencherVertices(){
	this->revolutionSolid(x, y, this->pontos, this->fatias);
}

MesaRedonda::MesaRedonda(int detalhe){
	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;
	if( this->fatias > 100 ) this->fatias = 100;

	int i=0;
	
	/*
	0,0
	3,0
	3,0.1
	0.5,0.1
	0.5,3.9
	5,3.9
	5,4
	0,4
	*/

	this->pontos = 31;
	
	x[i++] = 0;
	

	i=0;
	y[i++] = 0;

	this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
}