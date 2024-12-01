#include <bits/stdc++.h>
using namespace std;

int a, b;

void solve(string s, int nub, int one) {
  if (nub == b) {
    if (one == a)
      cout << s << "\n";
    return;
  }
  if (one != a) {
    solve(s + "0", nub + 1, one);
    solve(s + "1", nub + 1, one + 1);
  } else
    solve(s + "0", nub + 1, one);
}

int main() {

  cin >> a >> b;
  solve("", 0, 0);

  return 0;
}
