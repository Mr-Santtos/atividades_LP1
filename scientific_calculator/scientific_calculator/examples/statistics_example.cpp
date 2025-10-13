/**
 * @file statistics_example.cpp
 * @brief Exemplo de uso das funções estatísticas da calculadora científica
 */

#include "../include/math/statistics.h"
#include <iostream>

int main() {
    using namespace math::statistics;
    
    // Dados de exemplo
    double data[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.1};
    int size = 10;
    
    double x_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double y_data[] = {2.1, 4.2, 6.1, 8.3, 10.2, 12.1, 14.0, 16.2, 18.1, 20.0};
    
    std::cout << "=== ESTATÍSTICAS DESCRITIVAS ===" << std::endl;
    std::cout << "Dados: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Média: " << mean(data, size) << std::endl;
    std::cout << "Mediana: " << median(data, size) << std::endl;
    std::cout << "Moda: " << mode(data, size) << std::endl;
    std::cout << "Desvio Padrão (populacional): " << standard_deviation(data, size) << std::endl;
    std::cout << "Desvio Padrão (amostral): " << sample_standard_deviation(data, size) << std::endl;
    std::cout << "Variância (populacional): " << variance(data, size) << std::endl;
    std::cout << "Variância (amostral): " << sample_variance(data, size) << std::endl;
    std::cout << "Valor Mínimo: " << min_value(data, size) << std::endl;
    std::cout << "Valor Máximo: " << max_value(data, size) << std::endl;
    std::cout << "Amplitude: " << range(data, size) << std::endl;
    
    std::cout << "\n=== CORRELAÇÃO E REGRESSÃO ===" << std::endl;
    std::cout << "Dados X: ";
    for (int i = 0; i < size; i++) {
        std::cout << x_data[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Dados Y: ";
    for (int i = 0; i < size; i++) {
        std::cout << y_data[i] << " ";
    }
    std::cout << std::endl;
    
    double correlation_coeff = correlation(x_data, y_data, size);
    std::cout << "Coeficiente de Correlação: " << correlation_coeff << std::endl;
    
    double slope, intercept;
    linear_regression(x_data, y_data, size, slope, intercept);
    std::cout << "Regressão Linear: y = " << slope << "x + " << intercept << std::endl;
    
    double r_squared = coefficient_of_determination(x_data, y_data, size);
    std::cout << "Coeficiente de Determinação (R²): " << r_squared << std::endl;
    
    std::cout << "\n=== DISTRIBUIÇÕES ===" << std::endl;
    std::cout << "Distribuição Normal Padrão:" << std::endl;
    std::cout << "PDF(0): " << normal_pdf(0.0) << std::endl;
    std::cout << "PDF(1): " << normal_pdf(1.0) << std::endl;
    std::cout << "CDF(0): " << normal_cdf(0.0) << std::endl;
    std::cout << "CDF(1): " << normal_cdf(1.0) << std::endl;
    
    std::cout << "Distribuição Binomial (n=10, p=0.5):" << std::endl;
    std::cout << "PDF(k=5): " << binomial_pdf(10, 5, 0.5) << std::endl;
    std::cout << "CDF(k=5): " << binomial_cdf(10, 5, 0.5) << std::endl;
    
    std::cout << "\n=== TESTES ESTATÍSTICOS ===" << std::endl;
    double t_stat_one = t_test_one_sample(data, size, 5.0);
    std::cout << "Teste t (uma amostra, μ₀=5.0): " << t_stat_one << std::endl;
    
    double data2[] = {1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};
    double t_stat_two = t_test_two_samples(data, size, data2, size);
    std::cout << "Teste t (duas amostras): " << t_stat_two << std::endl;
    
    return 0;
}
