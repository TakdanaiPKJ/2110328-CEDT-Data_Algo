#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1001);
int k;

int bfs(vector<bool> visited, set<int> s, int n, int dep) {

  queue<pair<int, int>> q;
  visited[n] = true;
  q.push({n, 0});
  int cnt = 0;

  while (!q.empty()) {
    int tmp = q.front().first;
    int dis = q.front().second;
    q.pop();

    if (dis <= k) {
      cnt++;
      for (int neighbor : adj[tmp]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push({neighbor, dis + 1});
        }
      }
    }
  }
  return cnt;
}

int main() {

  int n, e;
  cin >> n >> e >> k;
  for (size_t i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> visited(1001, false);
  set<int> s;
  int mx = 1;
  for (size_t i = 0; i < n; i++) {
    mx = max(mx, bfs(visited, s, i, 0));
  }

  // cout << bfs(visited, s, 0, 0);
  cout << mx;

  return 0;
}
