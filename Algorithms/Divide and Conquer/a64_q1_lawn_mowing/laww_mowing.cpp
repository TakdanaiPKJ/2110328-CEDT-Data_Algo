#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long> &v, int a, int b, int k) {

  long long mxg = 0;
  int l = a, r = v.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    long long glass = v[mid] - (a == 0 ? 0 : v[a - 1]);
    long long cost = glass + (mid - (a) + 1) * k;
    // cout << l << "|" << r << "|" << glass << "|" << mid;
    if (cost <= b) {
      mxg = max(mxg, glass);
      l = mid + 1;
    } else
      r = mid - 1;
  }

  return mxg;
}

int main() {

  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> v(n);
  cin >> v[0];
  for (size_t i = 1; i < n; i++) {
    long long a;
    cin >> a;
    v[i] = v[i - 1] + a;
  }
  for (size_t i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    cout << solve(v, a, b, k) << "\n";
  }
  // for (auto x : v)
  // cout << x << " ";

  return 0;
}
