#pragma once

#include <cmath>
#include <string>
#include <vector>

namespace math::analytic {

/// -------------  POINT ----------------------------------------------------
struct Point2D {
    double x;
    double y;
};

/// Distance between two points (Euclidean)
inline double distance(const Point2D& a, const Point2D& b) noexcept
{
    return std::hypot(a.x - b.x, a.y - b.y);
}

/// Steps version
inline std::vector<std::string> distance_steps(const Point2D& a,
                                               const Point2D& b)
{
    std::vector<std::string> steps;
    steps.emplace_back("Calculando distância entre (" + std::to_string(a.x) +
                       ", " + std::to_string(a.y) +
                       ") e (" + std::to_string(b.x) + ", " +
                       std::to_string(b.y) + ").");
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    steps.emplace_back("Δx = |" + std::to_string(a.x) + " − " +
                       std::to_string(b.x) + "| = " + std::to_string(dx));
    steps.emplace_back("Δy = |" + std::to_string(a.y) + " − " +
                       std::to_string(b.y) + "| = " + std::to_string(dy));
    double dist = std::hypot(dx, dy);
    steps.emplace_back("distância = √(Δx² + Δy²) = √("
                       + std::to_string(dx*dx) + " + "
                       + std::to_string(dy*dy) +
                       ") = " + std::to_string(dist));
    return steps;
}

/// -------------  LINE ----------------------------------------------------
struct Line2D {
    // ax + by + c = 0
    double a, b, c;
};

/// Slope (m) of the line: m = -a/b   (b != 0)
inline double slope(const Line2D& l) noexcept
{
    return -l.a / l.b;
}

/// Steps version
inline std::vector<std::string> slope_steps(const Line2D& l)
{
    std::vector<std::string> steps;
    steps.emplace_back("Calculando inclinação da reta: " +
                       std::to_string(l.a) + "x + " +
                       std::to_string(l.b) + "y + " +
                       std::to_string(l.c) + " = 0");
    steps.emplace_back("m = -a / b = -" + std::to_string(l.a) +
                       " / " + std::to_string(l.b) + " = " +
                       std::to_string(slope(l)));
    return steps;
}

/// Distance from point P to line L
inline double distance_point_line(const Point2D& p, const Line2D& l) noexcept
{
    // |ax0 + by0 + c| / sqrt(a² + b²)
    return std::abs(l.a * p.x + l.b * p.y + l.c) /
           std::sqrt(l.a*l.a + l.b*l.b);
}

/// Steps version
inline std::vector<std::string> distance_point_line_steps(const Point2D& p,
                                                          const Line2D& l)
{
    std::vector<std::string> steps;
    steps.emplace_back("Calculando distância do ponto (" +
                       std::to_string(p.x) + ", " +
                       std::to_string(p.y) + ") à reta: " +
                       std::to_string(l.a) + "x + " +
                       std::to_string(l.b) + "y + " +
                       std::to_string(l.c) + " = 0");
    double numerator =
        std::abs(l.a * p.x + l.b * p.y + l.c);
    steps.emplace_back("|" + std::to_string(l.a) + "*" +
                       std::to_string(p.x) + " + " +
                       std::to_string(l.b) + "*" +
                       std::to_string(p.y) + " + " +
                       std::to_string(l.c) + "| = " +
                       std::to_string(numerator));
    double denominator =
        std::sqrt(l.a*l.a + l.b*l.b);
    steps.emplace_back("√(a² + b²) = √(" +
                       std::to_string(l.a*l.a) + " + " +
                       std::to_string(l.b*l.b) + ") = " +
                       std::to_string(denominator));
    double dist = numerator / denominator;
    steps.emplace_back("distância = |...| / √(...)= " +
                       std::to_string(dist));
    return dist > 0 ? steps : std::vector<std::string>{};
}

} // namespace math::analytic
