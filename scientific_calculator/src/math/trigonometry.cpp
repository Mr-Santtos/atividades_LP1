#include "include\trigonometry.h"
#include <cmath>
#include <sstream>

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
    return std::sin(deg_to_rad(degrees));
}

double cos_deg(double degrees) {
    return std::cos(deg_to_rad(degrees));
}

double tan_deg(double degrees) {
    return std::tan(deg_to_rad(degrees));
}

/* ------------------------- Inverse functions ------------------------- */
double asin_deg(double value) {
    return rad_to_deg(std::asin(value));
}

double acos_deg(double value) {
    return rad_to_deg(std::acos(value));
}

double atan_deg(double value) {
    return rad_to_deg(std::atan(value));
}

/* ------------------------- Laws ------------------------- */
double law_of_sines_side(double known_side, double known_angle_deg, double unknown_angle_deg) {
    return (known_side * std::sin(deg_to_rad(unknown_angle_deg))) /
           std::sin(deg_to_rad(known_angle_deg));
}

double law_of_cosines_side(double a, double b, double angleC_deg) {
    double C = deg_to_rad(angleC_deg);
    return std::sqrt(a * a + b * b - 2 * a * b * std::cos(C));
}

/* ------------------------- Step-by-step helpers ------------------------- */
std::vector<std::string> sin_deg_steps(double degrees) {
    std::vector<std::string> steps;
    std::ostringstream oss;

    steps.push_back("Converting degrees to radians:");
    oss << degrees << "° × π / 180 = " << deg_to_rad(degrees);
    steps.push_back(oss.str());

    steps.push_back("Apply sine:");
    oss.str(""); oss.clear();
    oss << "sin(" << deg_to_rad(degrees) << ") = " << sin_deg(degrees);
    steps.push_back(oss.str());

    return steps;
}

std::vector<std::string> law_of_cosines_steps(double a, double b, double angleC_deg) {
    std::vector<std::string> steps;
    std::ostringstream oss;

    double C = deg_to_rad(angleC_deg);
    steps.push_back("Formula: c² = a² + b² - 2ab cos(C)");

    oss << "c² = " << a << "² + " << b << "² - 2×" << a << "×" << b << "×cos(" << angleC_deg << "°)";
    steps.push_back(oss.str());

    double result = a*a + b*b - 2*a*b*std::cos(C);
    oss.str(""); oss.clear();
    oss << "c² = " << result;
    steps.push_back(oss.str());

    double c = std::sqrt(result);
    oss.str(""); oss.clear();
    oss << "c = sqrt(" << result << ") = " << c;
    steps.push_back(oss.str());

    return steps;
}

} // namespace math
