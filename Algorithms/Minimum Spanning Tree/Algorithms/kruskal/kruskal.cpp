#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &other) const { return other.w > w; }
};

vector<Edge> adj(100);
vector<int> disjoint;

int parent(int a) {
  if (disjoint[a] != a) {
    disjoint[a] = parent(disjoint[a]);
  }
  return disjoint[a];
}

void union_find(int a, int b) {
  int rootA = parent(a);
  int rootB = parent(b);
  if (rootA != rootB) {
    disjoint[rootA] = rootB;
  }
}

long long kruskal() {

  long long cost = 0;
  sort(adj.begin(), adj.end());
  for (auto x : adj) {
    int u = x.u;
    int v = x.v;
    if (parent(u) != parent(v)) {
      cost += x.w;
      union_find(u, v);
    }
  }
  return cost;
}

int main() {

  int n, e;
  cin >> n >> e;

  for (int i = 1; i <= n; i++) {
    disjoint[i] = i;
  }

  for (int i = 0; i < e; i++) {
    cin >> adj[i].u >> adj[i].v >> adj[i].w;
  }

  long long result = kruskal();
  cout << result << endl;
}
