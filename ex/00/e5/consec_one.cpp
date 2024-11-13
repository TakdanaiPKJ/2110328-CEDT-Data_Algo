#include "bits/stdc++.h"
using namespace std;

int n, k;
string tmp = "";

void solve(string s, int one, int cone, bool flag) {
  if (cone >= k)
    flag = true;
  if (s.length() == n) {
    if (flag) {
      cout << s << "\n";
    }
    return;
  }
  solve(s + "0", one, 0, flag);
  solve(s + "1", one, cone + 1, flag);

  return;
}

int main() {

  cin >> n >> k;
  solve("", 0, 0, false);

  return 0;
}
