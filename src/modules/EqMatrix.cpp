#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (!this->MatrixSameSize(other)) return false;
  return SameDimensionMatrixComparison(other);
}

bool S21Matrix::SameDimensionMatrixComparison(const S21Matrix& other) {
  for (int n = 0; n < this->m_cols * this->m_rows; n++)
    if (std::abs(this->m_matrix[n] - other.m_matrix[n]) >= 1e-7) return false;
  return true;
}

bool S21Matrix::MatrixSameSize(const S21Matrix& other) {
  return (m_rows == other.m_rows) && (m_cols == other.m_cols);
}