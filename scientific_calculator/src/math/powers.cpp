#include "powers.h"
#include <cmath>
#include <sstream>

namespace math {

double power(double base, double exponent) {
    return std::pow(base, exponent);
}

double root(double value, double degree) {
    if (degree == 0) throw std::domain_error("Root degree cannot be zero");
    return std::pow(value, 1.0 / degree);
}


std::vector<std::string> power_steps(double base, double exponent) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Compute using std::pow");
    steps.emplace_back("Result: " + std::to_string(power(base, exponent)));
    return steps;
}

std::vector<std::string> root_steps(double value, double degree) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Compute using std::pow with reciprocal exponent");
    steps.emplace_back("Result: " + std::to_string(root(value, degree)));
    return steps;
}

} 
