#include <queue>
#include <vector>
#ifdef ONPC
#define _GLIBCXX_DEBUG // if onpc it's will run -DONPC when run
#endif
#include <bits/stdc++.h>
using namespace std;

bool check(int n, int p) {
  while (n != p && n != 0) {
    n = (n - 1) / 2;
  }
  if (n == p)
    return false;
  return true;
}

void solve() {

  int n, m;
  cin >> n >> m;
  vector<int> vt;
  for (int i = 0; i < n; i++) {
    if (check(i, m)) {
      vt.push_back(i);
    }
  }
  cout << vt.size() << "\n";
  for (auto x : vt) {
    cout << x << " ";
  }

  return;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int TET = 1;
#ifdef ONPC
  cin >> TET;
#endif
  for (int i = 1; i <= TET; i++) {
    solve();
#ifdef ONPC
    cout << "\n__________________________\n";
#endif
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
  return 0;
}
