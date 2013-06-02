
#include <stdlib.h>
#include "SolidoDistorcao.h"
#include <iostream>
#include <conio.h>

/*********************************

	SolidoDistorcao

**********************************/

void SolidoDistorcao::preencherVertices(){
	this->distortionSolid(centros, raio, indice, fatias);
}

SolidoDistorcao::SolidoDistorcao(TipoSolidoDistorcao tipo, float raio, int detalhe){
	this->indice = 0;
	this->pontos = 0;
	this->fatias = detalhe;
	if( this->fatias < 3 ) this->fatias = 3;

	
	switch (tipo){
	case pernaDeMesa:
		
		this->centros[indice++] = Vec3(0,0,0);
		this->centros[indice++] = Vec3(0,10,0);
		
		break;
	default:
		return;
	}

	this->pontos = indice;

	comprimento = 0;
	for(int i=0; i<this->pontos-1; i++)
		comprimento += sqrt(
			(centros[i+1].X() - centros[i].X())*(centros[i+1].X() - centros[i].X()) + 
			(centros[i+1].Y() - centros[i].Y())*(centros[i+1].Y() - centros[i].Y()) + 
			(centros[i+1].Z() - centros[i].Z())*(centros[i+1].Z() - centros[i].Z()));
		
	this->guardarOBJ( this->fatias * 2 + (this->fatias) * (this->pontos-3) * 2 );
}