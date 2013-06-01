#include <iostream>
using namespace std;

#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Camera.h"
#include "Utilities.h"
#include "Frustum.h"


bool Camera::modoFPS = true;

Vec3 Camera::fpsMousePos = Vec3(0,0,0);

// posição da câmara
Vec3 Camera::pos;

// orientação horizontal e vertical
float Camera::alpha;
float Camera::beta;

//frustum culling
float Camera::dnear;
float Camera::dfar;
float Camera::fov;
float Camera::ratio=0;
Vec3 Camera::up;
Vec3 Camera::center;

float Camera::passo = 1.5;

void Camera::renderString( float x, float y, int spacing, Fonts font, char *string) {
	char *c;
	int x1=x;

	for (c=string; *c != '\0'; c++) {
		glRasterPos2f(x1,y);
		glutBitmapCharacter((void*)font, *c);
		x1 = x1 + glutBitmapWidth((void*)font,*c) + spacing;
	}
}

void Camera::changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	Camera::ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);

	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(Camera::fov , Camera::ratio, Camera::dnear ,Camera::dfar);
	//gluPerspective (60, ratio, 0.01 , 100.0); //set the perspective (angle of sight, width, height, ,depth)

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void Camera::setOrthographicProjection() {
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);

	// save previous matrix which contains the
	//settings for the perspective projection
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void Camera::restorePerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void Camera::moveTo(float x, float y, float z){
	Camera::pos = Vec3(x,y,z);
}

void Camera::lookAt(){
	// direcção da câmara usando os ângulos
	Camera::lookAt(cos(Camera::beta) * sin(Camera::alpha),
					sin(Camera::beta),
					cos(Camera::beta) * cos(Camera::alpha));
}


void Camera::lookAt(float dx, float dy, float dz){
	center = Vec3(
		pos.getVal(0)+dx,
		pos.getVal(1)+dy,
		pos.getVal(2)+dz);

	if( Frustum::isCullingEnabled() )
		Frustum::updateFrustum(&pos, &up, &center, Camera::fov, Camera::ratio, Camera::dnear, Camera::dfar);

	// transpor o mundo, rodar o mundo, colocar câmara
	gluLookAt(pos.getVal(0), pos.getVal(1), pos.getVal(2),    // posição da câmara
		center.getVal(0), center.getVal(1), center.getVal(2), // ponto para onde a câmara está apontada
		up.getVal(0), up.getVal(1), up.getVal(2));      // “up vector” (0.0f, 1.0f, 0.0f)


}

void Camera::passoMaior(){
	Camera::passo += 0.001;

	if( Camera::passo > 0.3 )
		Camera::passo += 0.002;

	cout << "Passo: " << Camera::passo << endl;
}

void Camera::passoMenor(){
	Camera::passo -= 0.001;

	if( Camera::passo > 0.3 )
		Camera::passo -= 0.002;

	if( Camera::passo < 0 )
		Camera::passo = 0.001;

	cout << "Passo: " << Camera::passo << endl;
}

void Camera::init(float x, float y, float z){
	// posição inicial: (x,y,z)
	pos = Vec3(x,y,z);
	
	up = Vec3(0,1,0);

	Camera::dnear = 1.0f;
	Camera::dfar = 470.0f;

	Camera::fov = 60.0f;

	glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer((float)glutGet(GLUT_WINDOW_WIDTH)/2, (float)glutGet(GLUT_WINDOW_HEIGHT)/2);
}

void Camera::toggleFPS(){
	Camera::modoFPS = !Camera::modoFPS;
	if( Camera::modoFPS ){
		glutSetCursor(GLUT_CURSOR_NONE);
		glutWarpPointer(fpsMousePos.X(), fpsMousePos.Y());
	}else{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
}

void Camera::moverFrente(){

	Vec3 increm = Vec3(
		Camera::passo * cos(Camera::beta) * sin(Camera::alpha),
		Camera::passo * sin(Camera::beta),
		Camera::passo * cos(Camera::beta) * cos(Camera::alpha));

	pos.incrementar(&increm);
	Frustum::scheduleUpdate();
}

void Camera::moverTras(){
	Vec3 increm = Vec3(
		-Camera::passo * cos(Camera::beta) * sin(Camera::alpha),
		-Camera::passo * sin(Camera::beta),
		-Camera::passo * cos(Camera::beta) * cos(Camera::alpha));

	pos.incrementar(&increm);
	Frustum::scheduleUpdate();
}

void Camera::moverEsquerda(){
	Vec3 increm = Vec3(
		Camera::passo * cos(Camera::beta) * sin(Camera::alpha+M_PI_2),
		0,
		Camera::passo * cos(Camera::beta) * cos(Camera::alpha+M_PI_2));

	pos.incrementar(&increm);
	Frustum::scheduleUpdate();
}

void Camera::moverDireita(){
	Vec3 increm = Vec3(
		Camera::passo * cos(Camera::beta) * sin(Camera::alpha-M_PI_2),
		0,
		Camera::passo * cos(Camera::beta) * cos(Camera::alpha-M_PI_2));

	pos.incrementar(&increm);
	Frustum::scheduleUpdate();
}

void Camera::mouseMove(int x, int y){
	if( !Camera::modoFPS ) return;
	fpsMousePos.reset( x, y, 0);
	
	Frustum::scheduleUpdate();
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