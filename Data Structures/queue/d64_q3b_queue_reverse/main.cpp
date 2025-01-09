#include "queue.h"
#include "student.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  CP::queue<char> q;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    q.push(x);
  }
  q.reverse(a, b);

  cout << "size of q = " << q.size() << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}
