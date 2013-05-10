#include <stdlib.h>

#include <glew.h>
#include <GL/glut.h>

#include "Figuras.h"

#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\SolidoRevolucao.h"

#include "Textura.h"

CG_OBJ *Figuras::objetos = NULL;

void Figuras::init(){
	Figuras::objetos = (CG_OBJ*)malloc(sizeof(CG_OBJ) * figCOUNT_ENUM);

	CG_OBJ::prepararBuffer(figCOUNT_ENUM);

	objetos[figParedes] = Cubo(250, 25,25*0.33,25); // paredes
	objetos[figParedeChao] = Plano(250, 25, 25);
	objetos[figParedeFrente] = Plano(250, 25, 25*0.33);
	objetos[figParedeLado] = Plano(250, 25*0.33, 25);
	objetos[figCopoSimples] = SolidoRevolucao(copoSimples, 50);
	objetos[figCopoChampanhe] = SolidoRevolucao(copoChampanhe, 50);
	objetos[figCopoVinho] = SolidoRevolucao(copoVinho, 50);

	objetos[figCubo_10_5camadas] = Cubo(10,5,5,5);
	objetos[figCilindro_r2_10camadas] = Cilindro(2,10,10,10);

	objetos[figTesteLuz] = SolidoRevolucao(testeLuz, 3);//Cilindro(10,60,150,150);//Esfera(10,30,30);
	objetos[figFormaCilindricaTesteLuz] = SolidoRevolucao(cilindrotesteLuz, 30);
	objetos[figEsfera] = Esfera(10, 50,50);
	objetos[figPlano] = Plano(10,1,1);

	objetos[figMesaRedonda] = SolidoRevolucao(mesa,50);
	objetos[figGarrafaVinho] = SolidoRevolucao(garrafa, 15);
	objetos[figCandeeiroSuspenso] = SolidoRevolucao(candeeiro, 50);
	objetos[figAbajourParaCandeeiroDePe] = SolidoRevolucao(abajour, 50);
	objetos[figCilindro_BaseDeCandeeiroDePe] = Cilindro(8,0.5,15,1);
	objetos[figCilindro_TroncoDeCandeeiroDePe] = Cilindro(1,30.5,8,15);
	objetos[figCilindro_SuporteDeAbajourDeCandeeiroDePe] = Cilindro(0.2,20,8, 20);
}

void Figuras::desenharFigura(int indice, float scaleX, float scaleY, float scaleZ){
	glPushMatrix();
	glColor3f(0, 1.0, 0);
	glScalef(scaleX, scaleY, scaleZ);
	objetos[indice].desenhar();
	glPopMatrix();
}

void Figuras::desenharCopoChampanhe(){
	glPushMatrix();
	glColor3f(0, 0.5, 0.5);
	glScalef(0.02,0.02,0.02);
	Textura::setTextura(1,1,0);
	objetos[figCopoChampanhe].desenhar();
	glPopMatrix();
}

void Figuras::desenharCopoSimples(){
	glPushMatrix();
	glColor3f(0.3, 0.8, 0.5);
	Textura::setTextura(1,1,0);
	objetos[figCopoSimples].desenhar();
	glPopMatrix();
}

void Figuras::desenharCopoVinho(){
	glPushMatrix();
	glColor3f(0.9, 0.1, 0.1);
	glScalef(0.015,0.015,0.015);
	Textura::setTextura(1,1,0);
	objetos[figCopoVinho].desenhar();
	glPopMatrix();
}

void Figuras::desenharGarrafaVinho(){
	glPushMatrix();
	glColor3f(1, 0.0, 0);
	glScalef(0.05,0.05,0.05);
	Textura::setTextura(1,1,90);
	objetos[figGarrafaVinho].desenhar();
	glPopMatrix();
}

void Figuras::desenharParedes(){
	glPushMatrix();
	Textura::setTextura(2,2,0);
	objetos[figParedeChao].desenhar();
	glTranslatef(0,250,0);

	glRotatef(180, 1,0,0);
	Textura::setTextura(2,2,0);
	objetos[figParedeChao].desenhar();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 0, 0, 1);
	glTranslatef(-250/2.0, -250/2.0, 0);
	Textura::setTextura(2*0.33,2,0);
	objetos[figParedeLado].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	glTranslatef(250/2.0, -250/2.0, 0);
	Textura::setTextura(2*0.33,2,0);
	objetos[figParedeLado].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -250/2.0, -250/2.0);
	Textura::setTextura(2,2*0.33,0);
	objetos[figParedeFrente].desenhar();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, -250/2.0, 250/2.0);
	Textura::setTextura(2,2*0.33,0);
	objetos[figParedeFrente].desenhar();
	glPopMatrix();


	
	
	
	/*glTranslatef(0, 250/2, 0);
	glScalef(-1,-1,-1);
	Textura::setTextura(5,5,0);
	objetos[figParedes].desenhar();*/
	glPopMatrix();
}

void Figuras::desenharMesaRedonda(){
	glColor3f(0.5,0.5,0);
	objetos[figMesaRedonda].desenhar();
}

void Figuras::desenharMesaEsplanada(){
	glPushMatrix();
	glTranslatef(0,4.05,0);glScalef(0.5,0.01,0.5);glColor3f(1,1,0);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.90,2,1.90);glScalef(0.065,0.4,0.065);glColor3f(1,0,1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.90,2,1.90);glScalef(0.065,0.4,0.065);glColor3f(1,0,1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.90,2,-1.90);glScalef(0.065,0.4,0.065);glColor3f(1,0,1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.90,2,-1.90);glScalef(0.065,0.4,0.065);glColor3f(1,0,1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
}

void Figuras::desenharMesaRectangular(){
	glColor3f(0.1,0.7,0.1);
	//tampo
	glPushMatrix();
	glTranslatef(0,5.5,0);
	glScalef(2,0.1,1);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	
	glColor3f(0.4,0.7,0);
	//pernas
	glPushMatrix();
	glScalef(0.1,0.5,0.1);
	glTranslatef(90,5,40);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.5,0.1);
	glTranslatef(-90,5,-40);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.5,0.1);
	glTranslatef(90,5,-40);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.1,0.5,0.1);
	glTranslatef(-90,5,40);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glColor3f(0,0.7,0.4);
	//barras laterias
	glPushMatrix();
	glScalef(1.7,0.1,0.01);
	glTranslatef(0,50,400);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.7,0.1,0.01);
	glTranslatef(0,50,-400);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();		

	glPushMatrix();
	glRotatef(90,0,1,0);
	glScalef(0.8,0.1,0.01);
	glTranslatef(0,50,900);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();	

	glPushMatrix();
	glRotatef(90,0,1,0);
	glScalef(0.8,0.1,0.01);
	glTranslatef(0,50,-900);
	objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
}

void Figuras::desenharCadeiraBalcao(){
	
	//pernas
	Textura::setTextura(1,3,90);
	glPushMatrix();
	glTranslatef(-1.5,5,-1.5);glScalef(0.1,1,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5,6.5,1.5);glScalef(0.1,1.30,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5,5,-1.5);glScalef(0.1,1,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5,6.5,1.5);glScalef(0.1,1.30,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();

	//reforço
	Textura::setTextura(1,1,90);
	glPushMatrix();
	glTranslatef(0,5,1.5);glRotatef(90,0,0,1);glScalef(0.1,0.3,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,5,-1.5);glRotatef(90,0,0,1);glScalef(0.1,0.3,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5,5,0);glRotatef(90,1,0,0);glScalef(0.1,0.3,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5,5,0);glRotatef(90,1,0,0);glScalef(0.1,0.3,0.1);objetos[figCilindro_r2_10camadas].desenhar();
	glPopMatrix();

	//acento
	Textura::setTextura(1,1,0);
	glPushMatrix();
	glTranslatef(0,10.05,0);glScalef(0.35,0.08,0.35);glColor3f(1,0,1);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	//costas
	glPushMatrix();
	glTranslatef(0,12.1,1.475);glScalef(0.35,0.15,0.05);glColor3f(1,1,0);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
}

void Figuras::desenharCadeiraSimples(){

	//pernas
	glPushMatrix();
	glScalef(0.02,0.3,0.02);glTranslatef(75,5,75);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.02,0.3,0.02);glTranslatef(75,5,-75);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.02,0.3,0.02);glTranslatef(-75,5,75);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glScalef(0.02,0.3,0.02);glTranslatef(-75,5,-75);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	
	//reforço
	glPushMatrix();
	glTranslatef(0,1,0);glScalef(0.3,0.02,0.02);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5,1,0);glScalef(0.01,0.02,0.3);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5,1,0);glScalef(0.01,0.02,0.3);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	//tampo
	glPushMatrix();
	glTranslatef(0,2.9,0);glScalef(0.33,0.02,0.33);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	//costas
	glPushMatrix();
	glTranslatef(1.5,5,1.5);glScalef(0.02,0.4,0.02);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5,5,1.5);glScalef(0.02,0.4,0.02);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glTranslatef(0,4,1.5);glScalef(0.3,0.08,0.01);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,5.25,1.5);glScalef(0.3,0.08,0.01);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,6.5,1.5);glScalef(0.3,0.08,0.01);objetos[figCubo_10_5camadas].desenhar();
	glPopMatrix();
}

void Figuras::desenharCandeeiroSuspenso(){
	glPushMatrix();

	glRotatef(180,1,0,0);

	glScalef(0.05,0.05,0.05);
	//glScalef(1,-1,1);
	
	Textura::setTextura(1,1,90);
	objetos[figCandeeiroSuspenso].desenhar();
	glPopMatrix();
	
	Textura::setTextura(1,1,0);
}

void Figuras::desenharCandeeiroPe(){
	glColor3f(0.4, 0.8, 0.3);
	
	
	Textura::setTextura(0.5,0.5,0);
	glPushMatrix();
	glTranslatef(0,0.25,0);
	objetos[figCilindro_BaseDeCandeeiroDePe].desenhar();
	glPopMatrix();
	
	Textura::setTextura(1,3,90);
	glPushMatrix();
	glTranslatef(0,15.75,0);
	objetos[figCilindro_TroncoDeCandeeiroDePe].desenhar();
	glPopMatrix();
	
	Textura::setTextura(1,1,0);
	glPushMatrix();
	glTranslatef(0,30.5,0);
	objetos[figAbajourParaCandeeiroDePe].desenhar();
	glPopMatrix();
	
	Textura::setTextura(1,3,90);
	glPushMatrix();
	glRotatef(90, 1, 0 , 0);
	glTranslatef(0, 0, -30.7);
	objetos[figCilindro_SuporteDeAbajourDeCandeeiroDePe].desenhar();
	glRotatef(90, 0, 0 , 1);
	objetos[figCilindro_SuporteDeAbajourDeCandeeiroDePe].desenhar();
	glPopMatrix();
	
	Textura::setTextura(1,1,0);
}
