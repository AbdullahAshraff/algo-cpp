#include <bits/stdc++.h>
using namespace std;

int maxProfitRecur(int i, vector<vector<int>> &jobs, vector<int> &memo) {
  if (i == jobs.size())
    return 0;

  if (memo[i] != -1)
    return memo[i];

  int ans = jobs[i][2];

  for (int j = i + 1; j < jobs.size(); j++) {
    if (jobs[j][0] >= jobs[i][1]) {
      ans = max(ans, jobs[i][2] + maxProfitRecur(j, jobs, memo));
    }
  }

  return memo[i] = ans;
}

int maxProfit(vector<vector<int>> &jobs) {
  int n = jobs.size();

  sort(jobs.begin(), jobs.end());

  int ans = 0;
  vector<int> memo(n, -1);

  for (int i = 0; i < n; i++) {
    ans = max(ans, maxProfitRecur(i, jobs, memo));
  }

  return ans;
}

int main() {
  vector<vector<int>> jobs = {
      {1, 2, 50}, {3, 5, 20}, {6, 19, 100}, {2, 100, 200}};
  cout << maxProfit(jobs);
  return 0;
}