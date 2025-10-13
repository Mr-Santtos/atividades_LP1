#ifndef MATH_STATISTICS_H
#define MATH_STATISTICS_H

#include <vector>

namespace math {
double mean(const std::vector<double>& v);
double variance(const std::vector<double>& v);
double stddev(const std::vector<double>& v);
} // namespace math

#endif // MATH_STATISTICS_H
