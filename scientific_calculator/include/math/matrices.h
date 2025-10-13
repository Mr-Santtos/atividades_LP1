#ifndef MATH_MATRICES_H
#define MATH_MATRICES_H

#include <vector>

namespace math {
using Matrix = std::vector<std::vector<double>>;
Matrix transpose(const Matrix& m);
double determinant(const Matrix& m);
Matrix inverse(const Matrix& m);
} // namespace math

#endif // MATH_MATRICES_H
