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

string rec(unordered_map<string, string> &ump, string s, int depth) {
  if (depth == 2)
    return s;
  if (ump.find(s) == ump.end())
    return "x";
  return rec(ump, ump[s], depth + 1);
}

void solve() {

  unordered_map<string, string> ump;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string f, s;
    cin >> f >> s;
    ump[s] = f;
  }
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    string gfa, gfb;
    gfa = rec(ump, a, 0);
    gfb = rec(ump, b, 0);
    if (gfa == gfb && gfa != "x" && a != b)
      cout << "YES\n";
    else
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
