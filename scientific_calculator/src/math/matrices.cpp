/**
 * @file   matrices.cpp
 * @brief  Implementação das funções declaradas em matrices.h.
 *
 * Cada função pura devolve o resultado computado e cada versão “steps”
 * descreve, passo a passo, como esse resultado foi obtido.  
 */

#include "matrices.h"

#include <cmath>
#include <sstream>
#include <iomanip>

namespace math {
namespace matrices {

/* --------------------------------------------------------------------- */
/*  Det. 2×2 ------------------------------------------------------------ */
double det_2x2(const Matrix2x2& m) {
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

std::vector<std::string> det_2x2_steps(const Matrix2x2& m) {
    std::vector<std::string> steps;
    steps.emplace_back("Determinante de uma matriz 2x2:");
    steps.emplace_back("[ a b ]");
    steps.emplace_back("[ c d ]");
    steps.emplace_back("\ta = " + std::to_string(m[0][0]));
    steps.emplace_back("\tb = " + std::to_string(m[0][1]));
    steps.emplace_back("\tc = " + std::to_string(m[1][0]));
    steps.emplace_back("\td = " + std::to_string(m[1][1]));

    double ad = m[0][0]*m[1][1];
    double bc = m[0][1]*m[1][0];

    steps.emplace_back("ad = a·d = " + std::to_string(ad));
    steps.emplace_back("bc = b·c = " + std::to_string(bc));

    double det = ad - bc;
    steps.emplace_back("det(A) = ad – bc = " + std::to_string(det));

    return steps;
}

/* --------------------------------------------------------------------- */
/*  Det. 3×3 ------------------------------------------------------------ */
double det_3x3(const Matrix3x3& m) {
    return m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1])
         - m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0])
         + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
}

std::vector<std::string> det_3x3_steps(const Matrix3x3& m) {
    std::vector<std::string> steps;
    steps.emplace_back("Determinante de uma matriz 3x3:");
    steps.emplace_back("[ a b c ]");
    steps.emplace_back("[ d e f ]");
    steps.emplace_back("[ g h i ]");

    steps.emplace_back("\ta = " + std::to_string(m[0][0]));
    steps.emplace_back("\tb = " + std::to_string(m[0][1]));
    steps.emplace_back("\tc = " + std::to_string(m[0][2]));
    steps.emplace_back("\td = " + std::to_string(m[1][0]));
    steps.emplace_back("\te = " + std::to_string(m[1][1]));
    steps.emplace_back("\tf = " + std::to_string(m[1][2]));
    steps.emplace_back("\tg = " + std::to_string(m[2][0]));
    steps.emplace_back("\th = " + std::to_string(m[2][1]));
    steps.emplace_back("\ti = " + std::to_string(m[2][2]));

    double aei = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    double bdi = m[0][1]*(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    double cdh = m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);

    steps.emplace_back("aei = a·(e·i – f·h) = " + std::to_string(aei));
    steps.emplace_back("bdi = b·(d·i – f·g) = " + std::to_string(bdi));
    steps.emplace_back("cdh = c·(d·h – e·g) = " + std::to_string(cdh));

    double det = aei - bdi + cdh;
    steps.emplace_back("det(A) = aei – bdi + cdh = " + std::to_string(det));

    return steps;
}

/* --------------------------------------------------------------------- */
/*  Inverso 2×2 --------------------------------------------------------- */
bool inverse_2x2(const Matrix2x2& m, Matrix2x2& inv) {
    double d = det_2x2(m);
    if (std::abs(d) < 1e-12) return false;

    inv[0][0] =  m[1][1]/d;
    inv[0][1] = -m[0][1]/d;
    inv[1][0] = -m[1][0]/d;
    inv[1][1] =  m[0][0]/d;
    return true;
}

std::vector<std::string> inverse_2x2_steps(const Matrix2x2& m) {
    std::vector<std::string> steps;
    steps.emplace_back("Cálculo da inversa de uma matriz 2x2:");

    double d = det_2x2(m);
    if (std::abs(d) < 1e-12) {
        steps.emplace_back("Matriz singular, inversa não existe.");
        return steps;
    }

    steps.emplace_back("det(A) = " + std::to_string(d));

    double a11 =  m[1][1]/d;
    double a12 = -m[0][1]/d;
    double a21 = -m[1][0]/d;
    double a22 =  m[0][0]/d;

    steps.emplace_back("a'11 = " + std::to_string(a11));
    steps.emplace_back("a'12 = " + std::to_string(a12));
    steps.emplace_back("a'21 = " + std::to_string(a21));
    steps.emplace_back("a'22 = " + std::to_string(a22));

    steps.emplace_back("Inversa:\n" +
        matrix_to_string(Matrix2x2{{{a11,a12},{a21,a22}}}));

    return steps;
}

/* --------------------------------------------------------------------- */
/*  Inverso 3×3 --------------------------------------------------------- */
bool inverse_3x3(const Matrix3x3& m, Matrix3x3& inv) {
    double d = det_3x3(m);
    if (std::abs(d) < 1e-12) return false;

    double c00 =  (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    double c01 = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    double c02 =  (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    double c10 = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
    double c11 =  (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
    double c12 = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);
    double c20 =  (m[0][1]*m[1][2] - m[0][2]*m[1][1]);
    double c21 = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);
    double c22 =  (m[0][0]*m[1][1] - m[0][1]*m[1][0]);

    inv[0][0] = c00/d; inv[0][1] = c10/d; inv[0][2] = c20/d;
    inv[1][0] = c01/d; inv[1][1] = c11/d; inv[1][2] = c21/d;
    inv[2][0] = c02/d; inv[2][1] = c12/d; inv[2][2] = c22/d;

    return true;
}

std::vector<std::string> inverse_3x3_steps(const Matrix3x3& m) {
    std::vector<std::string> steps;
    steps.emplace_back("Cálculo da inversa de uma matriz 3x3:");

    double d = det_3x3(m);
    if (std::abs(d) < 1e-12) {
        steps.emplace_back("Matriz singular, inversa não existe.");
        return steps;
    }
    steps.emplace_back("det(A) = " + std::to_string(d));

    double c00 =  (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    double c01 = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    double c02 =  (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    double c10 = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
    double c11 =  (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
    double c12 = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);
    double c20 =  (m[0][1]*m[1][2] - m[0][2]*m[1][1]);
    double c21 = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);
    double c22 =  (m[0][0]*m[1][1] - m[0][1]*m[1][0]);

    steps.emplace_back("Cofatores:");
    steps.emplace_back("c00 = " + std::to_string(c00));
    steps.emplace_back("c01 = " + std::to_string(c01));
    steps.emplace_back("c02 = " + std::to_string(c02));
    steps.emplace_back("c10 = " + std::to_string(c10));
    steps.emplace_back("c11 = " + std::to_string(c11));
    steps.emplace_back("c12 = " + std::to_string(c12));
    steps.emplace_back("c20 = " + std::to_string(c20));
    steps.emplace_back("c21 = " + std::to_string(c21));
    steps.emplace_back("c22 = " + std::to_string(c22));

    Matrix3x3 inv_matrix;
    inv_matrix[0][0] = c00/d; inv_matrix[0][1] = c10/d; inv_matrix[0][2] = c20/d;
    inv_matrix[1][0] = c01/d; inv_matrix[1][1] = c11/d; inv_matrix[1][2] = c21/d;
    inv_matrix[2][0] = c02/d; inv_matrix[2][1] = c12/d; inv_matrix[2][2] = c22/d;

    steps.emplace_back("Inversa = transposta dos cofatores / det(A):");
    steps.push_back(matrix_to_string(inv_matrix));

    return steps;
}

} // namespace matrices
} // namespace math
