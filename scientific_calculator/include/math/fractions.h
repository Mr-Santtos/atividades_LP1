#pragma once

#include <string>
#include <vector>

namespace math {

/**
 * @brief 
 */
struct Fraction {
    long long numerator{0};
    long long denominator{1};


    void simplify();


    double to_double() const;
};

/**
 * @brief 
 */
Fraction add(const Fraction& a, const Fraction& b);
Fraction subtract(const Fraction& a, const Fraction& b);
Fraction multiply(const Fraction& a, const Fraction& b);
Fraction divide(const Fraction& a, const Fraction& b);

/**
 * @brief 
 */
std::vector<std::string> add_steps(const Fraction& a, const Fraction& b);
std::vector<std::string> subtract_steps(const Fraction& a, const Fraction& b);
std::vector<std::string> multiply_steps(const Fraction& a, const Fraction& b);
std::vector<std::string> divide_steps(const Fraction& a, const Fraction& b);

}
