/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:10:48 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/16 22:10:49 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

static bool approx(float a, float b, float eps = 1e-4f)
{
    return std::fabs(a - b) < eps;
}

static void header(const char *name)
{
    std::cout << "\n=== " << name << " ===\n";
}

static void print_test(std::string const &label, bool success)
{
    std::cout << label << " -> " << (success ? "✅" : "❌") << "\n";
}

int main()
{
    header("Comparisons");
    Fixed a(1.0f), b(2), c(1);
    print_test("a < b", a < b);
    print_test("b > a", b > a);
    print_test("a <= c", a <= c);
    print_test("a >= c", a >= c);
    print_test("a == c", a == c);
    print_test("a != c", !(a != c));

    header("Arithmetic + - * /");
    Fixed x(5.5f), y(2);
    Fixed s = x + y; // 7.5
    Fixed m = x - y; // 3.5
    Fixed p = x * y; // 11
    Fixed d = x / y; // 2.75
    std::cout << "x=" << x << ", y=" << y << "\n";
    std::cout << "x+y=" << s << " (expected 7.5) -> " << (approx(s.toFloat(), 7.5f) ? "✅" : "❌") << "\n";
    std::cout << "x-y=" << m << " (expected 3.5) -> " << (approx(m.toFloat(), 3.5f) ? "✅" : "❌") << "\n";
    std::cout << "x*y=" << p << " (expected 11) -> " << (approx(p.toFloat(), 11.0f) ? "✅" : "❌") << "\n";
    std::cout << "x/y=" << d << " (expected 2.75) -> " << (approx(d.toFloat(), 2.75f) ? "✅" : "❌") << "\n";

    header("Increment / Decrement (pre/post)");
    Fixed inc; // 0
    bool pre = approx((++inc).toFloat(), 1.0f / 256);
    float afterPre = inc.toFloat();
    Fixed beforePost = inc++;
    bool post = approx(beforePost.toFloat(), afterPre);
    bool postResult = approx(inc.toFloat(), afterPre + 1.0f / 256);
    Fixed dec = inc;
    bool preDec = approx((--dec).toFloat(), inc.toFloat() - 1.0f / 256);
    Fixed beforePostDec = dec--;
    bool postDec = approx(beforePostDec.toFloat(), dec.toFloat() + 1.0f / 256);

    print_test("++inc gives 1/256", pre);
    print_test("inc++ returns old value", post);
    print_test("inc++ result increments", postResult);
    print_test("--dec gives value-1/256", preDec);
    print_test("dec-- returns old value", postDec);

    header("Chained arithmetic / scaling");
    Fixed u(3.25f), v(7.75f);
    Fixed w = (u * v) / v; // ≈ u (petite perte possible)
    std::cout << "(u*v)/v = " << w << " expected ≈ " << u << " -> "
              << (approx(w.toFloat(), u.toFloat(), 1e-3f) ? "✅" : "❌") << "\n";

    header("min/max overloads");
    Fixed a1(10), a2(10.5f);
    const Fixed ca1(1.5f), ca2(1.25f);
    print_test("&min(a1,a2)==&a1", &Fixed::min(a1, a2) == &a1);
    print_test("&max(a1,a2)==&a2", &Fixed::max(a1, a2) == &a2);
    print_test("&min(ca1,ca2)==&ca2", &Fixed::min(ca1, ca2) == &ca2);
    print_test("&max(ca1,ca2)==&ca1", &Fixed::max(ca1, ca2) == &ca1);

    header("Edge: large values but no overflow");
    Fixed big1(10000);
    Fixed big2(2);
    Fixed mul = big1 * big2;
    std::cout << "big1*big2 = " << mul << " (expected 20000) -> "
              << ((mul.toInt() == 20000) ? "✅" : "❌") << "\n";

    std::cout << "\n=== End of ex02 functional test ===\n";
    return 0;
}

