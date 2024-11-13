#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> flag(10001, false);
vector<int> vt;
vector<int> m(10001, -1);

void permute(int s) {
  if (s == n) {
    for (auto x : vt) {
      cout << x << " ";
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!flag[i] && (m[i] == -1 || flag[m[i]])) {
      flag[i] = true;
      vt.push_back(i);
      permute(s + 1);
      vt.pop_back();
      flag[i] = false;
    }
  }
}

int main() {

  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    m[b] = a;
  }
  permute(0);

  return 0;
}
