/****************************************************************
 *	Controlos:
 *	
 *	AWSD - movimento
 *	movimento do rato - olhar
 *  barra de espaços - libertar/prender o rato
 *	
 *	U/J - subir/descer a luz de testes
 *	I/K - rodar a luz de testes em volta da cena
 *	O/L - aumentar/diminuir a distancia da luz de testes à origem XZ
 *	
 *	[+] - aumentar a velocidade de movimento
 *	[-] - reduzir a velocidade de movimento
 *
 *	 Z  - alternar entre ver apenas_linhas / texturas
 *   X  - activar/desactivar Frustum Culling
 *
 *	ESC - sair da aplicação
 ****************************************************************/

#include <windows.h>
#include <glew.h>
#include <GL/glut.h>

#include <IL/il.h>


#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Input.h"
#include "Camera.h"

// Figuras
#include "Figuras.h"
#include "Textura.h"
#include "Light.h"
#include "Profiler.h"

int tipoPrimitiva = 3;

float teste = 0;

void desenharMontra(){
	
	Textura::setTextura(texRelva);
	glPushMatrix();
	glScalef(1,0.33,1);
	Figuras::desenharParedes();
	glPopMatrix();

	Textura::setTextura(texMadeira);
	glPushMatrix();
	glTranslatef(0, 250*0.33, 25);
	Figuras::desenharCandeeiroSuspenso();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 50);
	Figuras::desenharCandeeiroPe();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(20, 0, 50);
	glScalef(4,4,4);
	Figuras::desenharCadeiraSimples();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, 50);
	glScalef(4,4,4);
	Figuras::desenharCadeiraBalcao();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 0, 50);
	glScalef(3,3,3);
	Figuras::desenharMesaRectangular();
	glPopMatrix();

	// set de copos de champanhe
	Textura::setTextura(texShinyBrushedMetal);
	glPushMatrix();
	glTranslatef(60, 0, 50);
	glScalef(3,3,3);
	glTranslatef(0,6,0);
	Figuras::desenharCopoChampanhe(); //meio centro
	glTranslatef(-4,0,0);
	Figuras::desenharCopoChampanhe(); //direita
	glTranslatef(8,0,0);
	Figuras::desenharCopoChampanhe(); //esquerda
	glTranslatef(-4,0,-2);
	Figuras::desenharCopoChampanhe(); //perto centro
	glTranslatef(-4,0,0);
	Figuras::desenharCopoChampanhe(); //direita
	glTranslatef(8,0,0);
	Figuras::desenharCopoChampanhe(); //esquerda
	glTranslatef(-4,0,4);
	Figuras::desenharCopoChampanhe(); //longe centro
	glTranslatef(-4,0,0);
	Figuras::desenharCopoChampanhe(); //direita
	glTranslatef(8,0,0);
	Figuras::desenharCopoChampanhe(); //esquerda
	glTranslatef(4,0,-2);
	glPopMatrix();
	
	Textura::setTextura(texMadeira);
	glPushMatrix();
	glTranslatef(-60, 0, 30);
	glScalef(6,6,6);
	Figuras::desenharMesaRedonda();
	glPopMatrix();
	
	Textura::setTextura(texShinyBrushedMetal);
	glPushMatrix();
	glTranslatef(-60, 4*6, 30);
	Figuras::desenharCopoVinho();
	glTranslatef(6,0,0);
	Figuras::desenharCopoVinho();
	glTranslatef(-12,0,0);
	Figuras::desenharCopoVinho();
	glTranslatef(6,0,6);
	glScalef(1.4,1.4,1.4);
	Figuras::desenharGarrafaVinho();
	glPopMatrix();
	
	Textura::setTextura(texMadeira);
	glPushMatrix();
	glTranslatef(-60, 0, -30);
	glScalef(6,6,6);
	Figuras::desenharMesaEsplanada();
	glPopMatrix();

	glPushMatrix();
	Textura::setTextura(texShinyBrushedMetal);
	glTranslatef(-60, 4.1*6, -30);
	Figuras::desenharCopoSimples();
	glTranslatef(6,0,0);
	Figuras::desenharCopoSimples();
	glTranslatef(-12,0,0);
	Figuras::desenharCopoSimples();
	glTranslatef(6,0,6);
	glScalef(1.4,1.4,1.4);
	Figuras::desenharGarrafaVinho();
	glPopMatrix();
}

void renderScene(void) {
	Profiler::startFrame();
	
	Input::processInput();


	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();

	// posicionar a camara
	//Camera::lookAt(-1,0,-1);
	Camera::lookAt();

			  
	// opções
	if( Input::apenasLinhas ){
		// desactivou o culling na classe Input
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	}else{
		// activou o culling na classe Input
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	}

	// ligar e posicionar as luzes
	Light::enable(GL_LIGHTING);
	Light::enable(GL_LIGHT0);

	Light::ambiente(GL_LIGHT0, 0.2,0.2,0.2);
	Light::difusa(GL_LIGHT0, 0.9,0.9,0.9);

	//Light::posicao(GL_LIGHT0, 125*sin(Input::teste2), Input::teste1 ,110 + 125*cos(Input::teste2), 1.0);
	Light::posicao(GL_LIGHT0, Input::teste3*sin(Input::teste2), Input::teste1 ,Input::teste3*cos(Input::teste2), 1.0);
	
	glPushMatrix();
	//glTranslatef(125*sin(Input::teste2), Input::teste1 ,100 + 125*cos(Input::teste2));
	glTranslatef(Input::teste3*sin(Input::teste2), Input::teste1 ,Input::teste3*cos(Input::teste2));
	Textura::setTextura(texLava1);
	Figuras::desenharEmissorLuz();
	glPopMatrix();
	

	//double sided light
	//glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	

	Textura::setTextura(texMadeira);
	//Figuras::desenharFigura(figCilindro_r2_10camadas,1,1,1);
	//Figuras::desenharFigura(figFormaCilindricaTesteLuz,1,1,1);
	//Figuras::desenharFigura(figTesteLuz, 1,1,1);
	//Figuras::desenharFigura(figCopoVinho, 0.03,0.03,0.03);
	//Figuras::desenharMesaRedonda();
	//Figuras::desenharGarrafaVinho();
	//Figuras::desenharCandeeiroSuspenso();
	//Figuras::desenharFigura(figAbajourParaCandeeiroDePe, 1,1,1);
	//Figuras::desenharCandeeiroPe();
	//Figuras::desenharCopoSimples();
	//Figuras::desenharCopoChampanhe();
	//Figuras::desenharFigura(figPlano, 1,1,1);

	//Figuras::desenharFigura(figMesaPerna, 1, 5, 1);

	desenharMontra();

	//Figuras::desenharFigura(figCubo_10_5camadas,1,1,1);
	//Figuras::desenharFigura(figEsfera,1,1,1);
	//Figuras::desenharFigura(figGarrafaVinho, 0.2,0.2,0.2);
	
	Textura::unsetTextura();

	Light::disable(GL_LIGHTING);

	// ----------------
	// escrever texto
	// ----------------
	Camera::setOrthographicProjection();
	glColor3f(1,0,0);
	glPushMatrix();
	glLoadIdentity();
	char texto[100];
	sprintf(texto, "FPS: %.2f", Profiler::getFPS());
	Camera::renderString(5,10,0,Fonts::BITMAP_HELVETICA_10,texto);
	glPopMatrix();
	Camera::restorePerspectiveProjection();

	// End of frame
	glutSwapBuffers();
}



int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("ProjetoCG - Fase 3");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(Camera::changeSize);

// pôr aqui registo da funções do teclado e rato
	Input::init();

	// inicializar a câmara na posição: (x,y,z)
	Camera::init(0,5,-10);

	// glew init
	glewInit();

	// DevIL init
	ilInit();
	Textura::init(); //antes de inicializar as Figuras
	

	// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CCW); //esquema de mão direita


	// preparar objetos
	Figuras::init();


	Profiler::init();

	/*
	Profiler::start(proStartup);
	Sleep(5000);
	printf("passaram %d\n", Profiler::diff(proStartup));
	Profiler::pause(proStartup);
	Sleep(5000);
	printf("passaram %d\n", Profiler::diff(proStartup));
	Profiler::start(proStartup);
	Sleep(5000);
	printf("passaram %d\n", Profiler::diff(proStartup));*/




	
	// entrar no ciclo do GLUT 
	glutMainLoop();
	
	
	return 1;
}

