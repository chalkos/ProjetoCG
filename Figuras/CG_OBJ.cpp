#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <glew.h>
#include <GL/glut.h>

#include "CG_OBJ.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define anguloRigido M_PI_2

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

void CG_OBJ::addTextureCoord(int *indice, float x, float y){
	textureB[(*indice)++] = x;
	textureB[(*indice)++] = y;
}

void CG_OBJ::addVertex(int *indice, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	addVertex( indice, x1, y1, z1);
	addVertex( indice, x2, y2, z2);
	addVertex( indice, x3, y3, z3);
}

void CG_OBJ::addNormal(int *indice, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	addNormal( indice, x1, y1, z1);
	addNormal( indice, x2, y2, z2);
	addNormal( indice, x3, y3, z3);
}

void CG_OBJ::addTextureCoord(int *indice, float x1, float y1, float x2, float y2, float x3, float y3){
	addTextureCoord( indice, x1, y1);
	addTextureCoord( indice, x2, y2);
	addTextureCoord( indice, x3, y3);
}

void CG_OBJ::guardarOBJ(int nTriangulos){
	if( CG_OBJ::nBuffers >= CG_OBJ::maxBuffers ){
		std::cout << "[ERRO] Todos os " << CG_OBJ::maxBuffers << " buffers estão ocupados.\nPress any key to exit" << std::endl;
		_getch();
		exit(EXIT_FAILURE);
	}

	// escolher o buffer
	this->bufferPos = CG_OBJ::nBuffers;
	CG_OBJ::nBuffers+=3;


	// mete os numeros de triangulos, vertices e floats
	this->nTriangulos = nTriangulos;
	this->nVertices = this->nTriangulos * 3;
	this->nFloats = this->nVertices * 3;

	this->vertexB = (float*)malloc(sizeof(float) * this->nFloats);
	this->normalB = (float*)malloc(sizeof(float) * this->nFloats);
	this->textureB = (float*)malloc(sizeof(float) * this->nVertices * 2);

	// definir valores predefinidos de acordo com
	// http://msdn.microsoft.com/en-us/library/windows/desktop/dd373945(v=vs.85).aspx
	this->emissiva = Vec3(0.0, 0.0, 0.0);
	this->especular = Vec3(0.0, 0.0, 0.0);
	this->ambiente = Vec3(0.8, 0.8, 0.8);
	this->difusa = Vec3(0.2, 0.2, 0.2);
	this->shininess = 0;

	// preencher os vértices
	this->preencherVertices();

	

	// preencher indices
	this->vertexI = (int*)malloc(sizeof(int) * this->nVertices);
	preencherIndices();

	// seleccionar os buffers e meter dados
	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos]);   // selecionar buffer para vértices
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->vertexB, GL_STATIC_DRAW); // meter vértices

	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos+1]); // selecionar buffer para normais
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nFloats, this->normalB, GL_STATIC_DRAW); // meter normais

	glBindBuffer(GL_ARRAY_BUFFER,CG_OBJ::buffers[this->bufferPos+2]); // selecionar buffer para texturas
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->nVertices * 2, this->textureB, GL_STATIC_DRAW); // meter texturas
}

/////////////// static
void CG_OBJ::prepararBuffer(int maxBuffers){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_2D);

	CG_OBJ::maxBuffers = maxBuffers*3;
	CG_OBJ::buffers = (GLuint*) malloc(CG_OBJ::maxBuffers * sizeof(GLuint));
	
	glGenBuffers(CG_OBJ::maxBuffers, CG_OBJ::buffers);
}

void CG_OBJ::revolutionSolidClose(float *x, float *y, int count, int fatias, Vec3 pos){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;
	int ni = 0;
	int ti = 0;

	int ri = 0; // iterador de fase no sólido de revolução

	float alpha;
	float alphaDelta;
	

	
	float cmp = 0;
	float cmpNext = 0;

	//Vec3 atual, proximo; // vetores para medir o ângulo

	float difX = (y[ri+1] - y[ri]);
	float difY = -(x[ri+1] - x[ri]);
	float difSX = ((y[ri+1] - y[ri])+(y[ri+2] - y[ri+1]))/2; //smooth
	float difSY = (-(x[ri+1] - x[ri])-(x[ri+2] - x[ri+1]))/2; //smooth

	// fecho em baixo
	cmp = cmpNext;
	cmpNext += sqrt( (x[ri+1] - x[ri])*(x[ri+1] - x[ri]) + (y[ri+1]-y[ri])*(y[ri+1]-y[ri]) );

	/*atual.reset( x[ri], y[ri], 0);
	proximo.reset( x[ri+1], y[ri+1], 0);
	proximo.decrementar( &atual );*/

	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

		this->addVertex(&vi,pos.X() + x[ri],pos.Y() + y[ri],pos.Z());
		this->addVertex(&vi,pos.X() + x[ri+1] * sin(alphaDelta), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alphaDelta));
		this->addVertex(&vi,pos.X() + x[ri+1] * sin(alpha), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alpha));
		
		
		/*if( acos( atual.innerProduct(&proximo) / (atual.norma() * proximo.norma()) ) >= anguloRigido || true ){
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
		}else{*/
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
		//}

		this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmp/comprimento);
		this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmpNext/comprimento);
		this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmpNext/comprimento);
	}


	// secções da figura
	for(ri++; ri < count-2; ri++){
		difX = (y[ri+1] - y[ri]);
		difY = -(x[ri+1] - x[ri]);
		difSX = ((y[ri+1] - y[ri])+(y[ri+2] - y[ri+1]))/2; //smooth
		difSY = (-(x[ri+1] - x[ri])-(x[ri+2] - x[ri+1]))/2; //smooth

		cmp = cmpNext;
		cmpNext += sqrt( (x[ri+1] - x[ri])*(x[ri+1] - x[ri]) + (y[ri+1]-y[ri])*(y[ri+1]-y[ri]) );

		
		/*atual.reset( x[ri], y[ri], 0);
		proximo.reset( x[ri+1], y[ri+1], 0);
		proximo.decrementar( &atual );*/

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);
			

			this->addVertex(&vi,pos.X() + x[ri] * sin(alpha), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alpha));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alphaDelta), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alpha), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alpha));
			
			/*if( acos( atual.innerProduct(&proximo) / (atual.norma() * proximo.norma()) ) >= anguloRigido || true ){
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			}else{*/
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
				this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
				this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
			//}
			
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmp/comprimento);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmpNext/comprimento);
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmpNext/comprimento);
			
			this->addVertex(&vi,pos.X() + x[ri] * sin(alphaDelta), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alphaDelta), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri] * sin(alpha), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alpha));
			
			/*if( acos( atual.innerProduct(&proximo) / (atual.norma() * proximo.norma()) ) >= anguloRigido || true ){
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alpha));
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			}else{*/
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
				this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			//}
			
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 0, 0);
		}

	}

	
	ri = count -1;
	difX = (y[ri] - y[ri-1]);
	difY = -(x[ri] - x[ri-1]);
	
	difSX = ((y[ri] - y[ri-1])+(y[ri-1] - y[ri-2]))/2; //smooth
	difSY = (-(x[ri] - x[ri-1])-(x[ri-1] - x[ri-2]))/2; //smooth
	
	cmp = cmpNext;
	cmp += sqrt( (x[ri] - x[ri-1])*(x[ri] - x[ri-1]) + (y[ri]-y[ri-1])*(y[ri]-y[ri-1]) );

	/*atual.reset( x[ri-1], y[ri-1], 0);
	proximo.reset( x[ri], y[ri], 0);
	proximo.decrementar( &atual );*/

	// fecho em cima
	for(int fatia=0; fatia < fatias; fatia++){
		alpha = delta * fatia;
		alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,pos.X() + x[ri],pos.Y() + y[ri],pos.Z());
			this->addVertex(&vi,pos.X() + x[ri-1] * sin(alpha), pos.Y() + y[ri-1], pos.Z() + x[ri-1] * cos(alpha));
			this->addVertex(&vi,pos.X() + x[ri-1] * sin(alphaDelta), pos.Y() + y[ri-1], pos.Z() + x[ri-1] * cos(alphaDelta));
		
			/*if( acos( atual.innerProduct(&proximo) / (atual.norma() * proximo.norma()) ) >= anguloRigido || true ){
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alpha));
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			}else{*/
				this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
				this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
				this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
			//}

			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmp/comprimento);
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmpNext/comprimento);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmpNext/comprimento);
	}
}

void CG_OBJ::revolutionSolidOpen(float *x, float *y, int count, int fatias, Vec3 pos){
	float delta = 2 * M_PI / fatias;
	
	int vi = 0;
	int ni = 0;
	int ti = 0;

	int ri = 0; // iterador de fase no sólido de revolução

	float cmp = 0;
	float cmpNext = 0;

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

		cmp = cmpNext;
		cmpNext += sqrt( (x[ri+1] - x[ri])*(x[ri+1] - x[ri]) + (y[ri+1]-y[ri])*(y[ri+1]-y[ri]) );

		// desenhar o reclangulo (=2 triangulos) dos lados
		for(int fatia=0; fatia < fatias; fatia++){
			alpha = delta * fatia;
			alphaDelta = delta * (fatia+1);

			this->addVertex(&vi,pos.X() + x[ri] * sin(alpha), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alpha));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alphaDelta), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alpha), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alpha), difSY, difSX * cos(alpha));
			
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmp/comprimento);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmpNext/comprimento);
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmpNext/comprimento);
			
			this->addVertex(&vi,pos.X() + x[ri] * sin(alphaDelta), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri+1] * sin(alphaDelta), pos.Y() + y[ri+1], pos.Z() + x[ri+1] * cos(alphaDelta));
			this->addVertex(&vi,pos.X() + x[ri] * sin(alpha), pos.Y() + y[ri], pos.Z() + x[ri] * cos(alpha));
			
			this->addNormal(&ni, difX * sin(alphaDelta), difY, difX * cos(alphaDelta));
			this->addNormal(&ni, difSX * sin(alphaDelta), difSY, difSX * cos(alphaDelta));
			this->addNormal(&ni, difX * sin(alpha), difY, difX * cos(alpha));
			
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmp/comprimento);
			this->addTextureCoord(&ti, (fatia+1)/(float)fatias, 1-cmpNext/comprimento);
			this->addTextureCoord(&ti, fatia/(float)fatias, 1-cmp/comprimento);
		}
	}
}

void CG_OBJ::preencherIndices(){
	int duplicados = 0;

	for(unsigned int i=0; i<this->nVertices; i++)
		vertexI[i] = 0xFFFFFFFF; // meter todos com o maior valor uint possivel
	
	for(unsigned int i=0; i<this->nVertices; i++){
		if( vertexI[i] == 0xFFFFFFFF ){
			vertexI[i] = i;
			for(int j=i+1; j<this->nVertices; j++){
				if( vertexB[i*3] == vertexB[j*3] &&
					vertexB[i*3+1] == vertexB[j*3+1] &&
					vertexB[i*3+2] == vertexB[j*3+2] && // se as coordenadas forem iguais
					
					normalB[i*3] == normalB[j*3] &&
					normalB[i*3+1] == normalB[j*3+1] &&
					normalB[i*3+2] == normalB[j*3+2] && // e se as normais forem iguais

					textureB[i*2] == textureB[j*2] &&
					textureB[i*2+1] == textureB[j*2+1] ){ // e se as coordenadas de textura forem iguais
						
						duplicados++;
						vertexI[j] = i; // é um duplicado!! -> mete no array de vertexI a apontar para lá
				}
			}
		}
	}
//	printf("VBO c/ indices: %d de %d eram duplicados!\n", duplicados, this->nVertices);
}

/////////////// non-static
void CG_OBJ::desenhar(){
	// Bind e semântica para vértices
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos]);
	glVertexPointer(3,GL_FLOAT,0,0);
	
	// Bind e semântica para normais
	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos+1]);
	glNormalPointer(GL_FLOAT,0,0);

	glBindBuffer(GL_ARRAY_BUFFER,buffers[this->bufferPos+2]);
	glTexCoordPointer(2,GL_FLOAT,0,0);

	//glMaterialfv(GL_FRONT, componente, array);

	float aux[3];
	glMaterialfv(GL_FRONT,GL_EMISSION,this->emissiva.getAll(aux));
	glMaterialfv(GL_FRONT,GL_SPECULAR,this->especular.getAll(aux));
	glMaterialfv(GL_FRONT,GL_AMBIENT,this->ambiente.getAll(aux));
	glMaterialfv(GL_FRONT,GL_DIFFUSE,this->difusa.getAll(aux));
	glMaterialfv(GL_FRONT,GL_SHININESS,&this->shininess);
	
	//  Desenhar
	//glDrawArrays(GL_TRIANGLES, 0, this->nVertices);
	glDrawElements(GL_TRIANGLES, this->nVertices ,GL_UNSIGNED_INT, vertexI); //com indices
	//resetMaterialPoperties();
}

CG_OBJ *CG_OBJ::setEmissiva(float r, float g, float b){
	this->emissiva = Vec3(r,g,b);
	return this;
}

CG_OBJ *CG_OBJ::setEspecular(float r, float g, float b){
	this->especular = Vec3(r,g,b);
	return this;
}

CG_OBJ *CG_OBJ::setAmbiente(float r, float g, float b){
	this->ambiente = Vec3(r,g,b);
	return this;
}

CG_OBJ *CG_OBJ::setDifusa(float r, float g, float b){
	this->difusa = Vec3(r,g,b);
	return this;
}

CG_OBJ *CG_OBJ::setShininess(float s){
	this->shininess = s;
	return this;
}

/////////////// abstract
void CG_OBJ::preencherVertices(){}

