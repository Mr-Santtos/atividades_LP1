#ifndef MATH_ANALYTIC_GEOMETRY_H
#define MATH_ANALYTIC_GEOMETRY_H

#include <utility>

namespace math {
struct Point { double x, y; };
double distance(const Point& a, const Point& b);
} // namespace math

#endif // MATH_ANALYTIC_GEOMETRY_H
