#pragma once

/**
 * @file matrices.h
 * @brief 2x2 and 3x3 matrix operations (determinant, addition, subtraction,
 *        multiplication, inversion).  
 *        Both pure functions and step‑by‑step helpers are provided.
 *
 * @author
 */

#include <array>
#include <string>
#include <vector>

namespace math {
namespace matrices {

/* ------------------------------------------------------------------------- */
/*                      2×2 matrix types & utilities                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Type alias for a 2×2 matrix stored in row‑major order.
 */
using Matrix2x2 = std::array<std::array<double, 2>, 2>;

/** Helper to print a 2×2 matrix as a string. */
inline std::string matrix_to_string(const Matrix2x2 &m);

/* ------------------------------------------------------------------------- */
/*                        Determinant (pure)                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Determinant of a 2×2 matrix.
 *
 * @param m The matrix.
 * @return determinant = ad - bc
 */
double det_2x2(const Matrix2x2 &m);

/* ------------------------------------------------------------------------- */
/*                        Determinant (step‑by‑step)                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Step‑by‑step calculation of the determinant of a 2×2 matrix.
 *
 * @param m The matrix.
 * @return Vector of strings, each describing one step of the computation.
 */
std::vector<std::string> det_2x2_steps(const Matrix2x2 &m);

/* ------------------------------------------------------------------------- */
/*                        Inverse (pure)                                     */
/* ------------------------------------------------------------------------- */

/**
 * @brief Inverse of a 2×2 matrix. Returns true if inverse exists and writes
 *        the result into `inv`.
 *
 * @param m   Input matrix.
 * @param inv Output matrix (only valid if function returns true).
 * @return true iff det(m) ≠ 0.
 */
bool inverse_2x2(const Matrix2x2 &m, Matrix2x2 &inv);

/* ------------------------------------------------------------------------- */
/*                        Inverse (step‑by‑step)                             */
/* ------------------------------------------------------------------------- */

/**
 * @brief Step‑by‑step calculation of the inverse of a 2×2 matrix.
 *
 * @param m Input matrix.
 * @return Vector of strings describing each step. If the matrix is singular
 *         the vector will contain only an error message.
 */
std::vector<std::string> inverse_2x2_steps(const Matrix2x2 &m);

/* ------------------------------------------------------------------------- */
/*                      3×3 matrix types & utilities                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Type alias for a 3×3 matrix stored in row‑major order.
 */
using Matrix3x3 = std::array<std::array<double, 3>, 3>;

/** Helper to print a 3×3 matrix as a string. */
inline std::string matrix_to_string(const Matrix3x3 &m);

/* ------------------------------------------------------------------------- */
/*                        Determinant (pure)                                 */
/* ------------------------------------------------------------------------- */

/**
 * @brief Determinant of a 3×3 matrix using the rule of Sarrus.
 *
 * @param m The matrix.
 * @return determinant
 */
double det_3x3(const Matrix3x3 &m);

/* ------------------------------------------------------------------------- */
/*                        Determinant (step‑by‑step)                         */
/* ------------------------------------------------------------------------- */

/**
 * @brief Step‑by‑step calculation of the determinant of a 3×3 matrix.
 *
 * @param m The matrix.
 * @return Vector of strings describing each step.
 */
std::vector<std::string> det_3x3_steps(const Matrix3x3 &m);

/* ------------------------------------------------------------------------- */
/*                        Inverse (pure)                                     */
/* ------------------------------------------------------------------------- */

/**
 * @brief Inverse of a 3×3 matrix. Returns true if inverse exists and writes
 *        the result into `inv`.
 *
 * @param m   Input matrix.
 * @param inv Output matrix (only valid if function returns true).
 * @return true iff det(m) ≠ 0.
 */
bool inverse_3x3(const Matrix3x3 &m, Matrix3x3 &inv);

/* ------------------------------------------------------------------------- */
/*                        Inverse (step‑by‑step)                             */
/* ------------------------------------------------------------------------- */

/**
 * @brief Step‑by‑step calculation of the inverse of a 3×3 matrix.
 *
 * @param m Input matrix.
 * @return Vector of strings describing each step. If the matrix is singular
 *         the vector will contain only an error message.
 */
std::vector<std::string> inverse_3x3_steps(const Matrix3x3 &m);

/* ------------------------------------------------------------------------- */
/*                        Multiplication (pure)                              */
/* ------------------------------------------------------------------------- */

/**
 * @brief Product of two 2×2 matrices: C = A · B
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return Resulting matrix.
 */
Matrix2x2 multiply_2x2(const Matrix2x2 &a, const Matrix2x2 &b);

/**
 * @brief Product of two 3×3 matrices: C = A · B
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return Resulting matrix.
 */
Matrix3x3 multiply_3x3(const Matrix3x3 &a, const Matrix3x3 &b);

/* ------------------------------------------------------------------------- */
/*                        Multiplication (step‑by‑step)                      */
/* ------------------------------------------------------------------------- */

/**
 * @brief Step‑by‑step multiplication of two 2×2 matrices.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return Vector of strings describing each element computation.
 */
std::vector<std::string> multiply_2x2_steps(const Matrix2x2 &a,
                                           const Matrix2x2 &b);

/**
 * @brief Step‑by‑step multiplication of two 3×3 matrices.
 *
 * @param a First matrix.
 * @param b Second matrix.
 * @return Vector of strings describing each element computation.
 */
std::vector<std::string> multiply_3x3_steps(const Matrix3x3 &a,
                                           const Matrix3x3 &b);

} // namespace matrices
} // namespace math

/* ------------------------------------------------------------------------- */
/*                     Inline helper implementations                        */
/* ------------------------------------------------------------------------- */

inline std::string math::matrices::matrix_to_string(
    const Matrix2x2 &m) {
    return "[" + std::to_string(m[0][0]) + "  " + std::to_string(m[0][1]) +
           "]\n[" + std::to_string(m[1][0]) + "  " + std::to_string(m[1][1]) +
           "]";
}

inline std::string math::matrices::matrix_to_string(
    const Matrix3x3 &m) {
    return "[" + std::to_string(m[0][0]) + "  " + std::to_string(m[0][1]) + "  " +
           std::to_string(m[0][2]) + "]\n[" + std::to_string(m[1][0]) + "  " +
           std::to_string(m[1][1]) + "  " + std::to_string(m[1][2]) + "]\n[" +
           std::to_string(m[2][0]) + "  " + std::to_string(m[2][1]) + "  " +
           std::to_string(m[2][2]) + "]";
}
