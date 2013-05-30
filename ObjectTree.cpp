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
	
	resChao->objecto( new Plano(100*a, 20, 20) )->texture(TipoTextura::texRelva, 1,1,0);

	// paredes do lado da porta
	resChao->addFilho( (new ObjectTree) //apenas para agrupar as paredes deste lado
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 4*u+o+p, 2, 2) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*a, o, -2*u+o+p))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))
		->addFilho( (new ObjectTree)->objecto( new Plano(a, 32*u, 2, 16) )->rotate( 90, Vec3(0,0,1) )->translate(Vec3(0.5*a, o, -8*u-16*u))
			->texture(TipoTextura::texParedePedra, 1, 1, -90))

			); //fim resChao



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
			if( raiz->luzes[i] == NULL )
				break;
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
			if( raiz->luzes[i] == NULL )
				break;
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