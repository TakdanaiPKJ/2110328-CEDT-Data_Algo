#include <bits/stdc++.h>
using namespace std;

vector<int> fib(50, -1);

int solve(int i) {
  if (i < 0)
    return 0;
  if (fib[i] != -1) {
    return fib[i];
  }
  fib[i] = solve(i - 1) + solve(i - 2);
  return fib[i];
}

int main() {

  int n;
  cin >> n;
  fib[0] = 0;
  fib[1] = 1;
  cout << solve(n);

  return 0;
}
