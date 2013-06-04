#include <iostream>
using namespace std;

#include <glew.h>
#include <GL/glut.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

#include "Input.h"
#include "Camera.h"
#include "Frustum.h"



bool Input::keyDown[256];
bool Input::apenasLinhas = false;

void Input::init(){
	// se isto n�o estiver definido, ao deixar uma tecla premida ele manda muitos sinais TeclaPressionada,TeclaN�oPressionada
	// com isto apenas � enviado um sinal TeclaPressionada, e um TeclaN�oPressionada quando se p�ra de carragar na tecla (e esse evento � tratado no Input::keyup)
	// este sistema (de flags) tamb�m permite que se consiga fazer um movimento para tr�s e para a direita ao mesmo tempo
	glutIgnoreKeyRepeat(1);

	// associar fun��es
	glutKeyboardFunc(Input::keyPress);
    glutKeyboardUpFunc(Input::KeyUp);

	glutMotionFunc(Camera::mouseMove);
	glutPassiveMotionFunc(Camera::mouseMove);
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

	if(tecla == 'x' || tecla == 'X'){
		Frustum::toggleFrustumCulling();
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
	
	if( keyDown['+'] ){
		Camera::passoMaior();
	}

	if( keyDown['-'] ){
		Camera::passoMenor();
	}


	
}

