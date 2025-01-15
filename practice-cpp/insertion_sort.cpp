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

void insertOrdered(vector<int> &vec, int element) {
  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    if (element < *(it)) {
      int previous_el = element;
      for (vector<int>::iterator iter = it; iter != vec.end(); iter++) {
        swap(*iter, previous_el);
      }
      vec.push_back(previous_el);
      return;
    }
  }
  vec.push_back(element);
}

vector<int> insertionSort(vector<int> &vec) {
  vector<int> res;
  for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++) {
    insertOrdered(res, *it);
  }
  return res;
}

int main() {
  vector<int> arrv = {6, 5, 4, 2, 1, 213, 0, 3, -123};
  vector<int> resultedVec = insertionSort(arrv);

  cout << "Input:  ";
  printVec(arrv);
  cout << "Output: ";
  printVec(resultedVec);
  cout << (isSorted(resultedVec) ? "test passed" : "test failed") << endl;
}