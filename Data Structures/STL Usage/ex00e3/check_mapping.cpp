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
  set<int> st;
  int n;
  cin >> n;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (st.find(a) == st.end()) {
      st.insert(a);

    } else
      flag = false;
  }
  auto cnt = *st.begin();
  for (auto x : st) {
    if (cnt != x) {
      flag = false;
      break;
    }
    cnt++;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
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
