#include "../s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) {
  if (!std::isfinite(num))
    throw std::invalid_argument("Can not handle infinite values");

  for (int n = 0; n < m_cols * m_rows; n++) {
    m_matrix[n] = num * m_matrix[n];
  }
}
