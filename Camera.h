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
	static bool frustumNeedsUpdate;
	static bool frustumCullingEnabled;
	
	// posição da câmara
	static float posX;
	static float posY;
	static float posZ;

	// orientação horizontal e vertical
	static float alpha;
	static float beta;

	static float passo; // tamanho de "dar um passo" numa direcção
	
	// frustum culling
	static float dnear; //distancia ao near
	static float dfar; //distancia ao far
	static float fov; //fov, parametro do gluPerspective
	static float ratio; //racio entre o comprimento e largura da janela
	static float Wnear, Hnear; // comprimento e largura do plano near
	static float up[3]; // vector up, como definido no gluLookAt
	static float center[3]; // ponto para onde a câmara está apontada
	static float frustum[]; // os 6 planos do frustum

public:
	static void init(float x, float y, float z);
	static void lookAt();
	static void toggleFPS();
	static void changeSize(int w, int h);
	
	// movimento
	static void moverFrente();
	static void moverTras();
	static void moverEsquerda();
	static void moverDireita();
	static void moveTo(float x, float y, float z);

	// direcção da câmara de acordo com a posição do rato
	static void mouseMove(int x, int y);
	static void lookAt(float x, float y, float z); //direcção forçada

	// velocidade da câmara
	static void passoMaior();
	static void passoMenor();

	// texto debug
	static void setOrthographicProjection();
	static void restorePerspectiveProjection();
	static void renderString( float x, float y, int spacing, Fonts font, char *string);

	//frustum culling
	static void updateFrustum();
	static bool pointInFrustum(float x, float y, float z);
	static bool pointInFrustum(float *p);
	static void toggleFrustumCulling();
	
};


#endif // __CAMERA_H_INCLUDED__