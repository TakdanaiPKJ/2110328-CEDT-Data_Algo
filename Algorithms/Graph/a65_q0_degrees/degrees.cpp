#include <bits/stdc++.h>
#include <map>
using namespace std;

int arr[10000];
map<int, int> m;

int main() {

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a != 0) {
        arr[i] += a;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    m[arr[i]]++;
  }
  for (int i = 0; i < m.size(); i++)
    cout << m[i] << " ";

  return 0;
}

