#include "../../include/math/statistics.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Manual implementations of math functions since standard library is not available
double sin(double x) {
    // Taylor series approximation for sin(x)
    double result = x;
    double term = x;
    for (int i = 1; i < 10; i++) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        result += term;
    }
    return result;
}

double cos(double x) {
    // Taylor series approximation for cos(x)
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i < 10; i++) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        result += term;
    }
    return result;
}

double exp(double x) {
    // Taylor series approximation for e^x
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i < 20; i++) {
        term *= x / i;
        result += term;
    }
    return result;
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

double log_approx(double x) {
    // Natural logarithm approximation
    if (x <= 0) return 0.0; // Invalid input
    if (x == 1) return 0.0;
    
    // Use series expansion for ln(1+x) where x = (x-1)
    double y = x - 1.0;
    double result = y;
    double term = y;
    for (int i = 2; i < 20; i++) {
        term *= -y;
        result += term / i;
    }
    return result;
}

double pow(double base, double exponent) {
    // Simple power function for integer exponents
    if (exponent == 0) return 1.0;
    if (exponent == 1) return base;
    if (exponent == 2) return base * base;
    if (exponent == 3) return base * base * base;
    // For non-integer exponents, use approximation
    return exp(exponent * log_approx(base));
}

double abs(double x) {
    return (x < 0) ? -x : x;
}

double erf_approx(double x) {
    // Approximation of error function
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;
    
    int sign = (x >= 0) ? 1 : -1;
    x = abs(x);
    
    double t = 1.0 / (1.0 + p * x);
    double y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * exp(-x * x);
    
    return sign * y;
}

namespace math {
namespace statistics {

/* ------------------------- Estatísticas Descritivas ------------------------- */

double mean(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

double median(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    // Create a copy and sort it
    double* sorted_data = new double[size];
    for (int i = 0; i < size; i++) {
        sorted_data[i] = data[i];
    }
    
    // Simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sorted_data[j] > sorted_data[j + 1]) {
                double temp = sorted_data[j];
                sorted_data[j] = sorted_data[j + 1];
                sorted_data[j + 1] = temp;
            }
        }
    }
    
    double result;
    if (size % 2 == 0) {
        // Even number of elements
        result = (sorted_data[size / 2 - 1] + sorted_data[size / 2]) / 2.0;
    } else {
        // Odd number of elements
        result = sorted_data[size / 2];
    }
    
    delete[] sorted_data;
    return result;
}

double mode(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    // Simple mode calculation - returns the most frequent value
    double mode_value = data[0];
    int max_count = 1;
    
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode_value = data[i];
        }
    }
    
    return mode_value;
}

double variance(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    double mean_value = mean(data, size);
    double sum_squared_diff = 0.0;
    
    for (int i = 0; i < size; i++) {
        double diff = data[i] - mean_value;
        sum_squared_diff += diff * diff;
    }
    
    return sum_squared_diff / size;
}

double sample_variance(const double* data, int size) {
    if (size <= 1) return 0.0;
    
    double mean_value = mean(data, size);
    double sum_squared_diff = 0.0;
    
    for (int i = 0; i < size; i++) {
        double diff = data[i] - mean_value;
        sum_squared_diff += diff * diff;
    }
    
    return sum_squared_diff / (size - 1);
}

double standard_deviation(const double* data, int size) {
    return sqrt(variance(data, size));
}

double sample_standard_deviation(const double* data, int size) {
    return sqrt(sample_variance(data, size));
}

double min_value(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    double min_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    return min_val;
}

double max_value(const double* data, int size) {
    if (size <= 0) return 0.0;
    
    double max_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

double range(const double* data, int size) {
    return max_value(data, size) - min_value(data, size);
}

/* ------------------------- Correlação e Regressão ------------------------- */

double correlation(const double* x, const double* y, int size) {
    if (size <= 1) return 0.0;
    
    double mean_x = mean(x, size);
    double mean_y = mean(y, size);
    
    double numerator = 0.0;
    double sum_x_squared = 0.0;
    double sum_y_squared = 0.0;
    
    for (int i = 0; i < size; i++) {
        double diff_x = x[i] - mean_x;
        double diff_y = y[i] - mean_y;
        
        numerator += diff_x * diff_y;
        sum_x_squared += diff_x * diff_x;
        sum_y_squared += diff_y * diff_y;
    }
    
    double denominator = sqrt(sum_x_squared * sum_y_squared);
    if (denominator == 0.0) return 0.0;
    
    return numerator / denominator;
}

void linear_regression(const double* x, const double* y, int size, double& slope, double& intercept) {
    if (size <= 1) {
        slope = 0.0;
        intercept = 0.0;
        return;
    }
    
    double mean_x = mean(x, size);
    double mean_y = mean(y, size);
    
    double numerator = 0.0;
    double denominator = 0.0;
    
    for (int i = 0; i < size; i++) {
        double diff_x = x[i] - mean_x;
        numerator += diff_x * (y[i] - mean_y);
        denominator += diff_x * diff_x;
    }
    
    if (denominator == 0.0) {
        slope = 0.0;
        intercept = mean_y;
    } else {
        slope = numerator / denominator;
        intercept = mean_y - slope * mean_x;
    }
}

double coefficient_of_determination(const double* x, const double* y, int size) {
    double corr = correlation(x, y, size);
    return corr * corr;
}

/* ------------------------- Distribuições ------------------------- */

double normal_pdf(double x) {
    // Probability density function of standard normal distribution
    return (1.0 / sqrt(2.0 * M_PI)) * exp(-0.5 * x * x);
}

double normal_cdf(double x) {
    // Cumulative distribution function of standard normal distribution
    // Using approximation
    return 0.5 * (1.0 + erf_approx(x / sqrt(2.0)));
}

double binomial_pdf(int n, int k, double p) {
    if (k < 0 || k > n || p < 0 || p > 1) return 0.0;
    
    // Calculate binomial coefficient C(n,k)
    double coeff = 1.0;
    for (int i = 0; i < k; i++) {
        coeff *= (double)(n - i) / (i + 1);
    }
    
    return coeff * pow(p, k) * pow(1.0 - p, n - k);
}

double binomial_cdf(int n, int k, double p) {
    if (k < 0) return 0.0;
    if (k >= n) return 1.0;
    
    double result = 0.0;
    for (int i = 0; i <= k; i++) {
        result += binomial_pdf(n, i, p);
    }
    return result;
}

/* ------------------------- Testes Estatísticos ------------------------- */

double t_test_one_sample(const double* data, int size, double hypothesized_mean) {
    if (size <= 1) return 0.0;
    
    double sample_mean = mean(data, size);
    double sample_std = sample_standard_deviation(data, size);
    
    if (sample_std == 0.0) return 0.0;
    
    return (sample_mean - hypothesized_mean) / (sample_std / sqrt(size));
}

double t_test_two_samples(const double* data1, int size1, const double* data2, int size2) {
    if (size1 <= 1 || size2 <= 1) return 0.0;
    
    double mean1 = mean(data1, size1);
    double mean2 = mean(data2, size2);
    double var1 = sample_variance(data1, size1);
    double var2 = sample_variance(data2, size2);
    
    double pooled_std = sqrt(((size1 - 1) * var1 + (size2 - 1) * var2) / (size1 + size2 - 2));
    if (pooled_std == 0.0) return 0.0;
    
    return (mean1 - mean2) / (pooled_std * sqrt(1.0 / size1 + 1.0 / size2));
}

} // namespace statistics
} // namespace math
