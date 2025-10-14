#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return (false);
	Point v0(c - a), v1(b - a), v2(point - a);
	Fixed dot0(v0 * v0), dot1(v0 * v1), dot2(v0 * v2), dot3(v1 * v1),
		dot4(v1 * v2);
	v0.~Point();
	v1.~Point();
	v2.~Point();
	Fixed inv(Fixed(1) / (dot0 * dot3 - dot1 * dot1));
	Fixed u((dot3 * dot2 - dot1 * dot4) * inv);
	Fixed v((dot0 * dot4 - dot1 * dot2) * inv);
	return (u > 0 && v > 0 && u + v < 1);
}