#ifndef __CAMERA_H_INCLUDED__
#define __CAMERA_H_INCLUDED__

enum Fonts {
	BITMAP_8_BY_13 = (int)GLUT_BITMAP_8_BY_13,
	BITMAP_9_BY_15 = (int)GLUT_BITMAP_9_BY_15,
	BITMAP_TIMES_ROMAN_10 = (int)GLUT_BITMAP_TIMES_ROMAN_10,
	BITMAP_TIMES_ROMAN_24 = (int)GLUT_BITMAP_TIMES_ROMAN_24,
	BITMAP_HELVETICA_10 = (int)GLUT_BITMAP_HELVETICA_10,
	BITMAP_HELVETICA_12 = (int)GLUT_BITMAP_HELVETICA_12,
	BITMAP_HELVETICA_18 = (int)GLUT_BITMAP_HELVETICA_18
};

class Camera{

private:
	static bool modoFPS;
	
	// posi��o da c�mara
	static float posX;
	static float posY;
	static float posZ;

	// orienta��o horizontal e vertical
	static float alpha;
	static float beta;

	static float passo; // tamanho de "dar um passo" numa direc��o

	

public:
	static void init(float x, float y, float z);
	static void lookAt();
	static void toggleFPS();
	
	// movimento
	static void moverFrente();
	static void moverTras();
	static void moverEsquerda();
	static void moverDireita();
	static void moveTo(float x, float y, float z);

	// direc��o da c�mara de acordo com a posi��o do rato
	static void mouseMove(int x, int y);
	static void lookAt(float x, float y, float z); //direc��o for�ada

	// velocidade da c�mara
	static void passoMaior();
	static void passoMenor();

	// texto debug
	static void setOrthographicProjection();
	static void restorePerspectiveProjection();
	static void renderString( float x, float y, int spacing, Fonts font, char *string);
	
};


#endif // __CAMERA_H_INCLUDED__