#ifdef ONPC
#define _GLIBCXX_DEBUG // if onpc it's will run -DONPC when run
#endif
#include <bits/stdc++.h>
using namespace std;

void solve() {

  int n, k, v;
  cin >> n >> k >> v;

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
