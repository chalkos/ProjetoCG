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