#include "../s21_matrix_oop.h"

void S21Matrix::FillMatrix(double start_value, double iteration_step) {
  double value{start_value};
  for (int i = 0; i < m_cols * m_rows; i++) {
    m_matrix[i] = value;
    value += iteration_step;
  }
}

void S21Matrix::printMatrix() {
  for (int i = 0; i < m_rows; ++i) {
    for (int j = 0; j < m_cols; ++j) {
      std::cout << '[' << m_matrix[j * m_rows + i] << "] ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}