/***********************************************
 * vec2D.h - a 2D vector class template
 *
 * by Annaleah Ernst, 2015
 ***********************************************/

#ifndef VEC2D_H
#define VEC2D_H

#define DEBUG_VEC2D

#include <iostream>
#include <assert.h>

template <typename T>
struct Point2D {
	T x, y;
};

template <typename T>
struct Vec2D {
private:
	//double mag, mag2;
public:
	T x, y;

	/****************/
	/* constructors */
	/****************/

	Vec2D() {}
	//Vec2D(T x, T y) : x(x), y(y), mag(NOT_MAG), mag2(NOT_MAG) {}
	//Vec2D(const Point2D<T> p) : x(p.x), y(p.y), mag(NOT_MAG), mag2(NOT_MAG) {}
	//Vec2D(const Vec2D<T>& other) : x(other.x), y(other.y), mag(other.mag), mag2(other.mag2) {}	// copy constructor
	//Vec2D(Vec2D<T>&& other) : cstring(other.cstring) { other.cstring = nullptr;  } // move constructor
	Vec2D(T x, T y) : x(x), y(y) {}
	Vec2D(const Point2D<T> p) : x(p.x), y(p.y) {}
	Vec2D(const Vec2D<T>& other) : x(other.x), y(other.y) {}	// copy constructor
	Vec2D(Vec2D<T>&& other) : cstring(other.cstring) { other.cstring = nullptr; } // move constructor
	
	/*******************/
	/* class functions */
	/*******************/

	/* check equality of current vector against that of another */
	bool equals(const Vec2D& other);

	/* add scalar to current vector. returns reference to current vector */
	Vec2D& addScalar(const T scalar);

	/* add point to current vector. returns reference to current vector */
	Vec2D& addPoint(const Point2D<T> p);

	/* add vector to the current vector. returns reference to current vector */
	Vec2D& addVec(const Vec2D& other);

	/* divide vector by scalar. returns reference to current vector */
	Vec2D& divideByScalar(const T scalar);

	/* elementwise divide by other vector. returns reference to current vector */
	Vec2D& divideByVec(const Vec2D& other);

	/* multiply current vector by scalar. returns reference to current vector */
	Vec2D& multiplyByScalar(const T scalar);

	/* elementwise multiply by other vector. returns reference to current vector */
	Vec2D& multiplyByVec(const Vec2D& other);

	/* normalize current vector. returns reference to current vector */
	Vec2D& normalize();

	/* subtract scalar from current vector. returns reference to current vector */
	Vec2D& subtractScalar(const T scalar);

	/* subtract point from current vector. returns reference to the current vector */
	Vec2D& subtractPoint(const Point2D<T> p);

	/* subtract vector from current vector. returns reference to current vector*/
	Vec2D& subtractVec(const Vec2D& other);

	/* gets the 2D cross product of two vectors. returns cross product as type T */
	T cross(const Vec2D& other);

	/* get the dot product of the current vector and another. returns the dot product as type T */
	T dot(const Vec2D& other);

	/* get magnitude of current vector. returns magnitude as a double */
	double magnitude();

	/* get magnitude squared of current vector. returns magnitude squared as a double */
	double magSquared();

	/* get right hand perpendicular vector to the current vector. returns a new vector */
	Vec2D normal();

	/* projects the current vector onto vector p. returns a new vector */
	Vec2D project(const Vec2D& p);

	/* crosses a scalar with the current vector. returns a new vector */
	Vec2D scalarCrossVec(const T scalar);

	/* crosses the current vector with a scalar. returns a new vector */
	Vec2D vecCrossScalar(const T scalar);

	/* gets a unit version of the current vector. returns a new vector */
	Vec2D unit();

	/* gets the normalized version of the right perpendicular vector. returns new vector */
	Vec2D unitNormal();

	/* given two points, returns vector corresponding to them*/
	static Vec2D vecFromPoints(const Point2D<T> origin, const Point2D<T> dest) { return Vec2D(dest.x - origin.x, dest.y - origin.y); }

	/* run unit tests on vec2D functions if in debug mode */
	static void runTests();

	/**************/
	/* destructor */
	/**************/

	~Vec2D(){};
};

#include "vec2D.tpp"

#endif