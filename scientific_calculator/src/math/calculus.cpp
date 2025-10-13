#include "include/math/calculus.h"
#include <cmath>
namespace math { namespace calculus {

double limit(const Function& f, double x, double h) {
    return f(x + h);
}

std::vector<std::string> limit_steps(const Function& f, double x, double h) {
    return {"limit not implemented (placeholder)"};
}

double derivative(const Function& f, double x, double h) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

std::vector<std::string> derivative_steps(const Function& f, double x, double h) {
    return {"derivative steps placeholder"};
}

double integral(const Function& f, double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i <= n; ++i) {
        double x = a + i * h;
        double fx = f(x);
        if (i == 0 || i == n) sum += fx;
        else sum += 2.0 * fx;
    }
    return sum * (h / 2.0);
}

std::vector<std::string> integral_steps(const Function& f, double a, double b, int n) {
    return {"integral steps placeholder"};
}

} } // namespace math::calculus
