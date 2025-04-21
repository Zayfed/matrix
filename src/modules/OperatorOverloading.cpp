#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temporary = *this;
  temporary.SumMatrix(other);
  return temporary;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix temporary = *this;
  temporary.SubMatrix(other);
  return temporary;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix temporary = *this;
  temporary.MulMatrix(other);
  return temporary;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix temporary = *this;
  temporary.MulNumber(num);
  return temporary;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

void S21Matrix::operator*=(const double num) { MulNumber(num); }

double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
    throw std::out_of_range("Matrix index out of range");
  return m_matrix[row * m_cols + col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
    throw std::out_of_range("Matrix index out of range");
  return m_matrix[row * m_cols + col];
}