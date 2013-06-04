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
	// se isto não estiver definido, ao deixar uma tecla premida ele manda muitos sinais TeclaPressionada,TeclaNãoPressionada
	// com isto apenas é enviado um sinal TeclaPressionada, e um TeclaNãoPressionada quando se pára de carragar na tecla (e esse evento é tratado no Input::keyup)
	// este sistema (de flags) também permite que se consiga fazer um movimento para trás e para a direita ao mesmo tempo
	glutIgnoreKeyRepeat(1);

	// associar funções
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

	//sair do modo FPS ao carregar na barra de espaços
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

