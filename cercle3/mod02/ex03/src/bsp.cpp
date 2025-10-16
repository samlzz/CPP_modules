/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:23:53 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/16 18:23:56 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed cross(Point const& p1, Point const& p2, Point const& p3)
{
  return (p1 - p3) * (p2 - p3);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Fixed d1 = cross(point, a, b);
  Fixed d2 = cross(point, b, a);
  Fixed d3 = cross(point, c, a);
  Fixed zero = Fixed(0);

  if (d1 == zero || d2 == zero || d3 == zero)
    return false;
  bool  allPos = (d1 > zero && d2 > zero && d3 > zero);
  bool  allNeg = (d1 < zero && d2 < zero && d3 < zero);
  return allPos || allNeg;
}
