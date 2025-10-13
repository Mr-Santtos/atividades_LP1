#ifndef MATH_FRACTIONS_H
#define MATH_FRACTIONS_H

#include <cstdint>

namespace math {

struct Fraction {
    int64_t num;
    int64_t den;
    Fraction(int64_t n = 0, int64_t d = 1);
    // Basic operations
    Fraction add(const Fraction& other) const;
    Fraction sub(const Fraction& other) const;
    Fraction mul(const Fraction& other) const;
    Fraction div(const Fraction& other) const;
};

} // namespace math

#endif // MATH_FRACTIONS_H
