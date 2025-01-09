#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w < w; }
};

int in[2001];
int out[2001];
vector<int> dis(2001, INT_MAX);
vector<vector<Edge>> v(2001);

void dijkstra(int st) {
  priority_queue<Edge> q;
  dis[st] = 0;
  q.push({st, 0});
  while (!q.empty()) {
    Edge tmp = q.top();
    q.pop();
    if (dis[tmp.en] < tmp.w)
      continue;
    for (auto x : v[tmp.en]) {
      if (dis[tmp.en] + x.w < dis[x.en]) {
        dis[x.en] = dis[tmp.en] + x.w;
        q.push({x.en, dis[x.en]});
      }
    }
  }
}

int main() {

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> in[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> out[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int cost = out[a] + in[b];
    // cout << cost;
    v[a].push_back({b, cost});
  }
  dijkstra(0);
  // cout << "\n---------\n";
  for (int i = 0; i < n; i++) {
    if (dis[i] == INT_MAX)
      cout << "-1 ";
    else
      cout << dis[i] << " ";
  }

  return 0;
}
