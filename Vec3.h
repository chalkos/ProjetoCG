#ifndef __VEC3_H_INCLUDED__
#define __VEC3_H_INCLUDED__

class Vec3{
private:
	float vec[3];

public:
	Vec3();
	Vec3(Vec3 *elem);
	Vec3(float A, float B, float C);
	Vec3(float *vec);
	Vec3 clone();
	
	float getVal(int pos);
	float X();
	float Y();
	float Z();
	void setVal(int pos, float val);
	void setX(float val);
	void setY(float val);
	void setZ(float val);
	float *getAll(float *arr);
	

	void reset(float A, float B, float C);

	// operações
	void incrementar( Vec3 *inc );
	void decrementar( Vec3 *dec );
	Vec3 somar( Vec3 *vec );
	Vec3 multiplicar( float val );
	Vec3 crossProduct( Vec3 *snd );
	float innerProduct( Vec3 *snd);
	void normalizar();
	float norma();
};


#endif // __VEC3_H_INCLUDED__