/*

 *
 *  Created on: 12-Aug-2013
 *      Author: vignan_pc
 */
/**
 * @file vector3f.h
 * @brief vector class
 * @details this vector is basically a struct having x,y,z co-ordinates and  hte operations on vectors
 */
#ifndef VECTOR3F_H_
#define VECTOR3F_H_

typedef struct{
	float x;
	float y;
	float z;
}vector3f;
/**
 *@brief Magnitude
 * @param a
 * @return magnitude of the given vector 'a'
 */
float magnitude(vector3f a);
/**
 * @brief Addition
 * @param a
 * @param b
 * @return returns a vector which is sum(a,b)
 */
vector3f sum(vector3f a,vector3f b);
/**
 * @brief  Subtraction
 * @param a
 * @param b
 * @return returns a vector which is difference of given two vectors sub(a,b)=a-b
 */
vector3f sub(vector3f a,vector3f b);
/**
 * @brief Scalar multiplication
 * @param a
 * @param c
 * @return returns a vector c*a (scalar multiplicaion)
 */
vector3f smulp(vector3f a,float c);
/**
 * @brief Dotproduct
 * @param a
 * @param b
 * @return returns scalar a.b
 */
float dotproduct(vector3f a,vector3f b);
/**
 * @brief cross product
 * @param a
 * @param b
 * @return returns vector a cross b
 */
vector3f crossproduct(vector3f a,vector3f b);
/**
 * @brief Unit Vector
 * @param a
 * @return returns unit
 */
vector3f unitvec(vector3f a);
/**
 * @brief Set values
 * @param x
 * @param y
 * @param z
 * @return create a new vector of co-ordinates x,y,z respectievely
 */
vector3f setvalues(float x,float y,float z);
#endif /* VECTOR3F_H_ */
