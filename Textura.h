#ifndef __TEXTURA_H_INCLUDED__
#define __TEXTURA_H_INCLUDED__

#include <GL/glut.h>

#include <IL/il.h>

enum TipoTextura {
	texMadeira,
	texFolhas,
	texPlanetaTerra,
	texLava1,
	texSol,
	texErvas,
	texRelva,
	texShinyMetal,
	texShinyBrushedMetal,

	// n�o acrescentar nada depois deste elemento
	texCOUNT_ENUM
};

class Textura {
public:

	// static
	static void init();
	static int getWidth(TipoTextura tipoTextura);
	static int getHeight(TipoTextura tipoTextura);
	static void setTextura(TipoTextura tipoTextura, float sx=1, float sy=1, float graus=0); //set textura, escala e rota��o
	static void setTextura(float sx, float sy, float graus=0); //set escala e rota��o
	static void translate(float x, float y);
	static void unsetTextura();

	// non-static
	int getWidth();
	int getHeight();



private:
	// static
	static GLuint *textureIds;
	static Textura *texturas;
	static ILuint *imageIds;
	static char **filenames;


	// non-static
	int t, tw, th;
	ILubyte *imageData;

	Textura(TipoTextura tipoTextura);
	
};

#endif // __TEXTURA_H_INCLUDED__