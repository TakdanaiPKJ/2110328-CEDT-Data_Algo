#include <bits/stdc++.h>
using namespace std;

struct pacndemic {
  int x;
  int y;
  int day;
};

vector<vector<int>> v(600, vector<int>(600, 0));
set<pair<int, int>> s;

int r, c, t;
int cnt = 0;

void floodfil() {

  queue<pacndemic> q;

  for (auto kep : s) {
    q.push({kep.second, kep.first, 0});
  }
  int di[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    pacndemic tmp = q.front();
    q.pop();

    int d = tmp.day;

    if (d > t)
      continue;
    if (v[tmp.y][tmp.x] == 0) {
      cnt++;
      v[tmp.y][tmp.x] = 1;
    }
    // cout << tmp.y << tmp.x << d << "\n";

    for (auto dd : di) {
      int xx = tmp.x + dd[1];
      int yy = tmp.y + dd[0];
      if (yy < r && xx < c && xx >= 0 && yy >= 0 && v[yy][xx] == 0) {
        // cout << tmp.y << tmp.x << "|" << yy << xx << d + 1 << "\n";
        // cnt++;

        q.push({xx, yy, d + 1});
      }
    }
  }
}

int main() {

  cin >> r >> c >> t;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> v[i][j];
      if (v[i][j] == 1) {
        s.insert({i, j});
        cnt++;
      }
    }
  }
  /*
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (cp[i][j] == 1)
        floodfil(i, j, 0);
    }
  }
  */
  floodfil();
  /*for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (v[i][j] == 1) {
        cnt++;
      }
     // cout << v[i][j];
    }
    //cout << "\n";
  }*/
  cout << cnt;

  return 0;
}
