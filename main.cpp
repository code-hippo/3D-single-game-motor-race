/*
 * main.cpp
 *
 *  Created on: 18-Aug-2013
 *      Author: vignan_pc
 */

#include <iostream>
#include <stdlib.h>


#include "GL/GL/include/GL/glut.h"
#include "math.h"

#include "readData.h"
#include "vector3f.h"
#include"terrain.h"
#include "texture.h"
#include "glm.h"
#include "physics.h"
#include "font1.h"
#include "screenscore.h"
#include "Obst.h"
using namespace std;
const float TERRAIN_WIDTH = 50.0f;
const float obstsize=10;
const float PI = 3.1415926535f;
Object* _Object;
terrain* _terrain;
GLuint _textureId;
GLuint _textureId1;
GLMmodel* _object;

float time=0;
float* fun(terrain* _terrain){
float array[30];
float * p;
p=array;
for (int i=0;i<10;i++){

	array[3*i]=RandomFloat(0,_terrain->width());

	array [(3*i)+1]=RandomFloat(0,_terrain->length());

	array [(3*i)+2]=RandomFloat(_terrain->getHeight(decimalval(array[3*i]),decimalval(array[3*i])),15);

}
return p;
}

void clean() {
	delete _terrain;
	delete _object;
	delete _Object;

}



void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	t3dInit();

}

 void handleKeypress(unsigned char key, int x, int y) {
	if (key==27) {
			clean();
			exit(0);
	}
}

float _angle=45.0;

#define KEY_ESCAPE 27





void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawTime(time);
		drawVelocity(23);
		drawDist(23);
gluLookAt(_Object->posonterrain().x-_Object->glulookat().x,_Object->posonterrain().y+_Object->glulookat().y,_Object->posonterrain().z-10-_Object->glulookat().z,
//	gluLookAt(_Object->posonterrain().x,_Object->posonterrain().y+5,_Object->posonterrain().z-15,
_Object->posonterrain().x,_Object->posonterrain().y,_Object->posonterrain().z-10,0,2,0);
//gluLookAt(0,25,0,_Object->pos.x,_Object->pos.y,_Object->pos.z,0,2,0);
//	gluLookAt(_Object->pos.x,_Object->pos.x,_Object->pos.x,0,0,0,0,2,0);

	glTranslatef(0.0f, 0.0f, -10.0f);
//	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	//glRotatef(-_angle, 0, 1.0f, 0.0f);

	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);


//gluLookAt( 10,3,0, 0,0,0, 0,1,0);
//	glClearColor(.35, .27, .31, 1.0);


	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-1.0f, -1.0f, -1.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	float scale = 50.0f / max(_terrain->width() - 1, _terrain->length() - 1);



	//gluLookAt(_Object->pos.x+10,heightAt(_Object->_terrain,_Object->pos.x,_Object->pos.z)+_Object->size0+10,_Object->pos.z-10, _Object->pos.x,heightAt(_Object->_terrain,_Object->pos.x,_Object->pos.z)+_Object->size0,_Object->pos.z, 0,1,0);
	//glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glScalef(scale, scale, scale);
	glTranslatef(-(float)(_terrain->width() - 1) / 2,
					 0.0f,
					 -(float)(_terrain->length() - 1) / 2);

//




	for(int z = 0; z < _terrain->length() -1; z++) {
		glBegin(GL_TRIANGLE_STRIP);

		for(int x = 0; x < _terrain->width()-1; x++) {


			vector3f normal = _terrain->getNormal(x, z);
			glColor3f( 1.0f, 1.0f, 1.0f);
						glNormal3f(normal.x, normal.y, normal.z);

						glTexCoord2f(x/(256.0),z/(256.0));

						glVertex3f(x, _terrain->getHeight(x, z), z);



						normal = _terrain->getNormal(x, z + 1);

									glNormal3f(normal.x, normal.y, normal.z);
									glTexCoord2f(x/256.0,(z+1)/256.0);
									glVertex3f(x, _terrain->getHeight(x, z + 1), z + 1);



		}
		glEnd();
	}

	float* positions=fun(_terrain);
			for (int i=0;i>10;i++){
				glTranslatef(*(positions+3*i),*(positions+3*i+1),*(positions+3*i+2));
				cout<<0;
				glutSolidCube(20);
			}
	glDisable(GL_TEXTURE_2D);

	glPushMatrix();
		  _Object->draw();
	glPopMatrix();

//	gluLookAt(_Object->posonterrain().x+_Object->glulookat().x,_Object->posonterrain().y+_Object->glulookat().y,_Object->posonterrain().z+_Object->glulookat().z,
//	    		_Object->posonterrain().x,_Object->posonterrain().y,_Object->posonterrain().z,0,2,0);
	glutSwapBuffers();
}


int winwidth = 1000;
int winheight = 1000;
string wintitle = "OpenGL/GLUT Window.";
float viewangle_field = 90;
float near_z = .1f;
float far_z = 500.0f;

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspect = (GLfloat) winwidth / winheight;
	gluPerspective(viewangle_field, aspect, near_z, far_z);		// set up a perspective projection matrix

//    gluLookAt(_Object->posonterrain().x+_Object->glulookat().x,_Object->posonterrain().y+_Object->glulookat().y,_Object->posonterrain().z+_Object->glulookat().z,
// 		_Object->posonterrain().x,_Object->posonterrain().y,_Object->posonterrain().z,0,2,0);
//	gluLookAt(0,45,0,0,0,0,0,0,-10);
							  // Define a viewing transformation
}


bool* Keystates = new bool[ 256];



void keyoperations()
{

	if(_Object->pos.y<heightAt(_terrain,_Object->pos.x,_Object->pos.z)+18*_Object->size0+6){
	float t=magnitude(_Object->velocity);
	float tsq=t*t;

	if(Keystates['w'])
	{
		if(_Object->speed>=0){
						if(dotproduct(_Object->velocity,setvalues(cos((_Object->bikeangle+90)*PI/180),0,(-1)*cos((_Object->bikeangle)*PI/180)))>=0)
						{
							_Object->velocity.z-=0.001*25*(cos(_Object->bikeangle*PI/180));
							_Object->velocity.x+=0.001*25*(cos(_Object->bikeangle+90*PI/180));
					}


/*		_Object->wx+=((.00003f)*cos((_Object->bikeangle+90)*PI/180));

		_Object->accelerate.x+=((.00003f)*cos((_Object->bikeangle+90)*PI/180));
		_Object->wy+=0;
		_Object->accelerate.y+=0;
		_Object->wz-=((.00003f)*cos((_Object->bikeangle)*PI/180));
		_Object->accelerate.z-=((.00003f)*cos((_Object->bikeangle)*PI/180));

	}
	else
	{
		if(_Object->accelerate.x==0){
			_Object->wx=0;
		}
		if(_Object->accelerate.z==0){
					_Object->wz=0;
				}

		_Object->accelerate.x-=_Object->wx;
		_Object->wx=0;
		_Object->accelerate.y-=0;
		_Object->wy=0;
		_Object->accelerate.z-=_Object->wz;
		_Object->wz=0;
*/	}
	}
	if(Keystates['a'])

	{
		 _Object->a=1;

        float hspeed=magnitude(setvalues(_Object->velocity.x,0,_Object->velocity.z));
		 _Object->velocity.x=hspeed*(59/60)*cos((+2.25+90+_Object->bikeangle)*PI/180);

		 _Object->velocity.z=-hspeed*(59/60)*cos((+2.25+_Object->bikeangle)*PI/180);
	//	glRotatef(2.25,0,1,0);

	//	_Object->bikeangle+=2.25;
}
    else
    	{_Object->a=0;}


/*
	//	_Object->turnangle=+30-(200*magnitude(_Object->velocity));


					_Object->ax+=((.00003f)*cos(_Object->bikeangle+90+90));
		_Object->ay+=0;
		_Object->az-=((.00003f)*cos(_Object->bikeangle+90));
		_Object->accelerate.x+=((.00003f)*cos(_Object->bikeangle+90+90));
		_Object->accelerate.y+=0;
		_Object->accelerate.z-=((.00003f)*cos(_Object->bikeangle+90));
	}
	else
	{

		if(_Object->accelerate.x==0){
					_Object->ax=0;
				}
		if(_Object->accelerate.z==0){
							_Object->az=0;
						}
		_Object->accelerate.x-=_Object->ax;
		_Object->accelerate.y-=0;
		_Object->accelerate.z-=_Object->az;
		_Object->ax=0;
		_Object->ay=0;
		_Object->az=0;
*/

	if(Keystates['d'])
	{
       _Object->d=1;
       float hspeed=magnitude(setvalues(_Object->velocity.x,0,_Object->velocity.z));
       _Object->velocity.x=hspeed*(59/60)*cos((-2.25+90+_Object->bikeangle)*PI/180);
      		 _Object->velocity.z=-hspeed*(59/60)*cos((-2.25+_Object->bikeangle)*PI/180);
	//	glRotatef(-2.25,0,1,0);
	//	_Object->bikeangle-=2.25;
	}
	else _Object->d=0;
		/*

		//  float a=v*1/10
	//	_Object->turnangle=-30+(150*magnitude(_Object->velocity));



		_Object->dx+=((.00003f)*cos(_Object->bikeangle-90+90));
		_Object->dy=0;
		_Object->dz-=((.00003f)*cos(_Object->bikeangle-90+90));
		_Object->accelerate.x+=((.00003f)*cos(_Object->bikeangle-90));
		_Object->accelerate.y+=0;
		_Object->accelerate.z-=((.00003f)*cos(_Object->bikeangle-90));
    }
	else
	{
		if(_Object->accelerate.x==0){
					_Object->dx=0;
				}
				if(_Object->accelerate.z==0){
							_Object->dz=0;
						}
		_Object->accelerate.x-=_Object->dx;
		_Object->dx=0;
		_Object->accelerate.y-=0;
		_Object->dy=0;
		_Object->accelerate.z-=_Object->dz;
		_Object->dz=0;
	*/

	if(Keystates['s'])
	{
		if(_Object->speed>0){
				if(dotproduct(_Object->velocity,setvalues(cos((_Object->bikeangle+90)*PI/180),0,(-1)*cos((_Object->bikeangle)*PI/180)))>0)
				{
					_Object->velocity.z+=0.0006*25*(cos(_Object->bikeangle*PI/180));
					_Object->velocity.x-=0.0006*25*(cos(_Object->bikeangle+90*PI/180));
			}


/*		_Object->sx+=((-0.00002f)*cos((_Object->bikeangle+90))*PI/180);
		_Object->sy=0;
		_Object->sz-=((-0.00002f)*cos((_Object->bikeangle+90))*PI/180);
		_Object->accelerate.x+=((-0.00002f)*cos((_Object->bikeangle))*PI/180);
		_Object->accelerate.y+=0;
		_Object->accelerate.z-=((-0.00002f)*cos((_Object->bikeangle))*PI/180);
	}
	else
	{
		if(_Object->accelerate.x==0){
					_Object->sx=0;
				}
				if(_Object->accelerate.z==0){
							_Object->sz=0;
						}
		_Object->accelerate.x-=_Object->sx;
		_Object->sx=0;
		_Object->accelerate.y-=0;
		_Object->sy=0;
		_Object->accelerate.z-=_Object->sz;
		_Object->sz=0;
*/	}
	}
	if (Keystates[' '])
	{


		if(_Object->speed>0){
						if(dotproduct(_Object->velocity,setvalues((1)*cos((_Object->bikeangle+90)*PI/180),0,(-1)*cos((_Object->bikeangle)*PI/180)))>0)
						{
							_Object->velocity.z+=0.002*25*(cos(_Object->bikeangle*PI/180));
							_Object->velocity.x-=0.002*25*(cos(_Object->bikeangle+90*PI/180));
					}
	}
		/*
	}
	if (magnitude(_Object->velocity)==0){

	}
	else{
		_Object->spx+=((-0.00003f)*cos((_Object->bikeangle+90))*PI/180);
		_Object->spy=0;
		_Object->spz-=((-0.00003f)*cos((_Object->bikeangle+90))*PI/180);

		_Object->accelerate.x+=((-0.00003f)*cos((_Object->bikeangle))*PI/180);
				_Object->accelerate.y+=0;
				_Object->accelerate.z-=((-0.00003f)*cos((_Object->bikeangle))*PI/180);
	}

}
	else
	{
		if (magnitude(_Object->velocity)==0){

			_Object->spx=0;
			_Object->spy=0;
			_Object->spz=0;

			}
			else{
	}


		if(_Object->accelerate.x==0){
					_Object->spx=0;
				}
				if(_Object->accelerate.z==0){
							_Object->spz=0;
						}
		_Object->accelerate.x-=_Object->spx;
		_Object->spx=0;
		_Object->accelerate.y-=0;
		_Object->spy=0;
		_Object->accelerate.z-=_Object->spz;
		_Object->spz=0;
}

*/	}
	}
}



void keypressed(unsigned char a,int x, int y)
{
	Keystates[ a ] =true;


}
void keyup(unsigned char a,int x,int y)
{
    Keystates[ a] =false;
}

void update(int value) {

 keyoperations();
 _angle+=0.3f;
 time=time+0.025;
	if (_angle > 360) {
		_angle -= 360;
	}

	_Object->framestime(25);



	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}



int main(int argc, char** argv)
{




	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winwidth, winheight);


	glutCreateWindow("RaceGame");
	initRendering();
	Image* image1 = loadImage("@#4.bmp");
			_textureId = readTexture(image1);

			delete image1;

			Image* image2 = loadImage("2texture.bmp");
							_textureId1 = readTexture(image2);

							delete image2;

							_terrain = createTerrain("123.bmp", 40.0);

							_object  = glmReadOBJ("Kroserica_simple2.obj");


						_Object  = load(_terrain,_object);


					//		_Object  = load(_terrain);

						float* positions=fun(_terrain);
													for (int i=0;i>10;i++){
														glTranslatef(*(positions+3*i),*(positions+3*i+1),*(positions+3*i+2));
														cout<<0;
														glutSolidCube(20);
													}
						glutReshapeFunc(handleResize);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);




	//	glutIdleFunc( screendisplay );									// register Idle Function
    glutKeyboardFunc( keypressed );
    glutKeyboardUpFunc( keyup);                                   // register Keyboard Handler
    glutTimerFunc(25,update,0);


	glutMainLoop();
	return 0;
}
//glTranslatef( 5.886971, -17.172176, -29.579876)
//glTranslatef(5.890946, -17.203533, 21.340796)
