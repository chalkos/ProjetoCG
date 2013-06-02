#include "Plano3D.h"

Plano3D::Plano3D(){}

Plano3D::Plano3D( Vec3 *normal, Vec3 *ponto ){
	this->normal = normal->clone();
	this->ponto = ponto->clone();
	this->D = -this->normal.innerProduct( &this->ponto );
}

Vec3 Plano3D::getPonto(){
	return this->ponto.clone();
}

Vec3 Plano3D::getNormal(){
	return this->normal.clone();
}

float Plano3D::distancia( Vec3 *ponto ){
	return this->normal.innerProduct( ponto ) + this->D;
}