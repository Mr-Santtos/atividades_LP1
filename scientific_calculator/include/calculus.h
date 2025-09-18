#ifndef CALCULUS_H
#define CALCULUS_H

#include <vector>
#include <functional>
#include <string>

namespace math {
namespace calculus {

// Forward declaration for function type
using Function = std::function<double(double)>;

/**
 * @brief Calculates numerical limit of a function at a point using forward difference
 * @param f The function to evaluate
 * @param x The point where limit is calculated
 * @param h Small step size (default 1e-6)
 * @return Approximated limit value
 */
double limit(const Function& f, double x, double h = 1e-6);

/**
 * @brief Step-by-step calculation of numerical limit
 * @param f The function to evaluate
 * @param x The point where limit is calculated
 * @param h Small step size (default 1e-6)
 * @return Vector of steps explaining the process
 */
std::vector<std::string> limit_steps(const Function& f, double x, double h = 1e-6);

/**
 * @brief Calculates first-order derivative using central difference method
 * @param f The function to differentiate
 * @param x The point where derivative is calculated
 * @param h Small step size (default 1e-6)
 * @return Approximated derivative value
 */
double derivative(const Function& f, double x, double h = 1e-6);

/**
 * @brief Step-by-step calculation of first-order derivative
 * @param f The function to differentiate
 * @param x The point where derivative is calculated
 * @param h Small step size (default 1e-6)
 * @return Vector of steps explaining the process
 */
std::vector<std::string> derivative_steps(const Function& f, double x, double h = 1e-6);

/**
 * @brief Calculates definite integral using trapezoidal rule
 * @param f The function to integrate
 * @param a Lower bound of integration
 * @param b Upper bound of integration
 * @param n Number of subintervals (default 1000)
 * @return Approximated integral value
 */
double integral(const Function& f, double a, double b, int n = 1000);

/**
 * @brief Step-by-step calculation of definite integral using trapezoidal rule
 * @param f The function to integrate
 * @param a Lower bound of integration
 * @param b Upper bound of integration
 * @param n Number of subintervals (default 1000)
 * @return Vector of steps explaining the process
 */
std::vector<std::string> integral_steps(const Function& f, double a, double b, int n = 1000);

} // namespace calculus
} // namespace math

#endif // CALCULUS_H
