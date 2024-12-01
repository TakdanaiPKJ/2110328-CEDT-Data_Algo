#include "bits/stdc++.h"
using namespace std;

int r, c;
int arr[20][20];

void solve(string s, int i, int j, bool visited[20][20]) {
  if (i <= 0 || j <= 0 || i > r || j > c || arr[i][j] == 1 || visited[i][j]) {
    return;
  }
  if (i == r && j == c) {
    cout << s << "\n";
    return;
  }
  visited[i][j] = true;
  solve(s + "A", i, j + 1, visited);
  solve(s + "B", i + 1, j, visited);
  solve(s + "C", i - 1, j, visited);
  visited[i][j] = false;
  return;
}

int main() {

  bool visited[20][20];
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> arr[i][j];
      visited[i][j] = false;
    }
  }
  solve("", 1, 1, visited);
  cout << "DONE";

  return 0;
}
