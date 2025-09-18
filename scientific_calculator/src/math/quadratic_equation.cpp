/*********************************************************************
 *   Implementação de solve_quadratic() e solve_quadratic_steps()
 *
 *   Algoritmo:
 *     1. Verifica que a ≠ 0 → se não, lança exceção.
 *     2. Calcula discriminante Δ = b² – 4ac.
 *     3. Se Δ < 0 → retorna std::make_pair(NAN,NAN).
 *     4. Caso contrário calcula:
 *          x1 = (-b + sqrt(Δ)) / (2a)
 *          x2 = (-b - sqrt(Δ)) / (2a)
 *
 *   Passo‑a‑passo detalhado: todas as etapas são registradas em
 *   std::vector<std::string>.
 *********************************************************************/

#include "include\quadratic_equation.h"

#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iomanip> // para std::setprecision

namespace math {

static constexpr double EPS = 1e-12;          // tolerância para a == 0
static const std::string NAN_STR = "NaN";

/* --------------------------------------------------------------- */
std::pair<double, double>
solve_quadratic(double a, double b, double c)
{
    if (std::abs(a) < EPS) {
        throw std::invalid_argument("Coeficiente 'a' não pode ser zero");
    }

    const double delta = b * b - 4.0 * a * c;

    // Raízes reais apenas se Δ >= 0
    if (delta < 0.0) {
        return {NAN, NAN};
    }

    const double sqrt_delta = std::sqrt(delta);
    const double denom      = 2.0 * a;

    const double x1 = (-b + sqrt_delta) / denom;
    const double x2 = (-b - sqrt_delta) / denom;

    return {x1, x2};
}

/* --------------------------------------------------------------- */
std::vector<std::string>
solve_quadratic_steps(double a, double b, double c)
{
    std::vector<std::string> steps;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6); // 6 casas decimais padrão

    /* ---------- 1. Verificar 'a' ≠ 0 -------------------------------- */
    if (std::abs(a) < EPS) {
        steps.push_back("Erro: o coeficiente 'a' não pode ser zero.");
        return steps;
    }
    oss.str(""); oss.clear();
    oss << "Coeficientes recebidos:\n"
        << "   a = " << a << "\n"
        << "   b = " << b << "\n"
        << "   c = " << c;
    steps.push_back(oss.str());

    /* ---------- 2. Discriminante ----------------------------------- */
    const double delta = b * b - 4.0 * a * c;
    oss.str(""); oss.clear();
    oss << "Δ (discriminante) = b² – 4ac\n"
        << "   Δ = (" << b << ")² – 4·(" << a << ")·(" << c << ")\n"
        << "   Δ = " << delta;
    steps.push_back(oss.str());

    /* ---------- 3. Caso Δ < 0 ------------------------------------- */
    if (delta < 0.0) {
        steps.push_back(
            "Δ é negativo → não há raízes reais.\n"
            "Resultado: x₁ = NaN, x₂ = NaN");
        return steps;
    }

    /* ---------- 4. Raiz quadrada de Δ ------------------------------ */
    const double sqrt_delta = std::sqrt(delta);
    oss.str(""); oss.clear();
    oss << "√Δ = √" << delta << " = " << sqrt_delta;
    steps.push_back(oss.str());

    /* ---------- 5. Denominador ------------------------------------- */
    const double denom = 2.0 * a;
    oss.str(""); oss.clear();
    oss << "Denominador (2a) = 2·(" << a << ") = " << denom;
    steps.push_back(oss.str());

    /* ---------- 6. Raízes ------------------------------------------------ */
    const double x1 = (-b + sqrt_delta) / denom;
    const double x2 = (-b - sqrt_delta) / denom;

    oss.str(""); oss.clear();
    oss << "x₁ = (-b + √Δ) / (2a)\n"
        << "   = (" << -b << ") + (" << sqrt_delta << ") "
        << "/ (" << denom << ") = " << x1;
    steps.push_back(oss.str());

    oss.str(""); oss.clear();
    oss << "x₂ = (-b - √Δ) / (2a)\n"
        << "   = (" << -b << ") - (" << sqrt_delta << ") "
        << "/ (" << denom << ") = " << x2;
    steps.push_back(oss.str());

    return steps;
}

} // namespace math
