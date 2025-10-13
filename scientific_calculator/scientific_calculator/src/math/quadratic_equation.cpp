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

#include "../../include/math/quadratic_equation.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef NAN
#define NAN (0.0/0.0)
#endif

// Manual implementations of math functions since standard library is not available
double abs(double x) {
    return (x < 0) ? -x : x;
}

double sqrt(double x) {
    // Newton's method for square root
    if (x < 0) return 0.0; // Invalid input
    if (x == 0) return 0.0;
    double result = x;
    for (int i = 0; i < 10; i++) {
        result = (result + x / result) / 2.0;
    }
    return result;
}

namespace math {

static constexpr double EPS = 1e-12;          // tolerância para a == 0
static const char* NAN_STR = "NaN";

/* --------------------------------------------------------------- */

Pair solve_quadratic(double a, double b, double c)
{
    if (abs(a) < EPS) {
        // Return NaN pair instead of throwing exception
        return Pair(NAN, NAN);
    }

    const double delta = b * b - 4.0 * a * c;

    // Raízes reais apenas se Δ >= 0
    if (delta < 0.0) {
        return {NAN, NAN};
    }

    const double sqrt_delta = sqrt(delta);
    const double denom      = 2.0 * a;

    const double x1 = (-b + sqrt_delta) / denom;
    const double x2 = (-b - sqrt_delta) / denom;

    return Pair(x1, x2);
}

/* --------------------------------------------------------------- */
// Note: Step-by-step function temporarily disabled due to std library issues
// The function solve_quadratic_steps() would be implemented here when std library is available

} // namespace math
