#ifndef __TEXTURA_H_INCLUDED__
#define __TEXTURA_H_INCLUDED__

enum TipoTextura {
	texMadeira,
	texMetal,
	texPlanetaTerra,
	texLava1,

	// não alterar
	texCOUNT_ENUM
};

class Textura {
public:

	// static
	static void init();
	static int getWidth(TipoTextura tipoTextura);
	static int getHeight(TipoTextura tipoTextura);
	static void setTextura(TipoTextura tipoTextura);
	static void unsetTextura();

	// non-static
	int getWidth();
	int getHeight();



private:
	// static
	static char **filenames;
	static ILuint *imageIds;
	static GLuint *textureIds;
	static Textura *texturas;

	// non-static
	int t, tw, th;
	ILubyte *imageData;

	Textura(TipoTextura tipoTextura);
	
};

#endif // __TEXTURA_H_INCLUDED__