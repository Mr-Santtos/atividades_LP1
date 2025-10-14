#pragma once
#include <vector>
#include <string>

namespace math {

/**
 * @brief Estrutura que representa o resultado de uma equação linear.
 */
struct LinearSolution {
    double x = 0.0;          ///< Valor da incógnita x (caso exista)
    bool unique = true;      ///< Indica se há uma única solução
    bool infinite = false;   ///< Indica se há infinitas soluções
    bool no_solution = false;///< Indica se não há solução
    std::string description; ///< Descrição textual da solução
};

/**
 * @brief Resolve uma equação linear da forma ax + b = c.
 * 
 * @param a Coeficiente de x
 * @param b Termo constante do lado esquerdo
 * @param c Termo do lado direito
 * @return LinearSolution Estrutura com o valor de x e informações da solução
 */
LinearSolution solve_linear(double a, double b, double c);

/**
 * @brief Gera um passo a passo textual da resolução de uma equação linear.
 * 
 * @param a Coeficiente de x
 * @param b Termo constante do lado esquerdo
 * @param c Termo do lado direito
 * @return std::vector<std::string> Lista de passos explicativos
 */
std::vector<std::string> solve_linear_steps(double a, double b, double c);

} // namespace math
