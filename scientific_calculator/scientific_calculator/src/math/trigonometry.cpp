#include "../../include/math/trigonometry.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Manual implementations of math functions since standard library is not available
double sin(double x) {
    // Taylor series approximation for sin(x)
    double result = x;
    double term = x;
    for (int i = 1; i < 10; i++) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }
    return result;
}

double cos(double x) {
    // Taylor series approximation for cos(x)
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i < 10; i++) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        result += term;
    }
    return result;
}

double tan(double x) {
    return sin(x) / cos(x);
}

double asin(double x) {
    // Approximation using Newton's method
    if (x < -1.0 || x > 1.0) return 0.0; // Invalid input
    double result = x;
    for (int i = 0; i < 10; i++) {
        result = result - (sin(result) - x) / cos(result);
    }
    return result;
}

double acos(double x) {
    return M_PI / 2.0 - asin(x);
}

double atan(double x) {
    // Approximation using series expansion
    double result = x;
    double term = x;
    for (int i = 1; i < 20; i++) {
        term *= -x * x;
        result += term / (2 * i + 1);
    }
    return result;
}

double sqrt(double x) {
    // Newton's method for square root
    if (x < 0) return 0.0; // Invalid input
    if (x == 0) return 0.0;
    double result = x;
    for (int i = 0; i < 10; i++) {
        result = (result + x / result) / 2.0;
    }
    return result;
}

namespace math {

/* ------------------------- Conversions ------------------------- */
double deg_to_rad(double degrees) {
    return degrees * M_PI / 180.0;
}

double rad_to_deg(double radians) {
    return radians * 180.0 / M_PI;
}

/* ------------------------- Direct functions ------------------------- */
double sin_deg(double degrees) {
    return sin(deg_to_rad(degrees));
}

double cos_deg(double degrees) {
    return cos(deg_to_rad(degrees));
}

double tan_deg(double degrees) {
    return tan(deg_to_rad(degrees));
}

/* ------------------------- Inverse functions ------------------------- */
double asin_deg(double value) {
    return rad_to_deg(asin(value));
}

double acos_deg(double value) {
    return rad_to_deg(acos(value));
}

double atan_deg(double value) {
    return rad_to_deg(atan(value));
}

/* ------------------------- Laws ------------------------- */
double law_of_sines_side(double known_side, double known_angle_deg, double unknown_angle_deg) {
    return (known_side * sin(deg_to_rad(unknown_angle_deg))) /
           sin(deg_to_rad(known_angle_deg));
}

double law_of_cosines_side(double a, double b, double angleC_deg) {
    double C = deg_to_rad(angleC_deg);
    return sqrt(a * a + b * b - 2 * a * b * cos(C));
}

/* ------------------------- Step-by-step helpers ------------------------- */
// Note: Step-by-step functions temporarily disabled due to std library issues
// std::vector<std::string> sin_deg_steps(double degrees) {
//     std::vector<std::string> steps;
//     std::ostringstream oss;
// 
//     steps.push_back("Converting degrees to radians:");
//     oss << degrees << "° × π / 180 = " << deg_to_rad(degrees);
//     steps.push_back(oss.str());
// 
//     steps.push_back("Apply sine:");
//     oss.str(""); oss.clear();
//     oss << "sin(" << deg_to_rad(degrees) << ") = " << sin_deg(degrees);
//     steps.push_back(oss.str());
// 
//     return steps;
// }
// 
// std::vector<std::string> law_of_cosines_steps(double a, double b, double angleC_deg) {
//     std::vector<std::string> steps;
//     std::ostringstream oss;
// 
//     double C = deg_to_rad(angleC_deg);
//     steps.push_back("Formula: c² = a² + b² - 2ab cos(C)");
// 
//     oss << "c² = " << a << "² + " << b << "² - 2×" << a << "×" << b << "×cos(" << angleC_deg << "°)";
//     steps.push_back(oss.str());
// 
//     double result = a*a + b*b - 2*a*b*std::cos(C);
//     oss.str(""); oss.clear();
//     oss << "c² = " << result;
//     steps.push_back(oss.str());
// 
//     double c = std::sqrt(result);
//     oss.str(""); oss.clear();
//     oss << "c = sqrt(" << result << ") = " << c;
//     steps.push_back(oss.str());
// 
//     return steps;
// }

} // namespace math
