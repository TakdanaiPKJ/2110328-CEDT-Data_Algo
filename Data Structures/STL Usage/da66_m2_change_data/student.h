#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to) {
  // your code here
  std::vector<std::vector<std::queue<int>>> v;
  while (!a.empty()) {
    v.push_back(a.top());
    a.pop();
  }
  for (auto &x : v) {
    for (auto &y : x) {
      for (int i = 0; i < y.size(); i++) {
        if (y.front() == from) {
          y.push(to);
        } else {
          y.push(y.front());
        }
        y.pop();
      }
      // std::cout << "\n";
    }
    // std::cout << "-----\n";
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    a.push(v[i]);
  }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a,
              int from, int to) {
  // your code here
  for (auto &x : a) {

    std::priority_queue<int> tmpq;
    while (!x.second.first.empty()) {
      if (x.second.first.top() == from) {
        tmpq.push(to);
      } else {
        tmpq.push(x.second.first.top());
      }
      x.second.first.pop();
    }
    x.second.first = tmpq;

    if (x.second.second == from) {
      x.second.second = to;
    }
  }
}

void change_3(
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>>
        &a,
    int from, int to) {
  // your code here

  std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>>
      tmp;
  for (auto x : a) {
    for (auto &l : x.first) {
      if (l == from)
        l = to;
    }
    std::map<int, std::pair<int, string>> tmpm;
    for (auto m : x.second) {
      if (m.second.first == from) {
        m.second.first = to;
      }
      if (m.first == from) {
        tmpm[to].first = m.second.first;
        tmpm[to].second = m.second.second;
      } else {
        tmpm[m.first].first = m.second.first;
        tmpm[m.first].second = m.second.second;
      }
    }
    x.second = tmpm;

    tmp.insert(x);
  }
  a = tmp;
}

#endif
