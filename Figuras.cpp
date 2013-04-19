#include <glew.h>
#include <GL/glut.h>

#include "Figuras.h"

#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\Copo.h"
#include "Figuras\SolidoRevolucao.h"

CG_OBJ Figuras::objetos[50];

void Figuras::init(){
	CG_OBJ::prepararBuffer(50);

	
	objetos[0] = Cubo(250, 25, 25, 25); // paredes
	objetos[1] = Copo(2,15);
	objetos[2] = Cubo(10,5,5,5); 
	objetos[3] = Cubo(10,5,2,10);

	objetos[20] = SolidoRevolucao(mesa,15);
	objetos[21] = SolidoRevolucao(garrafa, 15);
	objetos[22] = SolidoRevolucao(candeeiro, 15);
	objetos[23] = SolidoRevolucao(abajour, 15);
	objetos[24] = Cilindro(8,0.5,15,1);
	objetos[25] = Cilindro(1,30.5,8,15);
	objetos[26] = Cilindro(0.2,20,8, 20);

	objetos[40] = Copo(2, 15);
}

void Figuras::desenharFigura(int indice){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	//glScalef(0.05,0.05,0.05);
	//glScalef(1,-1,1);
	objetos[indice].desenhar();
	glPopMatrix();
}

void Figuras::desenharCopoChampanhe(){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	objetos[40].desenhar();
	glPopMatrix();
}

void Figuras::desenharGarrafa(){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	objetos[21].desenhar();
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

void Figuras::desenharMesa(int tipo){
	switch (tipo)
	{
		case 1: //mesa rectangular 4 pernas
			glPushMatrix();
			glTranslatef(0,5.5,0);
			glScalef(2,0.1,1);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			//pernas
			glPushMatrix();
			glScalef(0.1,0.5,0.1);
			glTranslatef(90,5,40);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			glPushMatrix();
			glScalef(0.1,0.5,0.1);
			glTranslatef(-90,5,-40);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			glPushMatrix();
			glScalef(0.1,0.5,0.1);
			glTranslatef(90,5,-40);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			glPushMatrix();
			glScalef(0.1,0.5,0.1);
			glTranslatef(-90,5,40);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			//barras laterias
			glPushMatrix();
			glScalef(1.7,0.1,0.01);
			glTranslatef(0,50,400);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();

			glPushMatrix();
			glScalef(1.7,0.1,0.01);
			glTranslatef(0,50,-400);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();		

			glPushMatrix();
			glRotatef(90,0,1,0);
			glScalef(0.8,0.1,0.01);
			glTranslatef(0,50,900);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();	

			glPushMatrix();
			glRotatef(90,0,1,0);
			glScalef(0.8,0.1,0.01);
			glTranslatef(0,50,-900);
			glColor3f(0,1,0);
			objetos[2].desenhar();
			glPopMatrix();
				
			break;

		case 2:
			glColor3f(0,1,0);
			objetos[20].desenhar();
	}

}

void Figuras::desenharCadeira(int tipo){
	switch (tipo)
	{
		case 1: //cadeira normal
			//pernas
			glPushMatrix();
			glScalef(0.02,0.3,0.02);glTranslatef(75,5,75);objetos[2].desenhar();
			glPopMatrix();
			glPushMatrix();
			glScalef(0.02,0.3,0.02);glTranslatef(75,5,-75);objetos[2].desenhar();
			glPopMatrix();
			glPushMatrix();
			glScalef(0.02,0.3,0.02);glTranslatef(-75,5,75);objetos[2].desenhar();
			glPopMatrix();
			glPushMatrix();
			glScalef(0.02,0.3,0.02);glTranslatef(-75,5,-75);objetos[2].desenhar();
			glPopMatrix();
			//reforço
			glPushMatrix();
			glTranslatef(0,1,0);glScalef(0.3,0.02,0.02);objetos[2].desenhar();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(1.5,1,0);glScalef(0.01,0.02,0.3);objetos[2].desenhar();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-1.5,1,0);glScalef(0.01,0.02,0.3);objetos[2].desenhar();
			glPopMatrix();
			//tampo
			glPushMatrix();
			glTranslatef(0,2.9,0);glScalef(0.35,0.02,0.35);objetos[2].desenhar();
			glPopMatrix();
			//costas
			glPushMatrix();
			glScalef(1,0.01,1);glTranslatef(0,0,0);objetos[2].desenhar();
			glPopMatrix();

			break;
	}
}

void Figuras::desenharCandeeiroSuspenso(){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(0.05,0.05,0.05);
	glScalef(1,-1,1);
	objetos[22].desenhar();
	glPopMatrix();
}

void Figuras::desenharCandeeiroPe(){
	glColor3f(0, 1.0, 0);
	
	glPushMatrix();
	glTranslatef(0,0.25,0);
	objetos[24].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,15.75,0);
	objetos[25].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,30.5,0);
	objetos[23].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 1, 0 , 0);
	glTranslatef(0, 0, -30.7);
	objetos[26].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 1, 0 , 0);
	glTranslatef(0, 0, -30.7);
	glRotatef(90, 0, 0 , 1);
	objetos[26].desenhar();
	glPopMatrix();
}