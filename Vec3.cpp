#include <math.h>

#include "Vec3.h"

Vec3::Vec3(){}

Vec3 Vec3::clone(){
	return Vec3(this);
}

Vec3::Vec3(Vec3 *elem){
	vec[0] = elem->getVal(0);
	vec[1] = elem->getVal(1);
	vec[2] = elem->getVal(2);
}

Vec3::Vec3(float a, float b, float c){
	this->vec[0] = a;
	this->vec[1] = b;
	this->vec[2] = c;
}

void Vec3::reset(float A, float B, float C){
	this->vec[0] = A;
	this->vec[1] = B;
	this->vec[2] = C;
}

Vec3::Vec3(float *vec){
	this->vec[0] = vec[0];
	this->vec[1] = vec[1];
	this->vec[2] = vec[2];
}

float Vec3::getVal(int pos){
	return this->vec[pos];
}

float Vec3::X(){
	return this->vec[0];
}

float Vec3::Y(){
	return this->vec[1];
}

float Vec3::Z(){
	return this->vec[2];
}

void Vec3::setVal(int pos, float val){
	this->vec[pos] = val;
}

void Vec3::incrementar( Vec3 *inc ){
	this->vec[0] += inc->getVal(0);
	this->vec[1] += inc->getVal(1);
	this->vec[2] += inc->getVal(2);
}

void Vec3::decrementar( Vec3 *dec ){
	this->vec[0] -= dec->getVal(0);
	this->vec[1] -= dec->getVal(1);
	this->vec[2] -= dec->getVal(2);
}

Vec3 Vec3::somar( Vec3 *vec ){
	return Vec3(
		this->vec[0] + vec->getVal(0),
		this->vec[1] + vec->getVal(1),
		this->vec[2] + vec->getVal(2));
}

Vec3 Vec3::multiplicar( float val ){
	return Vec3(
		this->vec[0] * val,
		this->vec[1] * val,
		this->vec[2] * val);
}

Vec3 Vec3::crossProduct( Vec3 *snd ){
	return Vec3(
		vec[1] * snd->getVal(2) - snd->getVal(1) * vec[2],
		vec[2] * snd->getVal(0) - snd->getVal(2) * vec[0],
		vec[0] * snd->getVal(1) - snd->getVal(0) * vec[1]);
}

float Vec3::innerProduct( Vec3 *snd){
	return
		vec[0] * snd->getVal(0) +
		vec[1] * snd->getVal(1) +
		vec[2] * snd->getVal(2);
}

void Vec3::normalizar(){
	float norm = sqrt( vec[0] * vec[0] + vec[1] * vec[1] + vec[1] * vec[2] );
	
	vec[0] /= norm;
	vec[1] /= norm;
	vec[2] /= norm;
}

float *Vec3::getAll(float *arr){
	arr[0] = X();
	arr[1] = Y();
	arr[2] = Z();
	return arr;
}

float Vec3::norma(){
	return sqrt( vec[0] * vec[0] + vec[1] * vec[1] + vec[1] * vec[2] );
}