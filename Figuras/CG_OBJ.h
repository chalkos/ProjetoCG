#ifndef __CG_OBJ_H_INCLUDED__
#define __CG_OBJ_H_INCLUDED__


#include <glew.h>
#include <GL/glut.h>


/*
TODO:
- uma maneira de alertar quando ocupar todos os buffers, ou maneira de alocar mais.
*/

class CG_OBJ {
protected:
	////////////// static
	static int maxBuffers;
	static int nBuffers;

	void addVertex(int *indice, float x, float y, float z);
	void addNormal(int *indice, float x, float y, float z);
	void addTexture(int *indice, float x, float y);

	////////////// non-static
	int nTriangulos; // numero de triangulos
	int nVertices;   // numero de vertices
	int nFloats;     // numero de floats

	int bufferPos;   // posi��o no buffer onde est� o objecto

	float *vertexB;  // array de coordenadas
	float *normalB;  // array de normais
	float *textureB; // array de coordenadas de textura

	// inicializa alguns valores para depois ser preenchido o array de coordenadas
	void guardarOBJ(int nTriangulos);

	// m�todo que preenche o array de v�rtices com os v�rtices
	virtual void preencherVertices();

	// preenche o array de v�rtices de acordo com coordenadas XY e faz um s�lido de revolu��o
	void revolutionSolidClose(float *x, float *y, int count, int fatias);
	void revolutionSolidOpen(float *x, float *y, int count, int fatias);

public:
	/////////////// static
	static GLuint *buffers;
	static void prepararBuffer(int maxBuffers);
	

	/////////////// non-static
	void desenhar();

	// obt�m o numero m�ximo de buffers actual
	static int getMaxBuffers();
};


#endif // __CG_OBJ_H_INCLUDED__