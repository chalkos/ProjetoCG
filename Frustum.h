#ifndef __FRUSTUM_H_INCLUDED__
#define __FRUSTUM_H_INCLUDED__

#include "Plano3D.h"
#include "BoundingVolume.h"

enum PlanosFrustum {
	planoNear,
	planoFar,
	planoLeft,
	planoRight,
	planoTop,
	planoBottom,

	planoCOUNT_ENUM
};

class Frustum{
private:
	static bool frustumNeedsUpdate;
	static bool frustumCullingEnabled;
	static Plano3D plano[planoCOUNT_ENUM];

public:
	static void updateFrustum( Vec3 *pos, Vec3 *up, Vec3 *center, float fov, float ratio, float dNear, float dFar);
	
	// testes de pontos
	static bool pointInFrustum(Vec3 *ponto);
	static bool volumeInFrustum(BoundingVolume *vol);

	static void toggleFrustumCulling();
	static bool isCullingEnabled();
	static void scheduleUpdate();
};

#endif // __FRUSTUM_H_INCLUDED__