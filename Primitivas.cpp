#include "Primitivas.h"
#include "Utilities.h"

#include <stdlib.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>

bool Primitivas::colorir;

void Primitivas::changeColor(){
	if(!Primitivas::colorir) return;

	glColor3f(
		(rand() % 80)*0.01+0.1, // gera numeros entre 0.1 e 0.9
		(rand() % 80)*0.01+0.1, // como a seed é a mesma para cada forma
		(rand() % 80)*0.01+0.1); // os numeros gerados sao os mesmos
}

void Primitivas::setColorir(bool valor){
	Primitivas::colorir = valor;
}

void Primitivas::setColorSeed(unsigned int seed){
	srand(seed);
}

void Primitivas::criarPlano(float comprimento, float largura, int camadas){
	float x2 = comprimento/camadas;
	float z2 = largura/camadas;

	Primitivas::setColorSeed(2);
	if( largura == -1 ) largura = comprimento;

	comprimento /= 2;
	largura /= 2;

	glBegin(GL_TRIANGLES);
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {
		Primitivas::changeColor();
		glVertex3f(-comprimento + i*x2, 0.0f, largura - j*z2);
		glVertex3f(-comprimento + (i+1)*x2 , 0.0f, largura - (j+1)*z2);
		glVertex3f(-comprimento + i*x2, 0.0f, largura - (j+1)*z2);
		
		Primitivas::changeColor();
		glVertex3f(-comprimento + i*x2, 0.0f, largura - j*z2);
		glVertex3f(-comprimento + (i+1)*x2, 0.0f, largura - j*z2);
		glVertex3f(-comprimento + (i+1)*x2, 0.0f, largura - (j+1)*z2);
		}
	}

	glEnd();
}

void Primitivas::criarCubo(float lado, int camadas){
	Primitivas::setColorSeed(3);
	float mlado = lado/2;
	float n = lado/camadas;

	glBegin(GL_TRIANGLES);

	//baixo
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(-mlado + i*n, -mlado, mlado - j*n);
		glVertex3f(-mlado + i*n, -mlado, mlado - (j+1)*n);
		glVertex3f(-mlado + (i+1)*n, -mlado, mlado - (j+1)*n);
		
		glVertex3f(-mlado + (i+1)*n, -mlado, mlado - j*n);
		glVertex3f(-mlado + i*n, -mlado, mlado - j*n);
		glVertex3f(-mlado + (i+1)*n, -mlado, mlado - (j+1)*n);
		}
	}
	//cima
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(-mlado + i*n, mlado, mlado - j*n);
		glVertex3f(-mlado + i*n, mlado, mlado - (j+1)*n);
		glVertex3f(-mlado + (i+1)*n, mlado, mlado - (j+1)*n);
		
		glVertex3f(-mlado + (i+1)*n, mlado, mlado - j*n);
		glVertex3f(-mlado + i*n, mlado, mlado - j*n);
		glVertex3f(-mlado + (i+1)*n, mlado, mlado - (j+1)*n);
		}
	
	}
	//frente
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(-mlado + (i+1)*n, mlado - j*n, mlado);
		glVertex3f(-mlado + i*n, mlado - (j+1)*n, mlado);
		glVertex3f(-mlado + i*n, mlado - j*n, mlado);
		
		glVertex3f(-mlado + (i+1)*n, mlado - j*n, mlado);
		glVertex3f(-mlado + (i+1)*n, mlado - (j+1)*n, mlado);
		glVertex3f(-mlado + i*n, mlado - (j+1)*n, mlado);
		}
	}
	//atras
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(-mlado + (i+1)*n, mlado - j*n, -mlado);
		glVertex3f(-mlado + i*n, mlado - (j+1)*n, -mlado);
		glVertex3f(-mlado + i*n, mlado - j*n, -mlado);

		glVertex3f(-mlado + (i+1)*n, mlado - j*n, -mlado);
		glVertex3f(-mlado + (i+1)*n, mlado - (j+1)*n,-mlado);
		glVertex3f(-mlado + i*n, mlado - (j+1)*n, -mlado);
		}
	}
	//direita
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(mlado, -mlado + i*n, -mlado + j*n);
		glVertex3f(mlado, -mlado + (i+1)*n, -mlado + j*n);
		glVertex3f(mlado, -mlado + (i+1)*n, -mlado + (j+1)*n);

		glVertex3f(mlado, -mlado + i*n , -mlado + j*n);
		glVertex3f(mlado, -mlado + (i+1)*n , -mlado + (j+1)*n);
		glVertex3f(mlado, -mlado + i*n, -mlado + (j+1)*n);
		}
	}
	//esquerda
	for(int i=0; i<camadas; i++) {
		for(int j=0; j<camadas; j++) {		
		Primitivas::changeColor();
		glVertex3f(-mlado, -mlado + i*n, -mlado + j*n);
		glVertex3f(-mlado, -mlado + (i+1)*n, -mlado + j*n);
		glVertex3f(-mlado, -mlado + (i+1)*n, -mlado + (j+1)*n);

		glVertex3f(-mlado, -mlado + i*n , -mlado + j*n);
		glVertex3f(-mlado, -mlado + (i+1)*n , -mlado + (j+1)*n);
		glVertex3f(-mlado, -mlado + i*n, -mlado + (j+1)*n);
		}
	}

	glEnd();
}

void Primitivas::criarCilindro(float raio, float altura, unsigned fatias, unsigned seccoes){
	Primitivas::setColorSeed(4);
	float delta = 2 * M_PI / fatias;
	float seccaos = 10;
	float seccao, seccaoSeg;

	float altura2 = altura/2;

	

	glBegin(GL_TRIANGLES);
		
		// o topo (desenhado em y=altura/2)
		Primitivas::changeColor();
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			glVertex3f(0,altura2,0);
			glVertex3f(raio * sin(alpha), altura2, raio * cos(alpha));
			glVertex3f(raio * sin(alpha+delta), altura2, raio * cos(alpha+delta));
		}

		// as várias secções de altura (para que os triangulos nao fiquem muito esticados)
		for(int i = 0; i<seccoes; i++){
			Primitivas::changeColor();
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

		// a base (desenhado em y= -altura/2)
		Primitivas::changeColor();
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			glVertex3f(0,-altura2,0);
			glVertex3f(raio * sin(alpha+delta), -altura2, raio * cos(alpha+delta));
			glVertex3f(raio * sin(alpha), -altura2, raio * cos(alpha));
		}


	glEnd();
}

void Primitivas::criarEsfera(float raio, unsigned fatias, unsigned seccoes){
	Primitivas::setColorSeed(5);


	float alpha = 2 * M_PI / fatias;
	float beta = M_PI / seccoes;


	glBegin(GL_TRIANGLES);

	// desenhar a parte de baixo
	float i = -(seccoes/2.0f);
	for(int j=0; j < fatias; j++){
		Primitivas::changeColor();
		glVertex3f(raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		glVertex3f(raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		glVertex3f(raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));
	}

	// desenhar as secções intermédias
	for(/* inicializado acima */; i < (seccoes/2.0f)-1; i+=1){
		for(int j=0; j < fatias; j++){
			Primitivas::changeColor();
			glVertex3f(raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			glVertex3f(raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
			glVertex3f(raio * cos(beta*(i+1)) * sin(alpha*j), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*j));
			//continue;
			glVertex3f(raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
			glVertex3f(raio * cos(beta*i) * sin(alpha*(j+1)), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*(j+1)));
			glVertex3f(raio * cos(beta*(i+1)) * sin(alpha*(j+1)), raio * sin(beta*(i+1)), raio * cos(beta*(i+1)) * cos(alpha*(j+1)));
		}
	}

	// desenhar a secção de cima
	i += 1;
	for(int j=0; j < fatias; j++){
		Primitivas::changeColor();
		glVertex3f(raio * cos(beta*i) * sin(alpha*j), raio * sin(beta*i), raio * cos(beta*i) * cos(alpha*j));
		glVertex3f(raio * cos(beta*(i-1)) * sin(alpha*j), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*j));
		glVertex3f(raio * cos(beta*(i-1)) * sin(alpha*(j+1)), raio * sin(beta*(i-1)), raio * cos(beta*(i-1)) * cos(alpha*(j+1)));
	}

	glEnd();
}