/******************************************/
/* operator overloads for the Vec2D class */
/******************************************/

#ifndef VEC2D_OPS
#define VEC2D_OPSs

template <typename T>
std::ostream& operator<<(std::ostream& os, Vec2D<T>& v) {
	os << '{' << v.x << ", " << v.y << '}';
	return os;
};

template <typename T>
bool operator==(Vec2D<T>& a, const Vec2D<T>& b){
	return a.equals(b);
}

template <typename T>
bool operator!=(Vec2D<T>& a, const Vec2D<T>& b){
	return !operator==(a, b);
}

template <typename T>
inline Vec2D<T>& operator+=(Vec2D<T>& v, const T scalar){
	return v.addScalar(scalar);
}
template <typename T> 
Vec2D<T> operator+(const T scalar, const Vec2D<T>& v) { 
	return Vec2D<T>(v) += scalar;
}
template <typename T> 
Vec2D<T> operator+(const Vec2D<T>& v, const T scalar) { 
	return Vec2D<T>(v) += scalar;
}

template <typename T>
Vec2D<T>& operator+=(Vec2D<T>& vec, const Point2D<T>& p){
	return vec.addPoint(p);
}
template <typename T> 
Vec2D<T> operator+(const Vec2D<T>& vec, const Point2D<T>& p) { 
	return Vec2D<T>(vec) += p; 
}
template <typename T> 
Vec2D<T> operator+(const Point2D<T>& p, Vec2D<T>& vec) { 
	return Vec2D<T>(vec) += p; 
}

//template <typename T>
//Point2D<T> operator+=(Point2D<T>& a, const Point2D<T>& b) {
//	a.x += b.x;
//	a.y += b.y;
//	return *this;
//}
//template <typename T>
//Point2D<T> operator+(const Point2D<T>& a, const Point2D<T>& b) {
//	return Point2D<T>(a) += b;
//}

template <typename T>
Vec2D<T>& operator+=(Vec2D<T>& a, const Vec2D<T>& b){
	return a.addVec(b);
}
template <typename T> 
Vec2D<T> operator+(const Vec2D<T>& a, const Vec2D<T>& b) { 
	return Vec2D<T>(a) += b; 
}

template <typename T>
Vec2D<T>& operator/=(Vec2D<T>& v, const T scalar){
	return v.divideByScalar(scalar);
}
template <typename T> 
Vec2D<T> operator/(const Vec2D<T>& v, const T scalar) { 
	return Vec2D<T>(v) /= scalar; 
}

template <typename T>
Vec2D<T>& operator/=(Vec2D<T>& dividend, const Vec2D<T>& divisor){
	return dividend.divideByVec(divisor);
}
template <typename T> 
Vec2D<T> operator/(const Vec2D<T>& dividend, const Vec2D<T>& divisor) {
	return Vec2D<T>(dividend) /= divisor; 
}

template <typename T>
Vec2D<T>& operator*=(Vec2D<T>& v, const T scalar){
	return v.multiplyByScalar(scalar);
}
template <typename T> 
Vec2D<T> operator*(const T scalar, const Vec2D<T>& v) { 
	return Vec2D<T>(v) *= scalar; 
}
template <typename T> 
Vec2D<T> operator*(const Vec2D<T>& v, const T scalar) { 
	return Vec2D<T>(v) *= scalar; 
}

template <typename T>
Vec2D<T>& operator*=(Vec2D<T>& a, const Vec2D<T>& b){
	return a.multiplyByVec(b);
}
template <typename T> 
Vec2D<T> operator*(const Vec2D<T>& a, const Vec2D<T>& b) { 
	return Vec2D<T>(a) *= b; 
}

template <typename T>
Vec2D<T>& operator-=(Vec2D<T>& v, const T scalar){
	return v.subtractScalar(scalar);
}
template <typename T> 
Vec2D<T> operator-(const Vec2D<T>& v, const T scalar) { 
	return Vec2D<T>(v) -= scalar; 
}

template <typename T>
Vec2D<T>& operator-=(Vec2D<T>& vec, const Point2D<T>& p){
	return vec.subtractPoint(p);
}
template <typename T> 
Vec2D<T> operator-(const Vec2D<T>& vec, const Point2D<T>& p) { 
	return Vec2D<T>(vec) -= p; 
}

template <typename T>
Vec2D<T>& operator-=(Vec2D<T>& a, const Vec2D<T>& b){
	return a.subtractVec(b);
}
template <typename T> 
Vec2D<T> operator-(const Vec2D<T>& a, const Vec2D<T>& b) { 
	return Vec2D<T>(a) -= b; 
}

#endif