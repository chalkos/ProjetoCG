#include <glew.h>
#include <GL/glut.h>

#ifndef __LIGHT_H_INCLUDED__
#define __LIGHT_H_INCLUDED__

class Light{
public:
	//glLightfv(GL_LIGHT0, GL_POSITION, pos);
	static void posicao(GLenum light, float x, float y, float z, float w);
	static void ambiente(GLenum light, float r, float g, float b);
	static void difusa(GLenum light, float r, float g, float b);
	static void especular(GLenum light, float r, float g, float b);
	static void enable(GLenum light);
	static void disable(GLenum light);
};

#endif // __LIGHT_H_INCLUDED__