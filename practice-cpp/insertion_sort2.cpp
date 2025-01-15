#include <array>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int isSorted(vector<int> &vec) {
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    if (*it < *(it - 1)) {
      return false;
    }
  }
  return true;
}

void printVec(vector<int> &vec) {
  cout << "[";
  cout << *(vec.cbegin());
  for (vector<int>::const_iterator it = vec.cbegin() + 1; it != vec.cend();
       it++) {
    cout << ',' << *it;
  }
  cout << "]";
  cout << endl;
}

void insertionSort(vector<int>& vec, int n) {
  for (int i = 1; i < n; i++) {
    const int key = vec[i];
    int j = i - 1;
    while (j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      j--;
    }
    vec[j + 1] = key;
  }
}

int main() {
  vector<int> arrv = {6, 5, 4, 2, 1, 213, 0, 3, -123};
  cout << "Input:  ";
  printVec(arrv);

  insertionSort(arrv, arrv.size());

  cout << "Output: ";
  printVec(arrv);
  cout << (isSorted(arrv) ? "test passed" : "test failed") << endl;
}