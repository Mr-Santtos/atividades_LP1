#ifndef MATH_CALCULUS_H
#define MATH_CALCULUS_H

#include <vector>
#include <functional>
#include <string>

namespace math {
namespace calculus {
using Function = std::function<double(double)>;
double limit(const Function& f, double x, double h = 1e-6);
std::vector<std::string> limit_steps(const Function& f, double x, double h = 1e-6);
double derivative(const Function& f, double x, double h = 1e-6);
std::vector<std::string> derivative_steps(const Function& f, double x, double h = 1e-6);
double integral(const Function& f, double a, double b, int n = 1000);
std::vector<std::string> integral_steps(const Function& f, double a, double b, int n = 1000);
} // namespace calculus
} // namespace math

#endif // MATH_CALCULUS_H
