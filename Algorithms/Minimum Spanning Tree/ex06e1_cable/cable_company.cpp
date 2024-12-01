#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w < w; }
};

vector<vector<Edge>> v(1001);

int prim(int st) {
  vector<bool> visited(1001, false);
  priority_queue<Edge> q;
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
    sum += tmp.w;
    visited[tmp.en] = true;
    for (auto x : v[tmp.en]) {
      q.push(x);
    }
  }
  return sum;
}

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j <= n - i - 1; j++) {
      int a;
      cin >> a;
      v[i].push_back({j + i, a});
      v[j + i].push_back({i, a});
    }
  }
  cout << prim(0);

  return 0;
}
