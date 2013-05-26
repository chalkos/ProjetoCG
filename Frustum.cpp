#include <iostream>
using namespace std;

#include "Frustum.h"

#include "Utilities.h"
#include <math.h>

bool Frustum::frustumNeedsUpdate = true;
bool Frustum::frustumCullingEnabled = false;
Plano3D Frustum::plano[planoCOUNT_ENUM];

void Frustum::updateFrustum( Vec3 *pos, Vec3 *up, Vec3 *center, float fov, float ratio, float dNear, float dFar){
	if( !frustumNeedsUpdate || ratio == 0.0f )
		return;

	float tmp[3];
	Vec3 X,Y,Z;


	// obter o comprimento e largura dos planos near e far
	float Hnear = tan(toRadian(fov) / 2.0f) * dNear;
	float Wnear = Hnear * ratio;
	//Hfar = tan(toRadian(fov) / 2.0f) * dfar;
	//Wfar = Hfar * ratio;

	// obter o Z da camara
	Z = pos->clone();
	Z.decrementar( center );
	Z.normalizar();

	// obter o X da camara
	X = up->crossProduct(&Z);
	X.normalizar();

	// obter o up "real" (Y da camara)
	Y = Z.crossProduct( &X );
	
	// definir pontos e normais dos planos do frustum
	Vec3 normal;
	Vec3 ponto;
	Vec3 aux;

	// near
	ponto = pos->clone();
	ponto.decrementar( &Z.multiplicar(dNear) );
	normal = &Z.multiplicar( -1 );
	Frustum::plano[planoNear] = Plano3D( &normal, &ponto );

	// far
	ponto = pos->clone();
	ponto.decrementar( &Z.multiplicar(dFar) );
	normal = Z;
	Frustum::plano[planoFar] = Plano3D( &normal, &ponto );

	// right
	ponto = Frustum::plano[planoNear].getPonto();
	ponto.incrementar( &X.multiplicar( Wnear ) );
	aux = ponto.clone();
	aux.decrementar( pos );
	aux.normalizar();
	normal = Y.crossProduct( &aux );
	Frustum::plano[planoRight] = Plano3D( &normal, &ponto );

	// left
	ponto = Frustum::plano[planoNear].getPonto();
	ponto.decrementar( &X.multiplicar( Wnear ) );
	aux = ponto.clone();
	aux.decrementar( pos );
	aux.normalizar();
	normal = aux.crossProduct( &Y );
	Frustum::plano[planoLeft] = Plano3D( &normal, &ponto );

	// top
	ponto = Frustum::plano[planoNear].getPonto();
	ponto.incrementar( &Y.multiplicar( Hnear ) );
	aux = ponto.clone();
	aux.decrementar( pos );
	aux.normalizar();
	normal = aux.crossProduct( &X );
	Frustum::plano[planoTop] = Plano3D( &normal, &ponto );

	// bottom
	ponto = Frustum::plano[planoNear].getPonto();
	ponto.decrementar( &Y.multiplicar( Hnear ) );
	aux = ponto.clone();
	aux.decrementar( pos );
	aux.normalizar();
	normal = X.crossProduct( &aux );
	Frustum::plano[planoBottom] = Plano3D( &normal, &ponto );

	frustumNeedsUpdate = false;
}


bool Frustum::pointInFrustum( Vec3 *ponto ){

	for( int i=0; i<planoCOUNT_ENUM; i++){
		if( plano[i].distancia(ponto) < 0 )
			return false;
	}

	return true;
}

void Frustum::toggleFrustumCulling(){
	frustumCullingEnabled = !frustumCullingEnabled;

	if( frustumCullingEnabled )
		cout << "[ON] Frustum Culling" << endl;
	else
		cout << "[OFF] Frustum Culling" << endl;
}

bool Frustum::isCullingEnabled(){
	return frustumCullingEnabled;
}

bool Frustum::volumeInFrustum(BoundingVolume *vol){
	//
	//  Por implementar
	//
	
	return true;
}

void Frustum::scheduleUpdate(){
	frustumNeedsUpdate = true;
}