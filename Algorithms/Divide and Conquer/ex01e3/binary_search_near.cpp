#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int bsn(int a) {
  int l = 0, r = v.size() - 1;
  int ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a < v[mid]) {
      r = mid - 1;
    } else {
      ans = v[mid];
      l = mid + 1;
    }
  }
  return ans;
}

int main() {

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  while (m--) {
    int a;
    cin >> a;
    cout << bsn(a) << "\n";
  }

  return 0;
}
