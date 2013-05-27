#include <stdlib.h>

#include <glew.h>
#include <GL/glut.h>

#include "Figuras.h"

#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\SolidoRevolucao.h"
#include "Figuras\Complexo.h"

#include "Textura.h"

CG_OBJ *Figuras::objetos = NULL;

void Figuras::init(){
	Figuras::objetos = (CG_OBJ*)malloc(sizeof(CG_OBJ) * figCOUNT_ENUM);

	CG_OBJ::prepararBuffer(figCOUNT_ENUM);

	objetos[figParedePedra] = Complexo( complexoParedePedra );
	objetos[figRelva] = Plano(4*50*u, 50, 50);

	// "sol"
	objetos[figEmissorLuz] = Esfera( 2, 20, 20 );
	objetos[figEmissorLuz].setAmbiente(0,0,0);
	objetos[figEmissorLuz].setDifusa(0,0,0);
	objetos[figEmissorLuz].setEspecular(0,0,0);
	objetos[figEmissorLuz].setEmissiva(1,1,1);

	/*
	// definição de propriedades do material
	
	// copos e garrafa
	objetos[figCopoChampanhe].setEspecular(1,1,1);
	objetos[figCopoChampanhe].setShininess(100);
	objetos[figCopoSimples].setEspecular(1,1,1);
	objetos[figCopoSimples].setShininess(100);
	objetos[figCopoVinho].setEspecular(1,1,1);
	objetos[figCopoVinho].setShininess(100);
	objetos[figGarrafaVinho].setDifusa(0.14,0.33,0.14);
	objetos[figGarrafaVinho].setEspecular(1,1,1);
	objetos[figGarrafaVinho].setShininess(100);*/
}

void Figuras::desenharFigura(int indice, float scaleX, float scaleY, float scaleZ){
	glPushMatrix();
	glScalef(scaleX, scaleY, scaleZ);
	objetos[indice].desenhar();
	glPopMatrix();

}

void Figuras::desenharEmissorLuz(){
	glPushMatrix();
	int tempo = glutGet(GLUT_ELAPSED_TIME);
	Textura::translate(tempo/(float)10000/2,tempo/(float)10000);
	objetos[figEmissorLuz].desenhar();

	glPopMatrix();
	Textura::setTextura(1,1,0);
}


void Figuras::desenharParedePedra(){
	Textura::setTextura(TipoTextura::texRelva, 20, 20);
	objetos[figRelva].desenhar();

	Textura::setTextura(TipoTextura::texParedePedra);
	objetos[figParedePedra].desenhar();
}