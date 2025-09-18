#pragma once

#include <string>
#include <vector>

namespace math {

struct LinearSolution {
    double x;        
    bool unique{true};
};

LinearSolution solve_linear(double a, double b, double c);
std::vector<std::string> solve_linear_steps(double a, double b, double c);

} 
