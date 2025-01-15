#include <array>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int recur_count = 0;

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

void mergeVecs(vector<int> &vec, int start, int mid, int end) {
  vector<int> res = {};
  int i = start, j = mid;

  while (i < mid && j < end) {
    if (vec.at(i) < vec.at(j)) {
      res.push_back(vec.at(i));
      i++;
    } else {
      res.push_back(vec.at(j));
      j++;
    }
  }

  while (i < mid) {
    res.push_back(vec.at(i));
    i++;
  }
  while (j < end) {
    res.push_back(vec.at(j));
    j++;
  }

  // adding res to vec
  for (int i = 0; i < res.size(); i++) {
    vec[i + start] = res[i];
  }
}

void mergeSort(vector<int> &vec, int start = 0, int end = -1) {
  if (end == -1)
    end = vec.size();

  // base case
  if (end - start <= 2) {
    if (vec[start] >= vec[end - 1])
      swap(vec[start], vec[end - 1]);
    recur_count++;
    return;
  }

  int mid = (end + start) / 2;

  mergeSort(vec, start, mid);
  mergeSort(vec, mid, end);

  mergeVecs(vec, start, mid, end);
}

int main() {
  vector<int> arrv = {6, 5, 4, 2, 1, 213, 0, 3, -123};
  cout << "Input:  ";
  printVec(arrv);

  mergeSort(arrv);

  cout << "Output: ";
  printVec(arrv);
  cout << (isSorted(arrv) ? "test passed" : "test failed") << endl;
  cout << "n: " << arrv.size() << " Recur count: " << recur_count << endl;
}