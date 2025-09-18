#include <iostream>
#include <cmath>
#include "include\fractions.h"
#include "powers.h"
#include "linear_equation.h"
#include "quadratic_equation.h"
#include "functions.h"
#include "progressions.h"
#include "matrices.h"
#include "trigonometry.h"
#include "analytic_geometry.h"
#include "calculus.h"


int main() {
    using namespace math;


    Fraction f1{3, 4}, f2{5, 6};
    auto sum = add(f1, f2);
    std::cout << "Sum: " << sum.numerator << "/" << sum.denominator << "\n";

    std::cout << "Steps for addition:\n";
    for (auto& s : add_steps(f1, f2)) std::cout << "  - " << s << '\n';


    double p = pow(2.0, 3.5);
    std::cout << "\n2^3.5 = " << p << "\n";

    std::cout << "Steps for power:\n";
    for (auto& s : pow_steps(2.0, 3.5)) std::cout << "  - " << s << '\n';

    double x = solve_linear(2.0, -4.0, 10.0);   
    std::cout << "\nLinear solution: x = " << x << "\n";

    auto roots = solve_quadratic(1.0, -3.0, 2.0);   
    std::cout << "Quadratic roots: " << roots.first << ", " << roots.second << "\n";

    double y = evaluate_function(FunctionType::sin, M_PI / 6);
    std::cout << "\nsin(π/6) = " << y << "\n";

    double nth_ap = ap_nth_term(3.0, 5.0, 10); 
    std::cout << "10th term of AP: " << nth_ap << "\n";

    Matrix2x2 m{{1, 2}, {3, 4}};
    double det = determinant(m);
    std::cout << "\nDeterminant of [[1,2],[3,4]]: " << det << "\n";

    double rad = deg_to_rad(45.0);
    std::cout << "\nsin(45°) ≈ " << sin(rad) << "\n";

    Point p1{0, 0}, p2{3, 4};
    std::cout << "\nDistance between (0,0) and (3,4): " << distance(p1, p2) << "\n";

    double limit = numeric_limit([](double x){ return sin(x)/x; }, 0.0);
    std::cout << "\nLimit of sin(x)/x as x→0: " << limit << "\n";

    double derivative = central_difference([](double x){ return x * x; }, 2.0, 1e-5);
    std::cout << "Derivative at x=2 of f(x)=x^2: " << derivative << "\n";

    double integral = trapezoidal_integral([](double t){ return t*t; }, 0.0, 3.0, 1000);
    std::cout << "Integral of t^2 from 0 to 3: " << integral << "\n";
}
