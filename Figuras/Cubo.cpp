#include "Cubo.h"

/*********************************

	Cubo

**********************************/
void Cubo::preencherVertices(){
	float mladox = compX/2;
	float mladoy = compY/2;
	float mladoz = compZ/2;
	float nx = compX/camadasx;
	float ny = compY/camadasy;
	float nz = compZ/camadasz;

	int vi=0;
	int ni=0;
	int ti=0;

	//baixo
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {	
			this->addVertex(&vi,-mladox + i*nx, -mladoy, mladoz - j*nz);
			this->addVertex(&vi,-mladox + i*nx, -mladoy, mladoz - (j+1)*nz);
			this->addVertex(&vi,-mladox + (i+1)*nx, -mladoy, mladoz - (j+1)*nz);
		
			this->addVertex(&vi,-mladox + (i+1)*nx, -mladoy, mladoz - j*nz);
			this->addVertex(&vi,-mladox + i*nx, -mladoy, mladoz - j*nz);
			this->addVertex(&vi,-mladox+ (i+1)*nx, -mladoy, mladoz - (j+1)*nz);

			
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);

			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			this->addNormal(&ni,0,-1,0);
			
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 1, 1);
			
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 1, 1);
		}
	}
	//cima
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,-mladox + i*nx, mladoy, mladoz - j*nz);
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy, mladoz - (j+1)*nz);
			this->addVertex(&vi,-mladox + i*nx, mladoy, mladoz - (j+1)*nz);
		
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy, mladoz - j*nz);
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy, mladoz - (j+1)*nz);
			this->addVertex(&vi,-mladox + i*nx, mladoy, mladoz - j*nz);

			
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);

			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);
			this->addNormal(&ni,0,1,0);

			
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 1, 1);
			this->addTextureCoord(&ti, 0, 1);
			
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 1, 1);
			this->addTextureCoord(&ti, 0, 0);
		}
	
	}

	//frente
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasy; j++) {		
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - j*ny, mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - j*ny, mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - (j+1)*ny, mladoz);
		
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - j*ny, mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - (j+1)*ny, mladoz);
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - (j+1)*ny, mladoz);

			
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);

			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);
			this->addNormal(&ni,0,0,1);

			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 0, 1);
			
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 1, 1);
		}
	}
	//atras
	for(int i=0; i<camadasx; i++) {
		for(int j=0; j<camadasy; j++) {		
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - j*ny, -mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - (j+1)*ny, -mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - j*ny, -mladoz);

			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - j*ny, -mladoz);
			this->addVertex(&vi,-mladox + (i+1)*nx, mladoy - (j+1)*ny,-mladoz);
			this->addVertex(&vi,-mladox + i*nx, mladoy - (j+1)*ny, -mladoz);

			
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);

			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);
			this->addNormal(&ni,0,0,-1);

			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 0, 0);
			
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 1, 1);
			this->addTextureCoord(&ti, 0, 1);
		}
	}

	//direita
	for(int i=0; i<camadasy; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,mladox, -mladoy + i*ny, -mladoz + j*nz);
			this->addVertex(&vi,mladox, -mladoy + (i+1)*ny, -mladoz + j*nz);
			this->addVertex(&vi,mladox, -mladoy + (i+1)*ny, -mladoz + (j+1)*nz);

			this->addVertex(&vi,mladox, -mladoy + i*ny , -mladoz + j*nz);
			this->addVertex(&vi,mladox, -mladoy + (i+1)*ny , -mladoz + (j+1)*nz);
			this->addVertex(&vi,mladox, -mladoy + i*ny, -mladoz + (j+1)*nz);

			
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);

			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);
			this->addNormal(&ni,1,0,0);

			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 0, 0);
			this->addTextureCoord(&ti, 1, 0);
			
			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 1, 1);
		}
	}
	//esquerda
	for(int i=0; i<camadasy; i++) {
		for(int j=0; j<camadasz; j++) {		
			this->addVertex(&vi,-mladox, -mladoy + i*ny, -mladoz + j*nz);
			this->addVertex(&vi,-mladox, -mladoy + (i+1)*ny, -mladoz + (j+1)*nz);
			this->addVertex(&vi,-mladox, -mladoy + (i+1)*ny, -mladoz + j*nz);

			this->addVertex(&vi,-mladox, -mladoy + i*ny , -mladoz + j*nz);
			this->addVertex(&vi,-mladox, -mladoy + i*ny, -mladoz + (j+1)*nz);
			this->addVertex(&vi,-mladox, -mladoy + (i+1)*ny , -mladoz + (j+1)*nz);

			
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);

			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);
			this->addNormal(&ni,-1,0,0);

			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 1, 0);
			this->addTextureCoord(&ti, 0, 0);
			
			this->addTextureCoord(&ti, 0, 1);
			this->addTextureCoord(&ti, 1, 1);
			this->addTextureCoord(&ti, 1, 0);
		}
	}
}

Cubo::Cubo(float compX, float compY, float compZ, int camadasx, int camadasy, int camadasz){
	this->compX = compX;
	this->compY = compY;
	this->compZ = compZ;
	this->camadasx = camadasx;
	this->camadasy = camadasy;
	this->camadasz = camadasz;

	this->guardarOBJ(
		this->camadasx * this->camadasz * 4 +  // baixo, cima
		this->camadasx * this->camadasy * 4 +  // frente, tras
		this->camadasy * this->camadasz * 4  // esquerda, direita
		);
}

Cubo::Cubo(float lado, int camadasx, int camadasy, int camadasz){
	this->compX = lado;
	this->compY = lado;
	this->compZ = lado;
	this->camadasx = camadasx;
	this->camadasy = camadasy;
	this->camadasz = camadasz;

	this->guardarOBJ(
		this->camadasx * this->camadasz * 4 +  // baixo, cima
		this->camadasx * this->camadasy * 4 +  // frente, tras
		this->camadasy * this->camadasz * 4  // esquerda, direita
		);
}