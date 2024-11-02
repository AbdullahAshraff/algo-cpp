/**
 * @author Abdullah Ashraf
 * @brief Matrix Multiplication Algorithm (without recursion)
 * This code multiplies two matrices, matrix1 and matrix2,
 * and prints the result.
 */

/*
  matrix1 is

  1 2 3
  4 5 6

  matrix2 is

  7  8  9  10
  11 12 13 14
  15 16 17 18


  result is
  74 80 86 92
  173 188 203 218

*/

#include <iostream>
#include <vector>
#define MAT1_ROWS 2
#define MATMIX 3
#define MAT2_COLS 4
#define RES_ROWS MAT1_ROWS
#define RES_COLS MAT2_COLS

using namespace std;

void displayResult(int matrix[RES_ROWS][RES_COLS]) {
  for (int irow = 0; irow < RES_ROWS; irow++) {
    for (int icol = 0; icol < RES_COLS; icol++) {
      cout << matrix[irow][icol] << " ";
    }
    cout << endl;
  }
}

int main() {
  int matrix1[MAT1_ROWS][MATMIX] = {{1, 2, 3}, {4, 5, 6}};

  int matrix2[MATMIX][MAT2_COLS] = {
      {7, 8, 9, 10}, {11, 12, 13, 14}, {15, 16, 17, 18}};

  int result[RES_ROWS][RES_COLS] = {0};

  for (int resRow = 0; resRow < RES_ROWS; resRow++) {
    for (int resCol = 0; resCol < RES_COLS; resCol++) {
      for (int x = 0; x < MATMIX; x++) {
        result[resRow][resCol] += matrix1[resRow][x] * matrix2[x][resCol];
      }
    }
  }

  displayResult(result);
  return 0;
}
