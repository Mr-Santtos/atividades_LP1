#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include "../../include/math/linear_equation.h"

namespace math {

LinearSolution solve_linear(double a, double b, double c) {
    LinearSolution sol;

    // Tolerância para erros de ponto flutuante
    const double EPS = 1e-9;

    // Caso 1: a ≈ 0 (não é uma equação de 1º grau)
    if (std::fabs(a) < EPS) {
        if (std::fabs(b - c) < EPS) {
            // 0x + b = b → identidade (infinitas soluções)
            sol.infinite = true;
            sol.unique = false;
            sol.description = "Infinitas soluções (identidade verdadeira para qualquer x).";
            sol.x = std::numeric_limits<double>::quiet_NaN();
        } else {
            // 0x + b = c → contradição (sem solução)
            sol.no_solution = true;
            sol.unique = false;
            sol.description = "Nenhuma solução (equação impossível).";
            sol.x = std::numeric_limits<double>::quiet_NaN();
        }
        return sol;
    }

    // Caso 2: solução única
    sol.x = (c - b) / a;
    sol.description = "Solução única encontrada.";
    return sol;
}

std::vector<std::string> solve_linear_steps(double a, double b, double c) {
    std::vector<std::string> steps;
    const double EPS = 1e-9;

    steps.push_back("Equação inicial: " + std::to_string(a) + "x + " + std::to_string(b) + " = " + std::to_string(c));

    if (std::fabs(a) < EPS) {
        if (std::fabs(b - c) < EPS) {
            steps.push_back("O coeficiente 'a' é zero e os dois lados são iguais → infinitas soluções.");
        } else {
            steps.push_back("O coeficiente 'a' é zero e os lados diferem → nenhuma solução possível.");
        }
        return steps;
    }

    // Isolar o termo com x
    steps.push_back("Passo 1: Mover " + std::to_string(b) + " para o outro lado → subtrair de ambos os lados.");
    double rhs = c - b;
    steps.push_back("Resultado: " + std::to_string(a) + "x = " + std::to_string(rhs));

    // Dividir ambos os lados por 'a'
    steps.push_back("Passo 2: Dividir ambos os lados por " + std::to_string(a));
    double x = rhs / a;
    steps.push_back("Solução final: x = " + std::to_string(x));

    return steps;
}

} // namespace math
