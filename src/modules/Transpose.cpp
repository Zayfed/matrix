#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix transposed_matrix{m_cols, m_rows};
  for (int i = 0; i < m_rows * m_cols; ++i) {
    int row = i / m_cols;
    int col = i % m_cols;
    transposed_matrix(col, row) = (*this)(row, col);
  }
  return transposed_matrix;
}