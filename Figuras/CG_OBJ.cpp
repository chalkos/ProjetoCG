#include <stdio.h>
#include <stdlib.h>
#include <glew.h>
#include <GL/glut.h>

#include "CG_OBJ.h"

#define _USE_MATH_DEFINES
#include <math.h>

// search - glVertex3f(
// replace - this->addVertex(&vi,




/*********************************

	CG_OBJ

**********************************/
int CG_OBJ::maxBuffers = 0;
int CG_OBJ::nBuffers = 0;
GLuint *CG_OBJ::buffers = NULL;

int CG_OBJ::getMaxBuffers(){
	return CG_OBJ::maxBuffers;
}

void CG_OBJ::addVertex(int *indice, float x, float y, float z){
	vertexB[(*indice)++] = x;
	vertexB[(*indice)++] = y;
	vertexB[(*indice)++] = z;
}

void CG_OBJ::addNormal(int *indice, float x, float y, float z){
	float norma = sqrt( x*x + y*y + z*z);

	normalB[(*indice)++] = x/norma;
	normalB[(*indice)++] = y/norma;
	normalB[(*indice)++] = z/norma;
}

void CG_OBJ::guardarOBJ(int nTriangulos){
	// escolher o buffer
	this->bufferPos = CG_OBJ::nBuffers;
	CG_OBJ::nBuffers+=3;


	// mete os numeros de triangulos, vertices e floats
	this->nTriangulos = nTriangulos;
	this->nVertices = this->nTriangulos * 3;
	this->nFloats = this->nVertices * 3;

	this->vertexB = (float*)malloc(sizeof(float) * this->nFloats);
	this->normalB = (float*)malloc(sizeof(float) * this->nFloats);

	// preencher os vértices
	this->preencherVertices();

	// seleccionar os buffers e meter dados
	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos]);   // selecionar buffer para vértices
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->vertexB, GL_STATIC_DRAW); // meter vértices

	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos+1]); // selecionar buffer para normais
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->normalB, GL_STATIC_DRAW); // meter normais

	//glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos+2]); // selecionar buffer para texturas
	//glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->?????B, GL_STATIC_DRAW); // meter texturas
}

/////////////// static
void CG_OBJ::prepararBuffer(int maxBuffers){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	CG_OBJ::maxBuffers = maxBuffers*3;
	CG_OBJ::buffers = (GLuint*) malloc(CG_OBJ::maxBuffers * sizeof(GLuint));
	
	glGenBuffers(CG_OBJ::maxBuffers, CG_OBJ::buffers);
}

void CG_OBJ::revolutionSolidClose(float *x, float *y, int count, int fatias){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;
	int ni = 0;

	int ri = 0; // iterador de fase no sólido de revolução

	float alpha;
	float alphaDelta;

	float difX = (y[ri+1] - y[ri]);
	float difY = -(x[ri+1] - x[ri]);
	float difSX = ((y[ri+1] - y[ri])+(y[ri+2] - y[ri+1]))/2; //smooth
	float difSY = (-(x[ri+1] - x[ri])-(x[ri+2] - x[ri+1]))/2; //smooth

	// fecho em baixo
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,x[ri],y[ri],0);
		this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
		this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
		
		this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
		this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
		this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));

		
	}


	// secções da figura
	for(ri++; ri < count-2; ri++){
		difX = (y[ri+1] - y[ri]);
		difY = -(x[ri+1] - x[ri]);
		difSX = ((y[ri+1] - y[ri])+(y[ri+2] - y[ri+1]))/2; //smooth
		difSY = (-(x[ri+1] - x[ri])-(x[ri+2] - x[ri+1]))/2; //smooth

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);
			

			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
			
			this->addVertex(&vi,x[ri] * sin(alphaDelta), y[ri], x[ri] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
		}

	}


	ri = count -1;
	difX = (y[ri] - y[ri-1]);
	difY = -(x[ri] - x[ri-1]);
	
	difSX = ((y[ri] - y[ri-1])+(y[ri-1] - y[ri-2]))/2; //smooth
	difSY = (-(x[ri] - x[ri-1])-(x[ri-1] - x[ri-2]))/2; //smooth

	// fecho em cima
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,x[ri],y[ri],0);
			this->addVertex(&vi,x[ri-1] * sin(alpha), y[ri-1], x[ri-1] * cos(alpha));
			this->addVertex(&vi,x[ri-1] * sin(alphaDelta), y[ri-1], x[ri-1] * cos(alphaDelta));
		
			this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
	}


}

void CG_OBJ::revolutionSolidOpen(float *x, float *y, int count, int fatias){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;
	int ni = 0;

	int ri = 0; // iterador de fase no sólido de revolução

	float alpha;
	float alphaDelta;

	float difX, difY, difSX, difSY; // auxiliar à definição de normais, ver CG_OBJ::revolutionSolidClose

	// as várias secções de altura (para que os triangulos nao fiquem muito esticados)
	for(ri=0; ri < count-1; ri++){

		if(ri != count-2){
			difX = (y[ri+1] - y[ri]);
			difY = -(x[ri+1] - x[ri]);
			difSX = ((y[ri+1] - y[ri])+(y[ri+2] - y[ri+1]))/2; //smooth
			difSY = (-(x[ri+1] - x[ri])-(x[ri+2] - x[ri+1]))/2; //smooth
		}else{
			difX = difSX = (y[ri+1] - y[ri]);
			difY = difSY = -(x[ri+1] - x[ri]);
		}

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
			
			this->addVertex(&vi,x[ri] * sin(alphaDelta), y[ri], x[ri] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
		}
	}
}

/////////////// non-static
void CG_OBJ::desenhar(){
	// Bind e semântica para vértices
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos]);
	glVertexPointer(3,GL_FLOAT,0,0);
	
	// Bind e semântica para normais
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos+1]);
	glNormalPointer(GL_FLOAT,0,0);

	//glMaterialfv(GL_FRONT, componente, array);
	//glMaterialf(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,valor);

	//  Desenhar
	glDrawArrays(GL_TRIANGLES, 0, this->nVertices);
}

/////////////// abstract
void CG_OBJ::preencherVertices(){}





	