#ifndef __CG_OBJ_H_INCLUDED__
#define __CG_OBJ_H_INCLUDED__


#include <glew.h>
#include <GL/glut.h>

#include "../Vec3.h"

class CG_OBJ {
protected:
	////////////// static
	static int maxBuffers;
	static int nBuffers;

	void addVertex(int *indice, float x, float y, float z);
	void addNormal(int *indice, float x, float y, float z);
	void addTextureCoord(int *indice, float x, float y);
	
	void addVertex(int *indice, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	void addNormal(int *indice, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	void addTextureCoord(int *indice, float x1, float y1, float x2, float y2, float x3, float y3);

	////////////// non-static
	float comprimento; // altura dos solidos de revolucao

	void calculateBounds();

	int nTriangulos; // numero de triangulos
	int nVertices;   // numero de vertices
	int nFloats;     // numero de floats

	int bufferPos;   // posi��o no buffer onde est� o objecto

	float *vertexB;  // array de coordenadas
	int *vertexI;    // array de indices de coordenadas
	float *normalB;  // array de normais
	float *textureB; // array de coordenadas de textura

	// inicializa alguns valores para depois ser preenchido o array de coordenadas
	void guardarOBJ(int nTriangulos);

	// m�todo que preenche o array de v�rtices com os v�rtices
	virtual void preencherVertices();

	// preenche o array de v�rtices de acordo com coordenadas XY e faz um s�lido de revolu��o
	void revolutionSolidClose(float *x, float *y, int count, int fatias);
	void revolutionSolidOpen(float *x, float *y, int count, int fatias);

	// v�rias propriedades
	Vec3 emissiva;
	Vec3 especular;
	Vec3 ambiente;
	Vec3 difusa;
	float shininess;


public:
	/////////////// static
	static GLuint *buffers;
	static void prepararBuffer(int maxBuffers);

	// trata as coordenadas repetidas
	void preencherIndices();
	

	/////////////// non-static
	void desenhar();

	// obt�m o numero m�ximo de buffers actual
	static int getMaxBuffers();
	
	// obt�m os limites do objecto nos v�rios eixos
	Vec3 *minBound;
	Vec3 *maxBound;
	

	CG_OBJ *setEmissiva(float r, float g, float b);
	CG_OBJ *setEspecular(float r, float g, float b);
	CG_OBJ *setAmbiente(float r, float g, float b);
	CG_OBJ *setDifusa(float r, float g, float b);
	CG_OBJ *setShininess(float s);
};


#endif // __CG_OBJ_H_INCLUDED__