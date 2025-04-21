#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (m_cols != other.m_rows) throw std::invalid_argument("Invalid dimensions");

  S21Matrix product_matrix{m_rows, other.m_cols};

  for (int n = 0; n < m_rows * other.m_cols; n++) {
    product_matrix.m_matrix[n] = this->ElementOfProduct(other, n);
    if (!std::isfinite(product_matrix.m_matrix[n]))
      throw std::invalid_argument("Can not handle infinite values");
  }
  *this = product_matrix;
}

double S21Matrix::ElementOfProduct(const S21Matrix& other, int n) {
  double product = 0.0;
  int row = n / other.m_cols;
  int col = n % other.m_cols;

  for (int i = 0; i < m_cols; ++i) {
    product += (*this)(row, i) * other(i, col);
  }

  return product;
}