#include "bits/stdc++.h"
using namespace std;

vector<int> vt;
unordered_map<string, int> ump;

int main() {

  int n, k, tmp = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if (ump.find(a) == ump.end()) {
      ump[a] = tmp;
      vt.push_back(0);
      tmp++;
    }
    vt[ump[a]]++;
  }
  sort(vt.begin(), vt.end(), greater<int>());
  if (vt[k - 1] <= 0) {
    cout << vt[vt.size() - 1];
  } else
    cout << vt[k - 1];

  return 0;
}
