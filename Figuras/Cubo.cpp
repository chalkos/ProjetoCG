#include "Cubo.h"

/*********************************

	Cubo

**********************************/
void Cubo::preencherVertices(){
	float mlado = lado/2;
	float nx = lado/camadasx;
	float nz = lado/camadasz;

	int vi=0;

	//baixo
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {	
			CG_OBJ::addVertex(&vi,-mlado + i*nx, -mlado, mlado - j*nz);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, -mlado, mlado - (j+1)*nz);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - (j+1)*nz);
		
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - j*nz);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, -mlado, mlado - j*nz);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, -mlado, mlado - (j+1)*nz);
		}
	}
	//cima
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado, mlado - j*nz);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - (j+1)*nz);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado, mlado - (j+1)*nz);
		
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - j*nz);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado, mlado - (j+1)*nz);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado, mlado - j*nz);
		}
	
	}
	//frente
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - j*nz, mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - j*nz, mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - (j+1)*nz, mlado);
		
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - j*nz, mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - (j+1)*nz, mlado);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - (j+1)*nz, mlado);
		}
	}
	//atras
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - j*nz, -mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - (j+1)*nz, -mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - j*nz, -mlado);

			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - j*nz, -mlado);
			CG_OBJ::addVertex(&vi,-mlado + (i+1)*nx, mlado - (j+1)*nz,-mlado);
			CG_OBJ::addVertex(&vi,-mlado + i*nx, mlado - (j+1)*nz, -mlado);
		}
	}
	//direita
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			CG_OBJ::addVertex(&vi,mlado, -mlado + i*nx, -mlado + j*nz);
			CG_OBJ::addVertex(&vi,mlado, -mlado + (i+1)*nx, -mlado + j*nz);
			CG_OBJ::addVertex(&vi,mlado, -mlado + (i+1)*nx, -mlado + (j+1)*nz);

			CG_OBJ::addVertex(&vi,mlado, -mlado + i*nx , -mlado + j*nz);
			CG_OBJ::addVertex(&vi,mlado, -mlado + (i+1)*nx , -mlado + (j+1)*nz);
			CG_OBJ::addVertex(&vi,mlado, -mlado + i*nx, -mlado + (j+1)*nz);
		}
	}
	//esquerda
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			CG_OBJ::addVertex(&vi,-mlado, -mlado + i*nx, -mlado + j*nz);
			CG_OBJ::addVertex(&vi,-mlado, -mlado + (i+1)*nx, -mlado + (j+1)*nz);
			CG_OBJ::addVertex(&vi,-mlado, -mlado + (i+1)*nx, -mlado + j*nz);

			CG_OBJ::addVertex(&vi,-mlado, -mlado + i*nx , -mlado + j*nz);
			CG_OBJ::addVertex(&vi,-mlado, -mlado + i*nx, -mlado + (j+1)*nz);
			CG_OBJ::addVertex(&vi,-mlado, -mlado + (i+1)*nx , -mlado + (j+1)*nz);
		}
	}
}

Cubo::Cubo(float lado, int camadasx, int camadasz){
	this->lado = lado;
	this->camadasx = camadasx;
	this->camadasz = camadasz;

	this->guardarOBJ( this->camadasx * this->camadasz * 2 * 6);
}