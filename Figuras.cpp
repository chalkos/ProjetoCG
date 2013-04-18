#include <glew.h>
#include <GL/glut.h>

#include "Figuras.h"

#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\Copo.h"
#include "Figuras\Garrafa.h"

CG_OBJ Figuras::objetos[50];

void Figuras::init(){
	CG_OBJ::prepararBuffer(50);
	objetos[0] = Cubo(250, 25, 25, 25); // paredes
	objetos[1] = Copo(4,15);
	objetos[2] = Garrafa(1,15);
	objetos[3] = Cubo(10,5,2,10);
}

void Figuras::desenharFigura(int indice){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	//glScalef(0.05,0.05,0.05);
	objetos[indice].desenhar();
	glPopMatrix();
}

void Figuras::desenharCopoChampanhe(){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	objetos[1].desenhar();
	glPopMatrix();
}

void Figuras::desenharGarrafa(){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	objetos[2].desenhar();
	glPopMatrix();
}

void Figuras::desenharParedes(){
	glPushMatrix();
	glColor3f(1.0, 0, 0);
	glTranslatef(0, 250/2, 0);
	glScalef(-1,-1,-1);
	objetos[0].desenhar();
	glPopMatrix();
}