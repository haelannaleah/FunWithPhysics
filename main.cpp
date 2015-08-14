// actual implementations will go here
#include <iostream>
#include "vec2D.h"

int main(void) {
	Vec2D<int>::runTests();
	Vec2D<float>::runTests();
	Vec2D<double>::runTests();
	Vec2D<long>::runTests();
}