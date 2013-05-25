#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

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

	static void processInput();

	// variável de testes
	static float teste1;
	static float teste2;
	static float teste3;
	static bool apenasLinhas;
};

#endif // __INPUT_H_INCLUDED__
