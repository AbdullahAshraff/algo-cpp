/**
 * @author Abdullah Ashraf
 * @brief Matrix Multiplication Algorithm (Using Recursion)
 * This code multiplies two matrices, matrix1 and matrix2
 */

/*
  ------ matrix1 is
  1 2 3 5
  4 5 6 7
  7 8 9 8
  4 3 2 1

  ------ matrix2 is
  7  8  9  1
  11 12 13 2
  15 16 17 3
  8  7  6  5

  ------ result is
  114 115 116 39
  229 237 245 67
  336 352 368 90
  99 107 115 21

*/

#include <iostream>
#include <chrono>
#define MAX 4

using namespace std;

void display_result(int (&matrix)[MAX][MAX]) {
  for (int irow = 0; irow < MAX; irow++) {
    for (int icol = 0; icol < MAX; icol++) {
      cout << matrix[irow][icol] << " ";
    }
    cout << endl;
  }
}

void add_matrices(int (&A)[MAX][MAX], int (&B)[MAX][MAX],
                  int (&result)[MAX][MAX], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  }
}

void recursive_multiply_matrices(int (&matrix1)[MAX][MAX],
                                 int (&matrix2)[MAX][MAX],
                                 int (&result)[MAX][MAX], int n) {

  if (n == 1) {
    result[0][0] = matrix1[0][0] * matrix2[0][0];
    return;
  }

  int mid = n / 2;
  // each matrix is split into 4 sub matrices
  // matrix A
  int a11[MAX][MAX] = {0};
  int a12[MAX][MAX] = {0};
  int a21[MAX][MAX] = {0};
  int a22[MAX][MAX] = {0};
  // matrix B
  int b11[MAX][MAX] = {0};
  int b12[MAX][MAX] = {0};
  int b21[MAX][MAX] = {0};
  int b22[MAX][MAX] = {0};
  // matrix C
  int c11[MAX][MAX] = {0};
  int c12[MAX][MAX] = {0};
  int c21[MAX][MAX] = {0};
  int c22[MAX][MAX] = {0};
  // temporary matrices
  int temp1[MAX][MAX] = {0};
  int temp2[MAX][MAX] = {0};

  // Divide matrix a into submatrices
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      a11[i][j] = matrix1[i][j];
      b11[i][j] = matrix2[i][j];
      a12[i][j] = matrix1[i][j + mid];
      b12[i][j] = matrix2[i][j + mid];
      a21[i][j] = matrix1[i + mid][j];
      b21[i][j] = matrix2[i + mid][j];
      a22[i][j] = matrix1[i + mid][j + mid];
      b22[i][j] = matrix2[i + mid][j + mid];
    }
  }

  // the 11 quarter
  recursive_multiply_matrices(a11, b11, temp1, mid);
  recursive_multiply_matrices(a12, b21, temp2, mid);

  add_matrices(temp1, temp2, c11, mid);

  // the 12 quarter
  recursive_multiply_matrices(a11, b12, temp1, mid);
  recursive_multiply_matrices(a12, b22, temp2, mid);

  add_matrices(temp1, temp2, c12, mid);

  // the 21 quarter
  recursive_multiply_matrices(a21, b11, temp1, mid);
  recursive_multiply_matrices(a22, b21, temp2, mid);

  add_matrices(temp1, temp2, c21, mid);

  // the 22 quarter
  recursive_multiply_matrices(a21, b12, temp1, mid);
  recursive_multiply_matrices(a22, b22, temp2, mid);

  add_matrices(temp1, temp2, c22, mid);

  // saving the submatrices into result matrix
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      result[i][j] = c11[i][j];
      result[i][j + mid] = c12[i][j];
      result[i + mid][j] = c21[i][j];
      result[i + mid][j + mid] = c22[i][j];
    }
  }
}
int main() {
  int matrix1[MAX][MAX] = {
      {1, 2, 3, 5}, {4, 5, 6, 7}, {7, 8, 9, 8}, {4, 3, 2, 1}};

  int matrix2[MAX][MAX] = {
      {7, 8, 9, 1}, {11, 12, 13, 2}, {15, 16, 17, 3}, {8, 7, 6, 5}};

  int result[MAX][MAX] = {0};

  auto start = chrono::high_resolution_clock::now();

  recursive_multiply_matrices(matrix1, matrix2, result, MAX);

  auto end = chrono::high_resolution_clock::now();
  auto duration_recursive =
      chrono::duration_cast<chrono::microseconds>(end - start).count();

  display_result(result);

  cout << endl << "Time taken: " << duration_recursive << endl;

  return 0;
}