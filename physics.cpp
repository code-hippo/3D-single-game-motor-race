/*
 * physics.cpp
 *
 *  Created on: Aug 10, 2013
 *      Author: bhargavvar
 */


#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include "physics.h"
#include "terrain.h"
#include "glm.h"






#include "GL/GL/include/GL/glut.h"


const float PI = 3.1415926535f;

using namespace std;


const float fps =100;
const float updt=1/fps;

float timahead =0;

//declaration of material data of the object


//bike object related data and functions


Object::~Object()

{


}
Object::Object(terrain* p,GLMmodel* model)

//Object::Object(terrain* p)
{


    a=0;
    d=0;
    onterrainborder=false;
    pos.x=128;

    pos.z=128;
    //pos.y=heightAt(_terrain,pos.x,pos.z)+18*size0;
    timer =0;
    _terrain=p;
    _model=model;

    velocity=setvalues(.0,0,0);
	accelerate=setvalues(0.00,0,0);

    bikeangle=00;

    Gravity=.00000;

    size0=.28;
    bikebent=0;
    anglevel=0;

    isturnleft=false;
    isturnright=false;
    onterrainborder=false;
    timeaccumulator=1.0f;
    terrainlfactor=1;

     wx=0;
    	 wy=0;
    	 wz=0;
    	 ax=0;
     ay=0;
    	 az=0;
    	 sx=0;
    	 sy=0;
    	 sz=0;
    	 dx=0;
    	 dy=0;
    	 dz=0;
    	 spx=0;
    	 spy=0;
    	 spz=0;

    	 maxV=.1;
    	 turnangle=0;;


}


void Object::setVelocityX(float dt)
{
	velocity.x=dt;
}

void Object::setVelocityY(float dt)
{
	velocity.y=dt;
}

void Object::setVelocityZ(float dt)
{
	velocity.z=dt;
}



 	float Object::givbikeangle()
 	{
 		return bikeangle;
 	}

 	void Object::setbikeangle(float v)
 	{
 		bikeangle=v;

 	}


void Object::posupdate(float dt)
{


	float  maxX= ((int)_terrain->w-1)*terrainlfactor-18*size0;
	float  maxZ= ((int)_terrain->l-1)*terrainlfactor-18*size0;
    float  minX= 18*size0;
    float  minZ=18* size0;

    if ( pos.x<size0 || pos.z<size0 || pos.x>maxX-size0 || pos.z>maxZ-size0)
    {

    	onterrainborder= true;
    }


    pos.x += velocity.x* dt;
    pos.z += velocity.z* dt;

    if(pos.x<18*size0){
    	    pos.x-=velocity.x*dt;
    	   	if(velocity.x<0)
     		setVelocityX(0);
            accelerate.x=0;
    }
    if(pos.z<18*size0)
    {
    	pos.z-=velocity.z*dt;
    	if(velocity.z<0)

    		setVelocityZ(0);
    		accelerate.z=0;

    }
    if(pos.x>maxX)

{
    	pos.x-=velocity.x*dt;
    	if(velocity.x>0)
    	{
      		setVelocityX(0);
    	}
    		accelerate.x=0;
    	}

    if(pos.z>maxZ)
    {
    	pos.z-=velocity.z*dt;
    	if(velocity.z>0)
    		setVelocityZ(0);
    	accelerate.z=0;
    }







  vector3f a=accelerate;


	pos.y +=velocity.y* dt;


	 if(pos.y>heightAt(_terrain,pos.x,pos.z)+18*size0)
	   {
		  if(pos.y>heightAt(_terrain,pos.x,pos.z)+18*size0+01)
		  {
		   accelerate=setvalues(0,0,0);
		   Gravity=.000003;

		  }

      Gravity= 0.000003;

	   }



	   if(pos.y<=heightAt(_terrain,pos.x,pos.z)+18*size0){

		   Gravity=0;


	   if(pos.y<=heightAt(_terrain,pos.x,pos.z)+18*size0-.25)
	   {
		   if(velocity.y<0){

			   setVelocityY(0);
			   pos.y=heightAt(_terrain,pos.x,pos.z)+18*size0;
		   }





	   else{
		   pos.y=heightAt(_terrain,pos.x,pos.z)+18*size0;
		   velocity.y=0;
	   }
	   }



}

}

void Object::velupdate(float dt)
{

	//ob->posX += ((ob->force[0])/(ob->mass))* updt;
	//ob->posX += ((ob->force[1])/(ob->mass))* updt   ;
	if(speed>0){
		if(dotproduct(velocity,setvalues(cos(bikeangle*PI/180),0,(-1)*cos(bikeangle+90)*PI/180))>0)
		{
		velocity.x-=0.0000065*25*(cos((bikeangle+90)*PI/180));
		velocity.z+=0.0000065*25*(cos(bikeangle*PI/180));
	}
	else{
	velocity.y += Gravity* dt;
	velocity.x += accelerate.x *dt;
	velocity.y += accelerate.y *dt;
	velocity.z += accelerate.z *dt;
	}

	//ob->posX += ((ob->force[2])/(ob->mass))* updt;


}


}




void Object::draw()
{

	if (_model == NULL) {
					return;
				}



	float scale = 50.0f / max(_terrain->width() - 1, _terrain->length() - 1);

				glPushMatrix();



	//			glScalef(scale, scale, scale);
	//			glTranslatef(-(float)(_terrain->width() - 1) / 2,
	//							 18*size0*1/5,
		//						 -(float)(_terrain->length() - 1) / 2);


				glTranslatef(pos.x,heightAt(_terrain,pos.x,pos.z)+18*size0, pos.z);

	     //	glRotatef(90 - angle * 180 / PI, 0, 1, 0);
				glColor3f(1, 1, 1);
	   //		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	  //		glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);




//		glutSolidSphere(size0,30,30);
      //        glPushMatrix();
        //      glScalef(scal,scal,scal);
               if (a==1)
               {bikeangle+=2.25;}
               if (d==1)
               {bikeangle-=2.25;}
              glRotatef(+bikeangle,0,1,0);


             glmDraw(_model,GLM_COLOR);
        //       glPopMatrix();
				glPopMatrix();


			}


vector3f Object::glulookat()
{
	vector3f bikelookat;
	bikelookat.z=5*(-1)*cos(bikeangle*PI/180);
	bikelookat.y=5.0;
	bikelookat.x=5*(1)*cos((bikeangle+90)*PI/180);
	return bikelookat;

	}
vector3f Object::posonterrain()
{
	vector3f bikeposterra;
	 float     scale = 50.0f / max(_terrain->width() - 1, _terrain->length() - 1);




	 bikeposterra.x=scale*(pos.x-(float)(_terrain->width() - 1) / 2);
	 bikeposterra.y=scale*(18*size0+heightAt(_terrain,pos.x,pos.z));
	 bikeposterra.z=scale*(pos.z-(float)(_terrain->length() - 1) / 2);
	 return bikeposterra;
}




Object* load(terrain* terra,GLMmodel* mod)


//Object* load(terrain* terra)
{

  Object* q;
  q=new Object(terra,mod);

 // q=new Object(terra);

  return q;
}


const float dt = 1 / fps;


// In units seconds





void Object::framestime(float updt)
{




	while(updt>0)
	{




	   if (timeaccumulator > 1.0f)
	   {
		timeaccumulator =1.0f;
	   }
	   if(timeaccumulator < updt)
	   {

		   velupdate(timeaccumulator);

		   posupdate(timeaccumulator);

		   updt=-timeaccumulator;
	   }
	      else
	      {

	    	  velupdate(updt);

		      posupdate(updt);

		      timeaccumulator -= updt;
              updt=0;

	          }

	}

	  if(bikeangle <0 )
		  bikeangle=bikeangle+360;
	  if(bikeangle >360)
		  bikeangle=bikeangle-360;




}









