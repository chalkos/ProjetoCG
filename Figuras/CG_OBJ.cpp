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

void CG_OBJ::guardarOBJ(int nTriangulos){
	// escolher o buffer
	this->bufferPos = CG_OBJ::nBuffers;
	CG_OBJ::nBuffers++;


	// mete os numeros de triangulos, vertices e floats
	this->nTriangulos = nTriangulos;
	this->nVertices = this->nTriangulos * 3;
	this->nFloats = this->nVertices * 3;

	this->vertexB = (float*)malloc(sizeof(float) * this->nFloats);

	// preencher os v�rtices
	this->preencherVertices();

	// seleccionar o buffer
	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos]);

	// colocar os dados no buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->vertexB, GL_STATIC_DRAW);
}

/////////////// static
void CG_OBJ::prepararBuffer(int maxBuffers){
	glEnableClientState(GL_VERTEX_ARRAY);

	CG_OBJ::maxBuffers = maxBuffers;
	CG_OBJ::buffers = (GLuint*) malloc(CG_OBJ::maxBuffers * sizeof(GLuint));
	
	glGenBuffers(CG_OBJ::maxBuffers, CG_OBJ::buffers);
}

void CG_OBJ::revolutionSolidClose(float *x, float *y, int count, int fatias){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;

	int ri = 0; // iterador de fase no s�lido de revolu��o

	float alpha;
	float alphaDelta;

	// o topo (desenhado em y=altura/2)
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,x[ri],y[ri],0);
		this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
		this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
	}

	// as v�rias sec��es de altura (para que os triangulos nao fiquem muito esticados)
	for(ri++; ri < count-2; ri++){

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
			
			this->addVertex(&vi,x[ri] * sin(alphaDelta), y[ri], x[ri] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
		}
	}

	ri = count -1;
	
	// a base (desenhado em y= -altura/2)
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,x[ri],y[ri],0);
		this->addVertex(&vi,x[ri-1] * sin(alpha), y[ri-1], x[ri-1] * cos(alpha));
		this->addVertex(&vi,x[ri-1] * sin(alphaDelta), y[ri-1], x[ri-1] * cos(alphaDelta));
	}
}

void CG_OBJ::revolutionSolidOpen(float *x, float *y, int count, int fatias){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;

	int ri = 0; // iterador de fase no s�lido de revolu��o

	float alpha;
	float alphaDelta;

	// as v�rias sec��es de altura (para que os triangulos nao fiquem muito esticados)
	for(ri=0; ri < count-2; ri++){

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
			
			this->addVertex(&vi,x[ri] * sin(alphaDelta), y[ri], x[ri] * cos(alphaDelta));
			this->addVertex(&vi,x[ri+1] * sin(alphaDelta), y[ri+1], x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
		}
	}
}

/////////////// non-static
void CG_OBJ::desenhar(){
	//	Bind e sem�ntica
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos]);
	glVertexPointer(3,GL_FLOAT,0,0);

	//  Desenhar
	glDrawArrays(GL_TRIANGLES, 0, this->nVertices);
}

/////////////// abstract
void CG_OBJ::preencherVertices(){}





	