#include <vector>
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

set<int> st;
vector<int> cnt(1000010, 0);

void solve() {
  st.clear();

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    cnt[b]++;
    st.insert(b);
  }
  int a;
  for (int i = 0; i < m; i++) {
    cin >> a;
    bool flag = false;
    for (auto x : st) {
      if (st.find(a - x) == st.end()) {
        flag = false;
        continue;
      } else {
        if (a - x == x && cnt[x] < 2)
          flag = false;
        else {
          // cout << a << x << cnt[x];
          flag = true;
          cout << "YES\n";
        }
        break;
      }
    }
    if (!flag)
      cout << "NO\n";
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
