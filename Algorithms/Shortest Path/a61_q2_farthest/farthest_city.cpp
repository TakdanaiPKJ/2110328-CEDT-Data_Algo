#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w < w; }
};

vector<vector<Edge>> v(1001);
vector<int> dis(1001, INT_MAX);

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

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a == 0 || a == -1)
        continue;
      v[i].push_back({j, a});
    }
  }
  dijkstra(0);
  int mx = INT_MIN;
  for (size_t i = 1; i < n; i++) {
    mx = max(mx, dis[i]);
  }

  cout << ((mx == INT_MAX) ? -1 : mx);

  return 0;
}
