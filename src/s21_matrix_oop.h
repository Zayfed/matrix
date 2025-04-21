#ifndef s21MATRIX_OOP_H
#define s21MATRIX_OOP_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int m_rows;
  int m_cols;
  double* m_matrix;

  void deepCopy(const S21Matrix& matrix);
  bool MatrixSameSize(const S21Matrix& other);
  bool SameDimensionMatrixComparison(const S21Matrix& other);

  void SumMatrixElements(const S21Matrix& other);
  void SubMatrixElements(const S21Matrix& other);
  double ElementOfProduct(const S21Matrix& other, int n);

 public:
  // Accessors
  int getRows() { return m_rows; }
  int getCols() { return m_cols; }

  // Mutators
  void setRows(int new_rows);
  void setCols(int new_cols);

  // initialization constructor
  S21Matrix(int rows = 1, int cols = 1);

  // copy constructor
  S21Matrix(const S21Matrix& other);

  // copy assignment constructor
  S21Matrix& operator=(const S21Matrix& other);

  // move constructor
  S21Matrix(S21Matrix&& other) noexcept;

  // move assignment constructor
  S21Matrix& operator=(S21Matrix&& other) noexcept;

  // destructor
  ~S21Matrix();

  // Methods
  bool EqMatrix(const S21Matrix& another);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // Operators overloading
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  double& operator()(int row, int col);
  double operator()(int row, int col) const;

  // Extra methods
  void FillMatrix(double start_value = 1, double iteration_step = 1);
  S21Matrix Minor(int n_minor, int m_minor);
  void printMatrix();
};

#endif