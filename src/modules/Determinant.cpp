#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (m_cols != m_rows)
    throw std::invalid_argument(
        "Can not find a determinant of non-square matrix");

  if (m_cols == 1 && m_rows == 1) return m_matrix[0];

  double determinat{0};
  for (int cols = 0; cols < m_cols; cols++) {
    S21Matrix minor = Minor(0, cols);
    double minor_determinant = minor.Determinant();
    determinat +=
        pow(-1, cols) * (minor_determinant)*m_matrix[cols * m_rows + 0];
  }
  return determinat;
}

S21Matrix S21Matrix::Minor(int n_minor, int m_minor) {
  S21Matrix minor{m_rows - 1, m_cols - 1};
  int minor_index{0};

  for (int i{0}; i < m_cols * m_rows; i++) {
    int row{i % m_rows};
    int col{i / m_rows};
    if (row != n_minor && col != m_minor)
      minor.m_matrix[minor_index++] = m_matrix[i];
  }
  return minor;
}