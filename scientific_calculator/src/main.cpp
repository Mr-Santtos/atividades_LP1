#include <iostream>
#include <cmath>

// headers (se você não quiser usar .h, pode colar as structs no próprio main)
#include "fractions.cpp"
#include "functions.cpp"
#include "linear_equation.cpp"
#include "matrices.cpp"
#include "powers.cpp"
#include "progressions.cpp"
#include "quadratic_equation.cpp"
#include "analytic_geometry.cpp"


int main() {
    using namespace math;

    // Frações
    Fraction f1{3, 4}, f2{5, 6};
    auto sum = add(f1, f2);
    std::cout << "Sum: " << sum.numerator << "/" << sum.denominator << "\n";

    std::cout << "Steps for addition:\n";
    for (auto& s : add_steps(f1, f2)) std::cout << "  - " << s << '\n';

    // Potência
    double p = power(2.0, 3.5);
    std::cout << "\n2^3.5 = " << p << "\n";

    std::cout << "Steps for power:\n";
    for (auto& s : power_steps(2.0, 3.5)) std::cout << "  - " << s << '\n';

    // Equação linear
    auto sol = solve_linear(2.0, -4.0, 10.0);
    if (sol.unique)
        std::cout << "\nLinear solution: x = " << sol.x << "\n";
    else
        std::cout << "\nNo unique linear solution.\n";

    // Equação quadrática
    auto roots = solve_quadratic(1.0, -3.0, 2.0);
    std::cout << "Quadratic roots: " << roots.first << ", " << roots.second << "\n";

    // Função trigonométrica
    double y = std::sin(M_PI / 6);
    std::cout << "\nsin(π/6) = " << y << "\n";

    // Progressão aritmética
    double nth_ap = progressions::pa_nth_term(3.0, 5.0, 10);
    std::cout << "10th term of AP: " << nth_ap << "\n";

    // Matriz 2x2
    Matrix2x2 m{{1, 2}, {3, 4}};
    double det = matrices::det_2x2(m);
    std::cout << "\nDeterminant of [[1,2],[3,4]]: " << det << "\n";

    // Conversão de graus para radianos
    double rad = M_PI / 180.0 * 45.0;
    std::cout << "\nsin(45°) ≈ " << std::sin(rad) << "\n";

    // Geometria analítica
    analytic::Point2D p1{0, 0}, p2{3, 4};
    std::cout << "\nDistance between (0,0) and (3,4): "
              << analytic::distance(p1, p2) << "\n";

    return 0;
}
