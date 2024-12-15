/**
 * @author Abdullah Ashraf
 * @brief Matrix Multiplication Algorithm (without recursion)
 * This code multiplies two matrices, matrix1 and matrix2,
 * and prints the result.
 */

/*
  ------ matrix1 is
  1 2 3
  4 5 6

  ------ matrix2 is
  7  8  9  10
  11 12 13 14
  15 16 17 18

  ------ result is
  74 80 86 92
  173 188 203 218

*/

#include <iostream>
#include <chrono>
#define MAT1_ROWS 4
#define MATMIX 4
#define MAT2_COLS 4
#define RES_ROWS MAT1_ROWS
#define RES_COLS MAT2_COLS

using namespace std;

void display_result(int matrix[RES_ROWS][RES_COLS]) {
  for (int irow = 0; irow < RES_ROWS; irow++) {
    for (int icol = 0; icol < RES_COLS; icol++) {
      cout << matrix[irow][icol] << " ";
    }
    cout << endl;
  }
}

void multiply_matrices(int (&matrix1)[MAT1_ROWS][MATMIX],
                       int (&matrix2)[MATMIX][MAT2_COLS],
                       int (&result)[RES_ROWS][RES_COLS]) {
  for (int resRow = 0; resRow < RES_ROWS; resRow++) {
    for (int resCol = 0; resCol < RES_COLS; resCol++) {
      for (int x = 0; x < MATMIX; x++) {
        result[resRow][resCol] += matrix1[resRow][x] * matrix2[x][resCol];
      }
    }
  }
}

int main() {
  int matrix1[4][4] = {{1, 2, 3, 5}, {4, 5, 6, 7}, {7, 8, 9, 8}, {4, 3, 2, 1}};

  int matrix2[4][4] = {
      {7, 8, 9, 1}, {11, 12, 13, 2}, {15, 16, 17, 3}, {8, 7, 6, 5}};

  int result[RES_ROWS][RES_COLS] = {0};

  auto start = chrono::high_resolution_clock::now();
  multiply_matrices(matrix1, matrix2, result);

  auto end = chrono::high_resolution_clock::now();
  auto duration_recursive =
      chrono::duration_cast<chrono::microseconds>(end - start).count();

  display_result(result);

  cout << endl << "Time taken: " << duration_recursive << endl;

  return 0;
}
