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

  int y, d;
  cin >> y >> d;
  v[0].push_back({1, d});
  v[1].push_back({0, d});
  for (int i = 2; i < y; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int a, b;
      cin >> a >> b;
      a--;
      v[i].push_back({a, b});
      v[a].push_back({i, b});
    }
    dijkstra(0);
    cout << dis[1] << " ";
    fill(dis.begin(), dis.end(), INT_MAX);
  }

  return 0;
}
