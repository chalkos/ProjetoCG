#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <float.h>
#include <glew.h>
#include <GL/glut.h>

#include "ObjectTree.h"

#include "Figuras\CG_OBJ.h"
#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\SolidoRevolucao.h"
#include "Figuras\Triangulo.h"

#include "Frustum.h"
#include "Profiler.h"

#include "Utilities.h"

#define a 60   // altura das paredes (6*u)
#define u 10   // undidade
#define m 5    // metade
#define q 2.5  // um quarto
#define o 1.25 // um oitavo
#define p 0.05 // distancia pequena


ObjectTree *ObjectTree::raizObj = NULL;

void ObjectTree::init(){

	CG_OBJ::prepararBuffer(300); // preparar buffers

	Light *lTeste = (new Light(luz0))
		->setPos(Vec3(10,10,10), 0)
		->setAmb(Vec3(0.2, 0.2, 0.2))
		->setDif(Vec3(0.9, 0.9, 0.9));
	
	ObjectTree *resChao = new ObjectTree();
	ObjectTree *telhado = new ObjectTree();
	ObjectTree *deco = new ObjectTree();
	raizObj = (new ObjectTree())
		->addFilho( resChao )
		->addFilho( deco )
		//->addFilho( telhado )
		;

	// chão
	resChao->addFilho( (new ObjectTree)->objecto( new Plano(24*u+2*o, 40*u+2*o, 12, 20) )->translate(Vec3(12*u, 0, -20*u))
		->texture(TipoTextura::texChaoMadeira, 1, 1, 0));

	// paredes do lado da porta
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as paredes deste lado
		//parede de pedra
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 4*u+o, 2, 2) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*a, o, -0.5*(4*u+o)+o))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 32*u+o, 2, 16) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*a, o, -8*u -0.5*(32*u+o) ))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 4*u-o, 2, 2) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*a, o, 0.5*(4*u+o)))
			->texture(TipoTextura::texParedeDentro, 1, 1, -90)) //lado de dentro
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 32*u-o, 2, 16) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*a, o, 8*u +0.5*(32*u-o) ))
			->texture(TipoTextura::texParedeDentro, 1, 1, -90)) //lado de dentro
		//madeira vertical fina
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, -q+o+p))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, +q-4*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, -q-8*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, +q-14*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, -q-20*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, q-28*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, -q-34*u))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a-q), o+p, q-40*u-o-p))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		//secções de madeira vertical
		->addFilho( (new ObjectTree)->objecto( new Plano(a, u*6, 1, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a), o+p, -17*u))
			->texture(TipoTextura::texMadeira, 12, 2, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(4*u, 3*u, 1, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(3*u)+u, o+p+p, -17*u))
			->texture(TipoTextura::texCalmCookie, 1, 1, -90)) //poster cookie
		->addFilho( (new ObjectTree)->objecto( new Plano(a, u*6, 1, 1) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*(a), o+p, -31*u))
			->texture(TipoTextura::texMadeira, 12, 2, -90))
		//madeira vertical por cima da porta
		->addFilho( (new ObjectTree)->objecto( new Plano(u, 4*u, 1, 2) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(a-m, o+p, -6*u))
			->texture(TipoTextura::texMadeira, 4, 1, -90))
		//madeira horizontal na parte de cima
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 4*u+o+p, 1, 4) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(a-o, o+p, -0.5*(4*u+o+p)+o+p))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 6*u, 1, 4) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(a-o, o+p, -11*u))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 8*u, 1, 4) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(a-o, o+p, -24*u))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 6*u+o+p, 1, 4) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(a-o, o+p, -40*u-o-p +0.5*(6*u+o+p)   ))
			->texture(TipoTextura::texMadeira, 1, 1, 0))
		); //fim paredes do lado da porta

	// paredes do lado esquerdo à porta
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as paredes deste lado
		//parede de pedra
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(12*u+o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*a, 40*u+o, -(12*u)))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(12*u-o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*a, -40*u+o, (12*u)))
			->texture(TipoTextura::texParedeDentro, 1, 1, -90)) //parte de dentro
		//madeira vertical fina
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 40*u+o+p, -q+o+p ))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 40*u+o+p, -8*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 40*u+o+p, -16*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 40*u+o+p, -24*u+q-o-p))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		//madeira horizontal na parte de cima
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 2*(12*u+o+p), 1, 24) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(a-o, 40*u+o+p, -12*u))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
	); //fim paredes do lado esquerdo à porta

	// paredes do lado direito da porta
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as paredes deste lado
		//parede de pedra
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(12*u+o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*a, o, (12*u)))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(12*u-o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(-90, Vec3(1,0,0))->translate(Vec3(0.5*a, +o, -(12*u)))
			->texture(TipoTextura::texParedeDentro, 1, 1, -90)) //parte de dentro
		//madeira vertical fina
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), o+p, q-o-p ))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), o+p, 8*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), o+p, 16*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), o+p, 24*u-q+o+p))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		//madeira horizontal na parte de cima
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 2*(12*u+o+p), 1, 24) )->rotate( 90, Vec3(0,0,1) )->rotate(90, Vec3(1,0,0))->translate(Vec3(a-o, o+p, 12*u))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
	); //fim paredes do lado direito da porta

	// paredes do lado em frente à porta
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as paredes deste lado
		//parede de pedra
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(20*u+o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*a, 24*u+o, (20*u)))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 2*(20*u-o), 2, 12) )->rotate( 90, Vec3(0,0,1) )->rotate(0, Vec3(1,0,0))->translate(Vec3(0.5*a, -24*u+o, -(20*u)))
			->texture(TipoTextura::texParedeDentro, 1, 1, -90)) //parte de dentro
		//madeira vertical fina
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 24*u+o+p, q-o-p ))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 24*u+o+p, 10*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 24*u+o+p, 20*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, u, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 24*u+o+p, 30*u))
			->texture(TipoTextura::texMadeira, 2, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a-q, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*(a-q), 24*u+o+p, 40*u-q+o+p))
			->texture(TipoTextura::texMadeira, 1, 1, -90))
		//madeira horizontal na parte de cima
		->addFilho( (new ObjectTree)->objecto( new Plano(q, 2*(20*u+o+p), 1, 24) )->rotate( 90, Vec3(0,0,1) )->rotate(180, Vec3(1,0,0))->translate(Vec3(a-o, 24*u+o+p, 20*u))
			->texture(TipoTextura::texMadeira, 0.5, 1, 0))
	); //fim paredes do lado em frente à porta

	// palco
	/*
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as escadas
		->addFilho( (new ObjectTree)->objecto(new Plano(16*u, 16*u, 1, 1))->translate(Vec3(12*u, q, -32*u))
			->texture( TipoTextura::texAlcatifaVermelha, 4, 4, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 16*u, 1, 32))->rotate( 90, Vec3(0,0,1) )->rotate( 90, Vec3(1,0,0) )->translate(Vec3(q/2, -24*u, 12*u))
			->texture( TipoTextura::texMadeiraVermelha, 1, 1, 180))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 16*u, 1, 32))->rotate( 90, Vec3(0,0,1) )->translate(Vec3(q/2, -4*u,-32*u))
			->texture( TipoTextura::texMadeiraVermelha, 1, 1, 180))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 16*u, 1, 32))->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(q/2, 20*u, 32*u))
			->texture( TipoTextura::texMadeiraVermelha, 1, 1, 180))
	); //fim palco*/

	// balcão
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as partes do balcão
		//pés do balcão
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 7*u, 1, 3))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*o, -11*u+o, -3.5*u-o ))
			->texture( TipoTextura::texMadeiraEscura, 0.1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 11*u+q, 1, 3))->rotate(90, Vec3(0,0,1))->rotate(-90,Vec3(1,0,0))->translate(Vec3(0.5*o, 7*u+o, -0.5*(11*u+q)-11*u+o))
			->texture( TipoTextura::texMadeiraEscura, 0.1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, u, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*o, 22*u+o, m+6*u+o ))
			->texture( TipoTextura::texMadeiraEscura, 0.1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 10*u+q, 1, 3))->rotate(90, Vec3(0,0,1))->rotate(90,Vec3(1,0,0))->translate(Vec3(0.5*o, -6*u-o, 0.5*(10*u+q)+12*u-o))
			->texture( TipoTextura::texMadeiraEscura, 0.1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 6*u, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*o, 12*u-o, 3*u+o ))
			->texture( TipoTextura::texMadeiraEscura, 0.1, 1, 0))
		//corpo do balcão
		->addFilho( (new ObjectTree)->objecto(new Plano(u+m+q, 7*u+o, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*(u+m+q)+o, -11*u+q, -0.5*(7*u+o)-o ))
			->texture( TipoTextura::texMadeiraEscura, 1, 2, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u+m+q, 11*u+m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(-90, Vec3(1,0,0))->translate(Vec3( 0.5*(u+m+q)+o, 7*u+q, -0.5*(11*u+m)-11*u+q))
			->texture( TipoTextura::texMadeiraEscura, 1, 3, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u+m+q, 10*u+q, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(90, Vec3(1,0,0))->translate(Vec3( 0.5*(u+m+q)+o, -6*u, 0.5*(10*u+m)+12*u-o))
			->texture( TipoTextura::texMadeiraEscura, 1, 3, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u+m+q, 6*u-o, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*(u+m+q)+o, 12*u, 0.5*(6*u-o)+o ))
			->texture( TipoTextura::texMadeiraEscura, 1, 2, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u+m+q, u+q, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*(u+m+q)+o, 22*u+q, 0.5*(u+q)+(6*u-o)+o ))
			->texture( TipoTextura::texMadeiraEscura, 0.3, 1, 90))
		//Tampo do balcão parte de baixo
		->addFilho( (new ObjectTree)->objecto(new Plano(2*u, 8*u-o, 1, 1))->rotate(180, Vec3(0,0,1))->translate(Vec3( -0.5*(2*u)-10*u, -2*u+o, -0.5*(8*u-o)-o))
			->texture( TipoTextura::texMarble, 3, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(9*u+m+m+q, 2*u, 1, 1))->rotate(180, Vec3(0,0,1))->translate(Vec3( -0.5*(9*u+m+m+q)-12*u, -2*u+o, -0.5*(2*u)-6*u))
			->texture( TipoTextura::texMarble, 1, 4, 90))
		//Tampo, parte lateral
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 8*u-o, 1, 1))->rotate(90,Vec3(0,0,1))->translate(Vec3( 0.5*o+2*u-o, -10*u, -0.5*(8*u-o)-o))
			->texture( TipoTextura::texMarble, 3, 0.1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 11*u+m+m+q, 1, 1))->rotate(90,Vec3(0,0,1))->rotate(-90,Vec3(1,0,0))->translate(Vec3( 0.5*o+2*u-o, 8*u, -0.5*(11*u+m+m+q)-10*u))
			->texture( TipoTextura::texMarble, 3, 0.1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 9*u+m+m+q, 1, 1))->rotate(90,Vec3(0,0,1))->rotate(90,Vec3(1,0,0))->translate(Vec3( 0.5*o+2*u-o, -6*u, 0.5*(9*u+m+m+q)+12*u))
			->texture( TipoTextura::texMarble, 3, 0.1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 2*u, 1, 1))->rotate(90,Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*o+2*u-o, 22*u+q, 0.5*(2*u)+6*u))
			->texture( TipoTextura::texMarble, 1, 0.1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(o, 6*u-o, 1, 1))->rotate(90,Vec3(0,0,1))->rotate(180,Vec3(1,0,0))->translate(Vec3( 0.5*o+2*u-o, 12*u, 0.5*(6*u-o)+o))
			->texture( TipoTextura::texMarble, 3, 0.1, 90))
		//Tampo do balcão parte de cima
		->addFilho( (new ObjectTree)->objecto(new Plano(2*u, 6*u-o, 1, 1))->translate(Vec3( 0.5*(2*u)+10*u, 2*u, -0.5*(6*u-o)-o))
			->texture( TipoTextura::texMarble, 3, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(2*u, 2*u, 1, 1))->translate(Vec3(0.5*(2*u) + 10*u, 2*u, -0.5*(2*u) + -6*u))
			->texture( TipoTextura::texMarble, 1, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(9*u+m+m+q, 2*u, 1, 1))->translate(Vec3( 0.5*(9*u+m+m+q)+12*u, 2*u, -0.5*(2*u)-6*u))
			->texture( TipoTextura::texMarble, 1, 3, 90))
		//cenas em cima do balcão
			//...
	); //fim balcão


	// portas
	resChao->addFilho( (new ObjectTree) //apenas para agrupar o que diz respeito às portas
		->addFilho( (new ObjectTree)->objecto(new Plano(a-u, 2*u, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*(a-u), o+p, -0.5*(2*u)-4*u))
			->texture( TipoTextura::texDoorRight, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto(new Plano(a-u, 2*u, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*(a-u), o+p, -0.5*(2*u)-6*u))
			->texture( TipoTextura::texDoorLeft, 1, 1, -90))
		//parte de dentro
		->addFilho( (new ObjectTree)->objecto(new Plano(a-u, 2*u, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3( 0.5*(a-u), o+p, 0.5*(2*u)+6*u))
			->texture( TipoTextura::texDoorRight, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto(new Plano(a-u, 2*u, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3( 0.5*(a-u), o+p, 0.5*(2*u)+4*u))
			->texture( TipoTextura::texDoorLeft, 1, 1, -90))
	); //fim portas

	// decoração de paredes interiores do lado da porta
	for(int i=10; i<38; i+=2){
		deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*a, o+p, i*u))
			->texture(TipoTextura::texMadeira, 1, 2, 90));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(q, o+p, i*u+u))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a*0.5, o+p, i*u+u))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a-m+q, o+p, i*u+u))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
	}
	deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*a, o+p, 38*u))
		->texture(TipoTextura::texMadeira, 1, 2, 90));
	//madeira vertical fina (lado de dentro)
	deco->addFilho( (new ObjectTree)->objecto( new Plano(a, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*(a), o+p, 0.5*m+o+p))
		->texture(TipoTextura::texMadeira, 1, 2, 90)); //esquina
	deco->addFilho( (new ObjectTree)->objecto( new Plano(a, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*(a), o+p, -0.5*m+4*u))
		->texture(TipoTextura::texMadeira, 1, 2, 90)); //lado da porta
	deco->addFilho( (new ObjectTree)->objecto( new Plano(a, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*(a), o+p, 0.5*m+8*u))
		->texture(TipoTextura::texMadeira, 1, 2, 90)); //outro lado da porta
	deco->addFilho( (new ObjectTree)->objecto( new Plano(a, m, 2, 1) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*(a), o+p, -0.5*m+40*u-o-p))
		->texture(TipoTextura::texMadeira, 1, 2, 90)); //esquina do fundo
	//madeira vertical por cima da porta (lado de dentro)
	deco->addFilho( (new ObjectTree)->objecto( new Plano(u, 4*u, 1, 2) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(a-m, o+p, 6*u))
		->texture(TipoTextura::texMadeira, 4, 1, -90));
	//madeira horizontal (lado de dentro)
	deco->addFilho( (new ObjectTree)->objecto( new Plano(m, 2*u-q-m, 1, 1) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(a-q, o+p, 0.5*(2*u-q-m)+8*u+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*u-q-m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(q, o+p, 0.5*(2*u-q-m)+8*u+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*u-q-m, 1, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a*0.5, o+p, 0.5*(2*u-q-m)+8*u+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));

	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*u-q-m-p-o, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(q, o+p, 0.5*(2*u-q-m-p-o)+38*u+q))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*u-q-m-p-o, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a*0.5, o+p, 0.5*(2*u-q-m-p-o)+38*u+q))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*u-q-m-p-o, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a-m+q, o+p, 0.5*(2*u-q-m-p-o)+38*u+q))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	
	deco->addFilho( (new ObjectTree)->objecto( new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(a-q, o+p, 0.5*(0.5*(4*u-o-p-u)-q)+o+p+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(q, o+p, 0.5*(0.5*(4*u-o-p-u)-q)+o+p+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a*0.5, o+p, 0.5*(0.5*(4*u-o-p-u)-q)+o+p+m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));

	deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(0.5*a, o+p, 0.5*(4*u+o+p)))
		->texture(TipoTextura::texMadeira, 1, 2, 90));
	
	deco->addFilho( (new ObjectTree)->objecto( new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(a-q, o+p, -0.5*(0.5*(4*u-o-p-u)-q)+4*u-m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(q, o+p, -0.5*(0.5*(4*u-o-p-u)-q)+4*u-m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 0.5*(4*u-o-p-u)-q, 1, 2))->rotate(90, Vec3(0,0,1))->rotate(180, Vec3(1,0,0))->translate(Vec3(a*0.5, o+p, -0.5*(0.5*(4*u-o-p-u)-q)+4*u-m))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	
	
	// decoração de paredes interiores do lado oposto ao da porta
	for(int i=0; i<36; i+=2){
		deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(0.5*a, -24*u+o+p, -0.5*(m)-i*u-o-p))
			->texture(TipoTextura::texMadeira, 1, 2, 90));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(q, -24*u+o+p, -i*u-u-o-q-p))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(a*0.5, -24*u+o+p, -i*u-u-o-q-p))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
		deco->addFilho( (new ObjectTree)->objecto(new Plano(m, u+m, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(a-m+q, -24*u+o+p, -i*u-u-o-q-p))
			->texture(TipoTextura::texMadeira, 1, 1, 0));
	}
	deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(0.5*a, -24*u+o+p, -0.5*(m)-36*u-o-p))
		->texture(TipoTextura::texMadeira, 1, 2, 90));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(a, m, 2, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(0.5*a, -24*u+o+p, -0.5*(m)-40*u-o+m+q+p))
		->texture(TipoTextura::texMadeira, 1, 2, 90));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 4*u-q-2*p-u, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(q, -24*u+o+p, -0.5*(4*u-q-2*p-u)-36*u-m-o-p))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 4*u-q-2*p-u, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(a*0.5, -24*u+o+p, -0.5*(4*u-q-2*p-u)-36*u-m-o-p))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 4*u-q-2*p-u, 1, 1))->rotate(90, Vec3(0,0,1))->translate(Vec3(a-m+q, -24*u+o+p, -0.5*(4*u-q-2*p-u)-36*u-m-o-p))
		->texture(TipoTextura::texMadeira, 1, 1, 0));
	
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*(12*u-p-o), 1, 12))->rotate(90, Vec3(0,0,1))->rotate(-90, Vec3(1,0,0))->translate(Vec3(q, o+p, -0.5*(2*(12*u-p-o))-o-p))
		->texture( TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*(12*u-p-o), 1, 12))->rotate(90, Vec3(0,0,1))->rotate(-90, Vec3(1,0,0))->translate(Vec3(a-q, o+p, -0.5*(2*(12*u-p-o))-o-p))
		->texture( TipoTextura::texMadeira, 1, 1, 0));
	
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*(12*u-p-o), 1, 12))->rotate(90, Vec3(0,0,1))->rotate(90, Vec3(1,0,0))->translate(Vec3(q, -40*u+o+p, 0.5*(2*(12*u-p-o))+o+p))
		->texture( TipoTextura::texMadeira, 1, 1, 0));
	deco->addFilho( (new ObjectTree)->objecto(new Plano(m, 2*(12*u-p-o), 1, 12))->rotate(90, Vec3(0,0,1))->rotate(90, Vec3(1,0,0))->translate(Vec3(a-q, -40*u+o+p, 0.5*(2*(12*u-p-o))+o+p))
		->texture( TipoTextura::texMadeira, 1, 1, 0));
	
	// mesa bilhar
	resChao->addFilho( (new ObjectTree) //apenas para agrupar o que diz respeito à mesa de bilhar
		// tecido na area de jogo
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, 4*u, 3, 2))->translate(Vec3( 0.5*(6*u)+4*u, 2*u, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// madeira na parte de baixo da mesa
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, 4*u+m, 4, 3))->rotate(-180, Vec3(0,0,1))->translate(Vec3( -0.5*(6*u)-4*u, -1*u-m, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		// tecido acima
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->translate(Vec3( 0.5*(q)+4*u-q, 2*u+q, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->translate(Vec3( 0.5*(q)+10*u, 2*u+q, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, q, 3, 1))->translate(Vec3( 0.5*(6*u+m)+4*u-q, 2*u+q, -40*u+0.5*(q)+7*u-q))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, q, 3, 1))->translate(Vec3( 0.5*(6*u+m)+4*u-q, 2*u+q, -40*u+0.5*(q)+11*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// tecido nas bordas
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->rotate(-90, Vec3(0,0,1))->translate(Vec3( -0.5*(q)-2*u, 4*u, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*(q)+2*u, -10*u, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, q, 3, 1))->rotate(90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+4*u, -40*u+7*u, -0.5*(q)-2*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, q, 3, 1))->rotate(-90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+4*u, 40*u-11*u, 0.5*(q)+2*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// madeira exterior
		->addFilho( (new ObjectTree)->objecto(new Plano(u-q, 4*u+m, 1, 2))->rotate(-90, Vec3(0,0,1))->translate(Vec3( 0.5*(u-q)-2*u-q, 10*u+q, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u-q, 4*u+m, 1, 2))->rotate(90, Vec3(0,0,1))->translate(Vec3( -0.5*(u-q)+2*u+q, -4*u+q, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, u-q, 3, 1))->rotate(90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+4*u, -40*u+11*u+q, 0.5*(u-q)-2*u-q  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, u-q, 3, 1))->rotate(-90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+4*u, 40*u-7*u+q, -0.5*(u-q)+2*u+q  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		// pernas
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+4*u)/u, 0, (-40*u+0.5*(m+q)+7*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+9*u)/u, 0, (-40*u+0.5*(m+q)+7*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+4*u)/u, 0, (-40*u+0.5*(m+q)+10*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+9*u)/u, 0, (-40*u+0.5*(m+q)+10*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
	); //fim mesa bilhar
	
	// segunda mesa bilhar (a da direita
	resChao->addFilho( (new ObjectTree) //apenas para agrupar o que diz respeito à mesa de bilhar
		// tecido na area de jogo
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, 4*u, 3, 2))->translate(Vec3( 0.5*(6*u)+14*u, 2*u, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// madeira na parte de baixo da mesa
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, 4*u+m, 4, 3))->rotate(-180, Vec3(0,0,1))->translate(Vec3( -0.5*(6*u)-14*u, -1*u-m, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		// tecido acima
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->translate(Vec3( 0.5*(q)+14*u-q, 2*u+q, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->translate(Vec3( 0.5*(q)+110*u, 2*u+q, -40*u+0.5*(4*u)+7*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, q, 3, 1))->translate(Vec3( 0.5*(6*u+m)+14*u-q, 2*u+q, -40*u+0.5*(q)+7*u-q))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, q, 3, 1))->translate(Vec3( 0.5*(6*u+m)+14*u-q, 2*u+q, -40*u+0.5*(q)+11*u))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// tecido nas bordas
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->rotate(-90, Vec3(0,0,1))->translate(Vec3( -0.5*(q)-2*u, 14*u, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(q, 4*u, 1, 2))->rotate(90, Vec3(0,0,1))->translate(Vec3( 0.5*(q)+2*u, -20*u, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, q, 3, 1))->rotate(90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+14*u, -40*u+7*u, -0.5*(q)-2*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u, q, 3, 1))->rotate(-90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+14*u, 40*u-11*u, 0.5*(q)+2*u  ))
			->texture( TipoTextura::texBilharTecido, 1, 1, 0))
		// madeira exterior
		->addFilho( (new ObjectTree)->objecto(new Plano(u-q, 4*u+m, 1, 2))->rotate(-90, Vec3(0,0,1))->translate(Vec3( 0.5*(u-q)-2*u-q, 20*u+q, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(u-q, 4*u+m, 1, 2))->rotate(90, Vec3(0,0,1))->translate(Vec3( -0.5*(u-q)+2*u+q, -14*u+q, -40*u+0.5*(4*u)+7*u  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 90))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, u-q, 3, 1))->rotate(90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+14*u, -40*u+11*u+q, 0.5*(u-q)-2*u-q  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new Plano(6*u+m, u-q, 3, 1))->rotate(-90, Vec3(1,0,0))->translate(Vec3( 0.5*(6*u)+14*u, 40*u-7*u+q, -0.5*(u-q)+2*u+q  ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		// pernas
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+14*u)/u, 0, (-40*u+0.5*(m+q)+7*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+19*u)/u, 0, (-40*u+0.5*(m+q)+7*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+14*u)/u, 0, (-40*u+0.5*(m+q)+10*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
		->addFilho( (new ObjectTree)->objecto(new SolidoRevolucao(pernaBilhar, 10))->scale(Vec3(u,u,u))->translate(Vec3( (0.5*(m+q)+19*u)/u, 0, (-40*u+0.5*(m+q)+10*u)/u ))
			->texture( TipoTextura::texMadeiraEscura, 1, 1, 0))
	); //fim mesa bilhar



	
	checkBounds(raizObj);
}

void ObjectTree::checkBounds(ObjectTree *tree){
	if( tree == NULL )
		return;

	if( tree->obj == NULL && tree->numFilhos == 0 ){
		std::cout << "[ERRO] Não pode haver árvores sem filhos e sem objectos!\nPress any key to exit" << std::endl;
		_getch();
		exit(EXIT_FAILURE);
	}

	// verificar os limites dos filhos
	for(int i=0; i<tree->numFilhos; i++)
		checkBounds( tree->filhos[i] );
	
	// atribuir valores predefinidos absurdos
	tree->boundsMin = new Vec3(FLT_MAX, FLT_MAX, FLT_MAX);
	tree->boundsMax = new Vec3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

	// verificar o próprio limite (caso tenha um objecto)
	if( tree->obj != NULL ){
		tree->boundsMin->setX( tree->obj->minBound->X() );
		tree->boundsMin->setY( tree->obj->minBound->Y() );
		tree->boundsMin->setZ( tree->obj->minBound->Z() );
		tree->boundsMax->setX( tree->obj->maxBound->X() );
		tree->boundsMax->setY( tree->obj->maxBound->Y() );
		tree->boundsMax->setZ( tree->obj->maxBound->Z() );

		// obter o local efectivo
		localEfectivo(tree, tree->boundsMin);
		localEfectivo(tree, tree->boundsMax);
	}

	// expandir o próprio conforme o tamanho dos filhos (caso os tenha)
	for(int i=0; i<tree->numFilhos; i++){
		if( tree->boundsMin->X() > tree->filhos[i]->boundsMin->X() ) tree->boundsMin->setX( tree->filhos[i]->boundsMin->X() );
		if( tree->boundsMin->Y() > tree->filhos[i]->boundsMin->Y() ) tree->boundsMin->setY( tree->filhos[i]->boundsMin->Y() );
		if( tree->boundsMin->Z() > tree->filhos[i]->boundsMin->Z() ) tree->boundsMin->setZ( tree->filhos[i]->boundsMin->Z() );
		
		if( tree->boundsMax->X() < tree->filhos[i]->boundsMax->X() ) tree->boundsMax->setX( tree->filhos[i]->boundsMax->X() );
		if( tree->boundsMax->Y() < tree->filhos[i]->boundsMax->Y() ) tree->boundsMax->setY( tree->filhos[i]->boundsMax->Y() );
		if( tree->boundsMax->Z() < tree->filhos[i]->boundsMax->Z() ) tree->boundsMax->setZ( tree->filhos[i]->boundsMax->Z() );
	}
}

void ObjectTree::localEfectivo(ObjectTree *tree, Vec3 *ponto){
	Vec3 res = Vec3();
	GLfloat matriz[16];

	glPushMatrix();
	for(int i=0; i<tree->modsCount; i++)
			switch( tree->modsTipo[i] ){
			case TipoMod::rotação:
				glRotatef( tree->modsExtra[i], tree->modsVec[i].X(), tree->modsVec[i].Y(), tree->modsVec[i].Z());
				break;
			case TipoMod::translação:
				glTranslatef(tree->modsVec[i].X(), tree->modsVec[i].Y(), tree->modsVec[i].Z());
				break;
			case TipoMod::escala:
				glScalef(tree->modsVec[i].X(), tree->modsVec[i].Y(), tree->modsVec[i].Z());
				break;
			}

	glGetFloatv(GL_MODELVIEW_MATRIX, matriz);

	res.setX( matriz[0] * ponto->X() + matriz[4] * ponto->Y() + matriz[8] * ponto->Z() + matriz[12] );
	res.setY( matriz[1] * ponto->X() + matriz[5] * ponto->Y() + matriz[9] * ponto->Z() + matriz[13] );
	res.setZ( matriz[2] * ponto->X() + matriz[6] * ponto->Y() + matriz[10] * ponto->Z() + matriz[14] );
	
	ponto->setX( res.X() );
	ponto->setY( res.Y() );
	ponto->setZ( res.Z() );

	glPopMatrix();
}

void ObjectTree::draw(){
	drawAux( raizObj, frusIntersecta);
}

void ObjectTree::drawAux( ObjectTree *raiz, PosicaoNoFrustum posNoFrustum){
	if( raiz == NULL )
		return;

	if( raiz->toggle != NULL && *raiz->toggle == false )
		return;

	// se não estiver visivel, não desenha
	if( posNoFrustum != frusDentro )
		if( (posNoFrustum = Frustum::boxInFrustum( raiz->boundsMin, raiz->boundsMax ) ) == frusFora )
			return;

	if( raiz->obj != NULL ){

		// desenhar o próprio
		glPushMatrix();

		// ligar luzes
		for(int i=0; i<8; i++){
			if( raiz->luzes[i] == NULL ){
				if( i == 0 ){ //não ligou nenhum luz
					Light::disable(GL_LIGHTING);
					glColor3f( raiz->cor.X(), raiz->cor.Y(), raiz->cor.Z());
				}
				break;
			}
			raiz->luzes[i]->aplicarELigar();
		}

		/*
		// mostrar bounding boxes
		glColor3f(1,0,0);
		glBegin(GL_LINES);
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMax->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMax->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMax->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMin->Y(), raiz->boundsMax->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMin->Y(), raiz->boundsMax->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMax->Y(), raiz->boundsMax->Z());
		
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMax->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMax->Y(), raiz->boundsMax->Z());
		glVertex3f( raiz->boundsMin->X(), raiz->boundsMax->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMax->Y(), raiz->boundsMin->Z());
		
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMax->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMin->Y(), raiz->boundsMin->Z());
		glVertex3f( raiz->boundsMax->X(), raiz->boundsMin->Y(), raiz->boundsMax->Z());
		glEnd();
		glColor3f(1,1,1);
		*/

		// colocar textura
		if( raiz->texTipo >= 0 && raiz->texTipo < TipoTextura::texCOUNT_ENUM)
			Textura::setTextura(raiz->texTipo, raiz->texScaleX, raiz->texScaleY, raiz->texAnguloRotacao);
		else
			Textura::unsetTextura();

		for(int i=0; i<raiz->modsCount; i++)
			switch( raiz->modsTipo[i] ){
			case TipoMod::rotação:
				glRotatef( raiz->modsExtra[i], raiz->modsVec[i].X(), raiz->modsVec[i].Y(), raiz->modsVec[i].Z());
				break;
			case TipoMod::translação:
				glTranslatef(raiz->modsVec[i].X(), raiz->modsVec[i].Y(), raiz->modsVec[i].Z());
				break;
			case TipoMod::escala:
				glScalef(raiz->modsVec[i].X(), raiz->modsVec[i].Y(), raiz->modsVec[i].Z());
				break;
			}

		// efectivamente desenhar
		raiz->obj->desenhar();
		

		// desligar luzes
		for(int i=0; i<8; i++){
			if( raiz->luzes[i] == NULL ){
				if( i == 0 ) //voltar a ligar a iluminação
					Light::enable(GL_LIGHTING);
				break;
			}
			raiz->luzes[i]->desligar();
		}

		glPopMatrix(); 
	}

	// desenhar filhos
	for(int i=0; i<raiz->numFilhos; i++)
		drawAux( raiz->filhos[i], posNoFrustum );
	return;
}

ObjectTree::ObjectTree(){
	this->modsCount = 0;
	this->modsExtra = NULL;
	this->modsTipo = NULL;
	this->modsVec = NULL;

	texturizar = false;
	cor = Vec3(1,1,1);

	toggle = NULL;

	for(int i=0; i<8; i++)
		luzes[i] = NULL;

	numFilhos = 0;
	filhos = NULL;

	obj = NULL;
}

ObjectTree *ObjectTree::rotate( float angulo, Vec3 vec ){
	this->modsTipo = (TipoMod*)realloc(this->modsTipo, sizeof(TipoMod) * (this->modsCount+1));
	this->modsVec = (Vec3*)realloc(this->modsVec, sizeof(Vec3) * (this->modsCount+1));
	this->modsExtra = (float*)realloc(this->modsExtra, sizeof(float) * (this->modsCount+1));

	this->modsTipo[ this->modsCount ] = TipoMod::rotação;
	this->modsVec[ this->modsCount ] = vec.clone();
	this->modsExtra[ this->modsCount ] = angulo;

	this->modsCount++;

	return this;
}

ObjectTree *ObjectTree::translate( Vec3 vec ){
	this->modsTipo = (TipoMod*)realloc(this->modsTipo, sizeof(TipoMod) * (this->modsCount+1));
	this->modsVec = (Vec3*)realloc(this->modsVec, sizeof(Vec3) * (this->modsCount+1));
	this->modsExtra = (float*)realloc(this->modsExtra, sizeof(float) * (this->modsCount+1));

	this->modsTipo[ this->modsCount ] = TipoMod::translação;
	this->modsVec[ this->modsCount ] = vec.clone();
	this->modsExtra[ this->modsCount ] = 0;

	this->modsCount++;
	return this;
}

ObjectTree *ObjectTree::scale( Vec3 vec ){
	this->modsTipo = (TipoMod*)realloc(this->modsTipo, sizeof(TipoMod) * (this->modsCount+1));
	this->modsVec = (Vec3*)realloc(this->modsVec, sizeof(Vec3) * (this->modsCount+1));
	this->modsExtra = (float*)realloc(this->modsExtra, sizeof(float) * (this->modsCount+1));

	this->modsTipo[ this->modsCount ] = TipoMod::escala;
	this->modsVec[ this->modsCount ] = vec.clone();
	this->modsExtra[ this->modsCount ] = 0;

	this->modsCount++;
	return this;
}

ObjectTree *ObjectTree::color( Vec3 vec ){
	this->texturizar = false;
	this->cor = vec.clone();
	return this;
}

ObjectTree *ObjectTree::texture( TipoTextura tipo, float sX, float sY, float anguloRot ){
	this->texturizar = true;
	this->texTipo = tipo;
	this->texScaleX = sX;
	this->texScaleY = sY;
	this->texAnguloRotacao = anguloRot;
	return this;
}

ObjectTree *ObjectTree::addLight( Light *luz ){
	int i;
	for(i=0; i<8; i++){
		if( luzes[i] == NULL )
			break;
	}

	if( i >= 8 ) return this;

	luzes[i] = luz;
	return this;
}

ObjectTree *ObjectTree::addFilho( ObjectTree *filho ){
	int incremento = 1;

	filhos = (ObjectTree**)realloc( filhos, (numFilhos+incremento)*sizeof(ObjectTree*));

	filhos[numFilhos] = filho;

	numFilhos += incremento;

	return this;
}

ObjectTree *ObjectTree::objecto( CG_OBJ *O ){
	this->obj = O;
	return this;
}