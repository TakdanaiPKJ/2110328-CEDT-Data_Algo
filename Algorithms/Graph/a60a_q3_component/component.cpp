#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<bool> visited(10001, false);

void bfs(int n) {

  queue<int> q;
  for (auto x : adj[n]) {
    q.push(x);
  }
  visited[n] = true;
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    visited[tmp] = true;
    for (auto x : adj[tmp]) {
      if (!visited[x])
        q.push(x);
    }
  }
}

int main() {

  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int cnt = 0;
  for (size_t i = 1; i <= n; i++) {
    if (!visited[i]) {
      cnt++;
      bfs(i);
    }
  }
  cout << cnt;

  return 0;
}
