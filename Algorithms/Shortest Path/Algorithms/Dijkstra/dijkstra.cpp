#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w < w; }
};

vector<vector<Edge>> v(100);
vector<int> dis(100, INT_MAX);

void dijkstra(int st) {

  priority_queue<Edge> q;
  dis[st] = 0;
  q.push({st, 0});
  while (!q.empty()) {
    Edge tmp = q.top();
    q.pop();
    if (tmp.w > dis[tmp.en])
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

  int n, e, st;
  cin >> n >> e >> st;
  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  dijkstra(st);
  for (size_t i = 0; i < n; i++) {
    cout << dis[i] << "\n";
  }

  return 0;
}
