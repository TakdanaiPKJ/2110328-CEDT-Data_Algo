#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(300, vector<int>(300, 0));

void solve(int a, int b, int top, int bottom, int left, int right) {
  if (a == 0) {
    v[top][left] = b;
    return;
  }

  int midr = (top + bottom) / 2;
  int midc = (left + right) / 2;
  solve(a - 1, b, top, midr, left, midc);
  solve(a - 1, b - 1, top, midr, midc, right);
  solve(a - 1, b + 1, midr, bottom, left, midc);
  solve(a - 1, b, midr, bottom, midc, right);
  return;
}

int main() {

  int a, b;
  cin >> a >> b;
  int sz = 1 << a;
  solve(a, b, 0, 1 << a, 0, 1 << a);
  for (size_t i = 0; i < sz; i++) {
    for (size_t j = 0; j < sz; j++) {
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
