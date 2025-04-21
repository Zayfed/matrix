#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (m_cols != m_rows)
    throw std::invalid_argument(
        "Can not find a determinant of non-square matrix");

  S21Matrix CalcComplements{m_rows, m_cols};
  for (int i{0}; i < m_cols * m_rows; i++) {
    int rows{i % m_rows};
    int cols{i / m_rows};
    S21Matrix minor = Minor(rows, cols);
    double determinant = minor.Determinant();
    CalcComplements.m_matrix[i] = determinant * pow(-1, rows + cols);
  }
  return CalcComplements;
}