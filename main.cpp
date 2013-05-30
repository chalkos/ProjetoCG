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

#include "Textura.h"
#include "Light.h"
#include "Profiler.h"
#include "ObjectTree.h"

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
	

	
	//referencia
	glColor3f(1,1,1);
	glutSolidSphere(2, 10, 10);

	glLineWidth(20.5);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0,  0, 0);
	glVertex3f(10, 0, 0);
	
	glColor3f(0, 1, 0);
	glVertex3f(0,  0, 0);
	glVertex3f(0, 10, 0);
	
	glColor3f(0, 0, 1);
	glVertex3f(0,  0, 0);
	glVertex3f(0, 0, 10);
	glEnd();
	glLineWidth(1);

	// ligar e posicionar as luzes
	/*Light::enable(GL_LIGHTING);
	Light::enable(GL_LIGHT0);

	Light::ambiente(GL_LIGHT0, 0.2,0.2,0.2);
	Light::difusa(GL_LIGHT0, 0.9,0.9,0.9);

	//Light::posicao(GL_LIGHT0, 125*sin(Input::teste2), Input::teste1 ,110 + 125*cos(Input::teste2), 1.0);
	Light::posicao(GL_LIGHT0, Input::teste3*sin(Input::teste2), Input::teste1 ,Input::teste3*cos(Input::teste2), 1.0);
	
	
	glPushMatrix();
	//glTranslatef(125*sin(Input::teste2), Input::teste1 ,100 + 125*cos(Input::teste2));
	glTranslatef(Input::teste3*sin(Input::teste2), Input::teste1 ,Input::teste3*cos(Input::teste2));
	//Textura::setTextura(texLava1);
	//Figuras::desenharEmissorLuz();
	glutSolidSphere(5, 10, 10);
	glPopMatrix();
	*/
	
	glColor3f(1,1,1);

	

	
	ObjectTree::draw();

	
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
	sprintf_s(texto, 100, "FPS: %.2f", Profiler::getFPS());
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
	glutCreateWindow("ProjetoCG - Bar");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(Camera::changeSize);

// pôr aqui registo da funções do teclado e rato
	Input::init();

	// inicializar a câmara na posição: (x,y,z)
	Camera::init(-4, 5, -4);

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
	ObjectTree::init();


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

