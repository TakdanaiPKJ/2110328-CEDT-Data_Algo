#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
};

vector<vector<Edge>> v(100);
vector<int> dis(100, INT_MAX);
bool has_negative_cycle = false;

void bellman_ford(int st, int n) {
  dis[st] = 0;

  // Relax all edges (n-1) times
  for (int i = 1; i < n; ++i) {
    for (int u = 0; u < n; ++u) {
      for (auto x : v[u]) {
        if (dis[u] != INT_MAX && dis[u] + x.w < dis[x.en]) {
          dis[x.en] = dis[u] + x.w;
        }
      }
    }
  }

  // Check for negative weight cycles
  for (int u = 0; u < n; ++u) {
    for (auto x : v[u]) {
      if (dis[u] != INT_MAX && dis[u] + x.w < dis[x.en]) {
        has_negative_cycle = true;
        break;
      }
    }
    if (has_negative_cycle) break;
  }
}

int main() {
  int n, e, st;
  cin >> n >> e >> st;

  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});  // If undirected graph
  }

  bellman_ford(st, n);

  if (has_negative_cycle) {
    cout << "Negative weight cycle detected!" << endl;
  } else {
    for (size_t i = 0; i < n; ++i) {
      if (dis[i] == INT_MAX) {
        cout << "INF\n";  // unreachable node
      } else {
        cout << dis[i] << "\n";  // print the shortest distance
      }
    }
  }

  return 0;
}
