/**
 * @file matrices_example.cpp
 * @brief Exemplo de uso das funções de matrizes da calculadora científica
 */

#include "../include/math/matrices.h"
#include <iostream>

int main() {
    using namespace math::matrices;
    
    std::cout << "=== OPERAÇÕES COM MATRIZES ===" << std::endl;
    
    // Exemplo 1: Matriz 2x2 - Determinante
    std::cout << "\n1. DETERMINANTE DE MATRIZ 2x2" << std::endl;
    Matrix2x2 m2x2;
    m2x2[0][0] = 3; m2x2[0][1] = 1;
    m2x2[1][0] = 2; m2x2[1][1] = 4;
    
    std::cout << "   Matriz A:" << std::endl;
    std::cout << "   [" << m2x2[0][0] << "  " << m2x2[0][1] << "]" << std::endl;
    std::cout << "   [" << m2x2[1][0] << "  " << m2x2[1][1] << "]" << std::endl;
    
    double det2 = det_2x2(m2x2);
    std::cout << "   det(A) = " << det2 << std::endl;
    
    // Exemplo 2: Matriz 2x2 - Inversa
    std::cout << "\n2. INVERSA DE MATRIZ 2x2" << std::endl;
    Matrix2x2 inv2x2;
    bool has_inverse = inverse_2x2(m2x2, inv2x2);
    
    if (has_inverse) {
        std::cout << "   Matriz inversa A⁻¹:" << std::endl;
        std::cout << "   [" << inv2x2[0][0] << "  " << inv2x2[0][1] << "]" << std::endl;
        std::cout << "   [" << inv2x2[1][0] << "  " << inv2x2[1][1] << "]" << std::endl;
    } else {
        std::cout << "   Matriz singular - inversa não existe" << std::endl;
    }
    
    // Exemplo 3: Matriz 3x3 - Determinante
    std::cout << "\n3. DETERMINANTE DE MATRIZ 3x3" << std::endl;
    Matrix3x3 m3x3;
    m3x3[0][0] = 1; m3x3[0][1] = 2; m3x3[0][2] = 3;
    m3x3[1][0] = 4; m3x3[1][1] = 5; m3x3[1][2] = 6;
    m3x3[2][0] = 7; m3x3[2][1] = 8; m3x3[2][2] = 9;
    
    std::cout << "   Matriz B:" << std::endl;
    std::cout << "   [" << m3x3[0][0] << "  " << m3x3[0][1] << "  " << m3x3[0][2] << "]" << std::endl;
    std::cout << "   [" << m3x3[1][0] << "  " << m3x3[1][1] << "  " << m3x3[1][2] << "]" << std::endl;
    std::cout << "   [" << m3x3[2][0] << "  " << m3x3[2][1] << "  " << m3x3[2][2] << "]" << std::endl;
    
    double det3 = det_3x3(m3x3);
    std::cout << "   det(B) = " << det3 << std::endl;
    
    // Exemplo 4: Matriz 3x3 - Inversa
    std::cout << "\n4. INVERSA DE MATRIZ 3x3" << std::endl;
    Matrix3x3 inv3x3;
    bool has_inverse3 = inverse_3x3(m3x3, inv3x3);
    
    if (has_inverse3) {
        std::cout << "   Matriz inversa B⁻¹:" << std::endl;
        std::cout << "   [" << inv3x3[0][0] << "  " << inv3x3[0][1] << "  " << inv3x3[0][2] << "]" << std::endl;
        std::cout << "   [" << inv3x3[1][0] << "  " << inv3x3[1][1] << "  " << inv3x3[1][2] << "]" << std::endl;
        std::cout << "   [" << inv3x3[2][0] << "  " << inv3x3[2][1] << "  " << inv3x3[2][2] << "]" << std::endl;
    } else {
        std::cout << "   Matriz singular - inversa não existe" << std::endl;
    }
    
    // Exemplo 5: Matriz 3x3 não-singular
    std::cout << "\n5. MATRIZ 3x3 NÃO-SINGULAR" << std::endl;
    Matrix3x3 m3x3_ns;
    m3x3_ns[0][0] = 2; m3x3_ns[0][1] = 1; m3x3_ns[0][2] = 1;
    m3x3_ns[1][0] = 1; m3x3_ns[1][1] = 2; m3x3_ns[1][2] = 1;
    m3x3_ns[2][0] = 1; m3x3_ns[2][1] = 1; m3x3_ns[2][2] = 2;
    
    std::cout << "   Matriz C:" << std::endl;
    std::cout << "   [" << m3x3_ns[0][0] << "  " << m3x3_ns[0][1] << "  " << m3x3_ns[0][2] << "]" << std::endl;
    std::cout << "   [" << m3x3_ns[1][0] << "  " << m3x3_ns[1][1] << "  " << m3x3_ns[1][2] << "]" << std::endl;
    std::cout << "   [" << m3x3_ns[2][0] << "  " << m3x3_ns[2][1] << "  " << m3x3_ns[2][2] << "]" << std::endl;
    
    double det3_ns = det_3x3(m3x3_ns);
    std::cout << "   det(C) = " << det3_ns << std::endl;
    
    Matrix3x3 inv3x3_ns;
    bool has_inverse3_ns = inverse_3x3(m3x3_ns, inv3x3_ns);
    
    if (has_inverse3_ns) {
        std::cout << "   Matriz inversa C⁻¹:" << std::endl;
        std::cout << "   [" << inv3x3_ns[0][0] << "  " << inv3x3_ns[0][1] << "  " << inv3x3_ns[0][2] << "]" << std::endl;
        std::cout << "   [" << inv3x3_ns[1][0] << "  " << inv3x3_ns[1][1] << "  " << inv3x3_ns[1][2] << "]" << std::endl;
        std::cout << "   [" << inv3x3_ns[2][0] << "  " << inv3x3_ns[2][1] << "  " << inv3x3_ns[2][2] << "]" << std::endl;
    }
    
    // Exemplo 6: Verificação das fórmulas
    std::cout << "\n6. VERIFICAÇÃO DAS FÓRMULAS" << std::endl;
    
    // Para matriz 2x2: det = ad - bc
    double a = m2x2[0][0], b = m2x2[0][1];
    double c = m2x2[1][0], d = m2x2[1][1];
    double manual_det = a * d - b * c;
    std::cout << "   Matriz 2x2: det = ad - bc = " << a << "×" << d << " - " << b << "×" << c 
              << " = " << manual_det << " (calculado: " << det2 << ")" << std::endl;
    
    // Para matriz 3x3: regra de Sarrus
    double a1 = m3x3_ns[0][0], b1 = m3x3_ns[0][1], c1 = m3x3_ns[0][2];
    double a2 = m3x3_ns[1][0], b2 = m3x3_ns[1][1], c2 = m3x3_ns[1][2];
    double a3 = m3x3_ns[2][0], b3 = m3x3_ns[2][1], c3 = m3x3_ns[2][2];
    double manual_det3 = a1*(b2*c3 - c2*b3) - b1*(a2*c3 - c2*a3) + c1*(a2*b3 - b2*a3);
    std::cout << "   Matriz 3x3: det = a1(b2c3-c2b3) - b1(a2c3-c2a3) + c1(a2b3-b2a3) = " 
              << manual_det3 << " (calculado: " << det3_ns << ")" << std::endl;
    
    return 0;
}
