#include <iostream>
using namespace std;

#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Camera.h"
#include "Utilities.h"


// indices de pontos e normais do frustum
enum Frustum {
	nearCenterX,
	nearCenterY,
	nearCenterZ,
	nearNormalX,
	nearNormalY,
	nearNormalZ,
	nearD,
	
	farCenterX,
	farCenterY,
	farCenterZ,
	farNormalX,
	farNormalY,
	farNormalZ,
	farD,
	
	leftPointX,
	leftPointY,
	leftPointZ,
	leftNormalX,
	leftNormalY,
	leftNormalZ,
	leftD,
	
	rightPointX,
	rightPointY,
	rightPointZ,
	rightNormalX,
	rightNormalY,
	rightNormalZ,
	rightD,
	
	topPointX,
	topPointY,
	topPointZ,
	topNormalX,
	topNormalY,
	topNormalZ,
	topD,
	
	bottomPointX,
	bottomPointY,
	bottomPointZ,
	bottomNormalX,
	bottomNormalY,
	bottomNormalZ,
	bottomD,

	// contador
	frostumCOUNT_ENUM
};

bool Camera::frustumCullingEnabled = false;
bool Camera::frustumNeedsUpdate = true;
bool Camera::modoFPS = true;

// posição da câmara
float Camera::posX;
float Camera::posY;
float Camera::posZ;

// orientação horizontal e vertical
float Camera::alpha;
float Camera::beta;

//frustum culling
float Camera::dnear;
float Camera::dfar;
float Camera::fov;
float Camera::ratio=0;
float Camera::Wnear;
float Camera::Hnear;
//float Camera::Wfar;
//float Camera::Hfar;
float Camera::up[3];
float Camera::center[3];
float Camera::frustum[frostumCOUNT_ENUM];

float Camera::passo = 0.5;

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

void Camera::toggleFrustumCulling(){
	Camera::frustumCullingEnabled = !Camera::frustumCullingEnabled;

	if( Camera::frustumCullingEnabled )
		cout << "[ON] Frustum Culling" << endl;
	else
		cout << "[OFF] Frustum Culling" << endl;
}


void Camera::lookAt(float dx, float dy, float dz){
	center[0] = posX+dx;
	center[1] = posY+dy;
	center[2] = posZ+dz;

	if( Camera::frustumCullingEnabled )
		Camera::updateFrustum();

	// transpor o mundo, rodar o mundo, colocar câmara
	gluLookAt(posX, posY, posZ,    // posição da câmara
		center[0], center[1], center[2], // ponto para onde a câmara está apontada
		up[0], up[1], up[2]);      // “up vector” (0.0f, 1.0f, 0.0f)


}

void Camera::passoMaior(){
	Camera::passo += 0.01;

	cout << "Passo: " << Camera::passo << endl;
}

void Camera::passoMenor(){
	Camera::passo -= 0.01;

	if( Camera::passo < 0 )
		Camera::passo = 0.001;

	cout << "Passo: " << Camera::passo << endl;
}

void Camera::init(float x, float y, float z){
	// posição inicial: (x,y,z)
	Camera::posX = x;
	Camera::posY = y;
	Camera::posZ = z;
	
	Camera::up[0] = 0;
	Camera::up[1] = 1;
	Camera::up[2] = 0;

	Camera::dnear = 0.1f;
	Camera::dfar = 400.0f;

	Camera::fov = 60.0f;

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

bool Camera::pointInFrustum(float *p){
	if( innerProduct( frustum+nearNormalX, p ) + frustum[nearD] < 0 ) return false;
	if( innerProduct( frustum+farNormalX, p ) + frustum[farD] < 0 ) return false;
	if( innerProduct( frustum+topNormalX, p ) + frustum[topD] < 0 ) return false;
	if( innerProduct( frustum+rightNormalX, p ) + frustum[rightD] < 0 ) return false;
	if( innerProduct( frustum+bottomNormalX, p ) + frustum[bottomD] < 0 ) return false;
	if( innerProduct( frustum+leftNormalX, p ) + frustum[leftD] < 0 ) return false;

	return true;
}

bool Camera::pointInFrustum(float x, float y, float z) {
	float aux[3] = {x,y,z};
	return Camera::pointInFrustum(aux);
}

void Camera::updateFrustum(){
	if( !frustumNeedsUpdate || Camera::ratio == 0.0f )
		return;

	float tmp[3];
	float X[3], Y[3], Z[3];


	// obter o comprimento e largura dos planos near e far
	Hnear = tan(toRadian(fov) / 2.0f) * dnear;
	Wnear = Hnear * ratio;
	//Hfar = tan(toRadian(fov) / 2.0f) * dfar;
	//Wfar = Hfar * ratio;

	// obter o Z da camara
	Z[0] = posX - center[0];
	Z[1] = posY - center[1];
	Z[2] = posZ - center[2];
	normalize(Z);

	// obter o X da camara
	crossProduct(X, up, Z);
	normalize(X);

	// obter o up "real"
	crossProduct(Y,Z,X);

	
	// definir pontos e normais do frustum
	// near
	frustum[nearCenterX] = posX - Z[0] * dnear;
	frustum[nearCenterY] = posY - Z[1] * dnear;
	frustum[nearCenterZ] = posZ - Z[2] * dnear;
	frustum[nearNormalX] = -Z[0];
	frustum[nearNormalY] = -Z[1];
	frustum[nearNormalZ] = -Z[2];
	frustum[nearD] = innerProduct( frustum+nearNormalX, frustum+nearCenterX );

	// far
	frustum[farCenterX] = posX - Z[0] * dfar;
	frustum[farCenterY] = posY - Z[1] * dfar;
	frustum[farCenterZ] = posZ - Z[2] * dfar;
	frustum[farNormalX] = Z[0];
	frustum[farNormalY] = Z[1];
	frustum[farNormalZ] = Z[2];
	frustum[farD] = innerProduct( frustum+farNormalX, frustum+farCenterX );

	// right
	frustum[rightPointX] = (frustum[nearCenterX] + X[0] * Wnear);
	frustum[rightPointY] = (frustum[nearCenterY] + X[1] * Wnear);
	frustum[rightPointZ] = (frustum[nearCenterZ] + X[2] * Wnear);
	tmp[0] = frustum[rightPointX] - posX;
	tmp[1] = frustum[rightPointY] - posY;
	tmp[2] = frustum[rightPointZ] - posZ;
	normalize( tmp );
	crossProduct( frustum+rightNormalX, Y, tmp );
	frustum[rightD] = innerProduct( frustum+rightNormalX, frustum+rightPointX );

	// left
	frustum[leftPointX] = (frustum[nearCenterX] - X[0] * Wnear);
	frustum[leftPointY] = (frustum[nearCenterY] - X[1] * Wnear);
	frustum[leftPointZ] = (frustum[nearCenterZ] - X[2] * Wnear);
	tmp[0] = frustum[leftPointX] - posX;
	tmp[1] = frustum[leftPointY] - posY;
	tmp[2] = frustum[leftPointZ] - posZ;
	normalize( tmp );
	crossProduct( frustum+leftNormalX, tmp, Y );
	frustum[leftD] = innerProduct( frustum+leftNormalX, frustum+leftPointX );

	// top
	frustum[topPointX] = (frustum[nearCenterX] + Y[0] * Hnear);
	frustum[topPointY] = (frustum[nearCenterY] + Y[1] * Hnear);
	frustum[topPointZ] = (frustum[nearCenterZ] + Y[2] * Hnear);
	tmp[0] = frustum[topPointX] - posX;
	tmp[1] = frustum[topPointY] - posY;
	tmp[2] = frustum[topPointZ] - posZ;
	normalize( tmp );
	crossProduct( frustum+topNormalX, tmp, X );
	frustum[topD] = innerProduct( frustum+topNormalX, frustum+topPointX );

	// bottom
	frustum[bottomPointX] = (frustum[nearCenterX] - Y[0] * Hnear);
	frustum[bottomPointY] = (frustum[nearCenterY] - Y[1] * Hnear);
	frustum[bottomPointZ] = (frustum[nearCenterZ] - Y[2] * Hnear);
	tmp[0] = frustum[bottomPointX] - posX;
	tmp[1] = frustum[bottomPointY] - posY;
	tmp[2] = frustum[bottomPointZ] - posZ;
	normalize( tmp );
	crossProduct( frustum+bottomNormalX, X, tmp );
	frustum[bottomD] = innerProduct( frustum+bottomNormalX, frustum+bottomPointX );








	frustumNeedsUpdate = false;
}

void Camera::moverFrente(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha);
	posY = posY + Camera::passo * sin(Camera::beta);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha);
	frustumNeedsUpdate = true;
}

void Camera::moverTras(){
	posX = posX - Camera::passo * cos(Camera::beta) * sin(Camera::alpha);
	posY = posY - Camera::passo * sin(Camera::beta);
	posZ = posZ - Camera::passo * cos(Camera::beta) * cos(Camera::alpha);
	frustumNeedsUpdate = true;
}

void Camera::moverEsquerda(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha+M_PI_2);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha+M_PI_2);
	frustumNeedsUpdate = true;
}

void Camera::moverDireita(){
	posX = posX + Camera::passo * cos(Camera::beta) * sin(Camera::alpha-M_PI_2);
	posZ = posZ + Camera::passo * cos(Camera::beta) * cos(Camera::alpha-M_PI_2);
	frustumNeedsUpdate = true;
}

void Camera::mouseMove(int x, int y){
	if( !Camera::modoFPS ) return;
	
	frustumNeedsUpdate = true;
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