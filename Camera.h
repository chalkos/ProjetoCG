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
	
};