#pragma once

// Note: Standard library headers temporarily disabled due to compiler issues
// #include <vector>
// #include <string>

namespace math {

// Simple pair structure to replace std::pair
struct Pair {
    double first, second;
    Pair(double f, double s) : first(f), second(s) {}
};

/**
 * @brief Resolve uma equação do segundo grau ax² + bx + c = 0
 * @param a Coeficiente de x² (a ≠ 0)
 * @param b Coeficiente de x
 * @param c Termo independente
 * @return Pair – primeira raiz, segunda raiz.
 *         Se Δ < 0, ambas retornam NaN. Se a == 0, retorna NaN.
 */
Pair solve_quadratic(double a, double b, double c);

/**
 * @brief Passo‑a‑passo da resolução de uma equação do segundo grau
 *
 * Cada elemento do vector contém um trecho explicativo em português.
 *
 * @param a Coeficiente de x² (a ≠ 0)
 * @param b Coeficiente de x
 * @param c Termo independente
 * @return std::vector<std::string> – sequência de passos. Se Δ < 0,
 *         o último elemento informa que não há raízes reais.
 */
// Note: Step-by-step function temporarily disabled due to std library issues
// std::vector<std::string> solve_quadratic_steps(double a, double b, double c);

} // namespace math
