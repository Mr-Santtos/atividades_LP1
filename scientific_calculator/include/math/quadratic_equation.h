#ifndef MATH_QUADRATIC_EQUATION_H
#define MATH_QUADRATIC_EQUATION_H

#include <utility>
#include <vector>

namespace math {
std::vector<double> solve_quadratic(double a, double b, double c);
std::pair<bool, std::pair<double,double>> solve_quadratic_checked(double a, double b, double c);
} // namespace math

#endif // MATH_QUADRATIC_EQUATION_H
