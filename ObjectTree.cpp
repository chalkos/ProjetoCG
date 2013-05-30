#include <stdlib.h>
#include <stdio.h>
#include <glew.h>
#include <GL/glut.h>

#include "ObjectTree.h"

#include "Figuras\CG_OBJ.h"
#include "Figuras\Plano.h"
#include "Figuras\Cubo.h"
#include "Figuras\Cilindro.h"
#include "Figuras\Esfera.h"
#include "Figuras\SolidoRevolucao.h"

#define a 60   // altura das paredes (6*u)
#define u 10   // undidade
#define m 5    // metade
#define q 2.5  // um quarto
#define o 1.25 // um oitavo
#define p 0.05 // distancia pequena


ObjectTree *ObjectTree::raizObj = NULL;

ObjectTree *ObjectTree::init(){

	CG_OBJ::prepararBuffer(50); // preparar buffers

	Light *lTeste = (new Light(luz0))
		->setPos(Vec3(10,10,10), 0)
		->setAmb(Vec3(0.2, 0.2, 0.2))
		->setDif(Vec3(0.9, 0.9, 0.9));
	
	//raizObj->objecto( (new SolidoRevolucao(TipoSolidoRevolucao::mesa, 3))->setAmbiente(0,0,1) )->scale(Vec3(30, 30, 30));
	//raizObj->objecto( (new SolidoRevolucao(TipoSolidoRevolucao::copoChampanhe, 30))->setAmbiente(0,0,1) );
	
	ObjectTree *resChao = new ObjectTree();
	ObjectTree *primeiroPiso = new ObjectTree();
	ObjectTree *telhado = new ObjectTree();
	raizObj = (new ObjectTree())
		->addFilho( resChao )
		->addFilho( primeiroPiso )
		->addFilho( telhado );
	
	resChao;//->objecto( new Plano(100*a, 20, 20) )->texture(TipoTextura::texRelva, 1,1,0);

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
			->texture(TipoTextura::texParedePedra, 1, 1, -90)) //lado de dentro
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 32*u-o, 2, 16) )->rotate( 90, Vec3(0,0,1) )->rotate( 180, Vec3(1,0,0) )->translate(Vec3(0.5*a, o, 8*u +0.5*(32*u-o) ))
			->texture(TipoTextura::texParedePedra, 1, 1, -90)) //lado de dentro
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
			->texture(TipoTextura::texParedePedra, 1, 1, -90)) //parte de dentro
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
			->texture(TipoTextura::texParedePedra, 1, 1, -90)) //parte de dentro
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
			->texture(TipoTextura::texParedePedra, 1, 1, -90)) //parte de dentro
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



	/*
		->addFilho( (new ObjectTree)
			->objecto( (new Plano(50,25,25))->setAmbiente(0,1,0) )
			->rotate( 45, Vec3(1,0,0)))*/

		
	
	
	return NULL;
}

void ObjectTree::draw(){
	drawAux( raizObj );
}

void ObjectTree::drawAux( ObjectTree *raiz ){
	if( raiz == NULL )
		return;

	if( raiz->toggle != NULL && *raiz->toggle == false )
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
		drawAux( raiz->filhos[i] );
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