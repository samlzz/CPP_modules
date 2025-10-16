/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:10:51 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/16 22:12:04 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const p);

static void header(const char *name)
{
	std::cout << "\n=== " << name << " ===\n";
}

static void print_result(std::string const& label, bool expected, bool got)
{
	std::cout << label << " → "
			  << (got ? "inside" : "outside")
			  << " (expected: " << (expected ? "inside" : "outside") << ") "
			  << (got == expected ? "✅" : "❌") << "\n";
}

static bool inside(Point a, Point b, Point c, Point p)
{
	return bsp(a, b, c, p);
}

int main()
{
	Point A(0.f, 0.f), B(5.f, 0.f), C(0.f, 5.f);

	header("Strictly inside");
	Point P1(1.f, 1.f);
	print_result("P1(1,1)", true, inside(A, B, C, P1));

	header("Outside");
	Point P2(6.f, 1.f);
	print_result("P2(6,1)", false, inside(A, B, C, P2));

	header("On vertex -> false");
	print_result("A(0,0)", false, inside(A, B, C, A));
	print_result("B(5,0)", false, inside(A, B, C, B));
	print_result("C(0,5)", false, inside(A, B, C, C));

	header("On edge -> false");
	Point E1(2.5f, 0.f); // sur AB
	Point E2(1.f, 4.f);  // proche de AC
	Point E3(2.f, 3.f);  // sur BC
	print_result("E1(2.5,0)", false, inside(A, B, C, E1));
	print_result("E3(2,3)",   false, inside(A, B, C, E3));

	header("Near-edge robustness (epsilon inside)");
	Point NE(2.0f, 2.0f + 1e-3f);
	bool r = inside(A, B, C, NE);
	print_result("NE(2.0,2.001)", true, r);

	header("Different orientation (clockwise)");
	Point A2(2.f, 1.f), B2(6.f, 2.f), C2(3.f, 5.f);
	print_result("P(3,2) inside", true,  inside(A2, B2, C2, Point(3.f, 2.f)));
	print_result("P(10,10) outside", false, inside(A2, B2, C2, Point(10.f, 10.f)));

	header("Thin triangle (conditioning)");
	Point T1(0.f, 0.f), T2(1000.f, 0.01f), T3(1000.f, -0.01f);
	print_result("P(999.9,0)", true,  inside(T1, T2, T3, Point(999.9f, 0.f)));
	print_result("P(1000.1,0)", false, inside(T1, T2, T3, Point(1000.1f, 0.f)));

	header("Immutability of Point (x,y const)");
	Point Pconst(3.f, 4.f);
	std::cout << "Point Pconst(" << Pconst.getX() << ", " << Pconst.getY()
			  << ") created (compile-time constness verified)\n";

	std::cout << "\n=== End of bsp functional test ===\n";
	return 0;
}

