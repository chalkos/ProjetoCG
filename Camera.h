class Camera{

private:
	static bool modoFPS;
	
	// posição da câmara
	static float posX;
	static float posY;
	static float posZ;

	// orientação horizontal e vertical
	static float alpha;
	static float beta;

	static float passo; // tamanho de "dar um passo" numa direcção

	

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

	// direcção da câmara de acordo com a posição do rato
	static void mouseMove(int x, int y);
	static void lookAt(float x, float y, float z); //direcção forçada

	// velocidade da câmara
	static void passoMaior();
	static void passoMenor();
	
};