#ifndef MATH_LINEAR_EQUATION_H
#define MATH_LINEAR_EQUATION_H

#include <vector>

namespace math {
std::vector<double> solve_linear_system(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
} // namespace math

#endif // MATH_LINEAR_EQUATION_H
