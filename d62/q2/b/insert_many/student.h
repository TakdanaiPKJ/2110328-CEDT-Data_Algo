#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
  // write your code here
  std::sort(data.begin(), data.end());
  CP::vector<T> ans;
  int cnt = 0;
  for (int i = 0; i < data.size() + mSize; i++) {
    if (i - cnt == data[cnt].first) {
      ans.push_back(data[cnt].second);
      cnt++;
    } else {
      ans.push_back(mData[i - cnt]);
    }
  }
  operator=(ans);
}

#endif
