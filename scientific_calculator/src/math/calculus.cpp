#include "math/calculus.h"
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

namespace math {
namespace calculus {

// ------------------------------------------------------------
// 1️⃣  LIMITE NUMÉRICO
// ------------------------------------------------------------
double limit(const Function& f, double x, double h) {
    // Forward difference approach for numerical limit
    return (f(x + h) - f(x)) / h;
}

std::vector<std::string> limit_steps(const Function& f, double x, double h) {
    std::vector<std::string> steps;

    steps.emplace_back("Calculando limite numérico de f(x) em x = " + 
                       std::to_string(x) + " com h = " + std::to_string(h));

    // Compute f(x+h) and f(x)
    double fx_plus_h = f(x + h);
    double fx = f(x);
    
    steps.emplace_back("f(x+h) = f(" + std::to_string(x + h) + ") = " + 
                       std::to_string(fx_plus_h));
    steps.emplace_back("f(x) = f(" + std::to_string(x) + ") = " + 
                       std::to_string(fx));
    
    // Calculate difference
    double diff = fx_plus_h - fx;
    steps.emplace_back("(f(x+h) - f(x)) = " + std::to_string(fx_plus_h) + 
                       " - " + std::to_string(fx) + " = " + std::to_string(diff));
    
    // Calculate limit
    double result = diff / h;
    steps.emplace_back("lim = (f(x+h) - f(x)) / h = " + std::to_string(diff) + 
                       " / " + std::to_string(h) + " = " + std::to_string(result));
    
    return steps;
}

// ------------------------------------------------------------
// 2️⃣  DERIVADA NUMÉRICA PRIMEIRA ORDEM
// ------------------------------------------------------------
double derivative(const Function& f, double x, double h) {
    // Central difference formula: f'(x) ≈ [f(x+h) - f(x-h)] / (2h)
    return (f(x + h) - f(x - h)) / (2 * h);
}

std::vector<std::string> derivative_steps(const Function& f, double x, double h) {
    std::vector<std::string> steps;

    steps.emplace_back("Calculando derivada numérica de f(x) em x = " + 
                       std::to_string(x) + " com h = " + std::to_string(h));

    // Compute f(x+h) and f(x-h)
    double fx_plus_h = f(x + h);
    double fx_minus_h = f(x - h);
    
    steps.emplace_back("f(x+h) = f(" + std::to_string(x + h) + ") = " + 
                       std::to_string(fx_plus_h));
    steps.emplace_back("f(x-h) = f(" + std::to_string(x - h) + ") = " + 
                       std::to_string(fx_minus_h));
    
    // Calculate numerator
    double numerator = fx_plus_h - fx_minus_h;
    steps.emplace_back("(f(x+h) - f(x-h)) = " + std::to_string(fx_plus_h) + 
                       " - (" + std::to_string(fx_minus_h) + ") = " + 
                       std::to_string(numerator));
    
    // Calculate denominator
    double denominator = 2 * h;
    steps.emplace_back("2h = 2 × " + std::to_string(h) + " = " + 
                       std::to_string(denominator));
    
    // Calculate derivative
    double result = numerator / denominator;
    steps.emplace_back("f'(x) ≈ (f(x+h) - f(x-h)) / (2h) = " + 
                       std::to_string(numerator) + " / " + 
                       std::to_string(denominator) + " = " + 
                       std::to_string(result));
    
    return steps;
}

// ------------------------------------------------------------
// 3️⃣  INTEGRAL DEFINIDA POR REGRAS DO TRAPÉZIO
// ------------------------------------------------------------
double integral(const Function& f, double a, double b, int n) {
    // Trapezoidal rule: ∫[a,b] f(x) dx ≈ h/2 * [f(a) + 2*Σf(xi) + f(b)]
    
    if (n <= 0) return 0;
    
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // First and last terms
    
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return h * sum;
}

std::vector<std::string> integral_steps(const Function& f, double a, double b, int n) {
    std::vector<std::string> steps;

    steps.emplace_back("Calculando integral definida de f(x) de " + 
                       std::to_string(a) + " a " + std::to_string(b) + 
                       " com " + std::to_string(n) + " subintervalos");

    // Calculate step size
    double h = (b - a) / n;
    steps.emplace_back("h = (b - a) / n = (" + std::to_string(b) + " - " + 
                       std::to_string(a) + ") / " + std::to_string(n) + 
                       " = " + std::to_string(h));

    // Calculate f(a) and f(b)
    double fa = f(a);
    double fb = f(b);
    
    steps.emplace_back("f(a) = f(" + std::to_string(a) + ") = " + 
                       std::to_string(fa));
    steps.emplace_back("f(b) = f(" + std::to_string(b) + ") = " + 
                       std::to_string(fb));

    // Calculate sum of intermediate points
    double sum = 0.5 * (fa + fb); // Start with first and last terms
    steps.emplace_back("Soma inicial: 0.5 × (f(a) + f(b)) = 0.5 × (" + 
                       std::to_string(fa) + " + " + std::to_string(fb) + 
                       ") = " + std::to_string(0.5 * (fa + fb)));

    // Add middle terms
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        double fx = f(x);
        steps.emplace_back("f(" + std::to_string(x) + ") = " + 
                           std::to_string(fx));
        sum += fx;
    }

    // Final calculation
    double integral_result = h * sum;
    steps.emplace_back("Integral ≈ h × (f(a) + 2×Σf(xi) + f(b)) / 2");
    steps.emplace_back("Integral ≈ " + std::to_string(h) + " × " + 
                       std::to_string(sum) + " = " + std::to_string(integral_result));
    
    return steps;
}

} // namespace calculus
} // namespace math
