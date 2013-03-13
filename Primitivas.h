#ifndef __PRIMITIVAS_H_INCLUDED__
#define __PRIMITIVAS_H_INCLUDED__

class Primitivas{
public:
	
	/// <summary>cria um plano XZ, centrado na origem com os vertices especificados</summary>
	/// <param name='comprimento'>Comprimento (ao longo do eixo x)</param>
	/// <param name='largura'>Largura (ao longo do eixo z)</param>
	static void criarPlano(float comprimento, float largura=-1);
	 
	/// <summary>cria um cubo</summary>
	/// <param name='lado'>Comprimento do lado do cubo</param>
	static void criarCubo(float lado);

	/// <summary>cria um cilindro</summary>
	/// <param name='raio'>O raio da base</param>
	/// <param name='altura'>A altura do cilindro</param>
	/// <param name='fatias'>Número de fatias</param>
	/// <param name='seccoes'>Número de secções</param>
	static void criarCilindro(float raio, float altura, unsigned fatias, unsigned seccoes);
};


#endif // __PRIMITIVAS_H_INCLUDED__