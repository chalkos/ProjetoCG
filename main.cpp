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
	gluPerspective(60.0f , ratio, 0.01f ,1000.0f);
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

	//Figuras::desenharParedes();
	//Figuras::desenharGarrafa();
	
	Figuras::desenharFigura(3);
	

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
	glutCreateWindow("ProjetoCG - Sandbox");
		

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

