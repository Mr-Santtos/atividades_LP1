#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/fractions.h"

using namespace math;

TEST_CASE("Fractions addition") {
    Fraction a{1,2}, b{1,3};
    Fraction r = add(a,b);
    REQUIRE(r.numerator == 5);
    REQUIRE(r.denominator == 6);

    auto steps = add_steps(a,b);
    REQUIRE(steps.size() >= 4); // at least the four expected steps
}

TEST_CASE("Fractions multiplication") {
    Fraction a{2,3}, b{3,4};
    Fraction r = multiply(a,b);
    REQUIRE(r.numerator == 1);
    REQUIRE(r.denominator == 2);

    auto steps = multiply_steps(a,b);
    REQUIRE(steps.size() >= 4);
}

/* ... mais 3 testes por função (subtrair, dividir, simplificar) ... */
