#include "include/linear_equation.h"
#include <sstream>
#include <limits>


namespace math {

LinearSolution solve_linear(double a, double b, double c) {
    LinearSolution sol;
    if (a == 0) {                     
        sol.unique = false;
        sol.x = std::numeric_limits<double>::quiet_NaN();
        return sol;
    }
    sol.x = (c - b) / a;
    return sol;
}

std::vector<std::string> solve_linear_steps(double a, double b, double c) {
    std::vector<std::string> steps;
    steps.push_back("Equation: " + std::to_string(a) + "x + "
                    + std::to_string(b) + " = " + std::to_string(c));
    if (a == 0) {
        steps.push_back("Coefficient a is zero → no unique solution.");
        return steps;
    }
    steps.push_back("Step 1: Move constant to RHS");
    double rhs = c - b;
    steps.emplace_back(std::to_string(rhs) + " = " + std::to_string(c) + " - "
                       + std::to_string(b));
    steps.push_back("Step 2: Divide by a");
    double x = rhs / a;
    steps.emplace_back("x = " + std::to_string(x));
    return steps;
}

} 
