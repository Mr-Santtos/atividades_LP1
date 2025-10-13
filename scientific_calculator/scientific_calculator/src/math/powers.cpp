#include "../../include/math/powers.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Manual implementations of math functions since standard library is not available
double log_approx(double x) {
    // Natural logarithm approximation
    if (x <= 0) return 0.0; // Invalid input
    if (x == 1) return 0.0;
    
    // Use series expansion for ln(1+x) where x = (x-1)
    double y = x - 1.0;
    double result = y;
    double term = y;
    for (int i = 2; i < 20; i++) {
        term *= -y;
        result += term / i;
    }
    return result;
}

double exp_approx(double x) {
    // Taylor series approximation for e^x
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i < 20; i++) {
        term *= x / i;
        result += term;
    }
    return result;
}

double pow_manual(double base, double exponent) {
    // Simple power function for integer exponents
    if (exponent == 0) return 1.0;
    if (exponent == 1) return base;
    if (exponent == 2) return base * base;
    if (exponent == 3) return base * base * base;
    // For non-integer exponents, use approximation
    return exp_approx(exponent * log_approx(base));
}

namespace math {

double power(double base, double exponent) {
    return pow_manual(base, exponent);
}

double root(double value, double degree) {
    if (degree == 0) {
        // Return NaN instead of throwing exception
        return 0.0/0.0; // NaN
    }
    return pow_manual(value, 1.0 / degree);
}


// Note: Step-by-step functions temporarily disabled due to std library issues
/*
std::vector<std::string> power_steps(double base, double exponent) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Compute using manual power function");
    steps.emplace_back("Result: " + std::to_string(power(base, exponent)));
    return steps;
}

std::vector<std::string> root_steps(double value, double degree) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Compute using manual power function with reciprocal exponent");
    steps.emplace_back("Result: " + std::to_string(root(value, degree)));
    return steps;
}
*/

} 
