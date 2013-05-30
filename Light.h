#ifndef __LIGHT_H_INCLUDED__
#define __LIGHT_H_INCLUDED__

#include <glew.h>
#include <GL/glut.h>

#include "Vec3.h"

enum LuzId {
	luz0 = GL_LIGHT0,
	luz1 = GL_LIGHT1,
	luz2 = GL_LIGHT2,
	luz3 = GL_LIGHT3,
	luz4 = GL_LIGHT4,
	luz5 = GL_LIGHT5,
	luz6 = GL_LIGHT6,
	luz7 = GL_LIGHT7
};

class Light{
private:
	Vec3 pos;
	float D; //para as coordenadas homogéneas
	Vec3 amb;
	Vec3 dif;
	Vec3 esp;
	Vec3 dir;
	float sExp; // intensidade da luz, 0-128
	float sCutOff; // abertura da luz, [0-90] ou 180
	GLenum nr;

public:
	// static
	static void posicao(GLenum light, float x, float y, float z, float w);
	static void ambiente(GLenum light, float r, float g, float b);
	static void difusa(GLenum light, float r, float g, float b);
	static void especular(GLenum light, float r, float g, float b);
	static void direccao(GLenum light, float x, float y, float z);
	static void spotExp(GLenum light, float exp);
	static void spotCutOff(GLenum light, float cutOff);
	static void enable(GLenum light);
	static void disable(GLenum light);

	// non-static
	Light();
	Light(LuzId id);
	Light *setPos(Vec3 pos, float D);
	Light *setAmb(Vec3 amb);
	Light *setDif(Vec3 dif);
	Light *setEsp(Vec3 esp);
	Light *setDir(Vec3 dir);
	Light *setSpotExp(float exp);
	Light *setSpotCutOff(float cutOff);
	
	void aplicarELigar();
	void desligar();
};

#endif // __LIGHT_H_INCLUDED__