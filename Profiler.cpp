#include <stdlib.h>

#include <GL/glut.h>

#include "Profiler.h"

int *Profiler::cronometros = NULL;
int *Profiler::emPausa = NULL;
int Profiler::frames = 0;
float Profiler::fps = -1;

void Profiler::init(){
	cronometros = (int*)malloc(sizeof(int) * proCOUNT_ENUM);
	emPausa = (int*)malloc(sizeof(int) * proCOUNT_ENUM);
	for(int i=0; i<proCOUNT_ENUM; i++){
		cronometros[i] = -1;
		emPausa[i] = -1;
	}
}

int Profiler::now(){
	return glutGet(GLUT_ELAPSED_TIME);
}

int Profiler::diff(ProfilerData cronometro){
	if( emPausa[cronometro] != -1 )
		return emPausa[cronometro];
	return now() - cronometros[cronometro];
}

void Profiler::pause(ProfilerData cronometro){
	emPausa[cronometro] = diff(cronometro);
}

void Profiler::start(ProfilerData cronometro){
	if( emPausa[cronometro] != -1 ){
		cronometros[cronometro] = now() - emPausa[cronometro];
		emPausa[cronometro] = -1;
	}else
		cronometros[cronometro] = now();
}

void Profiler::startFrame(){
	if( cronometros[proFrame] == -1 )
		start(proFrame);
	frames++;

	if( diff(proFrame) > 1000 ){
		fps = frames/(float)diff(proFrame)*1000;
		frames = 0;
		start(proFrame);
	}
}

float Profiler::getFPS(){
	return fps;
}