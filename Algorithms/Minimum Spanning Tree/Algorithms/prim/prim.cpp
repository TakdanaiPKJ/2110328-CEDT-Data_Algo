#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w < w; }
};

vector<vector<Edge>> v(100);

int prim(int st) {
  priority_queue<Edge> q;
  vector<bool> visited(100, false);
  int sum = 0;
  visited[st] = true;
  for (auto x : v[st]) {
    q.push(x);
  }
  while (!q.empty()) {
    Edge tmp = q.top();
    q.pop();
    if (visited[tmp.en])
      continue;
    visited[tmp.en] = true;
    sum += tmp.w;
    for (auto x : v[tmp.en]) {
      q.push(x);
    }
  }
  return sum;
}

int main() {

  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v[x].push_back({y, z});
    v[y].push_back({y, z});
  }
  cout << prim(0);

  return 0;
}
