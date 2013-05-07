class Input{
private:
	static bool keyDown[256];

public:
	static void init();

	static void mouseMove(int x, int y);
	static void mouseButton(int botão, int estado, int x, int y);

	static void specialKeyPress(int tecla, int x, int y);
	static void keyPress(unsigned char tecla, int x, int y);
	static void KeyUp(unsigned char tecla, int x, int y);

	static void timer(int value);

	// variável de testes
	static float teste1;
	static float teste2;
};

