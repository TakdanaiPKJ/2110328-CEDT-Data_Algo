#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100001);
vector<bool> visited(100001, false);

void dfs(int n, vector<int> &deg) {

  stack<int> st;
  st.push(n);
  visited[n] = true;

  while (!st.empty()) {
    int tmp = st.top();
    st.pop();
    visited[tmp] = true;
    deg.push_back(adj[tmp].size());
    for (auto x : adj[tmp]) {
      if (!visited[x]) {
        st.push(x);
      }
    }
  }
  return;
}

bool chk(vector<int> &deg) {
  int deg1 = 0, deg2 = 0;
  for (auto x : deg) {
    if (x == 1)
      deg1++;
    else if (x == 2)
      deg2++;
    else if (x > 2)
      return false;
  }
  if (deg.size() == 1)
    return true;
  return deg1 == 2 && deg2 == deg.size() - 2;
}

int main() {

  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int cnt = 0;
  for (size_t i = 0; i < n; i++) {
    if (!visited[i]) {
      vector<int> deg;
      dfs(i, deg);
      if (chk(deg)) {
        cnt++;
      }
    }
  }
  cout << cnt;

  return 0;
}
