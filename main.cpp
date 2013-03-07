#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#include "primitivas.h"

float angle = 0;
float translate[3] = {0,0,0};
int ver = GL_FRONT_AND_BACK;
int face = GL_FRONT;
int drawMode = GL_LINE;

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
	gluLookAt(10.0,2.0,10.0, 
		      0.0,1.0,0.0,
			  0.0f,1.0f,0.0f);

	// opções
    //glCullFace(ver);
	glPolygonMode(face,drawMode);
	//GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
	//GL_FILL, GL_LINE, GL_POINT

	// pôr instruções de desenho aqui
	glRotatef(angle,0,1,0); // rodar o espaço antes de colocar os triangulos
	glTranslatef(translate[0],translate[1],translate[2]);

	/*
	glBegin(GL_TRIANGLES); //F
		glColor3f(0.6,0.6,0.6);
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, -1.0f);
		
	glEnd();*/
	glutSolidSphere(2, 10, 10);
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
		angle -= 5;
	}else if( tecla == GLUT_KEY_RIGHT ){
		angle += 5;
	}
	glutPostRedisplay(); //redesenhar
}

void mouseButton(int botão, int estado, int x, int y){

}

void mouseMove(int x, int y){

}


// escrever função de processamento do menu
void menuCreate(int id_op){
	switch(id_op){
		case 1: ver = GL_BACK; break;
		case 2: ver = GL_FRONT; break;
		case 3: face = GL_FRONT; break;
		case 4: face = GL_BACK; break;
		case 5: face = GL_FRONT_AND_BACK; break;
		case 6: drawMode = GL_FILL; break;
		case 7: drawMode = GL_LINE; break;
		case 8: drawMode = GL_POINT; break;
	}
	glutPostRedisplay(); //redesenhar
}



int main(int argc, char **argv) {

// inicialização
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		

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
	int menuID = glutCreateMenu(menuCreate);
	
	glutAddMenuEntry("ver frente", 1); //GL_BACK
	glutAddMenuEntry("ocultar frente", 2); //GL_FRONT
	glutAddMenuEntry("pMode: GL_FRONT", 3);
	glutAddMenuEntry("pMode: GL_BACK", 4);
	glutAddMenuEntry("pMode: GL_FRONT_AND_BACK", 5);
	glutAddMenuEntry("pMode: GL_FILL", 6);
	glutAddMenuEntry("pMode: GL_LINE", 7);
	glutAddMenuEntry("pMode: GL_POINT", 8);

	//GL_FRONT, GL_BACK, GL_FRONT_AND_BACK
	//GL_FILL, GL_LINE, GL_POINT

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutSetMenu(menuID);

	//glutPostRedisplay() //redesenhar


// alguns settings para OpenGL
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glFrontFace(GL_CCW); //esquema de mão direita
	
// entrar no ciclo do GLUT 
	glutMainLoop();
	
	return 1;
}

