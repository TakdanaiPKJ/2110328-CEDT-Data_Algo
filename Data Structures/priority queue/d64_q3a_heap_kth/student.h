#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "priority_queue.h"
#include <algorithm>
#include <vector>

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
  // write your code here
  // can include anything
  std::vector<T> v;
  for (size_t i = 0; i < std::min(size_t(8), mSize); i++) {
    v.push_back(mData[i]);
  }
  std::sort(v.begin(), v.end(), mLess);
  return *(v.end() - k);
}

#endif
