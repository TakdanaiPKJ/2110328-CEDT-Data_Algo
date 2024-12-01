#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<bool> &visited, vector<vector<int>> &adj, int n, int prev) {

  visited[n] = true;

  for (auto x : adj[n]) {
    if (!visited[x]) {
      if (dfs(visited, adj, x, n))
        return true;
    } else if (x != prev) {
      return true;
    }
  }
  return false;
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> adj(a);
    vector<bool> visited(a, false);
    for (int j = 0; j < b; j++) {
      int aa, ab;
      cin >> aa >> ab;
      adj[aa].push_back(ab);
      adj[ab].push_back(aa);
    }
    bool tmp = false;
    for (int j = 0; j < a; j++) {
      if (!visited[j]) {
        if (dfs(visited, adj, j, -1)) {
          tmp = true;
          break;
        }
      }
    }

    cout << ((tmp) ? "YES\n" : "NO\n");
  }

  return 0;
}
