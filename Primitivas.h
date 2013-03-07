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
	/// <param n
	static void criarCilindro(float raio, float altura, float fatias);
};


#endif // __PRIMITIVAS_H_INCLUDED__