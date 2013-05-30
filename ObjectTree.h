#ifndef __OBJECTTREE_H_INCLUDED__
#define __OBJECTTREE_H_INCLUDED__

#include "Vec3.h"
#include "Light.h"
#include "Figuras\CG_OBJ.h"
#include "Textura.h"

enum TipoMod {
	translação,
	rotação,
	escala
};

class ObjectTree{
private:
	//nodo

	// modificações (translações, rotações, escalas)
	int modsCount;
	TipoMod *modsTipo;
	Vec3 *modsVec;
	float *modsExtra;

	bool texturizar;
	Vec3 cor;
	TipoTextura texTipo;
	float texScaleX, texScaleY, texAnguloRotacao;
	Light *luzes[8];
	CG_OBJ *obj;
	bool *toggle;

	// filhos
	int numFilhos;
	ObjectTree **filhos;

	// a árvore
	static ObjectTree *raizObj;
	static void drawAux( ObjectTree *raiz );

public:
	ObjectTree();
	
	ObjectTree *rotate( float angulo, Vec3 vec );
	ObjectTree *translate( Vec3 vec );
	ObjectTree *scale( Vec3 vec );
	ObjectTree *color( Vec3 vec );
	ObjectTree *texture( TipoTextura tipo, float sX, float sY, float anguloRot );
	ObjectTree *addLight( Light *luz );

	ObjectTree *objecto( CG_OBJ *O );

	ObjectTree *addFilho( ObjectTree *filho );

	static ObjectTree *init();
	static void draw();
};

#endif // __OBJECTTREE_H_INCLUDED__