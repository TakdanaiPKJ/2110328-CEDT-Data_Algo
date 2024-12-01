#include <bits/stdc++.h>
using namespace std;

int r, c;
int arr[20][20];

void solve(int i, int j, string s) {
  if (i <= 0 || i > r || j <= 0 || j > c || arr[i][j]) {
    return;
  }
  // cout << i << j;
  if (i == r && j == c) {
    // cout << i << j;
    cout << s << "\n";
  }
  arr[i][j] = 1;
  solve(i, j + 1, s + "A");
  solve(i + 1, j, s + "B");
  solve(i - 1, j, s + "C");
  arr[i][j] = 0;
}

int main() {

  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> arr[i][j];
    }
  }
  solve(1, 1, "");
  cout << "DONE";

  return 0;
}
