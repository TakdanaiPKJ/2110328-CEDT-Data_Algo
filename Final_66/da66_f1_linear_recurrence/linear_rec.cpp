#include <bits/stdc++.h>
using namespace std;

int a[1002];
int c[1002];
vector<long long> mem(1002, INT_MAX);

long long solve(int n, int k) {
  if (n < k) {
    return a[n] % 32717;
  }
  long long sum = 0;
  for (int i = 1; i <= k; i++) {
    if (mem[n - i] == INT_MAX) {
      mem[n - i] = solve(n - i, k);
    }
    sum += (((c[i] % 32717) * (mem[n - i] % 32717)) % 32717);
  }
  return sum % 32717;
}

int main() {

  int k, n;
  cin >> k >> n;
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  cout << solve(n, k);

  return 0;
}
