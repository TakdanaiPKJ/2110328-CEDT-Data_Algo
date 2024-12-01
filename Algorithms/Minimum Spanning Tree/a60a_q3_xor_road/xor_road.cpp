#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int en, w;
  bool operator<(const Edge &other) const { return other.w > w; }
};

vector<vector<Edge>> v(10001);
vector<int> mem;

long long prim(int st) {
  priority_queue<Edge> q;
  vector<bool> visited(10001, false);
  long long sum = 0;
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

  int n;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    int a;
    cin >> a;
    mem.push_back(a);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n - i; j++) {
      int x = mem[i] ^ mem[i + j];
      v[i].push_back({i + j, x});
      v[i + j].push_back({i, x});
    }
  }
  cout << prim(0);

  return 0;
}
