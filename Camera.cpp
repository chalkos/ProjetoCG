#include <iostream>
using namespace std;

#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Camera.h"

bool Camera::modoFPS = true;

// posição da câmara
float Camera::posX;
float Camera::posY;
float Camera::posZ;

// orientação horizontal e vertical
float Camera::alpha;
float Camera::beta;

float Camera::passo = 0.5;//0.20;


void Camera::moveTo(float x, float y, float z){
	Camera::posX = x;
	Camera::posY = y;
	Camera::posZ = z;
}

void Camera::lookAt(){
	// direcção da câmara usando os ângulos
	Camera::lookAt(cos(Camera::beta) * sin(Camera::alpha),
					sin(Camera::beta),
					cos(Camera::beta) * cos(Camera::alpha));
}

void Camera::lookAt(float dx, float dy, float dz){
	// transpor o mundo, rodar o mundo, colocar câmara
	gluLookAt(posX, posY, posZ,    // posição da câmara
		posX+dx, posY+dy, posZ+dz, // ponto para onde a câmara está apontada
		0.0f, 1.0f, 0.0f);         // “up vector” (0.0f, 1.0f, 0.0f)
}

void Camera::passoMaior(){
	if( Camera::passo > 0.5 )
		Camera::passo += 0.1;
	else
		Camera::passo += 0.05;

	cout << "Passo: " << Camera::passo << endl;
}

void Camera::passoMenor(){
	if( Camera::passo > 0.5 )
		Camera::passo -= 0.1;
	else if( Camera::passo > 0.10 )
		Camera::passo -= 0.05;
	else
		Camera::passo -= 0.005;
	
	if( Camera::passo <= 0.01 )
		Camera::passo = 0;
	cout << "Passo: " << Camera::passo << endl;
}

void Camera::init(float x, float y, float z){
	// posição inicial: (x,y,z)
	Camera::posX = x;
	Camera::posY = y;
	Camera::posZ = z;

	glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer((float)glutGet(GLUT_WINDOW_WIDTH)/2, (float)glutGet(GLUT_WINDOW_HEIGHT)/2);
}

void Camera::toggleFPS(){
	Camera::modoFPS = !Camera::modoFPS;
	if( Camera::modoFPS ){
		glutSetCursor(GLUT_CURSOR_NONE);
		//glutWarpPointer((float)glutGet(GLUT_WINDOW_WIDTH)/2, (float)glutGet(GLUT_WINDOW_HEIGHT)/2);
	}else{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
}




void Camera::moverFrente(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha);
	posY = posY + Camera::passo * sin(Camera::beta);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha);
}

void Camera::moverTras(){
	posX = posX - Camera::passo * cos(Camera::beta) * sin(Camera::alpha);
	posY = posY - Camera::passo * sin(Camera::beta);
	posZ = posZ - Camera::passo * cos(Camera::beta) * cos(Camera::alpha);
}

void Camera::moverEsquerda(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha+M_PI_2);
	//posY = posY + Camera::passo * sin(Camera::beta);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha+M_PI_2);
}

void Camera::moverDireita(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha-M_PI_2);
	//posY = posY + Camera::passo * sin(Camera::beta);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha-M_PI_2);
}

void Camera::mouseMove(int x, int y){
	if( !Camera::modoFPS ) return;

	int w = glutGet(GLUT_WINDOW_WIDTH);
	int h = glutGet(GLUT_WINDOW_HEIGHT);

	// evitar que o rato saia da janela
	int w_box = w/2;
	int h_box = h/2;
	if( x > (w_box+w_box/2)) {
		x = x - w_box;
		glutWarpPointer(x, y);
		return;
	}else if( x < (w_box/2)) {
		x = x + w_box;
		glutWarpPointer(x, y);
		return;
	}

	if( y > (h_box+h_box/2) ) {
		y = h_box+h_box/2;
		glutWarpPointer(x, y);
		return;
	}else if( y < (h_box/2) ) {
		y = h_box/2;
		glutWarpPointer(x, y);
		return;
	}

	Camera::alpha = -((float)x - w_box)/(float)w_box * 2 * M_PI;
	
	Camera::beta = -((float)y - h_box)/(float)h_box;

	// -90º < Beta < 90º
	if( Camera::beta > 0.49 ) Camera::beta = 0.49;
	if( Camera::beta < -0.49 ) Camera::beta = -0.49;
	Camera::beta = Camera::beta * 2 * M_PI_2;
}