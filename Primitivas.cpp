#include "Primitivas.h"

#include <GL/glut.h>

void Primitivas::criarPlano(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4){
	glBegin(GL_TRIANGLES);
		glVertex3f(x1, 0.0f, z1);
		glVertex3f(x2, 0.0f, z2);
		glVertex3f(x4, 0.0f, z4);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3f(x3, 0.0f, z3);
		glVertex3f(x4, 0.0f, z4);
		glVertex3f(x2, 0.0f, z2);
	glEnd();
}