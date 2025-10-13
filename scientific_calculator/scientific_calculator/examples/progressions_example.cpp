/**
 * @file progressions_example.cpp
 * @brief Exemplo de uso das funções de progressões da calculadora científica
 */

#include "../include/math/progressions.h"
#include <iostream>

int main() {
    using namespace math::progressions;
    
    std::cout << "=== PROGRESSÕES ARITMÉTICAS E GEOMÉTRICAS ===" << std::endl;
    
    // Exemplo 1: Progressão Aritmética
    std::cout << "\n1. PROGRESSÃO ARITMÉTICA (PA)" << std::endl;
    std::cout << "   Primeiro termo (a₁) = 2" << std::endl;
    std::cout << "   Diferença comum (d) = 3" << std::endl;
    
    double a1_pa = 2.0;
    double d = 3.0;
    
    // Calcular alguns termos da PA
    for (int n = 1; n <= 5; n++) {
        double term = arithmetic_nth(a1_pa, d, n);
        std::cout << "   a" << n << " = " << term << std::endl;
    }
    
    // Calcular soma dos primeiros 5 termos
    double sum_pa = arithmetic_sum(a1_pa, d, 5);
    std::cout << "   Soma dos primeiros 5 termos: S₅ = " << sum_pa << std::endl;
    
    // Exemplo 2: Progressão Geométrica
    std::cout << "\n2. PROGRESSÃO GEOMÉTRICA (PG)" << std::endl;
    std::cout << "   Primeiro termo (a₁) = 2" << std::endl;
    std::cout << "   Razão comum (r) = 3" << std::endl;
    
    double a1_pg = 2.0;
    double r = 3.0;
    
    // Calcular alguns termos da PG
    for (int n = 1; n <= 5; n++) {
        double term = geometric_nth(a1_pg, r, n);
        std::cout << "   a" << n << " = " << term << std::endl;
    }
    
    // Calcular soma dos primeiros 5 termos
    double sum_pg = geometric_sum(a1_pg, r, 5);
    std::cout << "   Soma dos primeiros 5 termos: S₅ = " << sum_pg << std::endl;
    
    // Exemplo 3: PG com razão = 1
    std::cout << "\n3. PROGRESSÃO GEOMÉTRICA COM RAZÃO = 1" << std::endl;
    std::cout << "   Primeiro termo (a₁) = 5" << std::endl;
    std::cout << "   Razão comum (r) = 1" << std::endl;
    
    double a1_pg1 = 5.0;
    double r1 = 1.0;
    
    // Calcular alguns termos da PG
    for (int n = 1; n <= 4; n++) {
        double term = geometric_nth(a1_pg1, r1, n);
        std::cout << "   a" << n << " = " << term << std::endl;
    }
    
    // Calcular soma dos primeiros 4 termos
    double sum_pg1 = geometric_sum(a1_pg1, r1, 4);
    std::cout << "   Soma dos primeiros 4 termos: S₄ = " << sum_pg1 << std::endl;
    
    // Exemplo 4: PG com razão fracionária
    std::cout << "\n4. PROGRESSÃO GEOMÉTRICA COM RAZÃO FRACIONÁRIA" << std::endl;
    std::cout << "   Primeiro termo (a₁) = 16" << std::endl;
    std::cout << "   Razão comum (r) = 0.5" << std::endl;
    
    double a1_pg2 = 16.0;
    double r2 = 0.5;
    
    // Calcular alguns termos da PG
    for (int n = 1; n <= 6; n++) {
        double term = geometric_nth(a1_pg2, r2, n);
        std::cout << "   a" << n << " = " << term << std::endl;
    }
    
    // Calcular soma dos primeiros 6 termos
    double sum_pg2 = geometric_sum(a1_pg2, r2, 6);
    std::cout << "   Soma dos primeiros 6 termos: S₆ = " << sum_pg2 << std::endl;
    
    // Exemplo 5: Verificação das fórmulas
    std::cout << "\n5. VERIFICAÇÃO DAS FÓRMULAS" << std::endl;
    
    // PA: aₙ = a₁ + (n-1)d
    std::cout << "   PA: aₙ = a₁ + (n-1)d" << std::endl;
    std::cout << "   Para n=4: a₄ = " << a1_pa << " + (4-1)×" << d 
              << " = " << a1_pa << " + 3×" << d << " = " 
              << arithmetic_nth(a1_pa, d, 4) << std::endl;
    
    // PG: aₙ = a₁ × r^(n-1)
    std::cout << "   PG: aₙ = a₁ × r^(n-1)" << std::endl;
    std::cout << "   Para n=4: a₄ = " << a1_pg << " × " << r 
              << "^(4-1) = " << a1_pg << " × " << r << "³ = " 
              << arithmetic_nth(a1_pg, r, 4) << std::endl;
    
    return 0;
}
