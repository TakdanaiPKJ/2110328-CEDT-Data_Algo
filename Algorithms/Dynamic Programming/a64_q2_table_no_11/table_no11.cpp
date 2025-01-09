#include <bits/stdc++.h>
using namespace std;

vector<long long> v(10000000, -1);

long long solve(int i) {
  if (i <= 0)
    return 1;
  if (v[i] != -1)
    return v[i];
  v[i] = (2 * solve(i - 1) % 100000007 + solve(i - 2) % 100000007) % 100000007;

  return v[i];
}

int main() {

  int n;
  cin >> n;
  v[1] = 3;
  v[2] = 7;
  v[3] = 17;
  cout << solve(n) % 100000007;

  return 0;
}
