#include "functions.h"
#include <cmath>
#include <sstream>

namespace math {

/* Afim: y = a*x + b */
double affine(double a, double b, double x) { return a * x + b; }

std::vector<std::string> affine_steps(double a, double b, double x) {
    std::vector<std::string> steps;
    std::ostringstream oss;

    oss << "Afim: y = (" << a << ")·" << x << " + (" << b << ")";
    steps.push_back(oss.str());

    double prod = a * x;
    oss.str(""); oss.clear();
    oss << "a·x = " << prod;
    steps.push_back(oss.str());

    double res = prod + b;
    oss.str(""); oss.clear();
    oss << "y = " << res;
    steps.push_back(oss.str());
    return steps;
}

/* Quadrática: y = a*x² + b*x + c */
double quadratic(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

std::vector<std::string> quadratic_steps(double a, double b, double c,
                                         double x) {
    std::vector<std::string> steps;
    std::ostringstream oss;

    oss << "Quadrática: y = (" << a << ")·" << x << "^2 + ("
        << b << ")·" << x << " + (" << c << ")";
    steps.push_back(oss.str());

    double xx = x * x;
    oss.str(""); oss.clear();
    oss << "x² = " << xx;
    steps.push_back(oss.str());

    double ax2 = a * xx;
    oss.str(""); oss.clear();
    oss << "a·x² = (" << a << ")·" << xx << " = " << ax2;
    steps.push_back(oss.str());

    double bx = b * x;
    oss.str(""); oss.clear();
    oss << "b·x = (" << b << ")·" << x << " = " << bx;
    steps.push_back(oss.str());

    double res = ax2 + bx + c;
    oss.str(""); oss.clear();
    oss << "y = " << res;
    steps.push_back(oss.str());
    return steps;
}

/* Exponencial e */
double exponential(double x) { return std::exp(x); }

std::vector<std::string> exponential_steps(double x) {
    std::vector<std::string> steps;
    steps.emplace_back("e^x = " + std::to_string(std::exp(x)));
    return steps;
}

/* Logaritmo natural */
double ln(double x) { return std::log(x); }

std::vector<std::string> ln_steps(double x) {
    std::vector<std::string> steps;
    steps.emplace_back("ln(" + std::to_string(x) + ") = " +
                       std::to_string(std::log(x)));
    return steps;
}

/* Logaritmo base 10 */
double log10_(double x) { return std::log10(x); }

std::vector<std::string> log10_steps(double x) {
    std::vector<std::string> steps;
    steps.emplace_back("log10(" + std::to_string(x) + ") = " +
                       std::to_string(std::log10(x)));
    return steps;
}

} // namespace math
