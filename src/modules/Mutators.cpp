#include "../s21_matrix_oop.h"
void S21Matrix::setCols(int new_cols) {
  if (new_cols <= 0)
    throw std::invalid_argument("Column count must be positive");

  if (new_cols == m_cols) return;

  S21Matrix result(m_rows, new_cols);

  int min_cols = std::min(new_cols, m_cols);
  for (int i = 0; i < m_rows; ++i)
    for (int j = 0; j < min_cols; ++j) result(i, j) = (*this)(i, j);

  *this = result;
}

void S21Matrix::setRows(int new_rows) {
  if (new_rows <= 0) throw std::invalid_argument("Row count must be positive");

  if (new_rows == m_rows) return;

  S21Matrix result{new_rows, m_cols};
  int min_rows = std::min(new_rows, m_rows);
  for (int i = 0; i < min_rows; ++i)
    for (int j = 0; j < m_cols; ++j) result(i, j) = (*this)(i, j);
  *this = result;
}