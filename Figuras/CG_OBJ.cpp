#include <stdio.h>
#include <stdlib.h>
#include <glew.h>
#include <GL/glut.h>

#include "CG_OBJ.h"

#define _USE_MATH_DEFINES
#include <math.h>

// search - glVertex3f(
// replace - CG_OBJ::addVertex(&vi,


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

	// preencher os vértices
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

void CG_OBJ::revolutionSolid(float *x, float *y, int count, int fatias){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;

	int ri = 0; // iterador de fase no sólido de revolução

	// o topo (desenhado em y=altura/2)
	for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
		CG_OBJ::addVertex(&vi,x[ri],y[ri],0);
		CG_OBJ::addVertex(&vi,x[ri+1] * sin(alpha+delta), y[ri+1], x[ri+1] * cos(alpha+delta));
		CG_OBJ::addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
	}

	// as várias secções de altura (para que os triangulos nao fiquem muito esticados)
	for(ri++; ri < count-2; ri++){

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
			CG_OBJ::addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
			CG_OBJ::addVertex(&vi,x[ri+1] * sin(alpha+delta), y[ri+1], x[ri+1] * cos(alpha+delta));
			CG_OBJ::addVertex(&vi,x[ri+1] * sin(alpha), y[ri+1], x[ri+1] * cos(alpha));
			
			CG_OBJ::addVertex(&vi,x[ri] * sin(alpha+delta), y[ri], x[ri] * cos(alpha+delta));
			CG_OBJ::addVertex(&vi,x[ri+1] * sin(alpha+delta), y[ri+1], x[ri+1] * cos(alpha+delta));
			CG_OBJ::addVertex(&vi,x[ri] * sin(alpha), y[ri], x[ri] * cos(alpha));
		}
	}

	ri = count -1;

	// a base (desenhado em y= -altura/2)
	for(float alpha = 0; alpha < 2*M_PI; alpha += delta){
		CG_OBJ::addVertex(&vi,x[ri],y[ri],0);
		CG_OBJ::addVertex(&vi,x[ri-1] * sin(alpha), y[ri-1], x[ri-1] * cos(alpha));
		CG_OBJ::addVertex(&vi,x[ri-1] * sin(alpha+delta), y[ri-1], x[ri-1] * cos(alpha+delta));
	}
}

/////////////// non-static
void CG_OBJ::desenhar(){
	//	Bind e semântica
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos]);
	glVertexPointer(3,GL_FLOAT,0,0);

	//  Desenhar
	glDrawArrays(GL_TRIANGLES, 0, this->nVertices);
}

/////////////// abstract
void CG_OBJ::preencherVertices(){}





	