#include <bits/stdc++.h>
using namespace std;

set<int> s;
vector<int> dp(10000, 0);

int solve(int n) {

  for (int i = 1; i <= n; i++) {
    for (auto x : s) {
      if (i >= x)
        dp[i] = (dp[i] + dp[i - x]) % 1000003;
    }
  }
  return dp[n];
}

int main() {

  int n, k;
  cin >> n >> k;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  cout << solve(n);
  // cout << dp[n];

  return 0;
}
