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
	strcpy_s( Textura::filenames[texMadeira], FILENAME_MAX_SIZE, "Texturas/madeira.png" );
	strcpy_s( Textura::filenames[texMadeiraEscura], FILENAME_MAX_SIZE, "Texturas/madeiraEscura.png" );
	strcpy_s( Textura::filenames[texFolhas], FILENAME_MAX_SIZE, "Texturas/folhas.png" );
	strcpy_s( Textura::filenames[texPlanetaTerra], FILENAME_MAX_SIZE, "Texturas/planetaTerra.jpg" );
	strcpy_s( Textura::filenames[texLava1], FILENAME_MAX_SIZE, "Texturas/lava1.png" );
	strcpy_s( Textura::filenames[texSol], FILENAME_MAX_SIZE, "Texturas/sol.jpg" );
	strcpy_s( Textura::filenames[texErvas], FILENAME_MAX_SIZE, "Texturas/ervas.png" );
	strcpy_s( Textura::filenames[texRelva], FILENAME_MAX_SIZE, "Texturas/relva.png" );
	strcpy_s( Textura::filenames[texShinyMetal], FILENAME_MAX_SIZE, "Texturas/shinyMetal.png" );
	strcpy_s( Textura::filenames[texShinyBrushedMetal], FILENAME_MAX_SIZE, "Texturas/shinyBrushedMetal.png" );
	strcpy_s( Textura::filenames[texParedePedra], FILENAME_MAX_SIZE, "Texturas/paredePedra.png" );
	strcpy_s( Textura::filenames[texCalmCookie], FILENAME_MAX_SIZE, "Texturas/calmCookie.png" );
	strcpy_s( Textura::filenames[texChaoMadeira], FILENAME_MAX_SIZE, "Texturas/chaoMadeira.png" );

	// gerar identificadores de imagem
	Textura::imageIds = (ILuint*)malloc(sizeof(ILuint) * texCOUNT_ENUM);
	ilGenImages( texCOUNT_ENUM, Textura::imageIds);

	// gerar identificadores de textura e definir algumas propriedades
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
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->getWidth(), this->getHeight(), 0, 
		GL_RGBA, GL_UNSIGNED_BYTE, this->imageData);
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, this->getWidth(), this->getHeight(),
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

void Textura::setColor(float R, float G, float B){
	unsetTextura();
	glColor3f( R, G, B);

}

void Textura::setTextura(float sx, float sy, float graus){
	glMatrixMode(GL_TEXTURE);

	// apaga as modificações anteriores
	glLoadIdentity();

	// aplica a escala
	glScalef(sx,sy,1);

	// aplica a rotação (CCW)
	glRotatef(graus, 0, 0, 1);
	
	glMatrixMode(GL_MODELVIEW);
}

void Textura::setTextura(TipoTextura tipoTextura, float sx, float sy, float graus){
	glBindTexture(GL_TEXTURE_2D, textureIds[tipoTextura]);
	
	glMatrixMode(GL_TEXTURE);

	// apaga as modificações anteriores
	glLoadIdentity();

	// aplica a escala
	glScalef(sx,sy,1);

	// aplica a rotação (CCW)
	glRotatef(graus, 0, 0, 1);
	
	glMatrixMode(GL_MODELVIEW);
}

void Textura::unsetTextura(){
	glBindTexture(GL_TEXTURE_2D, 0);
	glMatrixMode(GL_TEXTURE);
	// apaga as modificações anteriores
	glLoadIdentity();
	
	glMatrixMode(GL_MODELVIEW);
}

void Textura::translate(float x, float y){
	glMatrixMode(GL_TEXTURE);

	// apaga as modificações anteriores
	glLoadIdentity();

	glTranslatef(x, y, 0);
	
	glMatrixMode(GL_MODELVIEW);
}