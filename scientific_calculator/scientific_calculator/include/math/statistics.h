#pragma once
/**
 * @file statistics.h
 * @brief Funções estatísticas para análise de dados.
 */

// Note: Standard library headers temporarily disabled due to compiler issues
// #include <vector>
// #include <string>

namespace math {
namespace statistics {

/* ------------------------- Estatísticas Descritivas ------------------------- */

/** Calcula a média aritmética de um conjunto de dados */
double mean(const double* data, int size);

/** Calcula a mediana de um conjunto de dados */
double median(const double* data, int size);

/** Calcula a moda de um conjunto de dados */
double mode(const double* data, int size);

/** Calcula o desvio padrão populacional */
double standard_deviation(const double* data, int size);

/** Calcula o desvio padrão amostral */
double sample_standard_deviation(const double* data, int size);

/** Calcula a variância populacional */
double variance(const double* data, int size);

/** Calcula a variância amostral */
double sample_variance(const double* data, int size);

/** Calcula o valor mínimo */
double min_value(const double* data, int size);

/** Calcula o valor máximo */
double max_value(const double* data, int size);

/** Calcula a amplitude (max - min) */
double range(const double* data, int size);

/* ------------------------- Correlação e Regressão ------------------------- */

/** Calcula o coeficiente de correlação de Pearson */
double correlation(const double* x, const double* y, int size);

/** Calcula a regressão linear simples (y = ax + b) */
void linear_regression(const double* x, const double* y, int size, double& slope, double& intercept);

/** Calcula o coeficiente de determinação (R²) */
double coefficient_of_determination(const double* x, const double* y, int size);

/* ------------------------- Distribuições ------------------------- */

/** Calcula a probabilidade da distribuição normal padrão */
double normal_pdf(double x);

/** Calcula a função de distribuição acumulada da normal padrão */
double normal_cdf(double x);

/** Calcula a probabilidade da distribuição binomial */
double binomial_pdf(int n, int k, double p);

/** Calcula a função de distribuição acumulada da binomial */
double binomial_cdf(int n, int k, double p);

/* ------------------------- Testes Estatísticos ------------------------- */

/** Teste t para uma amostra */
double t_test_one_sample(const double* data, int size, double hypothesized_mean);

/** Teste t para duas amostras independentes */
double t_test_two_samples(const double* data1, int size1, const double* data2, int size2);

/* ------------------------- Funções Step-by-Step ------------------------- */
// Note: Step-by-step functions temporarily disabled due to std library issues
// std::vector<std::string> mean_steps(const double* data, int size);
// std::vector<std::string> standard_deviation_steps(const double* data, int size);
// std::vector<std::string> correlation_steps(const double* x, const double* y, int size);
// std::vector<std::string> linear_regression_steps(const double* x, const double* y, int size);

} // namespace statistics
} // namespace math
