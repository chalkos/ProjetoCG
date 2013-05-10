#ifndef __PROFILER_H_INCLUDED__
#define __PROFILER_H_INCLUDED__

enum ProfilerData {
	proStartup,
	proCarregarFiguras,
	proCarregarTexturas,
	proFrame,
	
	// não acrescentar nada depois deste elemento
	proCOUNT_ENUM
};

class Profiler{
private:
	static int *cronometros;
	static int *emPausa;

	static int frames;
	static float fps;

public:
	static void init();
	static int diff(ProfilerData cronometro);
	static void start(ProfilerData cronometro); //tambem faz resume
	static void reset(ProfilerData cronometro);
	static void pause(ProfilerData cronometro);
	static int now();

	static void startFrame();
	static float getFPS();
};

#endif // __PROFILER_H_INCLUDED__