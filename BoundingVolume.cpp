#include "BoundingVolume.h"

enum IndiceBounds {
	bound_esq_cima_tras,
	bound_esq_cima_frente,
	bound_esq_baixo_tras,
	bound_esq_baixo_frente,
	bound_dir_cima_tras,
	bound_dir_cima_frente,
	bound_dir_baixo_tras,
	bound_dir_baixo_frente
};

BoundingVolume::BoundingVolume(Vec3 *center, Vec3 *dimensoes){
	Vec3 dim2 = dimensoes->multiplicar(0.5);

	bounds[ bound_esq_cima_tras ] = Vec3(
		center->X() - dim2.X(),
		center->Y() + dim2.Y(),
		center->Z() - dim2.Z());

	bounds[ bound_esq_cima_frente ] = Vec3(
		center->X() - dim2.X(),
		center->Y() + dim2.Y(),
		center->Z() + dim2.Z());

	bounds[ bound_esq_baixo_tras ] = Vec3(
		center->X() - dim2.X(),
		center->Y() - dim2.Y(),
		center->Z() - dim2.Z());

	bounds[ bound_esq_baixo_frente ] = Vec3(
		center->X() - dim2.X(),
		center->Y() - dim2.Y(),
		center->Z() + dim2.Z());


	bounds[ bound_dir_cima_tras ] = Vec3(
		center->X() + dim2.X(),
		center->Y() + dim2.Y(),
		center->Z() - dim2.Z());

	bounds[ bound_dir_cima_frente ] = Vec3(
		center->X() + dim2.X(),
		center->Y() + dim2.Y(),
		center->Z() + dim2.Z());

	bounds[ bound_dir_baixo_tras ] = Vec3(
		center->X() + dim2.X(),
		center->Y() - dim2.Y(),
		center->Z() - dim2.Z());

	bounds[ bound_dir_baixo_frente ] = Vec3(
		center->X() + dim2.X(),
		center->Y() - dim2.Y(),
		center->Z() + dim2.Z());
}