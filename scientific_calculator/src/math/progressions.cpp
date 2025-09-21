
#include "include/progressions.h"

namespace math {
namespace progressions {


double pa_nth_term(double a1, double d, unsigned long long n)
{
    return a1 + static_cast<double>(n - 1) * d;
}

std::vector<std::string> pa_nth_term_steps(double a1, double d,
                                           unsigned long long n)
{
    std::vector<std::string> steps;

    steps.emplace_back("Calculando o " + std::to_string(n) +
                       "-ésimo termo de PA:");
    steps.emplace_back("Primeiro termo (a₁):      " + std::to_string(a1));
    steps.emplace_back("Diferença comum (d):     " + std::to_string(d));

    double n_minus_1 = static_cast<double>(n - 1);
    steps.emplace_back("(n-1)                :   " +
                       std::to_string(n_minus_1));

    double prod = n_minus_1 * d;
    steps.emplace_back("(n-1)·d              :   " +
                       std::to_string(prod));

    double result = a1 + prod;
    steps.emplace_back("a₁ + (n-1)d          :   " +
                       std::to_string(result));

    return steps;
}

double pa_partial_sum(double a1, double d, unsigned long long n)
{

    double sum = static_cast<double>(n) / 2.0 *
                 (2.0 * a1 + static_cast<double>(n - 1) * d);
    return sum;
}

std::vector<std::string> pa_partial_sum_steps(double a1, double d,
                                               unsigned long long n)
{
    std::vector<std::string> steps;

    steps.emplace_back("Calculando soma parcial S(n) de PA:");
    steps.emplace_back("Primeiro termo (a₁):      " + std::to_string(a1));
    steps.emplace_back("Diferença comum (d):     " + std::to_string(d));
    steps.emplace_back("Número de termos (n):   " + std::to_string(n));

    double n_minus_1 = static_cast<double>(n - 1);
    double term_inside = 2.0 * a1 + n_minus_1 * d;

    steps.emplace_back("(n-1)                :   " +
                       std::to_string(n_minus_1));
    steps.emplace_back("2·a₁ + (n-1)d       :   " +
                       std::to_string(term_inside));

    double half_n = static_cast<double>(n) / 2.0;
    steps.emplace_back("n/2                 :   " +
                       std::to_string(half_n));

    double sum = half_n * term_inside;
    steps.emplace_back("(n/2)·[2a₁+(n-1)d] :   " + std::to_string(sum));

    return steps;
}


double pg_nth_term(double a1, double r, unsigned long long n)
{
    return a1 * std::pow(r, static_cast<double>(n - 1));
}

std::vector<std::string> pg_nth_term_steps(double a1, double r,
                                           unsigned long long n)
{
    std::vector<std::string> steps;

    steps.emplace_back("Calculando o " + std::to_string(n) +
                       "-ésimo termo de PG:");
    steps.emplace_back("Primeiro termo (a₁):      " + std::to_string(a1));
    steps.emplace_back("Razão comum (r):        " + std::to_string(r));

    double exp = static_cast<double>(n - 1);
    steps.emplace_back("(n-1)                :   " +
                       std::to_string(exp));

    double pow_val = std::pow(r, exp);
    steps.emplace_back("r^(n-1)              :   " +
                       std::to_string(pow_val));

    double result = a1 * pow_val;
    steps.emplace_back("a₁·r^(n-1)           :   " +
                       std::to_string(result));

    return steps;
}

double pg_partial_sum(double a1, double r, unsigned long long n)
{
    if (std::abs(r - 1.0) < 1e-12) {
        // Razão = 1 → soma simples
        return static_cast<double>(n) * a1;
    }
    return a1 * (1.0 - std::pow(r, static_cast<double>(n))) /
           (1.0 - r);
}

std::vector<std::string> pg_partial_sum_steps(double a1, double r,
                                               unsigned long long n)
{
    std::vector<std::string> steps;

    steps.emplace_back("Calculando soma parcial S(n) de PG:");
    steps.emplace_back("Primeiro termo (a₁):      " + std::to_string(a1));
    steps.emplace_back("Razão comum (r):        " + std::to_string(r));
    steps.emplace_back("Número de termos (n):   " + std::to_string(n));

    if (std::abs(r - 1.0) < 1e-12) {
        // Caso especial r == 1
        double sum = static_cast<double>(n) * a1;
        steps.emplace_back("r ≈ 1 → soma direta: n·a₁ = "
                           + std::to_string(sum));
        return steps;
    }

    double pow_val = std::pow(r, static_cast<double>(n));
    steps.emplace_back("r^n                  :   " +
                       std::to_string(pow_val));

    double numerator = 1.0 - pow_val;
    steps.emplace_back("(1 - r^n)            :   " +
                       std::to_string(numerator));

    double denominator = 1.0 - r;
    steps.emplace_back("(1 - r)              :   " +
                       std::to_string(denominator));

    double fraction = numerator / denominator;
    steps.emplace_back("(1-r^n)/(1-r)        :   " +
                       std::to_string(fraction));

    double sum = a1 * fraction;
    steps.emplace_back("a₁ · [(1-r^n)/(1-r)]  :   " +
                       std::to_string(sum));

    return steps;
}

} 
} 
