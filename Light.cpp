#include "Light.h"

void Light::posicao(GLenum light, float x, float y, float z, float w){
	GLfloat pos[4] = {x,y,z,w};
	glLightfv(light, GL_POSITION, pos); // posição da luz
}

void Light::ambiente(GLenum light, float r, float g, float b){
	GLfloat amb[3] = {r,g,b};
	glLightfv(light, GL_AMBIENT, amb); // cores da luz
}

void Light::difusa(GLenum light, float r, float g, float b){
	GLfloat diff[3] = {r,g,b};
	glLightfv(light, GL_DIFFUSE, diff); // cores da luz
}

void Light::especular(GLenum light, float r, float g, float b){
	GLfloat spe[3] = {r,g,b};
	glLightfv(light, GL_SPECULAR, spe); // cores da luz
	
}

void Light::enable(GLenum light){
	glEnable(light);
}

void Light::disable(GLenum light){
	glDisable(light);
	if( light == GL_LIGHTING )
		glColor3f(0,0,0);
}

void Light::direccao(GLenum light, float x, float y, float z){
	GLfloat dir[3] = {x,y,z};
	glLightfv(light, GL_SPOT_DIRECTION, dir); 
}

void Light::spotExp(GLenum light, float exp){
	glLightfv(light, GL_SPOT_EXPONENT, &exp); 
}

void Light::spotCutOff(GLenum light, float cutOff){
	glLightfv(light, GL_SPOT_EXPONENT, &cutOff); 
}






Light::Light(){
}

Light::Light(LuzId id){
	this->nr = id;

	this->amb = Vec3(0,0,0);
	this->dif = Vec3(0,0,0);
	this->esp = Vec3(0,0,0);
	this->pos = Vec3(0,0,0);
	this->D = 1;
	this->dir = Vec3(0,0,1);
	this->sExp = 0;
	this->sCutOff = 180;

}

Light *Light::setPos(Vec3 pos, float D){
	this->pos = pos.clone();
	this->D = D;
	return this;
}

Light *Light::setAmb(Vec3 amb){
	this->amb = amb.clone();
	return this;
}

Light *Light::setDif(Vec3 dif){
	this->dif = dif.clone();
	return this;
}

Light *Light::setEsp(Vec3 esp){
	this->esp = esp.clone();
	return this;
}

Light *Light::setDir(Vec3 dir){
	this->dir = dir.clone();
	return this;
}

Light *Light::setSpotExp(float exp){
	this->sExp = exp;
	return this;
}

Light *Light::setSpotCutOff(float cutOff){
	this->sCutOff = cutOff;
	return this;
}

void Light::aplicarELigar(){
	Light::ambiente( nr, amb.X(), amb.Y(), amb.Z() );
	Light::difusa( nr, dif.X(), dif.Y(), dif.Z() );
	Light::especular( nr, esp.X(), esp.Y(), esp.Z() );
	Light::posicao( nr, pos.X(), pos.Y(), pos.Z(), D );
	Light::enable(nr);
}

void Light::desligar(){
	Light::disable(nr);
}