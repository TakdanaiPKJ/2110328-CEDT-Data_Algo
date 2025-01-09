#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to, w;
};

vector<Edge> v;
vector<int> dis(1001, INT_MAX);

bool bf(int st, int n) {
  dis[st] = 0;

  bool chk = false;
  for (int i = 0; i < n; i++) {
    chk = false;
    for (auto x : v) {
      if (dis[x.from] != INT_MAX && dis[x.from] + x.w < dis[x.to]) {
        dis[x.to] = dis[x.from] + x.w;
        chk = true;
      }
    }
  }
  return chk;
}

int main() {

  int n, e, s;
  cin >> n >> e >> s;
  for (size_t i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({a, b, c});
  }
  if (bf(s, n)) {
    cout << "-1";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cout << dis[i] << " ";
  }

  return 0;
}
