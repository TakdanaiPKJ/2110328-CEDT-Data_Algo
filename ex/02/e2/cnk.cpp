#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(40, vector<int>(40, -1));

int bc(int n, int k) {

  if (n == k || k == 0)
    return 1;
  if (v[n][k] != -1)
    return v[n][k];
  v[n][k] = bc(n - 1, k - 1) + bc(n - 1, k);
  return v[n][k];
}

int main() {

  int n, k;
  cin >> n >> k;
  cout << bc(n, k);

  return 0;
}
