#ifndef __PRIMITIVAS_H_INCLUDED__
#define __PRIMITIVAS_H_INCLUDED__

class Primitivas{
public:
	
	/// <summary>cria um plano XZ, centrado na origem com os vertices especificados</summary>
	/// <param name='x1'>Primeira coordenada (x)</param>
	/// <param name='z1'>Primeira coordenada (z)</param>
	/// <param name='x2'>Segunda coordenada (x)</param>
	/// <param name='z2'>Segunda coordenada (z)</param>
	/// <param name='x3'>Terceira coordenada (x)</param>
	/// <param name='z3'>Terceira coordenada (z)</param>
	/// <param name='x4'>Quarta coordenada (x)</param>
	/// <param name='z4'>Quarta coordenada (z)</param>
	/// <param name='cor'>A cor (em hexadecimal) para pintar o plano</param>
	static void criarPlano(float x1, float z1, float x2, float z2, float x3, float z3, float x4, float z4, unsigned cor = 0x0);
	 
	/// <summary>cria um cubo</summary>
	/// <param name='lado'>Comprimento do lado do cubo</param>
	static void criarCubo(float lado);

	/// <summary>cria um cilindro</summary>
	/// <param name='raio'>O raio da base</param>
	/// <param name='altura'>A altura do cilindro</param>
	/// <param name='fatias'>N�mero de fatias</param>
	static void criarCilindro(float raio, float altura, unsigned fatias);

	/// <summary>cria uma esfera</summary>
	/// <param name='raio'>O raio da esfera</param>
	/// <param name='lati'>O n�mero de camadas na latitude</param>
	/// <param name='longi'>O n�mero de camadas na longitude</param>
	static void criarEsfera(float raio, int lati, int longi);

};


#endif // __PRIMITIVAS_H_INCLUDED__