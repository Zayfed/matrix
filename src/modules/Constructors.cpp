#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols) : m_rows{rows}, m_cols{cols} {
  if (m_cols < 1 || m_rows < 1) {
    throw std::invalid_argument(
        "Matrix dimensions must be positive integers\n");
  }
  m_matrix = new (std::nothrow) double[m_rows * m_cols]();

  if (!m_matrix) {
    throw std::invalid_argument("Error: Memory allocation failed.\n");
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : m_rows{other.m_rows}, m_cols{other.m_cols} {
  m_matrix = new double[other.m_rows * other.m_cols];
  std::copy(other.m_matrix, other.m_matrix + m_rows * m_cols, m_matrix);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (&other == this) return *this;

  deepCopy(other);
  return *this;
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : m_rows{other.m_rows},
      m_cols{other.m_cols},
      m_matrix{other.m_matrix}

{
  other.m_cols = 0;
  other.m_rows = 0;
  other.m_matrix = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    delete[] m_matrix;

    m_matrix = other.m_matrix;
    m_rows = other.m_rows;
    m_cols = other.m_cols;

    other.m_matrix = nullptr;
    other.m_rows = 0;
    other.m_cols = 0;
  }
  return *this;
}

S21Matrix::~S21Matrix() { delete[] m_matrix; }

void S21Matrix::deepCopy(const S21Matrix& matrix) {
  delete[] m_matrix;
  m_rows = matrix.m_rows;
  m_cols = matrix.m_cols;
  m_matrix = new double[matrix.m_cols * matrix.m_rows];
  std::copy(matrix.m_matrix, matrix.m_matrix + m_rows * m_cols, m_matrix);
}
