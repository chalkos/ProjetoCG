#ifndef __BOUNDINGVOLUME_H_INCLUDED__
#define __BOUNDINGVOLUME_H_INCLUDED__

#include "Vec3.h"

class BoundingVolume{
private:
	Vec3 bounds[8];

public:
	BoundingVolume(Vec3 *center, Vec3 *dimensoes);
};

#endif // __BOUNDINGVOLUME_H_INCLUDED__