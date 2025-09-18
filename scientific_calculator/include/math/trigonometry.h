#pragma once
/**
 * @file trigonometry.h
 * @brief Trigonometric functions, conversions, and step-by-step helpers.
 */

#include <vector>
#include <string>

namespace math {

/* ------------------------- Conversions ------------------------- */

/** Convert degrees to radians */
double deg_to_rad(double degrees);

/** Convert radians to degrees */
double rad_to_deg(double radians);

/* ------------------------- Direct functions ------------------------- */
double sin_deg(double degrees);
double cos_deg(double degrees);
double tan_deg(double degrees);

/* ------------------------- Inverse functions ------------------------- */
double asin_deg(double value);
double acos_deg(double value);
double atan_deg(double value);

/* ------------------------- Laws ------------------------- */
/** Law of sines: a/sin(A) = b/sin(B) = c/sin(C) */
double law_of_sines_side(double known_side, double known_angle_deg, double unknown_angle_deg);

/** Law of cosines: c² = a² + b² - 2ab cos(C) */
double law_of_cosines_side(double a, double b, double angleC_deg);

/* ------------------------- Step-by-step helpers ------------------------- */
std::vector<std::string> sin_deg_steps(double degrees);
std::vector<std::string> law_of_cosines_steps(double a, double b, double angleC_deg);

} // namespace math
