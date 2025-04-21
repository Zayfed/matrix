#include "../s21_matrix_oop.h"

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (!this->MatrixSameSize(other))
    throw std::invalid_argument(
        "Can not sub natrices with different demensions");
  this->SubMatrixElements(other);
}

void S21Matrix::SubMatrixElements(const S21Matrix& other) {
  for (int n = 0; n < m_cols * m_rows; n++) {
    m_matrix[n] = m_matrix[n] - other.m_matrix[n];
    if (!std::isfinite(m_matrix[n]))
      throw std::invalid_argument("Can not handle infinite values");
  }
}