#include <bits/stdc++.h>
using namespace std;

int arr[6001][6001];
int r, c, mn = INT_MAX;

void solve(int i, int j, int sum) {
  if (i < 0 || j < 0 || i >= r || j >= c || arr[i][j] == 3 || arr[i][j] == -1) {
    return;
  }
  if (arr[i][j] == 2) {
    mn = min(mn, sum);
    // cout << sum << "|";
    return;
  }
  int tmp = arr[i][j];
  arr[i][j] = -1;
  solve(i + 1, j, sum + 1);
  solve(i - 1, j, sum + 1);
  solve(i, j + 1, sum + 1);
  solve(i, j - 1, sum + 1);
  arr[i][j] = tmp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> r >> c;
  vector<pair<int, int>> one;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1)
        one.push_back({i, j});
    }
  }
  for (auto x : one) {
    solve(x.first, x.second, 1);
    // cout << x.first << x.second;
    /*for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << arr[i][j];
      }
      cout << "\n";
    }
    cout << "----------\n";*/
  }
  printf("%d", mn);
  return 0;
}
