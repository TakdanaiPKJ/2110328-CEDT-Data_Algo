#ifdef ONPC
#define _GLIBCXX_DEBUG // if onpc it's will run -DONPC when run
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937
    rnd(chrono::steady_clock::now()
            .time_since_epoch()
            .count()); // take current time in nano second as seed random number

typedef long long ll;
typedef long double ld;

void solve() {

  int n, m;
  set<pair<int, int>> st;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    st.insert({a, b});
  }
  for (int i = 0; i < m; i++) {
    pair<int, int> a;
    cin >> a.first >> a.second;
    auto x = st.lower_bound(a);
    if (*x == a) {
      cout << "0 0 ";
    } else if (x == st.begin()) {
      cout << "-1 -1 ";
    } else {
      auto y = x;
      y--;
      cout << y->first << " " << y->second << " ";
    }
  }
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
