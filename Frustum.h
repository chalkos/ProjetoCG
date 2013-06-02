#ifndef __FRUSTUM_H_INCLUDED__
#define __FRUSTUM_H_INCLUDED__

#include "Plano3D.h"

enum PlanosFrustum {
	planoNear,
	planoFar,
	planoLeft,
	planoRight,
	planoTop,
	planoBottom,

	planoCOUNT_ENUM
};

enum PosicaoNoFrustum{
	frusDentro,
	frusFora,
	frusIntersecta,
};

class Frustum{
private:
	static bool frustumNeedsUpdate;
	static bool frustumCullingEnabled;
	static Plano3D plano[planoCOUNT_ENUM];

	static bool pointInFrustum(Vec3 *ponto);
public:
	static void updateFrustum( Vec3 *pos, Vec3 *up, Vec3 *center, float fov, float ratio, float dNear, float dFar);

	// testes de pontos
	static PosicaoNoFrustum boxInFrustum(Vec3 *min, Vec3 *max);

	static void toggleFrustumCulling();
	static bool isCullingEnabled();
	static void scheduleUpdate();
};

#endif // __FRUSTUM_H_INCLUDED__