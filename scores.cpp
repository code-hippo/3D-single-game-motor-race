/*
 * scores.cpp
 *
 *  Created on: 08-Sep-2013
 *      Author: vignan_pc
 */
#include "scores.h"
void ChangehighScore(int Track_name,char* playername,int Score){

}
//void drawScene1(int box_count){
//	cout<<z_pos<<endl;
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_COLOR_MATERIAL);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluPerspective(90.0, (double)1000 / (double)1000,1.0, 3000.0);
//	gluLookAt(x_pos,y_pos,z_pos,x_pos,0,z_pos-30,0,1,0);
//	glScalef(1,1,1);
//	GLfloat ambientColor[] = {0.6f, 0.6f, 0.6f, 1.0f}; //Color (0.2, 0.2, 0.2)
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
//
//	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
//	GLfloat lightPos0[] = {0.0f, 30.0f, -30.0f, 1.0f};
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
//	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
//
//	glEnable(GL_TEXTURE_2D);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//
//	glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, _tex->sky_texture);
//	//std::cout << "sky"<<_tex->sky_texture<< endl;
//	glBegin(GL_QUADS);
//	//glColor3f( 1.0f, 1.0f, 1.0f);
//		//glColor3f(1.0,1.0,0.0);
//		glNormal3f(0,-1,0);
//		glTexCoord2f(0.0f, 0.0f);
//		glVertex3f(-30,30,-2018);
//		glTexCoord2f(0.0f, 68.0f);
//		glVertex3f(-30,30,30);
//		glTexCoord2f(2.0f, 68.0f);
//		glVertex3f(30,30,30);
//		glTexCoord2f(2.0f, 0.0f);
//		glVertex3f(30,30,-2018);
//	glEnd();
//	glPopMatrix();
//	glDisable(GL_TEXTURE_2D);
//	glEnable(GL_TEXTURE_2D);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, _tex->side_texture);
//		//cout<< "side" <<_tex->side_texture<<"\n";
//		glBegin(GL_QUADS);
//
//			//glColor3f(1.0,0.0,0.0);
//			glNormal3f(1,0,0);
//			glTexCoord2f(0.0f, 0.0f);
//			glVertex3f(-30,0,30);
//			glTexCoord2f(0.0f, 1.5);
//			glVertex3f(-30,30,30);
//			glTexCoord2f(50.0f,1.5);
//			glVertex3f(-30,30,-2018);
//			glTexCoord2f(50.0f, 0.0f);
//			glVertex3f(-30,0,-2018);
//		glEnd();
//		glBegin(GL_QUADS);
//			//glColor3f(1.0,0.0,1.0);
//			glNormal3f(-1,0,0);
//			glTexCoord2f(0.0f, 0.0f);
//			glVertex3f(30,0,30);
//			glTexCoord2f(0.0f, 1.5f);
//			glVertex3f(30,30,30);
//			glTexCoord2f(50.0f, 1.5f);
//			glVertex3f(30,30,-2018);
//			glTexCoord2f(50.0f, 0.0f);
//			glVertex3f(30,0,-2018);
//		glEnd();
//		glPopMatrix();
//		glDisable(GL_TEXTURE_2D);
//		glEnable(GL_TEXTURE_2D);
////		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//		glPushMatrix();
//	glBindTexture(GL_TEXTURE_2D, _tex->road_texture);
//	//cout<< "road" <<_tex->road_texture<<"\n";
//	glBegin(GL_QUADS);
//		//glColor3f(1.0,0.0,1.0);
//		glNormal3f(0,1,0);
//		glTexCoord2f(0.0f, 0.0f);
//		glVertex3f(-30,0,-2018);
//		glTexCoord2f(0.0f, 68.0f);
//		glVertex3f(-30,0,30);
//		glTexCoord2f(2.0f, 68.0f);
//		glVertex3f(30,0,30);
//		glTexCoord2f(2.0f, 0.0f);
//		glVertex3f(30,0,-2018);
//	glEnd();
//
//
//	glPopMatrix();
//	glDisable(GL_TEXTURE_2D);
//	glutSwapBuffers();
//}
