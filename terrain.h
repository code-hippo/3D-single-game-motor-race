/*
 * terrain.h
 *
 *  Created on: Aug 17, 2013
 *      Author: vignan
 */

#ifndef TERRAIN_H_
#define TERRAIN_H_
#include "vector3f.h"

/**
 * @file terrain.hat each point
 * @brief Terrain creation class
 * @details we us the normals and compute normals
 */
class terrain{
public:


	//class variables

	int l;
	int w;
	vector3f** normals;
	float** hs;    //two dimensional array to store height at every point
	bool normalscomputed;  //to check whether normals are upto date

public:
	terrain(int length,int width);
	~terrain();
	int length();
	int width();
	void setHeight(int x, int z, float y);
	void computeNormals();
	vector3f getNormal(int x, int z);
	float getHeight(int x,int z);

};
	terrain* createTerrain(const char* filename, float height);
	void clean();
	void initRendering();
	void handleKeypress(unsigned char key, int x, int y);
	void drawScene();
	void handleResize(int w, int h);
    float heightAt(terrain* t,float x,float z);

#endif /* TERRAIN_H_ */
