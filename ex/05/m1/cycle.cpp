#include <bits/stdc++.h>
#include <utility>
using namespace std;

void dfs(vector<bool> visited, vector<int> adj[], int n) {

  visited[n] = true;

  cout << n << " ";

  for (auto x : adj[n]) {
    if (!visited[x])
      dfs(visited, adj, x);
  }
  return;
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vector<int> adj[10001];
    vector<bool> visited(10001, false);
    for (int i = 0; i < b; i++) {
      int aa, ab;
      cin >> aa >> ab;
      adj[aa].push_back(ab);
      adj[ab].push_back(aa);
    }
    dfs(visited, adj, 0);
    // cout << ((tmp) ? "NO\n" : "YES\n");
  }

  return 0;
}
