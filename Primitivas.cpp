#include "Primitivas.h"
#include "Utilities.h"

#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

void Primitivas::criarPlano(float comprimento, float largura){
	if( largura == -1 ) largura = comprimento;
	
	comprimento /= 2;
	largura /= 2;

	glBegin(GL_TRIANGLES);
		glVertex3f(comprimento, 0.0f, largura);
		glVertex3f(comprimento, 0.0f, -largura);
		glVertex3f(-comprimento, 0.0f, largura);
		
		glVertex3f(comprimento, 0.0f, -largura);
		glVertex3f(-comprimento, 0.0f, -largura);
		glVertex3f(-comprimento, 0.0f, largura);
	glEnd();
}

void Primitivas::criarCubo(float lado){
	float mlado = lado/2;


	glBegin(GL_TRIANGLES);
		// baixo
		glVertex3f(mlado, -mlado, -mlado);
		glVertex3f(mlado, -mlado, mlado);
		glVertex3f(-mlado, -mlado, mlado);
		
		glVertex3f(mlado, -mlado, -mlado);
		glVertex3f(-mlado, -mlado, mlado);
		glVertex3f(-mlado, -mlado, -mlado);

		// cima
		glVertex3f(mlado, mlado, -mlado);
		glVertex3f(-mlado, mlado, mlado);
		glVertex3f(mlado, mlado, mlado);
		
		glVertex3f(mlado, mlado, -mlado);
		glVertex3f(-mlado, mlado, -mlado);
		glVertex3f(-mlado, mlado, mlado);

		// frente
		glVertex3f(mlado, mlado, mlado);
		glVertex3f(-mlado, -mlado, mlado);
		glVertex3f(mlado, -mlado, mlado);
		
		glVertex3f(mlado, mlado, mlado);
		glVertex3f(-mlado, mlado, mlado);
		glVertex3f(-mlado, -mlado, mlado);

		// tras
		glVertex3f(mlado, mlado, -mlado);
		glVertex3f(mlado, -mlado, -mlado);
		glVertex3f(-mlado, -mlado, -mlado);
		
		glVertex3f(mlado, mlado, -mlado);
		glVertex3f(-mlado, -mlado, -mlado);
		glVertex3f(-mlado, mlado, -mlado);

		// direita
		glVertex3f(mlado, mlado, mlado);
		glVertex3f(mlado, -mlado, -mlado);
		glVertex3f(mlado, mlado, -mlado);
		
		glVertex3f(mlado, mlado, mlado);
		glVertex3f(mlado, -mlado, mlado);
		glVertex3f(mlado, -mlado, -mlado);

		// esquerda
		glVertex3f(-mlado, mlado, mlado);
		glVertex3f(-mlado, mlado, -mlado);
		glVertex3f(-mlado, -mlado, -mlado);
		
		glVertex3f(-mlado, mlado, mlado);
		glVertex3f(-mlado, -mlado, -mlado);
		glVertex3f(-mlado, -mlado, mlado);


	glEnd();
}

void Primitivas::criarCilindro(float raio, float altura, unsigned fatias, unsigned seccoes){
	float delta = 2 * M_PI / fatias;
	float seccaos = 10;
	float seccao, seccaoSeg;

	float altura2 = altura/2;

	

	glBegin(GL_TRIANGLES);
		
		// a vermelho, o topo (desenhado em y=altura/2)
		glColor3f( 1,0,0 );
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			glVertex3f(0,altura2,0);
			glVertex3f(raio * sin(alpha), altura2, raio * cos(alpha));
			glVertex3f(raio * sin(alpha+delta), altura2, raio * cos(alpha+delta));
		}

		// a branco, as várias secções de altura (para que os triangulos nao fiquem muito esticados)
		glColor3f( 1,1,1 );
		for(int i = 0; i<seccoes; i++){
			seccao = (0.5 - 0.1*i) * altura;
			seccaoSeg = (0.5 - 0.1*(i+1)) * altura;

			// desenhar o reclangulo (=2 triangulos) dos lados
			for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
				glVertex3f(raio * sin(alpha), seccao, raio * cos(alpha));
				glVertex3f(raio * sin(alpha), seccaoSeg, raio * cos(alpha));
				glVertex3f(raio * sin(alpha+delta), seccaoSeg, raio * cos(alpha+delta));
			
				glVertex3f(raio * sin(alpha+delta), seccao, raio * cos(alpha+delta));
				glVertex3f(raio * sin(alpha), seccao, raio * cos(alpha));
				glVertex3f(raio * sin(alpha+delta), seccaoSeg, raio * cos(alpha+delta));
			}
		}

		// a verde, o topo (desenhado em y= -altura/2)
		glColor3f( 0,1,0 );
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			glVertex3f(0,-altura2,0);
			glVertex3f(raio * sin(alpha+delta), -altura2, raio * cos(alpha+delta));
			glVertex3f(raio * sin(alpha), -altura2, raio * cos(alpha));
		}


	glEnd();
}

void Primitivas::criarEsfera(float raio, unsigned fatias, unsigned seccoes){

}