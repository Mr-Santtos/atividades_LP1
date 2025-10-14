
#ifndef MATH_PROGRESSIONS_H
#define MATH_PROGRESSIONS_H

// Note: Standard library headers temporarily disabled due to compiler issues
// #include <vector>
// #include <string>
// #include <sstream>
// #include <iomanip>
// #include <cmath>

namespace math {
namespace progressions {

/// @brief Retorna o n‑ésimo termo de uma PA.
/// @param a1 Primeiro termo da PA.
/// @param d Diferença comum (razao) entre termos consecutivos.
/// @param n Índice do termo desejado (1‑baseado).
inline double arithmetic_nth(double a1, double d, unsigned long long n)
{
    return a1 + static_cast<double>(n - 1) * d;
}

/// @brief Passo‑a‑passo da PA – retorna as etapas de cálculo
///        do termo n‑ésimo.
/// @see arithmetic_nth
// Note: Step-by-step function temporarily disabled due to std library issues
// inline std::vector<std::string> arithmetic_nth_steps(double a1, double d,
//                                                      std::size_t n)

/// @brief Soma dos n primeiros termos de uma PA.
/// @see arithmetic_nth
inline double arithmetic_sum(double a1, double d, unsigned long long n)
{
    // Sₙ = n/2 * (2a₁ + (n‑1)d)
    return static_cast<double>(n) / 2.0 *
           (2.0 * a1 + static_cast<double>(n - 1) * d);
}

/// @brief Passo‑a‑passo da soma dos n primeiros termos de uma PA.
/// @see arithmetic_sum
// Note: Step-by-step function temporarily disabled due to std library issues
// inline std::vector<std::string> arithmetic_sum_steps(double a1, double d,
//                                                      std::size_t n)

/// @brief Retorna o n‑ésimo termo de uma PG.
/// @param a1 Primeiro termo da PG.
/// @param r Razão (fator) entre termos consecutivos.
/// @param n Índice do termo desejado (1‑baseado).
inline double geometric_nth(double a1, double r, unsigned long long n)
{
    return a1 * pow(r, static_cast<double>(n - 1));
}

/// @brief Passo‑a‑passo da PG – retorna as etapas de cálculo
///        do termo n‑ésimo.
/// @see geometric_nth
// Note: Step-by-step function temporarily disabled due to std library issues
// inline std::vector<std::string> geometric_nth_steps(double a1, double r,
//                                                    std::size_t n)

/// @brief Soma dos n primeiros termos de uma PG.
/// @see geometric_nth
inline double geometric_sum(double a1, double r, unsigned long long n)
{
    if (abs(r - 1.0) < 1e-12) // razão = 1 → soma simples
        return a1 * static_cast<double>(n);

    return a1 * (1.0 - pow(r, static_cast<double>(n))) /
           (1.0 - r);
}

/// @brief Passo‑a‑passo da soma dos n primeiros termos de uma PG.
/// @see geometric_sum
// Note: Step-by-step function temporarily disabled due to std library issues
// inline std::vector<std::string> geometric_sum_steps(double a1, double r,
//                                                     std::size_t n)

} // namespace progressions
} // namespace math

#endif // MATH_PROGRESSIONS_H
