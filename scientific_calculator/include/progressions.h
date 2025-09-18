
#ifndef MATH_PROGRESSIONS_H
#define MATH_PROGRESSIONS_H

#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

namespace math {
namespace progressions {

/// @brief Retorna o n‑ésimo termo de uma PA.
/// @param a1 Primeiro termo da PA.
/// @param d Diferença comum (razao) entre termos consecutivos.
/// @param n Índice do termo desejado (1‑baseado).
inline double arithmetic_nth(double a1, double d, std::size_t n)
{
    return a1 + static_cast<double>(n - 1) * d;
}

/// @brief Passo‑a‑passo da PA – retorna as etapas de cálculo
///        do termo n‑ésimo.
/// @see arithmetic_nth
inline std::vector<std::string> arithmetic_nth_steps(double a1, double d,
                                                     std::size_t n)
{
    std::vector<std::string> steps;
    std::ostringstream oss;

    steps.emplace_back("Primeiro termo (a₁): " + std::to_string(a1));
    steps.emplace_back("Diferença comum (d): " + std::to_string(d));
    steps.emplace_back("Índice desejado (n): " + std::to_string(n));

    double diff = static_cast<double>(n - 1) * d;
    oss << std::fixed << std::setprecision(6)
        << "(n‑1)*d = (" << n-1 << ") * " << d << " = " << diff;
    steps.emplace_back(oss.str());

    double an = a1 + diff;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "aₙ = a₁ + (n‑1)d = " << a1 << " + (" << diff << ") = "
        << an;
    steps.emplace_back(oss.str());

    return steps;
}

/// @brief Soma dos n primeiros termos de uma PA.
/// @see arithmetic_nth
inline double arithmetic_sum(double a1, double d, std::size_t n)
{
    // Sₙ = n/2 * (2a₁ + (n‑1)d)
    return static_cast<double>(n) / 2.0 *
           (2.0 * a1 + static_cast<double>(n - 1) * d);
}

/// @brief Passo‑a‑passo da soma dos n primeiros termos de uma PA.
/// @see arithmetic_sum
inline std::vector<std::string> arithmetic_sum_steps(double a1, double d,
                                                     std::size_t n)
{
    std::vector<std::string> steps;
    std::ostringstream oss;

    steps.emplace_back("Primeiro termo (a₁): " + std::to_string(a1));
    steps.emplace_back("Diferença comum (d): " + std::to_string(d));
    steps.emplace_back("Quantidade de termos (n): " + std::to_string(n));

    double term = 2.0 * a1 + static_cast<double>(n - 1) * d;
    oss << std::fixed << std::setprecision(6)
        << "Termo interno: 2a₁ + (n‑1)d = "
        << 2*a1 << " + (" << n-1 << "*" << d << ") = " << term;
    steps.emplace_back(oss.str());

    double sum = static_cast<double>(n) / 2.0 * term;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "Sₙ = n/2 * termo interno = (" << n
        << "/2)*(" << term << ") = " << sum;
    steps.emplace_back(oss.str());

    return steps;
}

/// @brief Retorna o n‑ésimo termo de uma PG.
/// @param a1 Primeiro termo da PG.
/// @param r Razão (fator) entre termos consecutivos.
/// @param n Índice do termo desejado (1‑baseado).
inline double geometric_nth(double a1, double r, std::size_t n)
{
    return a1 * std::pow(r, static_cast<double>(n - 1));
}

/// @brief Passo‑a‑passo da PG – retorna as etapas de cálculo
///        do termo n‑ésimo.
/// @see geometric_nth
inline std::vector<std::string> geometric_nth_steps(double a1, double r,
                                                   std::size_t n)
{
    std::vector<std::string> steps;
    std::ostringstream oss;

    steps.emplace_back("Primeiro termo (a₁): " + std::to_string(a1));
    steps.emplace_back("Razão (r): " + std::to_string(r));
    steps.emplace_back("Índice desejado (n): " + std::to_string(n));

    double power = static_cast<double>(n - 1);
    oss << std::fixed << std::setprecision(6)
        << "(n‑1) = " << n-1;
    steps.emplace_back(oss.str());

    double rn = std::pow(r, power);
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "r^(n‑1) = " << r << "^(" << power << ") = " << rn;
    steps.emplace_back(oss.str());

    double an = a1 * rn;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "aₙ = a₁ * r^(n‑1) = " << a1 << " * (" << rn
        << ") = " << an;
    steps.emplace_back(oss.str());

    return steps;
}

/// @brief Soma dos n primeiros termos de uma PG.
/// @see geometric_nth
inline double geometric_sum(double a1, double r, std::size_t n)
{
    if (std::abs(r - 1.0) < 1e-12) // razão = 1 → soma simples
        return a1 * static_cast<double>(n);

    return a1 * (1.0 - std::pow(r, static_cast<double>(n))) /
           (1.0 - r);
}

/// @brief Passo‑a‑passo da soma dos n primeiros termos de uma PG.
/// @see geometric_sum
inline std::vector<std::string> geometric_sum_steps(double a1, double r,
                                                    std::size_t n)
{
    std::vector<std::string> steps;
    std::ostringstream oss;

    steps.emplace_back("Primeiro termo (a₁): " + std::to_string(a1));
    steps.emplace_back("Razão (r): " + std::to_string(r));
    steps.emplace_back("Quantidade de termos (n): " + std::to_string(n));

    if (std::abs(r - 1.0) < 1e-12)
    {
        double sum = a1 * static_cast<double>(n);
        oss << std::fixed << std::setprecision(6)
            << "Razão r ≈ 1 → Sₙ = n*a₁ = "
            << n << "*" << a1 << " = " << sum;
        steps.emplace_back(oss.str());
        return steps;
    }

    double rn = std::pow(r, static_cast<double>(n));
    oss << std::fixed << std::setprecision(6)
        << "rⁿ = " << r << "^(" << n << ") = " << rn;
    steps.emplace_back(oss.str());

    double numerator = 1.0 - rn;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "Numerador: 1 – rⁿ = 1 – (" << rn
        << ") = " << numerator;
    steps.emplace_back(oss.str());

    double denominator = 1.0 - r;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "Denominador: 1 – r = 1 – (" << r
        << ") = " << denominator;
    steps.emplace_back(oss.str());

    double sum = a1 * numerator / denominator;
    oss.str(""); oss.clear();
    oss << std::fixed << std::setprecision(6)
        << "Sₙ = a₁ * (1 – rⁿ)/(1 – r) = "
        << a1 << " * (" << numerator
        << ") / (" << denominator << ") = " << sum;
    steps.emplace_back(oss.str());

    return steps;
}

} // namespace progressions
} // namespace math

#endif // MATH_PROGRESSIONS_H
