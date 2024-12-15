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

#include <chrono>
#include <iostream>

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

void subtract_matrices(int (&A)[MAX][MAX], int (&B)[MAX][MAX],
                       int (&result)[MAX][MAX], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = A[i][j] - B[i][j];
    }
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
  int a[MAX][MAX] = {0};
  int b[MAX][MAX] = {0};
  int c[MAX][MAX] = {0};
  int d[MAX][MAX] = {0};
  // matrix B
  int e[MAX][MAX] = {0};
  int f[MAX][MAX] = {0};
  int g[MAX][MAX] = {0};
  int h[MAX][MAX] = {0};
  // strassen seven variables
  int p1[MAX][MAX] = {0};
  int p2[MAX][MAX] = {0};
  int p3[MAX][MAX] = {0};
  int p4[MAX][MAX] = {0};
  int p5[MAX][MAX] = {0};
  int p6[MAX][MAX] = {0};
  int p7[MAX][MAX] = {0};
  // temporary matrices for calculations
  int temp1[MAX][MAX] = {0};
  int temp2[MAX][MAX] = {0};

  // Divide matrix a into submatrices
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      a[i][j] = matrix1[i][j];
      e[i][j] = matrix2[i][j];
      b[i][j] = matrix1[i][j + mid];
      f[i][j] = matrix2[i][j + mid];
      c[i][j] = matrix1[i + mid][j];
      g[i][j] = matrix2[i + mid][j];
      d[i][j] = matrix1[i + mid][j + mid];
      h[i][j] = matrix2[i + mid][j + mid];
    }
  }
  subtract_matrices(f, h, temp1, mid);
  recursive_multiply_matrices(a, temp1, p1, mid); // p1 = a(f-h)

  add_matrices(a, b, temp1, mid);
  recursive_multiply_matrices(temp1, h, p2, mid); // p2 = (a+b)h

  add_matrices(c, d, temp1, mid);
  recursive_multiply_matrices(temp1, e, p3, mid); // p3 = (c+d)e

  subtract_matrices(g, e, temp1, mid);
  recursive_multiply_matrices(d, temp1, p4, mid); // p4 = d(g-e)

  add_matrices(a, d, temp1, mid);
  add_matrices(e, h, temp2, mid);
  recursive_multiply_matrices(temp1, temp2, p5, mid); // p5 = (a+d)(e+h)

  subtract_matrices(b, d, temp1, mid);
  add_matrices(g, h, temp2, mid);
  recursive_multiply_matrices(temp1, temp2, p6, mid); // p6 = (b-d)(g+h)

  subtract_matrices(a, c, temp1, mid);
  add_matrices(e, f, temp2, mid);
  recursive_multiply_matrices(temp1, temp2, p7, mid); // p7 = (a-c)(e+f)

  // creating the result matrix
  for (int i = 0; i < mid; i++) {
    for (int j = 0; j < mid; j++) {
      result[i][j] = p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j];
      result[i][j + mid] = p1[i][j] + p2[i][j];
      result[i + mid][j] = p3[i][j] + p4[i][j];
      result[i + mid][j + mid] = p1[i][j] + p5[i][j] - p3[i][j] - p7[i][j];
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
