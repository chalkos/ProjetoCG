#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "Primitivas.h"

float angley = 0;
float anglex = 0;
float translate[3] = {0,0,0};
int drawMode_face = GL_FRONT; //
int drawMode_mode = GL_LINE;
int tipoPrimitiva = 2;

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
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(10*sin(anglex)*cos(angley), 10*sin(angley), 10*cos(anglex)*cos(angley),
		      0.0,1.0,0.0,
			  0.0f,1.0f,0.0f);

	// opções
    //glCullFace(ver);
	glPolygonMode(drawMode_face,drawMode_mode);
	//GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
	//GL_FILL, GL_LINE, GL_POINT

	// pôr instruções de desenho aqui
	//glRotatef(angley,0,1,0); // rodar o espaço antes de colocar os triangulos
	//glRotatef(anglex,1,0,0);
	glTranslatef(translate[0],translate[1],translate[2]);


	switch (tipoPrimitiva) {
		case 1: Primitivas::criarPlano(5,4,3); break;
		case 2: Primitivas::criarCubo(3,4); break;
		case 3: Primitivas::criarEsfera(2,20,20); break;
		case 4: Primitivas::criarCilindro(2, 5, 25); break;
	}

	// End of frame
	glutSwapBuffers();
}



// escrever função de processamento do teclado
void keyPress(unsigned char tecla, int x, int y){
	if( tecla == 'w' ){
		translate[2] -= 0.1;
	}else if( tecla == 's' ){
		translate[2] += 0.1;
	}else if( tecla == 'a' ){
		translate[0] -= 0.1;
	}else if( tecla == 'd' ){
		translate[0] += 0.1;
	}
}

void specialKeyPress(int tecla, int x, int y){
	if( tecla == GLUT_KEY_LEFT ){
		anglex -= 3.1415/16;
	}else if( tecla == GLUT_KEY_RIGHT ){
		anglex += 3.1415/16;
	}else if( tecla == GLUT_KEY_UP ){
		//if( angley < -3.1415/2 ) angley *= -1;
		angley += 3.1415/16;
	}else if( tecla == GLUT_KEY_DOWN ){
		//if( angley > 3.1415/2 ) angley *= -1;
		angley -= 3.1415/16;
	}
	glutPostRedisplay(); //redesenhar
}

void mouseButton(int botão, int estado, int x, int y){

}

void mouseMove(int x, int y){

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


// acções do menu de colorir
void colorirMenuCreate(int id_op){
	switch(id_op){
		case 1:
			Primitivas::setColorir(true);
			break;
		case 2:
			Primitivas::setColorir(false);
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
	glutKeyboardFunc(keyPress);
	glutSpecialFunc(specialKeyPress);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutPassiveMotionFunc(mouseMove);


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

	int colorirMenuID = glutCreateMenu(colorirMenuCreate);
	glutAddMenuEntry("Cores aleatórias", 1);
	glutAddMenuEntry("Branco sobre Preto", 2);

	int primitivaMenuID = glutCreateMenu(primitivaMenuCreate);
	glutAddMenuEntry("Plano", 1);
	glutAddMenuEntry("Cubo", 2);
	glutAddMenuEntry("Esfera", 3);
	glutAddMenuEntry("Cilindro", 4);

	int mainMenuID = glutCreateMenu(mainMenuCreate);
	glutAddSubMenu("Modo de preenchimento",drawModeMenuID);
	glutAddSubMenu("Colorir",colorirMenuID);
	glutAddSubMenu("Primitiva",primitivaMenuID);

	//GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
	//GL_FILL, GL_LINE, GL_POINT

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutSetMenu(mainMenuID);

	//glutPostRedisplay() //redesenhar


// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CCW); //esquema de mão direita
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}

