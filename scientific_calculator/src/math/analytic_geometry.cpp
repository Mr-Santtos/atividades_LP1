// src/math/analytic_geometry.cpp
//
// Este arquivo contém as definições de todas as funções declaradas em
// math/analytic_geometry.h (caso você decida retirar o keyword inline).
//
// Se preferir deixar tudo no header, basta apagar este arquivo – ele não será
// compilado nem vinculado.
//
// O código abaixo segue exatamente a mesma lógica que já estava em
// analytic_geometry.h; apenas movemos os corpos das funções para aqui.

#include "include\analytic_geometry.h"
#include <cmath>
#include <string>
#include <vector>

namespace math::analytic {

// ------------------------------------------------------------
// 1️⃣  DISTÂNCIA ENTRE DOIS PONTOS
// ------------------------------------------------------------
double distance(const Point2D& a, const Point2D& b) noexcept {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::hypot(dx, dy);            // √(dx² + dy²)
}

std::vector<std::string> distance_steps(const Point2D& a,
                                        const Point2D& b) {
    std::vector<std::string> steps;

    steps.emplace_back(
        "Calculando distância entre pontos (" +
        std::to_string(a.x) + ", " + std::to_string(a.y) +
        ") e (" + std::to_string(b.x) + ", " +
        std::to_string(b.y) + ").");

    double dx = a.x - b.x;
    double dy = a.y - b.y;

    steps.emplace_back(
        "Δx = |" + std::to_string(a.x) + " − " + std::to_string(b.x) +
        "| = " + std::to_string(dx));
    steps.emplace_back(
        "Δy = |" + std::to_string(a.y) + " − " + std::to_string(b.y) +
        "| = " + std::to_string(dy));

    double dist = std::hypot(dx, dy);
    steps.emplace_back("distância = √(Δx² + Δy²) = √("
                       + std::to_string(dx * dx) + " + "
                       + std::to_string(dy * dy) +
                       ") = " + std::to_string(dist));

    return steps;
}

// ------------------------------------------------------------
// 2️⃣  INCLINAÇÃO DE UMA RETA
// ------------------------------------------------------------
inline double slope(const Line2D& l) noexcept {
    // m = -a / b  (b != 0)
    return -l.a / l.b;
}

std::vector<std::string> slope_steps(const Line2D& l) {
    std::vector<std::string> steps;

    steps.emplace_back(
        "Calculando inclinação da reta: " + std::to_string(l.a) +
        "x + " + std::to_string(l.b) + "y + " +
        std::to_string(l.c) + " = 0");

    double m = slope(l);
    steps.emplace_back("m = -a / b = -" + std::to_string(l.a) +
                       " / " + std::to_string(l.b) +
                       " = " + std::to_string(m));

    return steps;
}

// ------------------------------------------------------------
// 3️⃣  DISTÂNCIA DE UM PONTO À RETA
// ------------------------------------------------------------
double distance_point_line(const Point2D& p, const Line2D& l) noexcept {
    // |ax0 + by0 + c| / sqrt(a² + b²)
    return std::abs(l.a * p.x + l.b * p.y + l.c) /
           std::sqrt(l.a * l.a + l.b * l.b);
}

std::vector<std::string> distance_point_line_steps(const Point2D& p,
                                                   const Line2D& l) {
    std::vector<std::string> steps;

    steps.emplace_back(
        "Calculando distância do ponto (" +
        std::to_string(p.x) + ", " + std::to_string(p.y) +
        ") à reta: " + std::to_string(l.a) + "x + " +
        std::to_string(l.b) + "y + " + std::to_string(l.c) +
        " = 0");

    double numerator =
        std::abs(l.a * p.x + l.b * p.y + l.c);
    steps.emplace_back(
        "|" + std::to_string(l.a) + "*" + std::to_string(p.x) +
        " + " + std::to_string(l.b) + "*" + std::to_string(p.y) +
        " + " + std::to_string(l.c) + "| = " + std::to_string(numerator));

    double denominator =
        std::sqrt(l.a * l.a + l.b * l.b);
    steps.emplace_back(
        "√(a² + b²) = √(" + std::to_string(l.a * l.a) +
        " + " + std::to_string(l.b * l.b) + ") = " +
        std::to_string(denominator));

    double dist = numerator / denominator;
    steps.emplace_back(
        "distância = |...| / √(...)= " + std::to_string(dist));

    return dist > 0 ? steps : std::vector<std::string>{};
}

} // namespace math::analytic
