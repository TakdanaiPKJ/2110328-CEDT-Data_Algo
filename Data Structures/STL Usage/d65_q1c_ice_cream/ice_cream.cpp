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
  unordered_map<int, int> kep;
  vector<int> money(100002, 0);
  int n, m, st;
  cin >> n >> m >> st;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    kep[a] = b;
  }
  money[0] = st;
  int curm = st;
  for (int i = 1; i < 100002; i++) {
    if (kep.find(i) != kep.end()) {
      curm = kep[i];
    }
    money[i] = money[i - 1] + curm;
  }
  for (int i = 0; i < m; i++) {
    int itim, kamoy;
    cin >> itim >> kamoy;
    if (money[kamoy] < itim) {
      itim += money[kamoy];
    }
    int ans = lower_bound(money.begin(), money.end(), itim) - money.begin();
    cout << ans << " ";
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
}
