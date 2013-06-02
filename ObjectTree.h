#ifndef __OBJECTTREE_H_INCLUDED__
#define __OBJECTTREE_H_INCLUDED__

#include "Vec3.h"
#include "Light.h"
#include "Figuras\CG_OBJ.h"
#include "Textura.h"
#include "Frustum.h"

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

	// outras caracteristicas
	bool texturizar;
	Vec3 cor;
	TipoTextura texTipo;
	float texScaleX, texScaleY, texAnguloRotacao;
	Light *luzes[8];
	
	// o objecto a desenhar
	CG_OBJ *obj;
	Vec3 *boundsMin;
	Vec3 *boundsMax;

	// activar/desactivar este objecto
	bool *toggle;

	// filhos
	int numFilhos;
	ObjectTree **filhos;

	// a árvore
	static ObjectTree *raizObj;
	static void drawAux( ObjectTree *raiz, PosicaoNoFrustum posNoFrustum );
	static void checkBounds(ObjectTree *tree);
	static void localEfectivo(ObjectTree *tree, Vec3 *ponto);
	static Light *luzesGlobais[8];

public:
	ObjectTree();
	
	ObjectTree *rotate( float angulo, Vec3 vec );
	ObjectTree *translate( Vec3 vec );
	ObjectTree *scale( Vec3 vec );
	ObjectTree *color( Vec3 vec );
	ObjectTree *texture( TipoTextura tipo, float sX, float sY, float anguloRot );
	ObjectTree *addLight( Light *luz );
	ObjectTree *addLights( Light *luzes[], int i0=-1, int i1=-1, int i2=-1, int i3=-1, int i4=-1, int i5=-1, int i6=-1, int i7=-1);

	ObjectTree *objecto( CG_OBJ *O );

	ObjectTree *addFilho( ObjectTree *filho );

	static void init();
	static void draw();
};

#endif // __OBJECTTREE_H_INCLUDED__