#include "student.h"
#include "vector.h"
#include <iostream>
#include <stdexcept>

int main() {
  int n;
  CP::vector<int> v;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    v.push_back(a);
  }
  v.compress();

  v.print_for_quiz();
}
