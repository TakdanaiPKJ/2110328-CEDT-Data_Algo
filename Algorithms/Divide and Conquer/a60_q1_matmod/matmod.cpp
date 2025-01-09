#include "bits/stdc++.h"
using namespace std;

vector<int> matrix_multiply(vector<int> &m1, vector<int> &m2, int k) {
  vector<int> tmp(4);
  tmp[0] = ((m1[0] * m2[0]) % k + (m1[1] * m2[2]) % k) % k;
  tmp[1] = ((m1[0] * m2[1]) % k + (m1[1] * m2[3]) % k) % k;
  tmp[2] = ((m1[2] * m2[0]) % k + (m1[3] * m2[2]) % k) % k;
  tmp[3] = ((m1[2] * m2[1]) % k + (m1[3] * m2[3]) % k) % k;
  return tmp;
}

vector<int> solve(vector<int> v, int n, int k) {
  if (n == 1) {
    v[0] %= k;
    v[1] %= k;
    v[2] %= k;
    v[3] %= k;
    return v;
  }
  vector<int> mid = solve(v, n / 2, k);
  if (n % 2 == 0) {
    return matrix_multiply(mid, mid, k);
  } else {
    vector<int> tmp = matrix_multiply(mid, mid, k);
    return matrix_multiply(v, tmp, k);
  }
}

int main() {

  int n, k;
  int a, b, c, d;
  vector<int> v(4);
  cin >> v[0] >> v[1] >> v[2] >> v[3];
  vector<int> ans = solve(v, n, k);
  cout << ans[0] << ans[1] << ans[2] << ans[3];

  return 0;
}
