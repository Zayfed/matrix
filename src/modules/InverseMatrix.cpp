#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (determinant == 0)
    throw std::invalid_argument("Determinnats is equal to zero");

  S21Matrix reverse_matrix{m_rows, m_cols};

  if (m_cols == 1 && m_rows == 1)
    reverse_matrix.m_matrix[0] = 1 / m_matrix[0];

  else {
    S21Matrix calcComplements = CalcComplements();
    calcComplements = calcComplements.Transpose();
    for (int i{0}; i < m_cols * m_rows; i++)
      reverse_matrix.m_matrix[i] =
          calcComplements.m_matrix[i] * (1.0 / determinant);
  }
  return reverse_matrix;
}
