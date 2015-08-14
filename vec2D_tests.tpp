/**********************************************
 * vec2D_tests - unit testing for Vec2D class
 *
 * by Annaleah Ernst, Summer 2015
 **********************************************/
#include <assert.h>

template <typename T>
void Vec2D<T>::runTests() {
	T num1 = 1;
	T num2 = 2;
	T num3 = 3;
	T num4 = 4;
	T num5 = 5;
	T num6 = 6;
	Point2D<T> pt = { num4, num2 };
	Point2D<T> pt2 = { -num4, -num2 };
	Vec2D<T> vec(num1, num2);
	Vec2D<T> vecOther(num6, num3);
	Vec2D<T> vecAdd2(vec.x + num2, vec.y + num2);
	Vec2D<T> vecMult4(vec.x * num4, vec.y * num4);
	Vec2D<T> vecAddPt(vec.x + pt.x, vec.y + pt.y);
	Vec2D<T> vecAddOther(vec.x + vecOther.x, vec.y + vecOther.y);
	Vec2D<T> vecMultOther(vec.x * vecOther.x, vec.y * vecOther.y);
	Vec2D<T> temp;

	/* equality tests */
	temp = vec;
	assert(temp.equals(vec));
	assert(!(temp.equals(vecAdd2)));
	assert(temp == vec);
	assert(!(temp == vecAdd2));
	assert(temp != vecAdd2);
	assert(!(temp != vec));

	/* point2d math tests */
	assert(vecAddPt == temp.addPoint(pt));
	assert(vecAddPt == vec + pt);
	assert(vecAddPt == pt + vec);
	temp = vec;
	assert(vecAddPt == (temp += pt));

	temp = vecAddPt;
	assert(vec == temp.subtractPoint(pt));
	assert(vec == vecAddPt - pt);
	temp = vecAddPt;
	assert(vec == (temp -= pt));

	/* scalar math tests */
	temp = vec;
	assert(vecAdd2 == temp.addScalar(num2));
	assert(vecAdd2 == vec + num2);
	assert(vecAdd2 == num2 + vec);
	temp = vec;
	assert(vecAdd2 == (temp += num2));

	assert(vec == temp.subtractScalar(num2));
	assert(temp == vecAdd2 - num2);
	temp = vecAdd2;
	assert(vec == (temp -= num2));

	assert(vecMult4 == temp.multiplyByScalar(num4));
	assert(vecMult4 == vec * num4);
	assert(vecMult4 == num4 * vec);
	temp = vec;
	assert(vecMult4 == (temp *= num4));

	assert(vec == temp.divideByScalar(num4));
	assert(vec == vecMult4 / num4);
	temp = vecMult4;
	assert(vec == (temp /= num4));

	/* vector math tests */
	temp = vec;
	assert(vecAddOther == temp.addVec(vecOther));
	assert(vecAddOther == vec + vecOther);
	assert(vecAddOther == vecOther + vec);
	temp = vec;
	assert(vecAddOther == (temp += vecOther));

	assert(vec == temp.subtractVec(vecOther));
	assert(temp == vecAddOther - vecOther);
	temp = vecAddOther;
	assert(vec == (temp -= vecOther));

	assert(vecMultOther == temp.multiplyByVec(vecOther));
	assert(vecMultOther == vec * vecOther);
	assert(vecMultOther == vecOther * vec);
	temp = vec;
	assert(temp == (temp *= vecOther));

	assert(vec == temp.divideByVec(vecOther));
	assert(vec == vecMultOther / vecOther);
	temp = vecMultOther;
	assert(vec == (temp /= vecOther));

	std::cout << "Math tests and operator override tests passed." << std::endl;

	/* classic vector functions unit tests */
	assert(vec.cross(vec) == 0);
	double numMag2 = vec.x * vec.x + vec.y * vec.y;
	double numMag = sqrt(numMag2);
	assert(vec.dot(vec) == numMag2);
	assert(vec.magSquared() == numMag2);
	assert(vec.magnitude() == numMag);
	temp = vec;
	assert(temp.normalize() == Vec2D<T>(vec.x / numMag, vec.y / numMag));
	assert(vec.unit() == temp);
	assert(vec.normal() == (temp = Vec2D<T>(vec.y, -vec.x)));
	assert(vec.project(temp) == Vec2D<T>(0, 0));
	assert(vec.scalarCrossVec(num3) == -num1 * vec.vecCrossScalar(num3));
	assert(vec.vecFromPoints(pt, pt2) == Vec2D<T>(pt2.x - pt.x, pt2.y * pt.y));
	std::cout << "All unit tests passed." << std::endl;

	/* currently non-exisitent unit function tests */
	//assert(vecAddPt == Vec2D<T>::addPoint(vec, pt));
	//assert(vecAddPt == Vec2D<T>::addPoint(pt, vec));
	//assert(vec == Vec2D::subtractPoint(vecAddPt, pt));
	//assert(vecAdd2 == Vec2D<T>::addScalar(vec, num2));
	//assert(vecAdd2 == Vec2D<T>::addScalar(num2, vec));
	//assert(vec == Vec2D<T>::subtractScalar(vecAdd2, num2));
	//assert(vecMult4 == Vec2D<T>::multiplyByScalar(vec, num4));
	//assert(vecMult4 == Vec2D<T>::multiplyByScalar(num4, vec));
	//assert(vec == Vec2D<T>::divideByScalar(vecMult4, num4));
	//assert(vecAddOther == Vec2D<T>::addVec(vec, vecOther));
	//assert(vecAddOther == Vec2D<T>::addVec(vecOther, vec));
	//assert(vec == Vec2D<T>::subtractVec(vecAddOther, vecOther));
	//assert(vecMultOther == Vec2D<T>::multiplyByVec(vec, vecOther));
	//assert(vecMultOther == Vec2D<T>::multiplyByVec(vecOther, vec));
	//assert(vec == Vec2D<T>::divideByVec(vecMultOther, vecOther));
}