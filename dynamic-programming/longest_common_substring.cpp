#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAX 20

using namespace std;

void print_arr(int (&arr)[MAX][MAX]) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      int x = arr[i][j];
      if (x == -1) {
        cout << '-' << ' ';
      } else
        cout << x << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int lcs(string &s1, string &s2, int s1_length, int s2_length,
        int (&ans)[MAX][MAX], int (&dir)[MAX][MAX]) {
  // print_arr(ans);
  if (ans[s1_length][s2_length] != -1) {
    return ans[s1_length][s2_length];
  }

  if (s1_length == 0 || s2_length == 0) // base case
    return 0;

  for (int i = s1_length - 1; i >= 0; i--) {
    for (int j = s2_length - 1; j >= 0; j--) {
      if (s1[i] == s2[j]) {
        ans[s1_length][s2_length] =
            1 + lcs(s1, s2, s1_length - 1, s2_length - 1, ans, dir);
        dir[s1_length][s2_length] = 1;
        return ans[s1_length][s2_length];
      } else {

        int first = lcs(s1, s2, s1_length - 1, s2_length, ans, dir);
        int second = lcs(s1, s2, s1_length, s2_length - 1, ans, dir);
        if (first > second) {
          ans[s1_length][s2_length] = first;
          dir[s1_length][s2_length] = 3;
        } else {
          ans[s1_length][s2_length] = second;
          dir[s1_length][s2_length] = 2;
        }
        return ans[s1_length][s2_length];
      }
    }
  }
  return 0;
}

int dynamic_lcs(string &s1, string &s2) {
  int ans[MAX][MAX];

  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      ans[i][j] = -1;

  int dir[MAX][MAX] = {0}; // 1 means diagonal, 2 means up, 3 means left

  int n1 = s1.length();
  int n2 = s2.length();
  int res = lcs(s1, s2, n1, n2, ans, dir);
  // print_arr(dir);
  return res;
}

int main() {
  string s1 = "abcdxyzxabcdxyzxab";
  // abcdxyzxabcdxyzxab  abcdxyzxabcdxyzxabcdxyzx
  string s2 = "xyzabcdxxyzabcdxxy";
  // xyzabcdxxyzabcdxxy  xyzabcdxxyzabcdxxyzabcdx

  cout << dynamic_lcs(s1, s2);
  cout << endl;
}
