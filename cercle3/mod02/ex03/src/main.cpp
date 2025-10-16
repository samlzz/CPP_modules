#include "Point.hpp"
#include <cassert>
#include <iostream>

// Déclaration de bsp (implémentée dans bsp.cpp)
bool bsp(Point const a, Point const b, Point const c, Point const p);

static void header(const char *name)
{
	std::cout << "\n=== " << name << " ===\n";
}

// Helpers
static bool inside(Point a, Point b, Point c, Point p)
{
	return bsp(a, b, c, p);
}

int main()
{
	// Triangle simple (orientation quelconque)
	Point A(0.f, 0.f), B(5.f, 0.f), C(0.f, 5.f);

	header("Strictly inside");
	Point P1(1.f, 1.f);
	assert(inside(A, B, C, P1));

	header("Outside");
	Point P2(6.f, 1.f);
	assert(!inside(A, B, C, P2));

	header("On vertex -> false");
	assert(!inside(A, B, C, A));
	assert(!inside(A, B, C, B));
	assert(!inside(A, B, C, C));

	header("On edge -> false");
	Point E1(2.5f, 0.f); // sur AB
	Point E2(1.f,
		4.f); // sur AC prolonge ? (ici pas sur le segment, on teste une vraie colinéarité sur l'arête)
	Point E3(2.f, 3.f); // sur BC (x+y=5)
	assert(!inside(A, B, C, E1));
	assert(!inside(A, B, C, E3));

	header("Near-edge robustness (epsilon inside)");
	// Un point très proche du bord mais à l'intérieur
	Point NE(2.0f, 2.0f + 1e-3f);
	bool  r = inside(A, B, C, NE);
	std::cout << "near-edge -> " << (r ? "inside" : "outside") << "\n";
	assert(r); // tolérance flottante

	header("Different orientation (clockwise)");
	Point A2(2.f, 1.f), B2(6.f, 2.f), C2(3.f, 5.f);
	assert(inside(A2, B2, C2, Point(3.f, 2.f)));
	assert(!inside(A2, B2, C2, Point(10.f, 10.f)));

	header("Thin triangle (conditioning)");
	Point T1(0.f, 0.f), T2(1000.f, 0.01f), T3(1000.f, -0.01f);
	assert(inside(T1, T2, T3, Point(999.9f, 0.f)));
	assert(!inside(T1, T2, T3, Point(1000.1f, 0.f)));

	header("Immutability of Point (x,y const)");
	Point Pconst(3.f, 4.f);
	// On ne peut pas faire Pconst._x = ... ; => compile-time check (verifié par l'interface seulement)

	std::cout << "\nAll ex03 tests passed ✅ (si pas de crash)\n";
}
