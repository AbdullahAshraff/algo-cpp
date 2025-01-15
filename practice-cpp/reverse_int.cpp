#include <iostream>
#define MAX 50
using namespace std;

void printArr(int arr[MAX]) {
  for (int i = 0; i < MAX; i++) {
    cout << arr[i];
  }
}

int reverseInt(int num) {
  int digits[MAX] = {0};
  int n = 0;
  int result = 0;

  // store digits in an array in a reversed order
  while (num > 0) {
    digits[n++] = num % 10;
    num /= 10;
  }

  // create the reversed int
  for (int i = 0; i < n; i++) {
    result = result * 10 + digits[i];
  }
  return result;
}

int main() {
  int num = 123456;

  cout << reverseInt(num) << endl;
}
