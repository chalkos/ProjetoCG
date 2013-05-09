#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <GL/glut.h>
#include <IL/il.h>

#include "Textura.h"

#define FILENAME_MAX_SIZE 512

char **Textura::filenames = NULL;

ILuint *Textura::imageIds = NULL;
GLuint *Textura::textureIds = NULL;

Textura *Textura::texturas = NULL;

void Textura::init(){
	// alocar espaço para guardar os nomes de ficheiro das texturas
	Textura::filenames = (char**)malloc(sizeof(char*) * TipoTextura::texCOUNT_ENUM);
	for(int i=0; i<TipoTextura::texCOUNT_ENUM; i++)
		Textura::filenames[i] = (char*)malloc(sizeof(char) * FILENAME_MAX_SIZE);

	// definir os nomes de ficheiro das texturas
	strcpy( Textura::filenames[texMadeira], "Texturas/madeira.png" );
	strcpy( Textura::filenames[texMetal], "Texturas/madeira.png" );
	strcpy( Textura::filenames[texPlanetaTerra], "Texturas/planetaTerra.jpg" );
	strcpy( Textura::filenames[texLava1], "Texturas/lava1.png" );

	// gerar identificadores de imagem e textura
	Textura::imageIds = (ILuint*)malloc(sizeof(ILuint) * texCOUNT_ENUM);
	ilGenImages( texCOUNT_ENUM, Textura::imageIds);
	Textura::textureIds = (GLuint*)malloc(sizeof(GLuint) * texCOUNT_ENUM);
	glGenTextures( texCOUNT_ENUM, Textura::textureIds);

	// alocar espaço para os objetos Textura
	texturas = (Textura*)malloc(sizeof(Textura) * texCOUNT_ENUM);
	
	// criar objetos Textura (carregar imagens, criar textura a partir da imagem, ..)
	for(int i=0; i<texCOUNT_ENUM; i++)
		texturas[i] = Textura((TipoTextura)i);

	for(int i=0; i<texCOUNT_ENUM; i++)
		std::cout << "textura: " << filenames[i] << "; dim: " << texturas[i].getWidth() << "x" << texturas[i].getHeight() << "; id=" << imageIds[i] << std::endl;

	unsetTextura();
}

Textura::Textura(TipoTextura tipoTextura){
	ilBindImage(imageIds[tipoTextura]);

	ilLoadImage((ILstring)Textura::filenames[tipoTextura]);
	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	imageData = ilGetData();
	tw = ilGetInteger(IL_IMAGE_WIDTH);
	th = ilGetInteger(IL_IMAGE_HEIGHT);


	// definição de parâmetros de textura
	glBindTexture(GL_TEXTURE_2D,textureIds[tipoTextura]);
	switch( tipoTextura ){
	case texMadeira:
	case texMetal:
	case texPlanetaTerra:
	case texLava1:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		break;

	default:
		break;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->getWidth(), this->getHeight(), 0, 
		GL_RGBA, GL_UNSIGNED_BYTE, this->imageData);
}

int Textura::getWidth(){
	return tw;
}

int Textura::getHeight(){
	return th;
}

int Textura::getWidth(TipoTextura tipoTextura){
	return Textura::texturas[tipoTextura].getWidth();
}

int Textura::getHeight(TipoTextura tipoTextura){
	return Textura::texturas[tipoTextura].getHeight();
}

void Textura::setTextura(TipoTextura tipoTextura){
	glBindTexture(GL_TEXTURE_2D, textureIds[tipoTextura]);
}

void Textura::unsetTextura(){
	glBindTexture(GL_TEXTURE_2D, 0);
}