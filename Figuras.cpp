#include <glew.h>
#include <GL/glut.h>

#include "Figuras.h"

#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\Copo.h"

CG_OBJ Figuras::objetos[50];

void Figuras::init(){
	CG_OBJ::prepararBuffer(50);
	objetos[0] = Cubo(250, 25, 25); // paredes
	objetos[1] = Copo(2,15);
}

void Figuras::desenharFigura(int indice){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	objetos[indice].desenhar();
	glPopMatrix();
}

void Figuras::desenharParedes(){
	glPushMatrix();
	glColor3f(1.0, 0, 0);
	glTranslatef(0, 250/2, 0);
	objetos[0].desenhar();
	glPopMatrix();
}