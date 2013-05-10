#include <iostream>
using namespace std;

#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Input.h"
#include "Camera.h"



bool Input::keyDown[256];
float Input::teste1 = 20;
float Input::teste2 = 3.1415;
float Input::teste3 = 70;
bool Input::apenasLinhas = false;

void Input::init(){
	// se isto n�o estiver definido, ao deixar uma tecla premida ele manda muitos sinais TeclaPressionada,TeclaN�oPressionada
	// com isto apenas � enviado um sinal TeclaPressionada, e um TeclaN�oPressionada quando se p�ra de carragar na tecla (e esse evento � tratado no Input::keyup)
	// este sistema (de flags) tamb�m permite que se consiga fazer um movimento para tr�s e para a direita ao mesmo tempo
	glutIgnoreKeyRepeat(1);

	// associar fun��es
	glutKeyboardFunc(Input::keyPress);
    glutKeyboardUpFunc(Input::KeyUp);
	glutSpecialFunc(Input::specialKeyPress);

	glutMouseFunc(Input::mouseButton);
	glutMotionFunc(Camera::mouseMove);
	glutPassiveMotionFunc(Camera::mouseMove);
}

void Input::mouseButton(int bot�o, int estado, int x, int y){

}

void Input::specialKeyPress(int tecla, int x, int y){
	
}

void Input::keyPress(unsigned char tecla, int x, int y){
	// mostrar as teclas
	//cout << "tecla: (0x" << hex << (int)tecla << dec << ") " << tecla << endl;
	
	//sair ao carregar ESC
	if(tecla == 27)
        exit(0);

	//sair do modo FPS ao carregar na barra de espa�os
	if(tecla == 32)
		Camera::toggleFPS();


	if(tecla == 'z' || tecla == 'Z'){
		apenasLinhas = !apenasLinhas;
		if( apenasLinhas )
			glDisable(GL_CULL_FACE);
		else
			glEnable(GL_CULL_FACE);
	}
	
	
	keyDown[tecla] = true;
	
	
}

void Input::KeyUp(unsigned char tecla, int x, int y){
    keyDown[tecla] = false;
}

void Input::processInput(){
	if( keyDown['w'] || keyDown['W'] )
		Camera::moverFrente();
	if( keyDown['s'] || keyDown['S'] )
		Camera::moverTras();
	if( keyDown['a'] || keyDown['A'] )
		Camera::moverEsquerda();
	if( keyDown['d'] || keyDown['D'] )
		Camera::moverDireita();

	// vari�vel para testes
	if( keyDown['j'] || keyDown['J'] ){
		Input::teste1 -= 0.1;
		cout << "[-] altura = " << Input::teste1 << endl;
	}
	
	if( keyDown['u'] || keyDown['U'] ){
		Input::teste1 += 0.1;
		cout << "[+] altura = " << Input::teste1 << endl;
	}

	if( keyDown['k'] || keyDown['K'] ){
		Input::teste2 -= 0.05;
		cout << "[-] angulo = " << Input::teste2 << endl;
	}
	
	if( keyDown['i'] || keyDown['I'] ){
		Input::teste2 += 0.05;
		cout << "[+] angulo = " << Input::teste2 << endl;
	}

	if( keyDown['l'] || keyDown['L'] ){
		Input::teste3 -= 0.1;
		cout << "[-] raio = " << Input::teste3 << endl;
	}
	
	if( keyDown['o'] || keyDown['O'] ){
		Input::teste3 += 0.1;
		cout << "[+] raio = " << Input::teste3 << endl;
	}
	
	if( keyDown['+'] ){
		Camera::passoMaior();
	}

	if( keyDown['-'] ){
		Camera::passoMenor();
	}


	
}

