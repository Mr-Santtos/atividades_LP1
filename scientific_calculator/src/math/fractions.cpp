#include "../../include/math/fractions.h"
#include <numeric>
#include <sstream>

namespace math {

void Fraction::simplify() {
    if (denominator == 0) return;           
    long long g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    if (denominator < 0) {                 
        numerator = -numerator;
        denominator = -denominator;
    }
}

double Fraction::to_double() const {
    return static_cast<double>(numerator) / denominator;
}



Fraction add(const Fraction& a, const Fraction& b) {
    Fraction r{a.numerator * b.denominator + b.numerator * a.denominator,
               a.denominator * b.denominator};
    r.simplify();
    return r;
}

Fraction subtract(const Fraction& a, const Fraction& b) {
    Fraction r{a.numerator * b.denominator - b.numerator * a.denominator,
               a.denominator * b.denominator};
    r.simplify();
    return r;
}

Fraction multiply(const Fraction& a, const Fraction& b) {
    Fraction r{a.numerator * b.numerator, a.denominator * b.denominator};
    r.simplify();
    return r;
}

Fraction divide(const Fraction& a, const Fraction& b) {
    Fraction r{a.numerator * b.denominator, a.denominator * b.numerator};
    r.simplify();
    return r;
}



std::vector<std::string> add_steps(const Fraction& a, const Fraction& b) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Compute common denominator");
    long long lcm = a.denominator * b.denominator / std::gcd(a.denominator, b.denominator);
    steps.push_back("Common denominator (lcm): " + std::to_string(lcm));

    steps.push_back("Step 2: Adjust numerators");
    long long adj_a_num = a.numerator * (lcm / a.denominator);
    long long adj_b_num = b.numerator * (lcm / b.denominator);
    steps.push_back(std::to_string(adj_a_num) + " + " + std::to_string(adj_b_num));

    steps.push_back("Step 3: Add numerators");
    long long sum = adj_a_num + adj_b_num;
    steps.push_back("Sum of numerators: " + std::to_string(sum));

    Fraction r{sum, lcm};
    r.simplify();
    steps.push_back("Simplified result: " + std::to_string(r.numerator) +
                    "/" + std::to_string(r.denominator));
    return steps;
}

std::vector<std::string> subtract_steps(const Fraction& a, const Fraction& b) {
    std::vector<std::string> steps = add_steps(a, {-b.numerator, b.denominator});
    steps[steps.size() - 1] =
        "Simplified result: " + std::to_string(steps.back().size());
    return steps;
}

std::vector<std::string> multiply_steps(const Fraction& a, const Fraction& b) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Multiply numerators");
    long long num = a.numerator * b.numerator;
    steps.push_back(std::to_string(a.numerator) + " × " + std::to_string(b.numerator)
                    + " = " + std::to_string(num));

    steps.push_back("Step 2: Multiply denominators");
    long long den = a.denominator * b.denominator;
    steps.push_back(std::to_string(a.denominator) + " × " + std::to_string(b.denominator)
                    + " = " + std::to_string(den));

    Fraction r{num, den};
    r.simplify();
    steps.push_back("Simplified result: " + std::to_string(r.numerator) +
                    "/" + std::to_string(r.denominator));
    return steps;
}

std::vector<std::string> divide_steps(const Fraction& a, const Fraction& b) {
    std::vector<std::string> steps;
    steps.push_back("Step 1: Invert divisor");
    steps.push_back(std::to_string(b.numerator) + " / " + std::to_string(b.denominator)
                    + " becomes " + std::to_string(b.denominator) + "/" +
                    std::to_string(b.numerator));

    steps.push_back("Step 2: Multiply numerators");
    long long num = a.numerator * b.denominator;
    steps.push_back(std::to_string(a.numerator) + " × " + std::to_string(b.denominator)
                    + " = " + std::to_string(num));

    steps.push_back("Step 3: Multiply denominators");
    long long den = a.denominator * b.numerator;
    steps.push_back(std::to_string(a.denominator) + " × " + std::to_string(b.numerator)
                    + " = " + std::to_string(den));

    Fraction r{num, den};
    r.simplify();
    steps.push_back("Simplified result: " + std::to_string(r.numerator) +
                    "/" + std::to_string(r.denominator));
    return steps;
}

} 
