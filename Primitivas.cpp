#include "Primitivas.h"
#include "Utilities.h"

#include <math.h>
#include <GL\glut.h>

void Primitivas::criarPlano(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4, unsigned cor){
	if(cor!=0x0) glColor3f( ((cor >> 16) & 0xff) / 255.0, ((cor >> 8) & 0xff) / 255.0, (cor & 0xff) / 255.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, 0.0f, z1);
		glVertex3f(x2, 0.0f, z2);
		glVertex3f(x4, 0.0f, z4);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(x3, 0.0f, z3);
		glVertex3f(x4, 0.0f, z4);
		glVertex3f(x2, 0.0f, z2);
	glEnd();
}

void Primitivas::criarCubo(float lado){
	float mlado = lado/2;

	// guardar a matrix de rotações e translações
	glPushMatrix();

	//baixo
	Primitivas::criarPlano(mlado,mlado,-mlado,mlado,-mlado,-mlado,mlado,-mlado,0x111111);

	//cima
	//glRotatef(90,1,0,0);
	glTranslatef(0,lado, 0);
	Primitivas::criarPlano(mlado, mlado, mlado, -mlado, -mlado, -mlado, -mlado, mlado,0x222222);
	
	//frente
	glRotatef(90,1,0,0);
	glTranslatef(0,mlado, mlado);
	Primitivas::criarPlano(mlado, mlado, mlado, -mlado, -mlado, -mlado, -mlado, mlado, 0x333333);

	//tras
	glTranslatef(0,-lado,0);
	Primitivas::criarPlano(mlado,mlado,-mlado,mlado,-mlado,-mlado,mlado,-mlado, 0x444444);

	//lado esquerdo
	glRotatef(90, 0,0,1);
	glTranslatef(mlado,mlado,0);
	Primitivas::criarPlano(mlado, mlado, mlado, -mlado, -mlado, -mlado, -mlado, mlado,0x555555);

	//lado direito
	glTranslatef(0,-lado,0);
	Primitivas::criarPlano(mlado,mlado,-mlado,mlado,-mlado,-mlado,mlado,-mlado,0x666666);
	
	// recuperar a matrix de rotações e translações
	glPopMatrix();
}

void Primitivas::criarCilindro(float raio, float altura, unsigned fatias){
	// guardar a matrix de rotações e translações
	glPushMatrix();

	float angle = (360 / fatias);
	float lado = sinf( toRadian(angle) )*raio;
	float x = cosf( toRadian(angle) )*raio;
	float z = lado;

	// fazer a base
	for(int i=0; i<fatias; i++){
		glBegin(GL_TRIANGLES);
			glColor3f( 0.01*i+0.3, 0.01*i+0.3, 0.01*i+0.3);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(x, 0.0f, -z);
			glVertex3f(raio, 0.0f, 0.0f);
		glEnd();
		glRotatef(angle, 0,1,0);
	}
	
	// voltar à matriz que estava quando a função foi chamada
	glPopMatrix();
	glPushMatrix();

	// refazer a base, mas com y=altura
	glTranslatef(0,altura,0);
	for(int i=0; i<fatias; i++){
		glBegin(GL_TRIANGLES);
			glColor3f( 0.01*i+0.3, 0.01*i+0.3, 0.01*i+0.3);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(raio, 0.0f, 0.0f);
			glVertex3f(x, 0.0f, -z);
		glEnd();
		glRotatef(angle, 0,1,0);
	}
	
	// voltar à matriz que estava quando a função foi chamada
	glPopMatrix();
	glPushMatrix();

	// fazer os rectangulos para os lados
	glRotatef(-90, 1, 0,0);
	glTranslatef(raio,0,0);
	glRotatef( -(90-angle/2), 0,0,1);
	for(int i=0; i<fatias; i++){
		criarPlano( 0,0,  -lado,0,  -lado,altura,  0,altura,   0x030303*i + 0x202020   );
		
		glRotatef( (90-angle/2), 0,0,1);
		glTranslatef(-raio,0,0);
		glRotatef(angle, 0,0,1);
		glTranslatef(raio,0,0);
		glRotatef( -(90-angle/2), 0,0,1);
	}


	// recuperar a matrix de rotações e translações
	glPopMatrix();
}