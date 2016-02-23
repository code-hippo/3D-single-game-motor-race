/*
 * physics.h
 *
 *  Created on: Aug 17, 2013
 *      Author: bhargavvar
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_




#endif /* PHYSICS_H_ */
/*
 * physics.h
 *
 *  Created on: Aug 12, 2013
 *      Author: bhargavvar
 */



#include "vector3f.h"

#include "terrain.h"

#include "glm.h"


//declaration of material data of the object
struct matprop
{

float res;
float myu;
};


//bike object related data and functions
class Object
{
public:
	terrain* _terrain;
	float terrainlfactor;
	GLMmodel* _model;


    float timeaccumulator;
	vector3f pos;







	vector3f velocity;

	float speed=magnitude(velocity);



	float velX;
	float velocityinX();


	void setVelocityX(float v);



	float velY;
	float velocityinY();
	void setVelocityY(float v);





	float velZ;



	float velocityinZ();
	void setVelocityZ(float v);


	vector3f accelerate;

	float bikeangle;
	void setbikeangle(float v);

	float givbikeangle();

	vector3f glulookat();
	vector3f posonterrain();

	float Gravity;
	vector3f force;
    float mass ;

    float size0;

    bool isturnleft;
    bool isturnright;
    bool onterrainborder;
	matprop material;
	void timeaccumulatorfunc();
	Object(terrain* terrain,GLMmodel* model);

//	Object(terrain* terrain);
	~Object();


	void posupdate(float dt);
	void velupdate(float dt);

	void framestime(float dt);
	void draw();

	void keyoperations();

	float timer;
	float bikebent;
	float maxV;
	float turnangle;

	float anglevel;

	   float a;
	    float d;

	float wx;
		float wy;
		float wz;
		float ax;
		float ay;
		float az;
		float sx;
		float sy;
		float sz;
		float dx;
		float dy;
		float dz;
		float spx;
		float spy;
		float spz;


};
    Object* load(terrain* p,GLMmodel* model);




 //  Object* load(terrain* p);
