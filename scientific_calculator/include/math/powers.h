#pragma once

#include <vector>
#include <string>

namespace math {

double power(double base, double exponent);
double root(double value, double degree); 

std::vector<std::string> power_steps(double base, double exponent);
std::vector<std::string> root_steps(double value, double degree);

} 
