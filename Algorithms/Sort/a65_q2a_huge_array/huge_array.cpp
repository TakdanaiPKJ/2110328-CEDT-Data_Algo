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

  map<int, int> mp;

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    mp[a] += b;
  }

  vector<int> vt;
  vector<int> sum;
  int csum = 0;
  for (auto x : mp) {
    vt.push_back(x.first);
    csum += x.second;
    sum.push_back(csum);
  }

  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    int l = 0, r = sum.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (sum[mid] >= a) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << vt[l] << "\n";
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
}
