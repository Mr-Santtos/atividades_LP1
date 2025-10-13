/**
 * @file quadratic_example.cpp
 * @brief Exemplo de uso das funções de equação quadrática da calculadora científica
 */

#include "../include/math/quadratic_equation.h"
#include <iostream>

int main() {
    using namespace math;
    
    std::cout << "=== RESOLUÇÃO DE EQUAÇÕES QUADRÁTICAS ===" << std::endl;
    
    // Exemplo 1: Equação com duas raízes reais
    std::cout << "\n1. Equação: x² - 5x + 6 = 0" << std::endl;
    std::cout << "   Coeficientes: a=1, b=-5, c=6" << std::endl;
    Pair result1 = solve_quadratic(1.0, -5.0, 6.0);
    std::cout << "   Raízes: x₁ = " << result1.first << ", x₂ = " << result1.second << std::endl;
    
    // Exemplo 2: Equação com uma raiz real (discriminante = 0)
    std::cout << "\n2. Equação: x² - 4x + 4 = 0" << std::endl;
    std::cout << "   Coeficientes: a=1, b=-4, c=4" << std::endl;
    Pair result2 = solve_quadratic(1.0, -4.0, 4.0);
    std::cout << "   Raízes: x₁ = " << result2.first << ", x₂ = " << result2.second << std::endl;
    
    // Exemplo 3: Equação sem raízes reais (discriminante < 0)
    std::cout << "\n3. Equação: x² + 2x + 5 = 0" << std::endl;
    std::cout << "   Coeficientes: a=1, b=2, c=5" << std::endl;
    Pair result3 = solve_quadratic(1.0, 2.0, 5.0);
    std::cout << "   Raízes: x₁ = " << result3.first << ", x₂ = " << result3.second << std::endl;
    std::cout << "   (NaN indica que não há raízes reais)" << std::endl;
    
    // Exemplo 4: Equação com coeficiente a = 0 (caso inválido)
    std::cout << "\n4. Equação: 0x² + 3x + 2 = 0" << std::endl;
    std::cout << "   Coeficientes: a=0, b=3, c=2" << std::endl;
    Pair result4 = solve_quadratic(0.0, 3.0, 2.0);
    std::cout << "   Raízes: x₁ = " << result4.first << ", x₂ = " << result4.second << std::endl;
    std::cout << "   (NaN indica que a equação não é quadrática)" << std::endl;
    
    // Exemplo 5: Equação com coeficientes decimais
    std::cout << "\n5. Equação: 2.5x² - 7.3x + 1.8 = 0" << std::endl;
    std::cout << "   Coeficientes: a=2.5, b=-7.3, c=1.8" << std::endl;
    Pair result5 = solve_quadratic(2.5, -7.3, 1.8);
    std::cout << "   Raízes: x₁ = " << result5.first << ", x₂ = " << result5.second << std::endl;
    
    // Verificação das raízes (substituição na equação)
    std::cout << "\n=== VERIFICAÇÃO DAS RAÍZES ===" << std::endl;
    std::cout << "Para a equação x² - 5x + 6 = 0:" << std::endl;
    double x1 = result1.first;
    double x2 = result1.second;
    double check1 = x1 * x1 - 5 * x1 + 6;
    double check2 = x2 * x2 - 5 * x2 + 6;
    std::cout << "   Verificação x₁: " << x1 << "² - 5(" << x1 << ") + 6 = " << check1 << std::endl;
    std::cout << "   Verificação x₂: " << x2 << "² - 5(" << x2 << ") + 6 = " << check2 << std::endl;
    
    return 0;
}
