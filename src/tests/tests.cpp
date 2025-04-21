#include "tests.h"

// Constructors

TEST(CreateMatrix, DefaultValues) {
  S21Matrix m;
  EXPECT_EQ(m.getCols(), 1);
  EXPECT_EQ(m.getRows(), 1);
}

TEST(CreateMatrix, DefaultConstructor) {
  S21Matrix matrix{5, 6};
  ASSERT_TRUE(matrix.getRows() == 5);
  ASSERT_TRUE(matrix.getCols() == 6);
}

TEST(CreateMatrix, SmallDimensions) {
  EXPECT_THROW(S21Matrix(0, 3), std::invalid_argument);
  EXPECT_THROW(S21Matrix(3, 0), std::invalid_argument);
  EXPECT_THROW(S21Matrix(-4, 0), std::invalid_argument);
  EXPECT_THROW(S21Matrix(0, -1), std::invalid_argument);
}

TEST(CreateMatrix, MoveConstructor) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b = std::move(matrix_a));
}

TEST(CreateMatrix, CopyConstructor) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b(matrix_a));
}

// Setter & Getters

TEST(Set, Success) {
  S21Matrix matrix;
  matrix.setRows(4);
  matrix.setCols(5);
  ASSERT_TRUE(matrix.getRows() == 4);
  ASSERT_TRUE(matrix.getCols() == 5);
}

TEST(Set, ZeroDimensions) {
  S21Matrix matrix{6, 9};
  EXPECT_THROW(matrix.setRows(0), std::invalid_argument);
  EXPECT_NO_THROW(matrix.setCols(5));
}

TEST(Set, SmallDimensions) {
  S21Matrix matrix{6, 9};
  EXPECT_THROW(matrix.setRows(-9), std::invalid_argument);
  EXPECT_NO_THROW(matrix.setCols(2));
}

TEST(Set, SetRowsUp) {
  S21Matrix m(2, 2);
  m(1, 1) = 4.8;

  m.setRows(5);
  EXPECT_EQ(m.getRows(), 5);
  EXPECT_EQ(m(1, 1), 4.8);
}

TEST(Set, SetRowsDown) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.setRows(1);
  EXPECT_EQ(m.getRows(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(Set, SetRowsZero) {
  S21Matrix m;
  EXPECT_ANY_THROW(m.setRows(0));
}

TEST(Set, SetColsUp) {
  S21Matrix m(2, 2);
  m(1, 1) = 9.9;

  m.setCols(5);
  EXPECT_EQ(m.getCols(), 5);
  EXPECT_EQ(m(1, 1), 9.9);
}

TEST(Set, SetColsDown) {
  S21Matrix m(2, 2);
  m(0, 0) = 6.9;

  m.setCols(1);
  EXPECT_EQ(m.getCols(), 1);
  EXPECT_EQ(m(0, 0), 6.9);
}

TEST(Set, SetColsZero) {
  S21Matrix m;
  EXPECT_ANY_THROW(m.setCols(0));
}

// SumMatrix

TEST(SumMatrix, SumSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  matrix1.SumMatrix(matrix2);
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

TEST(SumMatrix, SumWithDifferentDimensions) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 3};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
}

TEST(SumMatrix, SumOperatorSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  matrix1 = matrix1 + matrix2;
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

TEST(SumMatrix, SumEqOperatorSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  matrix1 += matrix2;
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

// SubMatrix

TEST(SubMatrix, SubSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix(3, 3);
  matrix2.FillMatrix();

  matrix1.SubMatrix(matrix2);
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

TEST(SubMatrix, SubWithDifferentDimensions) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 3};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST(SubMatrix, SubOperatorSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix(3, 3);
  matrix2.FillMatrix();

  matrix1 = matrix1 - matrix2;
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

TEST(SubMatrix, SubEqOperatorSuccess) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix(3, 3);
  matrix2.FillMatrix();

  matrix1 -= matrix2;
  S21Matrix result{3, 4};
  result.FillMatrix(2, 2);
  EXPECT_EQ(matrix1.EqMatrix(result), 1);
}

// EqMatrix

TEST(EqMatrix, True) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  ASSERT_TRUE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrix, False) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix(2, 2);
  matrix2.FillMatrix();

  ASSERT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrix, Exeption) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix(3, 3);
  matrix2.FillMatrix();

  ASSERT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(EqMatrix, Operator) {
  S21Matrix matrix1{3, 4};
  S21Matrix matrix2{3, 4};

  matrix1.FillMatrix();
  matrix2.FillMatrix();

  ASSERT_TRUE(matrix1 == matrix2);
}

// Multiplication

TEST(Mul, MulMatrices) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m{rows, cols};
  S21Matrix n{cols, rows};

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n(i, j) = c++;

  m.MulMatrix(n);

  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(Mul, EqMulOperator) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n(i, j) = c++;

  m *= n;

  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(Mul, EqMulOperatorNum) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  m *= 2;

  S21Matrix res(2, 3);
  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 6;
  res(1, 0) = 8;
  res(1, 1) = 10;
  res(1, 2) = 12;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(Mul, MulOperator) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n(i, j) = c++;

  m = m * n;

  S21Matrix res(2, 2);
  res(0, 0) = 58;
  res(0, 1) = 64;
  res(1, 0) = 139;
  res(1, 1) = 154;

  ASSERT_TRUE(m == res);
}

TEST(Mul, MulOperatorNum) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m(i, j) = c++;

  m = m * 2;

  S21Matrix res(2, 3);
  res(0, 0) = 2;
  res(0, 1) = 4;
  res(0, 2) = 6;
  res(1, 0) = 8;
  res(1, 1) = 10;
  res(1, 2) = 12;

  ASSERT_TRUE(m == res);
}

// Transpose

TEST(Transpose, Success) {
  S21Matrix matrix{2, 3};
  S21Matrix transposed_matrix{3, 2};
  matrix.FillMatrix(1, 1);
  matrix = matrix.Transpose();
  transposed_matrix(0, 0) = 1, transposed_matrix(0, 1) = 4;
  transposed_matrix(1, 0) = 2, transposed_matrix(1, 1) = 5;
  transposed_matrix(2, 0) = 3, transposed_matrix(2, 1) = 6;
  EXPECT_EQ(matrix.EqMatrix(transposed_matrix), true);
  EXPECT_EQ(transposed_matrix.getRows(), 3);
  EXPECT_EQ(transposed_matrix.getCols(), 2);
}

// CalcComponents

TEST(CalcComlements, Success) {
  S21Matrix matrix{3, 3};
  S21Matrix transposed_matrix{3, 3};
  matrix(0, 0) = 1, matrix(0, 1) = 2, matrix(0, 2) = 3;
  matrix(1, 0) = 4, matrix(1, 1) = 5, matrix(1, 2) = 6;
  matrix(2, 0) = 7, matrix(2, 1) = 8, matrix(2, 2) = 9;
  matrix = matrix.CalcComplements();
  transposed_matrix(0, 0) = -3, transposed_matrix(0, 1) = 6,
                       transposed_matrix(0, 2) = -3;
  transposed_matrix(1, 0) = 6, transposed_matrix(1, 1) = -12,
                       transposed_matrix(1, 2) = 6;
  transposed_matrix(2, 0) = -3, transposed_matrix(2, 1) = 6,
                       transposed_matrix(2, 2) = -3;
  EXPECT_EQ(matrix.EqMatrix(transposed_matrix), true);
}

TEST(CalcComlements, Exeption) {
  S21Matrix matrix{3, 2};
  S21Matrix transposed_matrix{3, 3};
  matrix(0, 0) = 1, matrix(0, 1) = 2;
  matrix(1, 0) = 4, matrix(1, 1) = 5;
  matrix(2, 0) = 7, matrix(2, 1) = 8;
  EXPECT_THROW(matrix.CalcComplements();, std::invalid_argument);
}

// InverseMatrix

TEST(InverseMatrix, Success) {
  S21Matrix matrix{3, 3};
  S21Matrix transposed_matrix{3, 3};

  matrix(0, 0) = 2, matrix(0, 1) = 4, matrix(0, 2) = 2;
  matrix(1, 0) = 1, matrix(1, 1) = 2, matrix(1, 2) = 4;
  matrix(2, 0) = 1, matrix(2, 1) = 4, matrix(2, 2) = 0;

  matrix = matrix.InverseMatrix();

  transposed_matrix(0, 0) = 4.0 / 3, transposed_matrix(0, 1) = -2.0 / 3,
                       transposed_matrix(0, 2) = -1;
  transposed_matrix(1, 0) = -1.0 / 3, transposed_matrix(1, 1) = 1.0 / 6,
                       transposed_matrix(1, 2) = 1.0 / 2;
  transposed_matrix(2, 0) = -1.0 / 6, transposed_matrix(2, 1) = 1.0 / 3,
                       transposed_matrix(2, 2) = 0;

  EXPECT_EQ(matrix.EqMatrix(transposed_matrix), true);
}

TEST(InverseMatrix, Exeption) {
  S21Matrix matrix{3, 3};
  S21Matrix transposed_matrix{3, 3};

  matrix(0, 0) = 1, matrix(0, 1) = 2, matrix(0, 2) = 3;
  matrix(1, 0) = 4, matrix(1, 1) = 5, matrix(1, 2) = 6;
  matrix(2, 0) = 7, matrix(2, 1) = 8, matrix(2, 2) = 9;

  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}