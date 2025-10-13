/**
 * @file powers_example.cpp
 * @brief Exemplo de uso das funções de potências e raízes da calculadora científica
 */

#include "../include/math/powers.h"
#include <iostream>

int main() {
    using namespace math;
    
    std::cout << "=== POTÊNCIAS E RAÍZES ===" << std::endl;
    
    // Exemplo 1: Potências básicas
    std::cout << "\n1. POTÊNCIAS BÁSICAS" << std::endl;
    
    double base1 = 2.0;
    double exp1 = 3.0;
    double result1 = power(base1, exp1);
    std::cout << "   " << base1 << "^" << exp1 << " = " << result1 << std::endl;
    
    double base2 = 5.0;
    double exp2 = 2.0;
    double result2 = power(base2, exp2);
    std::cout << "   " << base2 << "^" << exp2 << " = " << result2 << std::endl;
    
    double base3 = 3.0;
    double exp3 = 4.0;
    double result3 = power(base3, exp3);
    std::cout << "   " << base3 << "^" << exp3 << " = " << result3 << std::endl;
    
    // Exemplo 2: Potências com expoentes decimais
    std::cout << "\n2. POTÊNCIAS COM EXPOENTES DECIMAIS" << std::endl;
    
    double base4 = 4.0;
    double exp4 = 0.5;
    double result4 = power(base4, exp4);
    std::cout << "   " << base4 << "^" << exp4 << " = " << result4 << std::endl;
    std::cout << "   (Isso é equivalente à raiz quadrada de " << base4 << ")" << std::endl;
    
    double base5 = 8.0;
    double exp5 = 1.0/3.0;
    double result5 = power(base5, exp5);
    std::cout << "   " << base5 << "^" << exp5 << " = " << result5 << std::endl;
    std::cout << "   (Isso é equivalente à raiz cúbica de " << base5 << ")" << std::endl;
    
    // Exemplo 3: Raízes usando a função root
    std::cout << "\n3. RAÍZES USANDO A FUNÇÃO ROOT" << std::endl;
    
    double value1 = 16.0;
    double degree1 = 2.0;
    double root1 = root(value1, degree1);
    std::cout << "   Raiz quadrada de " << value1 << " = " << root1 << std::endl;
    
    double value2 = 27.0;
    double degree2 = 3.0;
    double root2 = root(value2, degree2);
    std::cout << "   Raiz cúbica de " << value2 << " = " << root2 << std::endl;
    
    double value3 = 32.0;
    double degree3 = 5.0;
    double root3 = root(value3, degree3);
    std::cout << "   Raiz quinta de " << value3 << " = " << root3 << std::endl;
    
    // Exemplo 4: Casos especiais
    std::cout << "\n4. CASOS ESPECIAIS" << std::endl;
    
    // Potência com expoente zero
    double base6 = 7.0;
    double exp6 = 0.0;
    double result6 = power(base6, exp6);
    std::cout << "   " << base6 << "^" << exp6 << " = " << result6 << std::endl;
    
    // Potência com expoente um
    double base7 = 9.0;
    double exp7 = 1.0;
    double result7 = power(base7, exp7);
    std::cout << "   " << base7 << "^" << exp7 << " = " << result7 << std::endl;
    
    // Raiz com grau zero (caso inválido)
    double value4 = 10.0;
    double degree4 = 0.0;
    double root4 = root(value4, degree4);
    std::cout << "   Raiz de grau " << degree4 << " de " << value4 << " = " << root4 << std::endl;
    std::cout << "   (NaN indica que o grau não pode ser zero)" << std::endl;
    
    // Exemplo 5: Verificação das fórmulas
    std::cout << "\n5. VERIFICAÇÃO DAS FÓRMULAS" << std::endl;
    
    // Verificar que a^(1/n) = raiz n-ésima de a
    double test_base = 64.0;
    double test_degree = 3.0;
    double power_result = power(test_base, 1.0/test_degree);
    double root_result = root(test_base, test_degree);
    std::cout << "   " << test_base << "^(1/" << test_degree << ") = " << power_result << std::endl;
    std::cout << "   Raiz " << test_degree << "-ésima de " << test_base << " = " << root_result << std::endl;
    std::cout << "   (Os resultados devem ser iguais)" << std::endl;
    
    // Exemplo 6: Potências de números negativos
    std::cout << "\n6. POTÊNCIAS DE NÚMEROS NEGATIVOS" << std::endl;
    
    double neg_base = -2.0;
    double pos_exp = 3.0;
    double neg_result = power(neg_base, pos_exp);
    std::cout << "   (" << neg_base << ")^" << pos_exp << " = " << neg_result << std::endl;
    
    double pos_base = 2.0;
    double neg_exp = -2.0;
    double neg_exp_result = power(pos_base, neg_exp);
    std::cout << "   " << pos_base << "^(" << neg_exp << ") = " << neg_exp_result << std::endl;
    std::cout << "   (Isso é equivalente a 1/" << pos_base << "^" << (-neg_exp) << ")" << std::endl;
    
    return 0;
}
