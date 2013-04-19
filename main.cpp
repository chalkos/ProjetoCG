#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Input.h"
#include "Camera.h"

// Figuras
#include "Figuras.h"

int drawMode_face = GL_FRONT_AND_BACK;
int drawMode_mode = GL_LINE;
int tipoPrimitiva = 3;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);

	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(60.0f , ratio, 0.1f ,400.0f);
	//gluPerspective (60, ratio, 0.01 , 100.0); //set the perspective (angle of sight, width, height, ,depth)

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);



	//////////////////////////////////////////

    glLoadIdentity ();
    
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();

	// posicionar a camara
	Camera::lookAt();
			  
	// opções
    //glCullFace(GL_BACK);  // não desenhar triangulos que não estão visiveis
	glPolygonMode(drawMode_face,drawMode_mode);

	//Figuras::desenharParedes();

	glPushMatrix();
	glScalef(1,0.33,1);
	Figuras::desenharParedes();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 250*0.33, 110);
	Figuras::desenharCandeeiroSuspenso();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 110);
	Figuras::desenharCandeeiroPe();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(20, 0, 110);
	glScalef(4,4,4);
	Figuras::desenharCadeiraSimples();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, 110);
	glScalef(4,4,4);
	Figuras::desenharCadeiraBalcao();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 0, 110);
	glScalef(3,3,3);
	Figuras::desenharMesaRectangular();
	glPopMatrix();

	// set de copos de champanhe
	glPushMatrix();
	glTranslatef(60, 0, 110);
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

	glPushMatrix();
	glTranslatef(-60, 0, 100);
	glScalef(6,6,6);
	Figuras::desenharMesaRedonda();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60, 4*6, 100);
	Figuras::desenharCopoVinho();
	glTranslatef(6,0,0);
	Figuras::desenharCopoVinho();
	glTranslatef(-12,0,0);
	Figuras::desenharCopoVinho();
	glTranslatef(6,0,6);
	glScalef(1.4,1.4,1.4);
	Figuras::desenharGarrafaVinho();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-100, 0, 60);
	glScalef(6,6,6);
	Figuras::desenharMesaEsplanada();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-100, 4*6, 60);
	Figuras::desenharCopoSimples();
	glTranslatef(6,0,0);
	Figuras::desenharCopoSimples();
	glTranslatef(-12,0,0);
	Figuras::desenharCopoSimples();
	glTranslatef(6,0,6);
	glScalef(1.4,1.4,1.4);
	Figuras::desenharGarrafaVinho();
	glPopMatrix();


	// End of frame
	glutSwapBuffers();
}


// acções do menu de modo de desenho
void drawModeMenuCreate(int id_op){
	switch(id_op){
		case 1:
			drawMode_face = GL_FRONT;
			drawMode_mode = GL_FILL;
			break;
		case 2:
			drawMode_face = GL_FRONT;
			drawMode_mode = GL_LINE;
			break;
		case 3:
			drawMode_face = GL_FRONT;
			drawMode_mode = GL_POINT;
			break;
		
		case 4:
			drawMode_face = GL_BACK;
			drawMode_mode = GL_FILL;
			break;
		case 5:
			drawMode_face = GL_BACK;
			drawMode_mode = GL_LINE;
			break;
		case 6:
			drawMode_face = GL_BACK;
			drawMode_mode = GL_POINT;
			break;
		
		case 7:
			drawMode_face = GL_FRONT_AND_BACK;
			drawMode_mode = GL_FILL;
			break;
		case 8:
			drawMode_face = GL_FRONT_AND_BACK;
			drawMode_mode = GL_LINE;
			break;
		case 9:
			drawMode_face = GL_FRONT_AND_BACK;
			drawMode_mode = GL_POINT;
			break;
	}
	glutPostRedisplay(); //redesenhar
}

// acções do menu de mudar primitiva
void primitivaMenuCreate(int id_op){
	tipoPrimitiva = id_op;
	glutPostRedisplay(); //redesenhar
}

// acções do menu principal
void mainMenuCreate(int id_op){
	
	glutPostRedisplay(); //redesenhar
}



int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("ProjetoCG - Showcase");
		

// registo de funções 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

// pôr aqui registo da funções do teclado e rato
	Input::init();

	// inicializar a câmara na posição: (x,y,z)
	Camera::init(0,5,-10);


// pôr aqui a criação do menu
	int drawModeMenuID = glutCreateMenu(drawModeMenuCreate);
	glutAddMenuEntry("FRONT - FILL", 1);
	glutAddMenuEntry("FRONT - LINE", 2);
	glutAddMenuEntry("FRONT - DOT", 3);
	glutAddMenuEntry("BACK - FILL", 4);
	glutAddMenuEntry("BACK - LINE", 5);
	glutAddMenuEntry("BACK - DOT", 6);
	glutAddMenuEntry("FRONT AND BACK - FILL", 7);
	glutAddMenuEntry("FRONT AND BACK - LINE", 8);
	glutAddMenuEntry("FRONT AND BACK - DOT", 9);

	int primitivaMenuID = glutCreateMenu(primitivaMenuCreate);
	glutAddMenuEntry("Plano", 1);
	glutAddMenuEntry("Cubo", 2);
	glutAddMenuEntry("Esfera", 3);
	glutAddMenuEntry("Cilindro", 4);

	int mainMenuID = glutCreateMenu(mainMenuCreate);
	glutAddSubMenu("Modo de preenchimento",drawModeMenuID);
	//glutAddSubMenu("Primitiva",primitivaMenuID);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutSetMenu(mainMenuID);


	// glew init
	glewInit();

	// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CCW); //esquema de mão direita


	// preparar objetos
	Figuras::init();
	
	// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}

