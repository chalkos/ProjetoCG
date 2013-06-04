#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

class Input{
private:
	static bool keyDown[256];

public:
	static void init();

	static void keyPress(unsigned char tecla, int x, int y);
	static void KeyUp(unsigned char tecla, int x, int y);

	static void processInput();

	// variável de testes
	static bool apenasLinhas;
};

#endif // __INPUT_H_INCLUDED__
