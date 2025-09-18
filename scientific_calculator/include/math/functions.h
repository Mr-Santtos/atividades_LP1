#pragma once

#include <vector>

namespace math {

/* ---------- Funções Afim ---------- */
double affine(double a, double b, double x);
std::vector<std::string> affine_steps(double a, double b, double x);

/* ---------- Quadrática ---------- */
double quadratic(double a, double b, double c, double x);
std::vector<std::string> quadratic_steps(double a, double b, double c, double x);

/* ---------- Exponencial (base e) ---------- */
double exponential(double x);
std::vector<std::string> exponential_steps(double x);

/* ---------- Logarítmica natural ---------- */
double ln(double x);
std::vector<std::string> ln_steps(double x);

/* ---------- Logarítmica base 10 ---------- */
double log10_(double x);
std::vector<std::string> log10_steps(double x);

} // namespace math
