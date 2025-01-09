#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &v, int k) {
  if (k == 1) {
    return (v[0] == 0) && (v[1] == 1);
  }
  int mid = (1 << k) / 2;
  vector<int> l(v.begin(), v.begin() + mid);
  vector<int> r(v.begin() + mid, v.end());
  if (solve(l, k - 1) && solve(r, k - 1)) {
    return true;
  }
  reverse(l.begin(), l.end());
  if (solve(l, k - 1) && solve(r, k - 1)) {
    return true;
  }
  return false;
}

int main() {

  int n, k;
  cin >> n >> k;
  for (size_t i = 0; i < n; i++) {
    vector<int> v(1 << k);
    for (size_t j = 0; j < (1 << k); j++) {
      cin >> v[j];
    }
    cout << (solve(v, k) ? "yes" : "no") << "\n";
  }
}
