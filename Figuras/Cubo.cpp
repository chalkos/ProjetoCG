#include "Cubo.h"

/*********************************

	Cubo

**********************************/
void Cubo::preencherVertices(){
	float mlado = lado/2;
	float nx = lado/camadasx;
	float ny = lado/camadasy;
	float nz = lado/camadasz;

	int vi=0;
	int ni=0;
	int ti=0;

	//baixo
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {	
			this->addVertex(&vi,-mlado + i*nx, -mlado, mlado - j*nz);
			this->addVertex(&vi,-mlado + i*nx, -mlado, mlado - (j+1)*nz);
			this->addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - (j+1)*nz);
		
			this->addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - j*nz);
			this->addVertex(&vi,-mlado + i*nx, -mlado, mlado - j*nz);
			this->addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - (j+1)*nz);

			
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);

			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
			
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
		}
	}
	//cima
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,-mlado + i*nx, mlado, mlado - j*nz);
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - (j+1)*nz);
			this->addVertex(&vi,-mlado + i*nx, mlado, mlado - (j+1)*nz);
		
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - j*nz);
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - (j+1)*nz);
			this->addVertex(&vi,-mlado + i*nx, mlado, mlado - j*nz);

			
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);

			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);

			
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasz);
			
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasz);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasz);
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasz);
		}
	
	}

	//frente
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasy; j++) {		
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - j*ny, mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - j*ny, mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - (j+1)*ny, mlado);
		
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - j*ny, mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - (j+1)*ny, mlado);
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - (j+1)*ny, mlado);

			
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);

			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);

			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasy);
			
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasy);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasy);
		}
	}
	//atras
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasy; j++) {		
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - j*ny, -mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - (j+1)*ny, -mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - j*ny, -mlado);

			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - j*ny, -mlado);
			this->addVertex(&vi,-mlado + (i+1)*nx, mlado - (j+1)*ny,-mlado);
			this->addVertex(&vi,-mlado + i*nx, mlado - (j+1)*ny, -mlado);

			
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);

			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);

			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, j/(float)camadasy);
			
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, j/(float)camadasy);
			this->addTextureCoord(&ti, (i+1)/(float)camadasx, (j+1)/(float)camadasy);
			this->addTextureCoord(&ti, i/(float)camadasx, (j+1)/(float)camadasy);
		}
	}

	//direita
	for(int i=0; i<camadasy; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,mlado, -mlado + i*ny, -mlado + j*nz);
			this->addVertex(&vi,mlado, -mlado + (i+1)*ny, -mlado + j*nz);
			this->addVertex(&vi,mlado, -mlado + (i+1)*ny, -mlado + (j+1)*nz);

			this->addVertex(&vi,mlado, -mlado + i*ny , -mlado + j*nz);
			this->addVertex(&vi,mlado, -mlado + (i+1)*ny , -mlado + (j+1)*nz);
			this->addVertex(&vi,mlado, -mlado + i*ny, -mlado + (j+1)*nz);

			
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);

			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);

			this->addTextureCoord(&ti, j/(float)camadasz, 1-i/(float)camadasy);
			this->addTextureCoord(&ti, j/(float)camadasz, 1-(i+1)/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-(i+1)/(float)camadasy);
			
			this->addTextureCoord(&ti, j/(float)camadasz, 1-i/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-(i+1)/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-i/(float)camadasy);
		}
	}
	//esquerda
	for(int i=0; i<camadasy; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,-mlado, -mlado + i*ny, -mlado + j*nz);
			this->addVertex(&vi,-mlado, -mlado + (i+1)*ny, -mlado + (j+1)*nz);
			this->addVertex(&vi,-mlado, -mlado + (i+1)*ny, -mlado + j*nz);

			this->addVertex(&vi,-mlado, -mlado + i*ny , -mlado + j*nz);
			this->addVertex(&vi,-mlado, -mlado + i*ny, -mlado + (j+1)*nz);
			this->addVertex(&vi,-mlado, -mlado + (i+1)*ny , -mlado + (j+1)*nz);

			
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);

			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);

			this->addTextureCoord(&ti, j/(float)camadasz, 1-i/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-(i+1)/(float)camadasy);
			this->addTextureCoord(&ti, j/(float)camadasz, 1-(i+1)/(float)camadasy);
			
			this->addTextureCoord(&ti, j/(float)camadasz, 1-i/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-i/(float)camadasy);
			this->addTextureCoord(&ti, (j+1)/(float)camadasz, 1-(i+1)/(float)camadasy);
		}
	}
}

Cubo::Cubo(float lado, int camadasx, int camadasy, int camadasz){
	this->lado = lado;
	this->camadasx = camadasx;
	this->camadasy = camadasy;
	this->camadasz = camadasz;

	this->guardarOBJ(
		this->camadasx * this->camadasz * 4 +  // baixo, cima
		this->camadasx * this->camadasy * 4 +  // frente, tras
		this->camadasy * this->camadasz * 4  // esquerda, direita
		);
}