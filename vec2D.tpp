/**********************************************************
* vec2D.tpp - the implementation of the Vec2D class
*
* by Annaleah Ernst, summer 2015
**********************************************************/
#ifndef VEC2D_IMP
#define VEC2D_IMP

template <typename T>
bool Vec2D<T>::equals(const Vec2D<T>& other){
	return (x == other.x && y == other.y) ? true : false;
}

template <typename T>
Vec2D<T>& Vec2D<T>::addScalar(const T scalar){
	x += scalar;
	y += scalar;
	return *this;
};

template <typename T>
Vec2D<T>& Vec2D<T>::addPoint(const Point2D<T> p){
	x += p.x;
	y += p.y;
	return *this;
}

template <typename T>
Vec2D<T>&  Vec2D<T>::addVec(const Vec2D<T>&  other){
	x += other.x;
	y += other.y;
	return *this;
};

template <typename T>
Vec2D<T>&  Vec2D<T>::divideByScalar(const T scalar){
	x /= scalar;
	y /= scalar;
	return *this;
};

template <typename T>
Vec2D<T>& Vec2D<T>::divideByVec(const Vec2D<T>& other){
	x /= other.x;
	y /= other.y;
	return *this;
};

template <typename T>
Vec2D<T>& Vec2D<T>::multiplyByScalar(const T scalar){
	x *= scalar;
	y *= scalar;
	return *this;
};

template <typename T>
Vec2D<T>& Vec2D<T>::multiplyByVec(const Vec2D<T>& other){
	x *= other.x;
	y *= other.y;
	return *this;
};

template <typename T>
Vec2D<T>&  Vec2D<T>::normalize(){
	double m = magnitude();
	x /= m;
	y /= m;
	return *this;
};

template <typename T>
Vec2D<T>& Vec2D<T>::subtractScalar(const T scalar){
	x -= scalar;
	y -= scalar;
	return *this;
}

template <typename T>
Vec2D<T>& Vec2D<T>::subtractPoint(const Point2D<T> p){
	x -= p.x;
	y -= p.y;
	return *this;
}

template <typename T>
Vec2D<T>&  Vec2D<T>::subtractVec(const Vec2D<T>&  other){
	x -= other.x;
	y -= other.y;
	return *this;
};

template <typename T>
double Vec2D<T>::magnitude(){
	// return mag == NOT_MAG ? sqrt(magSquared()) : mag;
	return sqrt(magSquared());
};

template <typename T>
double Vec2D<T>::magSquared(){
	//mag2 == NOT_MAG ? x*x + y*y : mag2 //if we include getters/setters for x y
	return x*x + y*y;
};

template <typename T>
T Vec2D<T>::dot(const Vec2D<T>&  other){
	return x*other.x + y*other.y;
};

template <typename T>
T Vec2D<T>::cross(const Vec2D<T>&  other){
	return x * other.y - other.x * y;
};

template <typename T>
Vec2D<T> Vec2D<T>::normal(){
	return Vec2D(y, -x);
};

template <typename T>
Vec2D<T> Vec2D<T>::project(const Vec2D<T>&  p){
	double coeff = dot(p) / magSquared();
	return Vec2D<T>(*this).multiplyByScalar(coeff);
};

template <typename T>
Vec2D<T> Vec2D<T>::unit(){
	double m = magnitude();
	return Vec2D(x / m, y / m);
};

template <typename T>
Vec2D<T> Vec2D<T>::unitNormal(){
	return normal().normalize();
}

template <typename T>
Vec2D<T> Vec2D<T>::scalarCrossVec(const T scalar){
	return Vec2D(-scalar * y, scalar * x);
};

template <typename T>
Vec2D<T> Vec2D<T>::vecCrossScalar(const T scalar){
	return Vec2D(scalar * y, -scalar * x);
};

#include "vec2D_OpOverloads.tpp"

#ifdef DEBUG_VEC2D
#include "vec2D_tests.tpp"
#else
template <typename T>
void Vec2D<T>::runTests() { /* we're not in debug; we don't care */ }
#endif // DEBUG_VEC2D

#endif // VEC2D_IMP